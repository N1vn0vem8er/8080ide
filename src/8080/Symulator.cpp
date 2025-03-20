#include "Symulator.h"
#include <iostream>

unsigned char Symulator::mreg()
{
    unsigned short memaddr = lreg;
    memaddr |= hreg << 8;
	return memory[memaddr];
}

unsigned short Symulator::maddr()
{
    unsigned short memaddr = lreg;
    memaddr |= hreg << 8;
	return memaddr;
}

void Symulator::doubleAdd(unsigned char reg1, unsigned char reg2)
{
	unsigned short tmp1 = reg1 << 8;
	tmp1 |= reg2;
	unsigned short tmp2 = hreg << 8;
	tmp2 |= lreg;
    if(tmp2 + tmp1 > 0xffff) CY = 1;
    else CY = 0;
	tmp2 += tmp1;
	hreg = tmp2 >> 8;
	lreg = tmp2;
}

void Symulator::jump()
{
	PC += 2;
	unsigned short temp = memory[PC] << 8;
	PC--;
	temp |= memory[PC];
	PC = temp - 1;
}

void Symulator::call()
{
    unsigned char haddr = (PC+2) >> 8, laddr = PC+2;
    push(haddr, laddr);
	this->jump();
}

void Symulator::ret()
{
    unsigned char haddr, laddr;
    pop(haddr, laddr);
    PC = haddr << 8;
    PC |= laddr;
}

void Symulator::rst(unsigned char num)
{
	switch (num)
	{
    case 0:
        push(PC >> 8, PC);
        PC = 0;
        break;
    case 1:
        push(PC >> 8, PC);
        PC = 0x08;
        break;
    case 2:
        push(PC >> 8, PC);
        PC = 0x10;
        break;
    case 3:
        push(PC >> 8, PC);
        PC = 0x18;
        break;
    case 4:
        push(PC >> 8, PC);
        PC = 0x20;
        break;
    case 5:
        push(PC >> 8, PC);
        PC = 0x28;
        break;
    case 6:
        push(PC >> 8, PC);
        PC = 0x30;
        break;
    case 7:
        push(PC >> 8, PC);
        PC = 0x38;
        break;
	default:
		break;
	}
}

void Symulator::sub(unsigned char reg)
{
	unsigned short a = areg, b = reg;
    if(a < b) CY = 1;
    else CY = 0;
    if(((unsigned char)((unsigned char)areg << 4) >> 4) < ((unsigned char)((unsigned char)reg << 4) >> 4)) AC=1;
    else AC=0;

	areg -= reg;
    if(areg == 0)Z=1;
    else Z=0;
    S = areg >> 7;
	if (areg % 2 == 0)P = 1;
	else P = 0;
}

void Symulator::add(unsigned char reg)
{
	unsigned short a = areg, b = reg;
    if(a + b > 0xff){
        CY = 1;}
    else{
        CY = 0;}

    if(((unsigned char)((unsigned char)areg << 4) >> 4) + ((unsigned char)((unsigned char)reg << 4) >> 4) > 0xf) AC=1;
    else AC=0;

	areg += reg;
    S = areg >> 7;
    if(areg == 0) Z = 1;
    else Z=0;
	if (areg % 2 == 0)P = 1;
	else P = 0;
}

void Symulator::ana(unsigned char reg)
{
	CY = 0;
	areg &= reg;
    S = areg >> 7;
    if(areg == 0)Z=1;
    else Z=0;
	if (areg % 2 == 0)P = 1;
	else P = 0;
}
void Symulator::xra(unsigned char reg)
{
	CY = 0;
	areg ^= reg;
    S = areg >> 7;
    if(areg == 0)Z=1;
    else Z=0;
	if (areg % 2 == 0)P = 1;
	else P = 0;
}
void Symulator::ora(unsigned char reg)
{
	CY = 0;
	areg |= reg;
    if(areg == 0)Z=1;
    else Z=0;
    S = areg >> 7;
	if (areg % 2 == 0)P = 1;
	else P = 0;
}
void Symulator::cmp(unsigned char reg)
{
    AC = (((unsigned char)((unsigned char)areg << 4) >> 4) + ((unsigned char)((unsigned char)-reg << 4) >> 4)) >> 4;
    if(areg == reg)Z=1;
    else Z=0;
    if(reg > areg)CY=1;
    else CY=0;
    if((areg + -reg) % 2 == 0) P=1;
    else P=0;
    S = (areg + -reg) >> 7;
}

