#include "assembler.h"
#include <sstream>
#include <algorithm>

Assembler::Assembler()
{

}

std::vector<std::string> Assembler::toVector(const std::string &code)
{
    std::vector<std::string> preprocesedCode;
    std::string line = "";
    bool readingComment = false;
    for(unsigned long i=0;i<code.length();i++)
    {
        if((code[i] == ';' && i > 1 && code[i-1] != '\'') || (code[i] == '/' && code[i+1] == '/'))
        {
            readingComment = true;
        }
        if(code[i] == '\n')
        {
            readingComment = false;
            preprocesedCode.push_back(line + '\n');
            line.clear();
            continue;
        }
        if(!readingComment)
            line+=code[i];
    }
    return preprocesedCode;
}

std::vector<std::string> Assembler::decodeConstants(const std::vector<std::string>& code)
{
    std::vector<std::string> preprocesedCode;
    int lineNumber = 0;
    for(std::string line : code)
    {
        if(line.length() > 2 && line[0] == '/' && line[1] == '/')
        {
            continue;
        }
        unsigned long position = 0;
        if(contains(line, "EQU ", position))
        {
            std::string operand = line.substr(position+4, line.length());
            if(!contains(line, ":", position))
            {
                errorMessages.push_back("No label for EQU at line: "+std::to_string(lineNumber + 1) + "\n");
                continue;
            }
            std::string label = line.substr(0, position);
            addEQUConstToLabels(label, operand);
            continue;
        }
        if(contains(line, "SET ", position))
        {
            std::string operand = line.substr(position+4, line.length());
            if(!contains(line, ":", position))
            {
                errorMessages.push_back("No label for SET at line: "+std::to_string(lineNumber + 1) + "\n");
                continue;
            }
            std::string label = line.substr(0, position);
            addSETConstToLabels(label, operand);
            continue;
        }
        preprocesedCode.push_back(line);
        lineNumber++;
    }
    return preprocesedCode;
}

std::vector<std::string> Assembler::decodeIfsAndMacros(const std::vector<std::string>& code)
{
    std::vector<std::string> preprocesedCode;
    bool readingIf = false;
    bool writingIf = true;
    bool readingMacro = false;
    std::vector<std::string> macro;
    std::string macroName = "";
    int lineNumber = 0;
    for(const auto& line : code)
    {
        unsigned long position = 0;
        if(line[0] == '\n') continue;
        if(contains(line, "IF ", position) || contains(line, "IF\t", position))
        {
            readingIf = true;
            std::string label = line.substr(position+3, line.length() - 1);
            label = label.substr(0, label.length() - 1);
            std::string val = getValueFormLabel(label);
            if(val.empty())
            {
                errorMessages.push_back("Constant from if not found at line: " + std::to_string(lineNumber + 1) + "\n");
                writingIf = false;
                continue;
            }
            if(fromHex(val) == 0)
            {
                writingIf = false;
                if(std::find(breakpoints.begin(), breakpoints.end(), lineNumber) != breakpoints.end())
                {
                    breakpoints.erase(std::remove(breakpoints.begin(), breakpoints.end(), lineNumber), breakpoints.end());
                }
            }
            else
                writingIf = true;
            continue;
        }
        if(readingIf && contains(line, "ENDIF"))
        {
            readingIf = false;
            writingIf = true;
            continue;
        }
        if(contains(line, " MACRO") || contains(line, "\tMACRO"))
        {
            if(!contains(line, ":", position))
            {
                errorMessages.push_back("No label for macro at line: "+std::to_string(lineNumber + 1) + "\n");
            }
            macroName = line.substr(0, position);
            readingMacro = true;
            continue;
        }
        if(contains(line, "ENDM"))
        {
            macros.push_back(std::make_pair(macroName, macro));
            macroName.clear();
            macro.clear();
            readingMacro = false;
            continue;
        }
        if(readingMacro)
        {
            macro.push_back(line);
        }
        if(!readingMacro && writingIf)
        {
            preprocesedCode.push_back(line);
        }
        lineNumber++;
    }

    return preprocesedCode;
}

std::vector<std::string> Assembler::applyMacros(const std::vector<std::string> &code)
{
    std::vector<std::string> preprocesedCode;
    for(const auto& line : code)
    {
        bool found = false;
        for(const auto& j : macros)
        {
            if(contains(line, j.first))
            {
                for(const auto& l : j.second)
                {
                    preprocesedCode.push_back(l);
                }
                found = true;
                break;
            }
        }
        if(!found)
            preprocesedCode.push_back(line);
    }
    return preprocesedCode;
}

