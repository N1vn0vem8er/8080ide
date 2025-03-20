#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <unordered_map>
#include <vector>
#include <string>

class Assembler
{
public:
    Assembler();
    std::vector<std::string> toVector(std::string code);
    std::vector<std::string> decodeConstants(const std::vector<std::string> &code);
    std::vector<std::string> decodeIfsAndMacros(const std::vector<std::string> &code);
    std::vector<std::string> applyMacros(const std::vector<std::string> &code);
    std::vector<std::string> decodeLabels(const std::vector<std::string> &code, unsigned short startAddress);
    std::vector<std::string> decodeOperands(const std::vector<std::string> &code);
    unsigned char* assemble(const std::vector<std::string> &code);
    int getCompCodeSize();
    std::vector<std::string> getErrorMessages() const;
    int getAssemblerAddress() const;
    void setAssemblerAddress(int newAssemblerAddress);

    std::vector<int> getBreakpoints() const;
    void setBreakpoints(const std::vector<int> &newBreakpoints);

    std::vector<std::pair<unsigned short, int>> getCodeBreakpoints() const;
    void setCodeBreakpoints(const std::vector<std::pair<unsigned short, int> > &newCodeBreakpoints);
    void clearErrorMessages();
    void clearCodeBreakpoints();
    void clearBreakpoints();

    std::vector<std::pair<unsigned short, int> > getLineAddrInsts() const;
    void resetLineAddrInsts();

private:
    //labels <name,value>
    std::vector<std::pair<std::string, std::string>> labels;
    std::vector<std::string> errorMessages;
    //macros <name,code>
    std::vector<std::pair<std::string, std::vector<std::string>>> macros;
    unsigned short assemblerAddress = 0;
    std::vector<int> breakpoints;
    std::vector<std::pair<unsigned short, int>> codeBreakpoints;
    std::vector<std::pair<unsigned short, int>> lineAddrInsts;
    bool assembleNoArgs(std::string currentinst, std::vector<unsigned char> &assembledCode);
    bool assembleOneargs(std::string currentinst, std::vector<unsigned char>& assembledCode);
    bool assembleTwoargs(std::string currentinst, std::vector<unsigned char>& assembledCode);
    bool assembleCallsandjmps(std::string currentinst, std::vector<unsigned char>& assembledCode);
    bool assemblePInst(std::string currentinst, std::vector<unsigned char>& assembledCode);
    bool contains(const std::string &string, const std::string &val);
    bool contains(const std::string &string, const std::string &val, unsigned long& position);
    void addEQUConstToLabels(std::string name, std::string val);
    void addSETConstToLabels(std::string name, std::string val);
    std::string getValueFormLabel(std::string label);
    unsigned long fromHex(std::string hex);
    std::string toHex(unsigned short val);
    int getInstLength(std::string inst);
    bool isOneArgs(std::string inst, int &length, unsigned long& pos);
    bool isTwoArgs(std::string inst, int &length, unsigned long& pos);
    bool isCallAndJmps(std::string inst, int &length, unsigned long& pos);
    bool isPInst(std::string inst, int &length, unsigned long& pos);
    std::string mathOperand(std::string operand);
    unsigned char* toUCharArray(const std::vector<unsigned char>& vector);
    bool isNumber(std::string val);
    int compCodeSize = 0;