void Symulator::dcr(unsigned char& reg)
{
    AC=(((unsigned char)((unsigned char)reg << 4) >> 4) - 1) >> 4;
    S = reg-- >> 7;
    if(reg % 2 == 0)P=1;
    else P=0;
	if (reg == 0)Z = 1;
	else Z = 0;
}

void Symulator::inr(unsigned char& reg)
{
    AC=(((unsigned char)((unsigned char)reg << 4) >> 4) + 1) >> 4;
    S = reg++ >> 7;
    if(reg % 2 == 0)P=1;
    else P=0;
	if (reg == 0)Z = 1;
	else Z = 0;
}

void Symulator::sbb(unsigned char reg)
{
	unsigned short tmp = areg;
    AC=(((unsigned char)((unsigned char)areg << 4) >> 4) - (((unsigned char)((unsigned char)reg << 4) >> 4) +CY )) >> 4;
    tmp -= reg + CY;
    CY = (tmp >> 8);
	areg = tmp;
    S = areg >> 7;
	if (areg == 0)Z = 1;
	else Z = 0;
	if (areg % 2 == 0)P = 1;
	else P = 0;
}

void Symulator::adc(unsigned char reg)
{
	unsigned short tmp = areg;
    AC=(((unsigned char)((unsigned char)areg << 4) >> 4) + (((unsigned char)((unsigned char)reg << 4) >> 4) +CY )) >> 4;
	tmp += reg + CY;
    CY = (tmp >> 8);
	areg = tmp;
    S = areg >> 7;
	if (areg == 0)Z = 1;
	else Z = 0;
	if (areg % 2 == 0)P = 1;
	else P = 0;
}

void Symulator::daa()
{
    unsigned short tmp = areg;
    if(((unsigned char)((unsigned char)areg << 4) >> 4) > 9)
    {
        areg += 6;
        tmp += 6;
        AC = 1;
        CY = (tmp >> 8);
    }
    if (((unsigned char)areg >> 4) > 9 || CY == 1)
    {
        areg += 0x60;
        tmp += 0x60;
        CY = (tmp >> 8);
    }
    if(areg == 0) Z=1;
    else Z=0;
    if(areg%2 == 0)P=1;
    else P=0;
    S = areg >> 7;
}

void Symulator::push(unsigned char reg1, unsigned char reg2)
{
    SP--;
    memory[SP] = reg1;
    SP--;
    memory[SP] = reg2;
}

void Symulator::pop(unsigned char& reg1, unsigned char& reg2)
{
	reg2 = memory[SP];
    SP++;
	reg1 = memory[SP];
    SP++;
}

void Symulator::nop()
{
	return;
}

void Symulator::makeFlagsReg()
{
	flags = (unsigned char)S << 7 | (unsigned char)Z << 6 | (unsigned char)AC << 4 | (unsigned char)P << 2 | (unsigned char)1 << 1 | (unsigned char)CY;
}

void Symulator::makeFlagsRegVar()
{
	S = flags >> 7;
	Z = flags >> 6;
	AC = flags >> 4;
	P = flags >> 2;
	CY = flags;
}

void Symulator::output(unsigned char deviceNumber)
{
	switch (deviceNumber)
    {
    case 0x0:
        inBuffer = areg;
        break;
	case 0x1:
		if (startCalled)
		{
			std::cout << areg;
		}
		else
		{
			outBuffer = areg;
		}
		break;
	default:
		break;
	}
}