std::vector<std::string> Assembler::decodeLabels(const std::vector<std::string>& code, unsigned short startAddress)
{
    std::vector<std::string> preprocesedCode;
    unsigned short address = startAddress;
    for(const auto& line : code)
    {
        if(line[0] == '\n') continue;
        unsigned long position = 0;
        if(contains(line, ": ", position) || contains(line, ":\t", position))
        {
            std::string label = line.substr(0, position);
            labels.push_back(std::make_pair(label, toHex(address)));
            preprocesedCode.push_back(line.substr(position+2, line.length()));
            address += getInstLength(line);
            continue;
        }
        address += getInstLength(line);
        preprocesedCode.push_back(line);
    }
    return preprocesedCode;
}

std::vector<std::string> Assembler::decodeOperands(const std::vector<std::string>& code)
{
    std::vector<std::string> preprocesedCode;
    int lineNumber = 0;
    for(const auto& line : code)
    {
        int length = 0;
        unsigned long position = 0;
        if(isOneArgs(line, length, position))
        {
            std::string operand = line.substr(position + length, line.length());
            operand.erase(std::remove(operand.begin(), operand.end(), ' '), operand.end());
            operand.erase(std::remove(operand.begin(), operand.end(), '\t'), operand.end());
            operand = operand.substr(0, operand.length() - 1);
            unsigned long apos = 0;
            if(operand.length() > 2 && contains(operand, "\'", apos))
            {
                std::string ansi = operand.substr(apos + 1, 1);
                operand = operand.replace(apos, apos+3, toHex(+ansi[0]));
            }
            if(isNumber(operand))
            {

            }
            else if(contains(operand, "+") || contains(operand, "-") || contains(operand, "*") || contains(operand, "/"))
            {
                operand = mathOperand(operand);
            }
            else
            {
                operand = getValueFormLabel(operand);
            }
            if(operand.empty())
            {
                errorMessages.push_back("Label not found or operand is incorrect at line: "+std::to_string(lineNumber + 1) + "\n");
            }
            std::string finished = line;
            finished = finished.substr(position, length);
            finished += operand;
            preprocesedCode.push_back(finished);
            continue;
        }
        if(isTwoArgs(line, length, position))
        {
            std::string operand = line.substr(position + length, line.length());
            operand.erase(std::remove(operand.begin(), operand.end(), ' '), operand.end());
            operand.erase(std::remove(operand.begin(), operand.end(), '\t'), operand.end());
            operand = operand.substr(0, operand.length() - 1);
            unsigned long apos = 0;
            if(operand.length() > 2 && contains(operand, "\'", apos))
            {
                std::string ansi = operand.substr(apos + 1, 1);
                operand = operand.replace(apos, apos+3, toHex(+ansi[0]));
            }
            if(isNumber(operand))
            {

            }
            else if(contains(operand, "+") || contains(operand, "-") || contains(operand, "*") || contains(operand, "/"))
            {
                operand = mathOperand(operand);
            }
            else
            {
                operand = getValueFormLabel(operand);
            }
            if(operand.empty())
            {
                errorMessages.push_back("Label not found or operand is incorrect at line: "+std::to_string(lineNumber + 1) + "\n");
            }
            std::string finished = line;
            finished = finished.substr(position, length);
            finished += operand;
            preprocesedCode.push_back(finished);
            continue;
        }
        if(isCallAndJmps(line, length, position))
        {
            std::string operand = line.substr(position + length, line.length());
            operand.erase(std::remove(operand.begin(), operand.end(), ' '), operand.end());
            operand.erase(std::remove(operand.begin(), operand.end(), '\t'), operand.end());
            operand = operand.substr(0, operand.length() - 1);
            unsigned long apos = 0;
            if(operand.length() > 2 && contains(operand, "\'", apos))
            {
                std::string ansi = operand.substr(apos + 1, 1);
                operand = operand.replace(apos, apos+3, toHex(+ansi[0]));
            }
            if(isNumber(operand))
            {

            }
            else if(contains(operand, "+") || contains(operand, "-") || contains(operand, "*") || contains(operand, "/"))
            {
                operand = mathOperand(operand);
            }
            else
            {
                operand = getValueFormLabel(operand);
            }
            if(operand.empty())
            {
                errorMessages.push_back("Label not found or operand is incorrect at line: "+std::to_string(lineNumber + 1) + "\n");
            }
            std::string finished = line;
            finished = finished.substr(position, length);
            finished += operand;
            preprocesedCode.push_back(finished);
            continue;
        }
        preprocesedCode.push_back(line);
        lineNumber++;
    }
    return preprocesedCode;
}