    std::unordered_map<std::string, unsigned char> noargs = { {"NOP", 0x0} , {"RLC", 0x07}, {"RAL", 0x17}, {"DAA",0x27}, {"STC", 0x37},
                                                             {"RRC",0x0f}, {"RAR", 0x1f},{"CMA",0x2f},{"CMC",0x3f},{"HLT",0x76},{"RNZ",0xc0},{"RNC",0xd0},{"RPO",0xe0},{"RP",0xf0},{"RZ",0xc8},
                                                             {"RC",0xd8},{"RPE",0xe8},{"RM",0xf8},{"XTHL",0xe3},{"PCHL",0xe9},{"SPHL",0xf9},{"XCHG",0xeb},{"DI",0xf3},{"EI",0xfb},{"STAX B",0x02},
                                                             {"STAX D",0x12},{"INX B",0x03},{"INX D",0x13},{"INX H",0x23},{"INX SP",0x33},{"INR B",0x04},{"INR D",0x14},{"INR H",0x24},{"INR M",0x34},
                                                             {"DCR B",0x05},{"DCR D",0x15},{"DCR H",0x25},{"DCR M",0x35},{"DAD B",0x09},{"DAD D",0x19},{"DAD H",0x29},{"DAD SP",0x39},{"LDAX B",0x0a},
                                                             {"LDAX D",0x1a},{"DCX B",0x0b},{"DCX D",0x1b},{"DCX H",0x2b},{"DCX SP",0x3b},{"INR C",0x0c},{"INR E",0x1c},{"INR L",0x2c},{"INR A",0x3c},
                                                             {"DCR C",0x0d},{"DCR E",0x1d},{"DCR L",0x2d},{"DCR A",0x3d},{"ADD B",0x80},{"ADD C",0x81},{"ADD D",0x82},{"ADD E",0x83},{"ADD H",0x84},
                                                             {"ADD L",0x85},{"ADD M",0x86},{"ADD A",0x87},{"ADC B",0x88},{"ADC C",0x89},{"ADC D", 0x8a},{"ADC E",0x8b},{"ADC H",0x8c},{"ADC L",0x8d},
                                                             {"ADC M",0x8e},{"ADC A",0x8f},{"SUB B",0x90},{"SUB C",0x91},{"SUB D",0x92},{"SUB E",0x93},{"SUB H",0x94},{"SUB L",0x95},{"SUB M",0x96},
                                                             {"SUB A",0x97},{"SBB B",0x98},{"SBB C",0x99},{"SBB D",0x9a},{"SBB E",0x9b},{"SBB H",0x9c},{"SBB L",0x9d},{"SBB M",0x9e},{"SBB A",0x9f},
                                                             {"ANA B",0xa0},{"ANA C",0xa1},{"ANA D",0xa2},{"ANA E",0xa3},{"ANA H",0xa4},{"ANA L",0xa5},{"ANA M",0xa6},{"ANA A",0xa7},{"XRA B",0xa8},
                                                             {"XRA C",0xa9},{"XRA D",0xaa},{"XRA E",0xab},{"XRA H",0xac},{"XRA L",0xad},{"XRA M",0xae},{"XRA A",0xaf},{"ORA B",0xb0},{"ORA C",0xb1},
                                                             {"ORA D",0xb2},{"ORA E",0xb3},{"ORA H",0xb4},{"ORA L",0xb5},{"ORA M",0xb6},{"ORA A",0xb7},{"CMP B",0xb8},{"CMP C",0xb9},{"CMP D",0xba},
                                                             {"CMP E",0xbb},{"CMP H",0xbc},{"CMP L",0xbd},{"CMP M",0xbe},{"CMP A",0xbf},{"POP B",0xc1},{"POP D",0xd1},{"POP H",0xe1},{"POP PSW",0xf1},
                                                             {"PUSH B",0xc5},{"PUSH D",0xd5},{"PUSH H",0xe5},{"PUSH PSW",0xf5},{"RST 0",0xc7},{"RST 2",0xd7},{"RST 4",0xe7},{"RST 6",0xf7},{"RST 1",0xcf},
                                                             {"RST 3",0xdf},{"RST 5",0xef},{"RST 7",0xff},{"MOV B,B",0x40},{"MOV B,C",0x41},{"MOV B,D",0x42},{"MOV B,E",0x43},{"MOV B,H",0x44},{"MOV B,L",0x45},
                                                             {"MOV B,M",0x46},{"MOV B,A",0x47},{"MOV C,B",0x48},{"MOV C,C",0x49},{"MOV C,D",0x4a},{"MOV C,E",0x4b},{"MOV C,H",0x4c},{"MOV C,L",0x4d},
                                                             {"MOV C,M",0x4e},{"MOV C,A",0x4f},{"MOV D,B",0x50},{"MOV D,C",0x51},{"MOV D,D",0x52},{"MOV D,E",0x53},{"MOV D,H",0x54},{"MOV D,L",0x55},
                                                             {"MOV D,M",0x56},{"MOV D,A",0x57},{"MOV E,B",0x58},{"MOV E,C",0x59},{"MOV E,D",0x5a},{"MOV E,E",0x5b},{"MOV E,H",0x5c},{"MOV E,L",0x5d},
                                                             {"MOV E,M",0x5e},{"MOV E,A",0x5f},{"MOV H,B",0x60},{"MOV H,C",0x61},{"MOV H,D",0x62},{"MOV H,E",0x63},{"MOV H,H",0x64},{"MOV H,L",0x65},
                                                             {"MOV H,M",0x66},{"MOV H,A",0x67},{"MOV L,B",0x68},{"MOV L,C",0x69},{"MOV L,D",0x6a},{"MOV L,E",0x6b},{"MOV L,H",0x6c},{"MOV L,L",0x6d},
                                                             {"MOV L,M",0x6e},{"MOV L,A",0x6f},{"MOV M,B",0x70},{"MOV M,C",0x71},{"MOV M,D",0x72},{"MOV M,E",0x73},{"MOV M,H",0x74},{"MOV M,L",0x75},
                                                             {"MOV M,A",0x77},{"MOV A,B",0x78},{"MOV A,C",0x79},{"MOV A,D",0x7a},{"MOV A,E",0x7b},{"MOV A,H",0x7c},{"MOV A,L",0x7d},{"MOV A,M",0x7e},
                                                             {"MOV A,A",0x7f}, {"RET",0xc9} };
    std::unordered_map<std::string, unsigned char> oneargs = { {"MVI A,", 0x3e} , {"MVI B,", 0x06},{"MVI D,",0x16},{"MVI H,",0x26},
                                                              {"MVI M,",0x36},{"MVI C,",0x0e},{"MVI E,",0x1e},{"MVI L,",0x2e},{"OUT ",0xd3},{"IN ",0xdb},{"ADI ",0xc6},{"SUI ",0xd6},{"ANI ",0xe6},{"ORI ",0xf6},
                                                              {"ACI ",0xce},{"SBI ",0xde},{"XRI ",0xee},{"CPI ",0xfe} };
    std::unordered_map<std::string, unsigned char> twoargs = { {"LXI B,",0x01},{"LXI D,",0x11},{"LXI H,",0x21},{"LXI SP,",0x31},{"SHLD ",0x22},{"STA ",0x32},
                                                              {"LHLD ",0x2a}, {"LDA ", 0x3a} };
    std::unordered_map<std::string, unsigned char> callsandjmps = { {"CNZ ",0xc4},{"CNC ",0xd4},
                                                                   {"CPO ",0xe4},{"CP ",0xf4},{"CZ ",0xcc},{"CC ",0xdc},{"CPE ",0xec},{"CM ",0xfc},{"CALL ",0xcd}, {"JNZ ",0xc2},{"JNC ",0xd2},{"JPO ",0xe2},{"JP ",0xf2},
                                                                   {"JMP ",0xc3},{"JZ ",0xca}, {"JC ",0xda},{"JPE ",0xea},{"JM ",0xfa}  };
};

#endif // ASSEMBLER_H