void Symulator::input(unsigned char deviceNumber)
{
	switch (deviceNumber)
	{
    case 0x0:
        areg = inBuffer;
        break;
    case 0x1:
        areg = outBuffer;
        break;
	default:
		break;
	}
}

void Symulator::halt()
{
	if (HLTType)
		while (true);
	else
		hlt = true;
}

bool Symulator::getInterruptsEnabled() const
{
    return interruptsEnabled;
}

void Symulator::setInterruptsEnabled(bool newInterruptsEnabled)
{
    interruptsEnabled = newInterruptsEnabled;
}

void Symulator::executeInstruction(unsigned char inst)
{
	unsigned short memaddr;
	unsigned short temp;
	switch (inst)
	{
	case 0x0:
		this->nop();
		break;
	case 0x1:
		PC++;
        creg = memory[PC];
		PC++;
        breg = memory[PC];
		break;
	case 0x2:
		memaddr = breg << 8;
		memaddr |= creg;
		memory[memaddr] = areg;
		break;
	case 0x3:
		temp = breg << 8;
		temp |= creg;
		temp++;
		creg = temp;
		breg = temp >> 8;
		break;
	case 0x4:
		this->inr(breg);
		break;
	case 0x5:
		this->dcr(breg);
		break;
	case 0x6:
		PC++;
		breg = memory[PC];
		break;
	case 0x7:
		if (areg >= 128) CY = 1;
        else CY = 0;
        areg = areg << 1;
        areg+=CY;
		break;
	case 0x8:
		this->nop();
		break;
	case 0x9:
		doubleAdd(breg, creg);
		break;
	case 0xa:
		memaddr = breg << 8;
		memaddr |= creg;
		areg = memory[memaddr];
		break;
	case 0xb:
		temp = breg << 8;
		temp |= creg;
		temp--;
		if (temp == 0)Z = 1;
		creg = temp;
		breg = temp >> 8;
		break;
	case 0xc:
		this->inr(creg);
		break;
	case 0xd:
		this->dcr(creg);
		break;
	case 0xe:
		PC++;
		creg = memory[PC];
		break;
	case 0xf:
        CY = areg & 1;
        areg = areg >> 1;
        areg += CY << 7;
		break;
	case 0x10:
		this->nop();
		break;
	case 0x11:
		PC++;
        ereg = memory[PC];
		PC++;
        dreg = memory[PC];
		break;
	case 0x12:
		memaddr = dreg << 8;
		memaddr |= ereg;
		memory[memaddr] = areg;
		break;
	case 0x13:
		temp = dreg << 8;
		temp |= ereg;
		temp++;
		ereg = temp;
		dreg = temp >> 8;
		break;
	case 0x14:
		this->inr(dreg);
		break;
	case 0x15:
		this->dcr(dreg);
		break;
	case 0x16:
		PC++;
		dreg = memory[PC];
		break;
	case 0x17:
        temp = areg;
        areg = areg << 1;
        areg += CY;
        if (temp >= 128)CY = 1;
        else CY = 0;
		break;
	case 0x18:
		this->nop();
		break;
	case 0x19:
		doubleAdd(dreg, ereg);
		break;
	case 0x1a:
		memaddr = dreg << 8;
		memaddr |= ereg;
		areg = memory[memaddr];
		break;
	case 0x1b:
		temp = dreg << 8;
		temp |= ereg;
		temp--;
		if (temp == 0)Z = 1;
		ereg = temp;
		dreg = temp >> 8;
		break;
	case 0x1c:
		this->inr(ereg);
		break;
	case 0x1d:
		this->dcr(ereg);
		break;
	case 0x1e:
		PC++;
		ereg = memory[PC];
		break;
	case 0x1f:
        temp = CY << 7;
        CY = areg & 1;
        areg = areg >> 1;
        areg+= temp;
		break;
	case 0x20:
		this->nop();
		break;
	case 0x21:
		PC++;
        lreg = memory[PC];
		PC++;
        hreg = memory[PC];
		break;
	case 0x22:
		PC++;
        temp = memory[PC];
        PC++;
        temp |= memory[PC] << 8;
        memory[temp] = lreg;
        memory[temp + 1] = hreg;
		break;
	case 0x23:
		temp = hreg << 8;
		temp |= lreg;
		temp++;
		lreg = temp;
		hreg = temp >> 8;
		break;
	case 0x24:
		this->inr(hreg);
		break;
	case 0x25:
		this->dcr(hreg);
		break;
	case 0x26:
		PC++;
		hreg = memory[PC];
		break;
	case 0x27:
		this->daa();
		break;
	case 0x28:
		this->nop();
		break;
	case 0x29:
		doubleAdd(hreg, lreg);
		break;
	case 0x2a:
        PC++;
        temp = memory[PC];
        PC++;
        temp |= memory[PC] << 8;
        lreg = memory[temp];
        hreg = memory[temp + 1];
		break;
	case 0x2b:
		temp = hreg << 8;
		temp |= lreg;
		temp--;
		if (temp == 0)Z = 1;
		lreg = temp;
		hreg = temp >> 8;
		break;
	case 0x2c:
		this->inr(lreg);
		break;
	case 0x2d:
		this->dcr(lreg);
		break;
	case 0x2e:
		PC++;
		lreg = memory[PC];
		break;
	case 0x2f:
        areg = ~areg;
		break;
	case 0x30:
		this->nop();
		break;
	case 0x31:
		PC++;
        SP = memory[PC];
		PC++;
        SP |= memory[PC] << 8;
		break;
	case 0x32:
		PC++;
        temp = memory[PC];
		PC++;
        temp |= memory[PC] << 8;
		memory[temp] = areg;
		break;
	case 0x33:
        SP++;
		break;
	case 0x34:
		this->inr(memory[maddr()]);
		break;
	case 0x35:
        this->dcr(memory[maddr()]);
		break;
	case 0x36:
		PC++;
		memory[maddr()] = memory[PC];
		break;
	case 0x37:
		CY = 1;
		break;
	case 0x38:
		this->nop();
		break;
	case 0x39:
		doubleAdd(SP << 8, SP);
		break;
	case 0x3a:
		PC++;
        temp = memory[PC];
		PC++;
        temp |= memory[PC] << 8;
		areg = memory[temp];
		break;
	case 0x3b:
        SP--;
		break;
	case 0x3c:
		this->inr(areg);
		break;
	case 0x3d:
		this->dcr(areg);
		if (areg == 0)Z = 1;
		break;
	case 0x3e:
		PC++;
		areg = memory[PC];
		break;
	case 0x3f:
        CY = !CY;
		break;
	case 0x40:
		breg = breg;
		break;
	case 0x41:
        breg = creg;
		break;
	case 0x42:
        breg = dreg;
		break;
	case 0x43:
        breg = ereg;
		break;
	case 0x44:
        breg = hreg;
		break;
	case 0x45:
        breg = lreg;
		break;
	case 0x46:
        breg = memory[this->maddr()];
		break;
	case 0x47:
        breg = areg;
		break;
	case 0x48:
        creg = breg;
		break;
	case 0x49:
		creg = creg;
		break;
	case 0x4a:
        creg = dreg;
		break;
	case 0x4b:
        creg = ereg;
		break;
	case 0x4c:
        creg = hreg;
		break;
	case 0x4d:
        creg = lreg;
		break;
	case 0x4e:
        creg = memory[this->maddr()];
		break;
	case 0x4f:
        creg = areg;
		break;
	case 0x50:
        dreg = breg;
		break;
	case 0x51:
        dreg = creg;
		break;
	case 0x52:
		dreg = dreg;
		break;
	case 0x53:
        dreg = ereg;
		break;
	case 0x54:
        dreg = hreg;
		break;
	case 0x55:
        dreg = lreg;
		break;
	case 0x56:
        dreg = memory[this->maddr()];
		break;
	case 0x57:
        dreg = areg;
		break;
	case 0x58:
        ereg = breg;
		break;
	case 0x59:
        ereg = creg;
		break;
	case 0x5a:
        ereg = dreg;
		break;
	case 0x5b:
		ereg = ereg;
		break;
	case 0x5c:
        ereg = hreg;
		break;
	case 0x5d:
        ereg = lreg;
		break;
	case 0x5e:
        ereg = memory[this->maddr()];
		break;
	case 0x5f:
        ereg = areg;
		break;
	case 0x60:
        hreg = breg;
		break;
	case 0x61:
        hreg = creg;
		break;
	case 0x62:
        hreg = dreg;
		break;
	case 0x63:
        hreg = ereg;
		break;
	case 0x64:
		hreg = hreg;
		break;
	case 0x65:
        hreg = lreg;
		break;
	case 0x66:
        hreg = memory[this->maddr()] ;
		break;
	case 0x67:
        hreg = areg;
		break;
	case 0x68:
        lreg = breg;
		break;
	case 0x69:
        lreg = creg;
		break;
	case 0x6a:
        lreg = dreg;
		break;
	case 0x6b:
        lreg = ereg;
		break;
	case 0x6c:
        lreg = hreg;
		break;
	case 0x6d:
		lreg = lreg;
		break;
	case 0x6e:
        lreg = memory[this->maddr()];
		break;
	case 0x6f:
        lreg = areg;
		break;
	case 0x70:
        memory[this->maddr()] = breg;
		break;
	case 0x71:
        memory[this->maddr()] = creg;
		break;
	case 0x72:
        memory[this->maddr()] = dreg;
		break;
	case 0x73:
        memory[this->maddr()] = ereg;
		break;
	case 0x74:
        memory[this->maddr()] = hreg;
		break;
	case 0x75:
        memory[this->maddr()] = lreg;
		break;
	case 0x76:
		halt();
		break;
	case 0x77:
        memory[this->maddr()] = areg;
		break;
	case 0x78:
        areg = breg;
		break;
	case 0x79:
        areg = creg;
		break;
	case 0x7a:
        areg = dreg;
		break;
	case 0x7b:
        areg = ereg;
		break;
	case 0x7c:
        areg = hreg;
		break;
	case 0x7d:
        areg = lreg;
		break;
	case 0x7e:
        areg = memory[this->maddr()];
		break;
	case 0x7f:
		areg = areg;
		break;
	case 0x80:
		this->add(breg);
		break;
	case 0x81:
		this->add(creg);
		break;
	case 0x82:
		this->add(dreg);
		break;
	case 0x83:
		this->add(ereg);
		break;
	case 0x84:
		this->add(hreg);
		break;
	case 0x85:
		this->add(lreg);
		break;
	case 0x86:
		this->add(mreg());
		break;
	case 0x87:
		this->add(areg);
		break;
	case 0x88:
		this->adc(breg);
		break;
	case 0x89:
		this->adc(creg);
		break;
	case 0x8a:
		this->adc(dreg);
		break;
	case 0x8b:
		this->adc(ereg);
		break;
	case 0x8c:
		this->adc(hreg);
		break;
	case 0x8d:
		this->adc(lreg);
		break;
	case 0x8e:
		this->adc(mreg());
		break;
	case 0x8f:
		this->adc(areg);
		break;
	case 0x90:
		this->sub(breg);
		break;
	case 0x91:
		this->sub(creg);
		break;
	case 0x92:
		this->sub(dreg);
		break;
	case 0x93:
		this->sub(ereg);
		break;
	case 0x94:
		this->sub(hreg);
		break;
	case 0x95:
		this->sub(lreg);
		break;
	case 0x96:
		this->sub(mreg());
		break;
	case 0x97:
		this->sub(areg);
		break;
	case 0x98:
		this->sbb(breg);
		break;
	case 0x99:
		this->sbb(creg);
		break;
	case 0x9a:
		this->sbb(dreg);
		break;
	case 0x9b:
		this->sbb(ereg);
		break;
	case 0x9c:
		this->sbb(hreg);
		break;
	case 0x9d:
		this->sbb(lreg);
		break;
	case 0x9e:
		this->sbb(mreg());
		break;
	case 0x9f:
		this->sbb(areg);
		break;
	case 0xa0:
		this->ana(breg);
		break;
	case 0xa1:
		this->ana(creg);
		break;
	case 0xa2:
		this->ana(dreg);
		break;
	case 0xa3:
		this->ana(ereg);
		break;
	case 0xa4:
		this->ana(hreg);
		break;
	case 0xa5:
		this->ana(lreg);
		break;
	case 0xa6:
		this->ana(mreg());
		break;
	case 0xa7:
		this->ana(areg);
		break;
	case 0xa8:
		this->xra(breg);
		break;
	case 0xa9:
		this->xra(creg);
		break;
	case 0xaa:
		this->xra(dreg);
		break;
	case 0xab:
		this->xra(ereg);
		break;
	case 0xac:
		this->xra(hreg);
		break;
	case 0xad:
		this->xra(lreg);
		break;
	case 0xae:
		this->xra(mreg());
		break;
	case 0xaf:
		this->xra(areg);
		break;
	case 0xb0:
		this->ora(breg);
		break;
	case 0xb1:
		this->ora(creg);
		break;
	case 0xb2:
		this->ora(dreg);
		break;
	case 0xb3:
		this->ora(ereg);
		break;
	case 0xb4:
		this->ora(hreg);
		break;
	case 0xb5:
		this->ora(lreg);
		break;
	case 0xb6:
		this->ora(mreg());
		break;
	case 0xb7:
		this->ora(areg);
		break;
	case 0xb8:
		this->cmp(breg);
		break;
	case 0xb9:
		this->cmp(creg);
		break;
	case 0xba:
		this->cmp(dreg);
		break;
	case 0xbb:
		this->cmp(ereg);
		break;
	case 0xbc:
		this->cmp(hreg);
		break;
	case 0xbd:
		this->cmp(lreg);
		break;
	case 0xbe:
		this->cmp(mreg());
		break;
	case 0xbf:
		this->cmp(areg);
		break;
	case 0xc0:
		if (Z == 0) this->ret();
		break;
	case 0xc1:
		this->pop(breg, creg);
		break;
	case 0xc2:
		if (Z == 0) jump();
		else PC += 2;
		break;
	case 0xc3:
		jump();
		break;
	case 0xc4:
		if (Z == 0) call();
		else PC += 2;
		break;
	case 0xc5:
		this->push(breg, creg);
		break;
	case 0xc6:
		PC++;
		this->add(memory[PC]);
		break;
	case 0xc7:
		this->rst(0);
		break;
	case 0xc8:
		if (Z == 1) this->ret();
		break;
	case 0xc9:
		this->ret();
		break;
	case 0xca:
		if (Z == 1) jump();
		else PC += 2;
		break;
	case 0xcb:
		PC++;
		this->input(memory[PC]);
		break;
	case 0xcc:
		if (Z == 1) call();
		else PC += 2;
		break;
	case 0xcd:
		this->call();
		break;
	case 0xce:
		PC++;
        this->adc(memory[PC]);
		break;
	case 0xcf:
		this->rst(1);
		break;
	case 0xd0:
		if (CY != 1) this->ret();
		break;
	case 0xd1:
		this->pop(dreg, ereg);
		break;
	case 0xd2:
		if (CY != 1) jump();
		else PC += 2;
		break;
	case 0xd3:
		PC++;
		this->output(memory[PC]);
		break;
	case 0xd4:
		if (CY != 1) call();
		else PC += 2;
		break;
	case 0xd5:
		this->push(dreg, ereg);
		break;
	case 0xd6:
		PC++;
        this->sub(memory[PC]);
		break;
	case 0xd7:
		this->rst(2);
		break;
	case 0xd8:
		if (CY == 1) this->ret();
		break;
	case 0xd9:
		break;
	case 0xda:
		if (CY == 1) jump();
		else PC += 2;
		break;
	case 0xdb:
        PC++;
        input(memory[PC]);
		break;
	case 0xdc:
		if (CY == 1) call();
		else PC += 2;
		break;
	case 0xdd:
		this->call();
		break;
	case 0xde:
		PC++;
        this->sbb(memory[PC]);
		break;
	case 0xdf:
		this->rst(3);
		break;
	case 0xe0:
		if (P == 0) this->ret();
		break;
	case 0xe1:
		this->pop(hreg, lreg);
		break;
	case 0xe2:
		if (P == 0) jump();
		else PC += 2;
		break;
	case 0xe3:
		temp = hreg << 8;
		temp |= lreg;
		this->pop(hreg, lreg);
        this->push((unsigned char)(temp >> 8), (unsigned char)temp);
		break;
	case 0xe4:
		if (P == 0) call();
		else PC += 2;
		break;
	case 0xe5:
		this->push(hreg, lreg);
		break;
	case 0xe6:
		PC++;
		this->ana(memory[PC]);
		break;
	case 0xe7:
		this->rst(4);
		break;
	case 0xe8:
		if (P == 1) this->ret();
		break;
	case 0xe9:
		PC = hreg << 8;
		PC |= lreg;
		break;
	case 0xea:
		if (P == 1) jump();
		else PC += 2;
		break;
	case 0xeb:
		temp = hreg << 8;
		temp |= lreg;
		hreg = dreg;
		lreg = ereg;
		dreg = temp >> 8;
		ereg = temp;
		break;
	case 0xec:
		if (P == 1) call();
		else PC += 2;
		break;
	case 0xed:
		this->call();
		break;
	case 0xee:
		PC++;
		this->xra(memory[PC]);
		break;
	case 0xef:
		this->rst(5);
		break;
	case 0xf0:
		if (S == 0) this->ret();
		break;
	case 0xf1:
        makeFlagsReg();
		this->pop(areg, flags);
        makeFlagsRegVar();
		break;
	case 0xf2:
		if (S == 0) jump();
		else PC += 2;
		break;
	case 0xf3:
        interruptsEnabled = false;
		break;
	case 0xf4:
		if (S == 0) call();
		else PC += 2;
		break;
	case 0xf5:
		makeFlagsReg();
		this->push(areg, flags);
		break;
	case 0xf6:
		PC++;
		this->ora(memory[PC]);
		break;
	case 0xf7:
		this->rst(6);
		break;
	case 0xf8:
		if (S == 1) this->ret();
		break;
	case 0xf9:
		SP = hreg << 8;
		SP |= lreg;
		break;
	case 0xfa:
		if (S == 1) jump();
		else PC += 2;
		break;
	case 0xfb:
        interruptsEnabled = true;
		break;
	case 0xfc:
		if (S == 1) call();
		else PC += 2;
		break;
	case 0xfd:
		this->call();
		break;
	case 0xfe:
		PC++;
		this->cmp(memory[PC]);
		break;
	case 0xff:
		this->rst(7);
		break;
	default:
		break;
	}
}