unsigned char *Assembler::assemble(const std::vector<std::string>& code)
{
    std::vector<unsigned char> assembledCode;
    int lineNumber = 0;
    for(const auto& line : code)
    {
        if(assembleNoArgs(line, assembledCode))
        {

        }
        else if(assembleOneargs(line, assembledCode))
        {

        }
        else if(assembleOneargs(line, assembledCode))
        {

        }
        else if(assembleTwoargs(line, assembledCode))
        {

        }
        else if(assembleCallsandjmps(line, assembledCode))
        {

        }
        else if(assemblePInst(line, assembledCode))
        {

        }
        else if(contains(line, "END"))
        {
            break;
        }
        else
        {
            if(line.length() != 1 && line[0] != '\n')
                errorMessages.push_back("Unknown instruction " + line + " at line: "+std::to_string(lineNumber + 1) + "\n");
        }


        if(std::find(breakpoints.begin(), breakpoints.end(), lineNumber) != breakpoints.end())
        {
            codeBreakpoints.push_back(std::make_pair(assemblerAddress, lineNumber));
        }
        lineAddrInsts.push_back(std::make_pair(assemblerAddress, lineNumber));

        lineNumber++;
    }
    compCodeSize = assembledCode.size();
    return toUCharArray(assembledCode);
}

int Assembler::getCompCodeSize()
{
    return compCodeSize;
}

std::vector<std::string> Assembler::getErrorMessages() const
{
    return errorMessages;
}

int Assembler::getAssemblerAddress() const
{
    return assemblerAddress;
}

void Assembler::setAssemblerAddress(int newAssemblerAddress)
{
    assemblerAddress = newAssemblerAddress;
}

std::vector<int> Assembler::getBreakpoints() const
{
    return breakpoints;
}

void Assembler::setBreakpoints(const std::vector<int> &newBreakpoints)
{
    breakpoints = newBreakpoints;
}

std::vector<std::pair<unsigned short, int> > Assembler::getCodeBreakpoints() const
{
    return codeBreakpoints;
}

void Assembler::setCodeBreakpoints(const std::vector<std::pair<unsigned short, int> > &newCodeBreakpoints)
{
    codeBreakpoints = newCodeBreakpoints;
}

void Assembler::clearErrorMessages()
{
    errorMessages.clear();
}

void Assembler::clearCodeBreakpoints()
{
    codeBreakpoints.clear();
}

void Assembler::clearBreakpoints()
{
    breakpoints.clear();
}

std::vector<std::pair<unsigned short, int> > Assembler::getLineAddrInsts() const
{
    return lineAddrInsts;
}

void Assembler::resetLineAddrInsts()
{
    lineAddrInsts.clear();
}

bool Assembler::assembleNoArgs(std::string currentinst, std::vector<unsigned char>& assembledCode)
{
    if(contains(currentinst, "ADI"))
        return false;
    for (const auto& j : noargs)
    {
        if (currentinst.find(j.first) != std::string::npos)
        {
            assembledCode.push_back(j.second);
            currentinst.clear();
            assemblerAddress += 1;
            return true;
        }
    }
    return false;
}

bool Assembler::assembleOneargs(std::string currentinst, std::vector<unsigned char>& assembledCode)
{
    for (const auto& j : oneargs)
    {
        if (currentinst.find(j.first) != std::string::npos)
        {
            assembledCode.push_back(j.second);
            assembledCode.push_back(fromHex(currentinst.substr(j.first.length(), currentinst.length())));
            currentinst.clear();
            assemblerAddress += 2;
            return true;
        }
    }
    return false;
}

bool Assembler::assembleTwoargs(std::string currentinst, std::vector<unsigned char>& assembledCode)
{
    for (const auto& j : twoargs)
    {
        if (currentinst.find(j.first) != std::string::npos)
        {
            assembledCode.push_back(j.second);
            assembledCode.push_back(fromHex(currentinst.substr(j.first.length(), currentinst.length())));
            assembledCode.push_back(fromHex(currentinst.substr(j.first.length(), currentinst.length())) >> 8);
            currentinst.clear();
            assemblerAddress += 3;
            return true;
        }
    }
    return false;
}

