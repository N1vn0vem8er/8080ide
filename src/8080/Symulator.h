#pragma once
class Symulator
{
private:
    unsigned char breg, creg, dreg, ereg, hreg, lreg, areg;
    unsigned short PC, memSize, SP;
	unsigned char* memory;
    bool CY, Z, AC, P, S, HLTType, hlt, startCalled;
    unsigned char flags, outBuffer, inBuffer;
    bool interruptsEnabled = false;
    unsigned char screenX, screenY, screenColor, screenAction;
    bool screenXRead, screenYRead, screenColorRead, screenActionRead;
	void executeInstruction(unsigned char inst);
	void halt();
    unsigned char mreg() const;
    unsigned short maddr() const;
	void doubleAdd(unsigned char reg1, unsigned char reg2);
	void jump();
	void call();
	void ret();
	void rst(unsigned char num);
	void sub(unsigned char reg);
	void add(unsigned char reg);
	void ana(unsigned char reg);
	void xra(unsigned char reg);
	void ora(unsigned char reg);
	void cmp(unsigned char reg);
	void dcr(unsigned char& reg);
	void inr(unsigned char& reg);
	void sbb(unsigned char reg);
	void adc(unsigned char reg);
	void daa();
	void nop();
	void push(unsigned char reg1, unsigned char reg2);
	void pop(unsigned char& reg1, unsigned char& reg2);
	void output(unsigned char deviceNumber);
	void input(unsigned char deviceNumber);
	void makeFlagsReg();
	void makeFlagsRegVar();
public:
	Symulator(unsigned short memorySize);
    ~Symulator();
    enum HltType{
        SetHTLFlag,
        WhileLoop
    };

	void load(unsigned char* instructions, int size);
	void start();
	void nextInst();
    void reset();
    unsigned char getBreg() const;
    unsigned char getCreg() const;
    unsigned char getDreg() const;
    unsigned char getEreg() const;
    unsigned char getHreg() const;
    unsigned char getLreg() const;
    unsigned char getAreg() const;
    unsigned short getPC() const;
    unsigned char getNextInst() const;
    bool getHLT() const;
    bool getCF() const;
    bool getP() const;
    bool getS() const;
    bool getAC() const;
    bool getZ() const;
    unsigned short getSP();
    unsigned char getMreg();
	unsigned char* getMemory();
    unsigned short getMemSize() const;
	void setBreg(unsigned char val);
	void setCreg(unsigned char val);
	void setDreg(unsigned char val);
	void setEreg(unsigned char val);
	void setHreg(unsigned char val);
	void setLreg(unsigned char val);
	void setAreg(unsigned char val);
	void setPC(unsigned short val);
	void setCF(bool val);
	void setP(bool val);
	void setAC(bool val);
	void setS(bool val);
	void setMemSize(unsigned short val);
	void setSP(unsigned short val);
    void setZ(bool val);
	unsigned char getOutBuffer();
	void setOutBuffer(unsigned char val);
    void setInBuffer(char val);
    char getInBuffer();
	void setHLTType(bool type);
	void setHLT(bool val);
    bool getInterruptsEnabled() const;
    void setInterruptsEnabled(bool newInterruptsEnabled);
    unsigned char getScreenX(bool read=false);
    void setScreenX(unsigned char newScreenX);
    unsigned char getScreenY(bool read=false);
    void setScreenY(unsigned char newScreenY);
    unsigned char getScreenColor(bool read=false);
    void setScreenColor(unsigned char newScreenColor);
    unsigned char getScreenAction(bool read=false);
    void setScreenAction(unsigned char newScreenAction);
};