Symulator::Symulator(unsigned short memorySize)
{
	this->HLTType = 1;
	this->hlt = false;
	this->breg = 0;
	this->creg = 0;
	this->dreg = 0;
	this->ereg = 0;
	this->hreg = 0;
	this->lreg = 0;
	this->PC = 0;
	this->areg = 0;
    this->CY = 0;
    this->SP = 32;
	this->startCalled = false;
	this->outBuffer = '\0';
	this->AC = 0;
	this->P = 0;
	this->S = 0;
	this->Z = 0;
	this->flags = 0;
	this->memSize = memorySize;
    this->inBuffer = 0x0;
	memory = new unsigned char[memSize];
	for (int i = 0; i < memSize; i++)
	{
		this->memory[i] = 0;
	}
}

Symulator::~Symulator()
{
    delete[] memory;
}

void Symulator::load(unsigned char* instructions, int size)
{
	for (int i = 0; i < size; i++)
	{
		memory[i] = instructions[i];
	}
}

void Symulator::start()
{
	this->startCalled = true;
	try {
		for (PC = 0; PC < memSize; PC++)
		{
			this->executeInstruction(memory[PC]);
		}
	}
	catch (...) {
		std::cout << PC << std::endl;
	}
}

void Symulator::nextInst()
{
    if(PC>memSize) return;
	this->executeInstruction(memory[PC]);
	PC++;
}