bool Assembler::assembleCallsandjmps(std::string currentinst, std::vector<unsigned char>& assembledCode)
{
    for (const auto& j : callsandjmps)
    {
        if (currentinst.find(j.first) != std::string::npos)
        {
            assembledCode.push_back(j.second);
            assembledCode.push_back(fromHex(currentinst.substr(j.first.length(), currentinst.length())));
            assembledCode.push_back(fromHex(currentinst.substr(j.first.length(), currentinst.length())) >> 8);
            currentinst.clear();
            assemblerAddress += 3;
            return true;
        }
    }
    return false;
}

bool Assembler::assemblePInst(std::string currentinst, std::vector<unsigned char> &assembledCode)
{
    if(currentinst.length()>1)
    {
        unsigned long pos = 0;
        if(contains(currentinst, "DB", pos))
        {
            assembledCode.push_back(fromHex(currentinst.substr(pos+2, currentinst.length())));
            return true;
        }
        if(contains(currentinst, "DW", pos))
        {
            assembledCode.push_back(fromHex(currentinst.substr(pos+2, currentinst.length())));
            assembledCode.push_back(fromHex(currentinst.substr(pos+2, currentinst.length())) >> 8);
            return true;
        }
        if(contains(currentinst, "STRING", pos))
        {
            unsigned long position = 0;
            if(contains(currentinst, "\"", position))
            {
                for(auto i = position+1; i < currentinst.length(); i++)
                {
                    if(currentinst[i] == '\"')
                    {
                        break;
                    }
                    assembledCode.push_back(+currentinst[i]);
                    assemblerAddress++;
                }
                return true;
            }
            else
            {
                errorMessages.push_back("String error");
            }
        }
        if(contains(currentinst, "ARRAY", pos))
        {
            for(auto i = pos + 6; i< currentinst.length(); i+=2)
            {
                if(currentinst[i] == '\n' || currentinst[i] == ' ' || currentinst[i] == '\t')
                    break;
                std::string tmp = "";
                tmp += currentinst[i];
                tmp += currentinst[i+1];
                assembledCode.push_back(fromHex(tmp));
                assemblerAddress++;
            }
        }
    }
    return false;
}

std::string Assembler::mathOperand(const std::string &operand)
{
    std::string tmp = "";
    std::string partOne = "";
    std::string partTwo = "";
    std::string resoults = "";
    for(unsigned long i = 0; i < operand.length(); i++)
    {
        if(operand[i] == '+' || operand[i] == '-' || operand[i] == '*' || operand[i] == '/')
        {
            if(isNumber(tmp))
            {
                resoults += std::to_string(fromHex(tmp));
            }
            else
            {
                std::string labelValue = getValueFormLabel(tmp);
                if(labelValue.empty())
                {
                    errorMessages.push_back("Label not found");
                }
                else
                {
                    resoults += std::to_string(fromHex(labelValue));
                }
            }
            resoults += operand[i];
            tmp.clear();
            continue;
        }
        tmp += operand[i];
    }
    if(isNumber(tmp))
    {
        resoults += std::to_string(fromHex(tmp));
    }
    else
    {
        std::string labelValue = getValueFormLabel(tmp);
        if(labelValue.empty())
        {
            errorMessages.push_back("Label not found");
        }
        else
        {
            resoults += std::to_string(fromHex(labelValue));
        }
    }
    resoults.erase(std::remove(resoults.begin(), resoults.end(), '\n'), resoults.end());
    resoults.erase(std::remove(resoults.begin(), resoults.end(), '\t'), resoults.end());
    resoults.erase(std::remove(resoults.begin(), resoults.end(), ' '), resoults.end());
    std::stringstream ss(resoults);
    double resoult;
    auto func = [](double &result, char op, double num){
        switch (op) {
        case '+':
            result += num;
            break;
        case '-':
            result -= num;
            break;
        case '*':
            result *= num;
            break;
        case '/':
            result /= num;
            break;
        }
    };
    ss >> resoult;
    char op;
    double num;
    while (ss >> op >> num)
    {
        func(resoult, op, num);
    }
    return toHex(resoult);
}

unsigned char *Assembler::toUCharArray(const std::vector<unsigned char> &vector)
{
    unsigned char* ucharArray = new unsigned char[vector.size()];
    std::copy(vector.begin(), vector.end(), ucharArray);
    return ucharArray;
}

bool Assembler::isNumber(const std::string &val) const
{
    for(const auto& i : val)
    {
        if(i == '\n')
            continue;
        if(!isxdigit(i))
            return false;
    }
    return true;
}

bool Assembler::contains(const std::string& string, const std::string& val) const
{
    return string.find(val) != std::string::npos;
}

bool Assembler::contains(const std::string& string, const std::string& val, unsigned long &position) const
{
    position = string.find(val);
    return position != std::string::npos;
}

void Assembler::addEQUConstToLabels(const std::string &name, const std::string &val)
{
    bool found = false;
    for(const auto& i : labels)
    {
        if(i.first == name)
        {
            found = true;
            return;
        }
    }
    if(!found)
        labels.push_back(std::make_pair(name, val));
}

void Assembler::addSETConstToLabels(const std::string &name, const std::string &val)
{
    bool found = false;
    for(auto& i : labels)
    {
        if(i.first == name)
        {
            i.second = val;
            found = true;
            return;
        }
    }
    if(!found)
        labels.push_back(std::make_pair(name, val));
}

std::string Assembler::getValueFormLabel(const std::string& label) const
{
    for(const auto& i : labels)
    {
        if(i.first == label)
            return i.second;
    }
    return "";
}

unsigned long Assembler::fromHex(const std::string &hex) const
{
    return strtol(hex.c_str(), nullptr, 16);
}

std::string Assembler::toHex(unsigned short val) const
{
    std::stringstream ss;
    ss << std::hex << val;
    return ss.str();
}

int Assembler::getInstLength(const std::string &inst)
{
    for(const auto& i : noargs)
    {
        if(inst.find(i.first) != std::string::npos)
        {
            return 1;
        }
    }
    for(const auto& i : oneargs)
    {
        if(inst.find(i.first) != std::string::npos)
        {
            return 2;
        }
    }
    for(const auto& i : twoargs)
    {
        if(inst.find(i.first) != std::string::npos)
        {
            return 3;
        }
    }
    for(const auto& i : callsandjmps)
    {
        if(inst.find(i.first) != std::string::npos)
        {
            return 3;
        }
    }
    if(contains(inst, "STRING"))
    {
        unsigned long position = 0;
        if(contains(inst, "\"", position))
        {
            int count = 0;
            for(auto i = position+1;i<inst.length();i++)
            {
                if(inst[i] == '\"')
                    break;
                count++;
            }
            return count;
        }
        else
        {
            errorMessages.push_back("String error");
        }
    }
    unsigned long position = 0;
    if(contains(inst , "ARRAY", position))
    {
        int count = 0;
        for(auto i = position + 6; i < inst.length(); i++)
        {
            if(inst[i] == '\n' || inst[i] == ' ' || inst[i] == '\t')
                break;
            count++;
        }
        return count;
    }
    if(contains(inst, "DW"))
    {
        return 2;
    }
    if(contains(inst, "DB"))
    {
        return 1;
    }
    return -1;
}

bool Assembler::isOneArgs(const std::string &inst, int& length, unsigned long &pos) const
{
    if(contains(inst, "DB"))
    {
        length = 3;
        pos = inst.find("DB");
        return true;
    }
    for(const auto& i : oneargs)
    {
        unsigned long position = inst.find(i.first);
        if(position != std::string::npos)
        {
            length = i.first.length();
            pos = position;
            return true;
        }
    }
    return false;
}

bool Assembler::isTwoArgs(const std::string &inst, int& length, unsigned long &pos) const
{
    if(contains(inst, "DW"))
    {
        length = 3;
        pos = inst.find("DW ");
        return true;
    }
    for(const auto& i : twoargs)
    {
        unsigned long position = inst.find(i.first);
        if(position != std::string::npos)
        {
            length = i.first.length();
            pos = position;
            return true;
        }
    }
    return false;
}

bool Assembler::isCallAndJmps(const std::string &inst, int &length, unsigned long &pos) const
{
    for(const auto& i : callsandjmps)
    {
        unsigned long position = inst.find(i.first);
        if(position != std::string::npos)
        {
            length = i.first.length();
            pos = position;
            return true;
        }
    }
    return false;
}

bool Assembler::isPInst(const std::string &inst, int &length, unsigned long &pos) const
{
    if(inst.length()>1)
    {
        if(contains(inst, "DB", pos))
        {
            length = 2;
            return true;
        }
        if(contains(inst, "DW", pos))
        {
            length = 2;
            return true;
        }
    }
    return false;
}