void Symulator::reset()
{
    PC = 0;
    SP = 0;
    CY = 0;
    P = 0;
    S = 0;
    AC = 0;
    Z = 0;
    areg = 0;
    breg = 0;
    creg = 0;
    dreg = 0;
    ereg = 0;
    hreg = 0;
    lreg = 0;
    SP = 32;
    outBuffer = '\0';
    inBuffer = '\0';
}

unsigned char Symulator::getBreg() const
{
	return breg;
}

unsigned char Symulator::getCreg() const
{
	return creg;
}

unsigned char Symulator::getDreg() const
{
	return dreg;
}

unsigned char Symulator::getEreg() const
{
	return ereg;
}

unsigned char Symulator::getHreg() const
{
	return hreg;
}

unsigned char Symulator::getLreg() const
{
	return lreg;
}

unsigned char Symulator::getAreg() const
{
	return areg;
}

unsigned short Symulator::getPC() const
{
	return PC;
}

unsigned char Symulator::getNextInst() const
{
	return memory[PC];
}

bool Symulator::getHLT() const
{
	return hlt;
}

bool Symulator::getCF() const
{
	return CY;
}

bool Symulator::getP() const
{
	return P;
}

bool Symulator::getS() const
{
	return S;
}

bool Symulator::getAC() const
{
	return AC;
}

bool Symulator::getZ() const
{
    return Z;
}

unsigned short Symulator::getSP()
{
	return SP;
}

unsigned char Symulator::getMreg()
{
    return mreg();
}

unsigned char* Symulator::getMemory()
{
	return memory;
}

unsigned short Symulator::getMemSize() const
{
	return memSize;
}

void Symulator::setBreg(unsigned char val)
{
	breg = val;
}

void Symulator::setCreg(unsigned char val)
{
	creg = val;
}

void Symulator::setDreg(unsigned char val)
{
	dreg = val;
}

void Symulator::setEreg(unsigned char val)
{
	ereg = val;
}

void Symulator::setHreg(unsigned char val)
{
	hreg = val;
}

void Symulator::setLreg(unsigned char val)
{
	lreg = val;
}

void Symulator::setAreg(unsigned char val)
{
	areg = val;
}

void Symulator::setPC(unsigned short val)
{
	PC = val;
}

void Symulator::setCF(bool val)
{
	CY = val;
}

void Symulator::setP(bool val)
{
	this->P = val;
}

void Symulator::setAC(bool val)
{
	this->AC = val;
}

void Symulator::setS(bool val)
{
	this->S = val;
}

void Symulator::setMemSize(unsigned short val)
{
	this->memSize = val;
}

void Symulator::setSP(unsigned short val)
{
	this->SP = val;
}

void Symulator::setZ(bool val)
{
    Z = val;
}

unsigned char Symulator::getOutBuffer()
{
	return outBuffer;
}

void Symulator::setOutBuffer(unsigned char val)
{
    outBuffer = val;
}

void Symulator::setInBuffer(char val)
{
    inBuffer = val;
}

char Symulator::getInBuffer()
{
    return inBuffer;
}

void Symulator::setHLTType(bool type)
{
	HLTType = type;
}

void Symulator::setHLT(bool val)
{
	hlt = val;
}
