#include <QtTest>
#include "../../8080/Symulator.h"

// add necessary includes here

class SymulatorTest : public QObject
{
    Q_OBJECT

public:
    SymulatorTest();
    ~SymulatorTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void testsymulatorCreaded();
    void testMemorySize();
    void testMemoryLoad();
    void testInstructionNOP();
    void testInstructionLXIB();
    void testInstructionLXID();
    void testInstructionLXIH();
    void testInstructionLXISP();
    void testInstructionSTAXB();
    void testInstructionSTAXD();
    void testInstructionSHLD();
    void testInstructionSTA();
    void testInstructionINXB();
    void testInstructionINXD();
    void testInstructionINXH();
    void testInstructionINXSP();
    void testInstructionINRB();
    void testInstructionINRD();
    void testInstructionINRH();
    void testInstructionINRM();
    void testInstructionDCRB();
    void testInstructionDCRD();
    void testInstructionDCRH();
    void testInstructionDCRM();
    void testInstructionMVIB();
    void testInstructionMVID();
    void testInstructionMVIH();
    void testInstructionMVIM();
    void testInstructionRLC();
    void testInstructionRAL();
    void testInstructionDAA();
    void testInstructionSTC();
    void testInstructionDADB();
    void testInstructionDADD();
    void testInstructionDADH();
    void testInstructionDADSP();
    void testInstructionLDAXB();
    void testInstructionLDAXD();
    void testInstructionLHLD();
    void testInstructionLDA();
    void testInstructionDCXB();
    void testInstructionDCXD();
    void testInstructionDCXH();
    void testInstructionDCXSP();
    void testInstructionINRC();
    void testInstructionINRE();
    void testInstructionINRL();
    void testInstructionINRA();
    void testInstructionDCRC();
    void testInstructionDCRE();
    void testInstructionDCRL();
    void testInstructionDCRA();
    void testInstructionMVIC();
    void testInstructionMVIE();
    void testInstructionMVIL();
    void testInstructionMVIA();
    void testInstructionRRC();
    void testInstructionRAR();
    void testInstructionCMA();
    void testInstructionCMC();
    void testInstructionMOVBB();
    void testInstructionMOVBC();
    void testInstructionMOVBD();
    void testInstructionMOVBE();
    void testInstructionMOVBH();
    void testInstructionMOVBL();
    void testInstructionMOVBM();
    void testInstructionMOVBA();
    void testInstructionMOVCB();
    void testInstructionMOVCC();
    void testInstructionMOVCD();
    void testInstructionMOVCE();
    void testInstructionMOVCH();
    void testInstructionMOVCL();
    void testInstructionMOVCM();
    void testInstructionMOVCA();
    void testInstructionMOVDB();
    void testInstructionMOVDC();
    void testInstructionMOVDD();
    void testInstructionMOVDE();
    void testInstructionMOVDH();
    void testInstructionMOVDL();
    void testInstructionMOVDM();
    void testInstructionMOVDA();
    void testInstructionMOVEB();
    void testInstructionMOVEC();
    void testInstructionMOVED();
    void testInstructionMOVEE();
    void testInstructionMOVEH();
    void testInstructionMOVEL();
    void testInstructionMOVEM();
    void testInstructionMOVEA();
    void testInstructionMOVHB();
    void testInstructionMOVHC();
    void testInstructionMOVHD();
    void testInstructionMOVHE();
    void testInstructionMOVHH();
    void testInstructionMOVHL();
    void testInstructionMOVHM();
    void testInstructionMOVHA();
    void testInstructionMOVLB();
    void testInstructionMOVLC();
    void testInstructionMOVLD();
    void testInstructionMOVLE();
    void testInstructionMOVLH();
    void testInstructionMOVLL();
    void testInstructionMOVLM();
    void testInstructionMOVLA();
    void testInstructionMOVMB();
    void testInstructionMOVMC();
    void testInstructionMOVMD();
    void testInstructionMOVME();
    void testInstructionMOVMH();
    void testInstructionMOVML();
    void testInstructionMOVMA();
    void testInstructionMOVAB();
    void testInstructionMOVAC();
    void testInstructionMOVAD();
    void testInstructionMOVAE();
    void testInstructionMOVAH();
    void testInstructionMOVAL();
    void testInstructionMOVAM();
    void testInstructionMOVAA();
    void testInstructionHLT();
    void testInstructionADDB();
    void testInstructionADDC();
    void testInstructionADDD();
    void testInstructionADDE();
    void testInstructionADDH();
    void testInstructionADDL();
    void testInstructionADDM();
    void testInstructionADDA();
    void testInstructionADCB();
    void testInstructionADCC();
    void testInstructionADCD();
    void testInstructionADCE();
    void testInstructionADCH();
    void testInstructionADCL();
    void testInstructionADCM();
    void testInstructionADCA();
    void testInstructionSUBB();
    void testInstructionSUBC();
    void testInstructionSUBD();
    void testInstructionSUBE();
    void testInstructionSUBH();
    void testInstructionSUBL();
    void testInstructionSUBM();
    void testInstructionSUBA();
    void testInstructionSBBB();
    void testInstructionSBBC();
    void testInstructionSBBD();
    void testInstructionSBBE();
    void testInstructionSBBH();
    void testInstructionSBBL();
    void testInstructionSBBM();
    void testInstructionSBBA();
    void testInstructionANAB();
    void testInstructionANAC();
    void testInstructionANAD();
    void testInstructionANAE();
    void testInstructionANAH();
    void testInstructionANAL();
    void testInstructionANAM();
    void testInstructionANAA();
    void testInstructionXRAB();
    void testInstructionXRAC();
    void testInstructionXRAD();
    void testInstructionXRAE();
    void testInstructionXRAH();
    void testInstructionXRAL();
    void testInstructionXRAM();
    void testInstructionXRAA();
    void testInstructionORAB();
    void testInstructionORAC();
    void testInstructionORAD();
    void testInstructionORAE();
    void testInstructionORAH();
    void testInstructionORAL();
    void testInstructionORAM();
    void testInstructionORAA();
    void testInstructionCMPB();
    void testInstructionCMPC();
    void testInstructionCMPD();
    void testInstructionCMPE();
    void testInstructionCMPH();
    void testInstructionCMPL();
    void testInstructionCMPM();
    void testInstructionCMPA();
    void testInstructionRNZ();
    void testInstructionRNC();
    void testInstructionRPO();
    void testInstructionRP();
    void testInstructionPOPB();
    void testInstructionPOPD();
    void testInstructionPOPH();
    void testInstructionPOPPSW();
    void testInstructionJNZ();
    void testInstructionJNC();
    void testInstructionJPO();
    void testInstructionJP();
    void testInstructionJMP();
    void testInstructionOUT();
    void testInstructionXTHL();
    void testInstructionDI();
    void testInstructionCNZ();
    void testInstructionCNC();
    void testInstructionCPO();
    void testInstructionCP();
    void testInstructionPUSHB();
    void testInstructionPUSHD();
    void testInstructionPUSHH();
    void testInstructionPUSHPSW();
    void testInstructionADI();
    void testInstructionSUI();
    void testInstructionANI();
    void testInstructionORI();
    void testInstructionRST0();
    void testInstructionRST2();
    void testInstructionRST4();
    void testInstructionRST6();
    void testInstructionRZ();
    void testInstructionRC();
    void testInstructionRPE();
    void testInstructionRM();
    void testInstructionRET();
    void testInstructionPCHL();
    void testInstructionSPHL();
    void testInstructionJZ();
    void testInstructionJC();
    void testInstructionJPE();
    void testInstructionJM();
    void testInstructionIN();
    void testInstructionXCHG();
    void testInstructionEI();
    void testInstructionCZ();
    void testInstructionCC();
    void testInstructionCPE();
    void testInstructionCM();
    void testInstructionCALL();
    void testInstructionACI();
    void testInstructionSBI();
    void testInstructionXRI();
    void testInstructionCPI();
    void testInstructionRST1();
    void testInstructionRST3();
    void testInstructionRST5();
    void testInstructionRST7();
private:
    Symulator* symulator = nullptr;
    const int memorySize = 100;
};

SymulatorTest::SymulatorTest() {}

SymulatorTest::~SymulatorTest() {}

void SymulatorTest::initTestCase()
{
    symulator = new Symulator(memorySize);
}

void SymulatorTest::cleanupTestCase()
{
    delete symulator;
}

void SymulatorTest::test_case1()
{

}

void SymulatorTest::testsymulatorCreaded()
{
    QVERIFY(symulator != nullptr);
}

void SymulatorTest::testMemorySize()
{
    QVERIFY(symulator->getMemSize() == memorySize);
}

void SymulatorTest::testMemoryLoad()
{
    unsigned char memory[] = {0x32, 0x12, 0x12, 0x54};
    const int size = 4;
    symulator->load(memory, size);
    QVERIFY(symulator->getMemory()[0] == memory[0]);
    QVERIFY(symulator->getMemory()[1] == memory[1]);
    QVERIFY(symulator->getMemory()[2] == memory[2]);
    QVERIFY(symulator->getMemory()[3] == memory[3]);
}

void SymulatorTest::testInstructionNOP()
{
    symulator->reset();
    unsigned char memory[] = {0x0};
    symulator->load(memory, 1);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionLXIB()
{
    symulator->reset();
    unsigned char memory[] = {0x01, 0x11, 0x21};
    symulator->load(memory, 3);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 3);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0x21);
    QVERIFY(symulator->getCreg() == 0x11);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionLXID()
{
    symulator->reset();
    unsigned char memory[] = {0x11, 0x11, 0x21};
    symulator->load(memory, 3);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 3);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0x21);
    QVERIFY(symulator->getEreg() == 0x11);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionLXIH()
{
    symulator->reset();
    unsigned char memory[] = {0x21, 0x11, 0x21};
    symulator->load(memory, 3);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 3);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0x21);
    QVERIFY(symulator->getLreg() == 0x11);
}

void SymulatorTest::testInstructionLXISP()
{
    symulator->reset();
    unsigned char memory[] = {0x31, 0x11, 0x21};
    symulator->load(memory, 3);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 3);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 0x2111);
}

void SymulatorTest::testInstructionSTAXB()
{
    symulator->reset();
    symulator->setBreg(0);
    symulator->setCreg(3);
    symulator->setAreg(15);
    unsigned char memory[] = {0x02, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 15);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 3);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getMemory()[3] == 15);
}

void SymulatorTest::testInstructionSTAXD()
{
    symulator->reset();
    symulator->setDreg(0);
    symulator->setEreg(3);
    symulator->setAreg(15);
    unsigned char memory[] = {0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 15);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 3);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getMemory()[3] == 15);
}

void SymulatorTest::testInstructionSHLD()
{
    symulator->reset();
    symulator->setLreg(43);
    symulator->setHreg(34);
    unsigned char memory[] = {0x22, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 3);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 34);
    QVERIFY(symulator->getLreg() == 43);
    QVERIFY(symulator->getMemory()[4] == 43);
    QVERIFY(symulator->getMemory()[5] == 34);
}

void SymulatorTest::testInstructionSTA()
{
    symulator->reset();
    symulator->setAreg(43);
    unsigned char memory[] = {0x32, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 3);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 43);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getMemory()[4] == 43);
}

void SymulatorTest::testInstructionINXB()
{
    symulator->reset();
    symulator->setBreg(54);
    symulator->setCreg(32);
    unsigned char memory[] = {0x03, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 54);
    QVERIFY(symulator->getCreg() == 33);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionINXD()
{
    symulator->reset();
    symulator->setDreg(54);
    symulator->setEreg(32);
    unsigned char memory[] = {0x13, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 54);
    QVERIFY(symulator->getEreg() == 33);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionINXH()
{
    symulator->reset();
    symulator->setHreg(54);
    symulator->setLreg(32);
    unsigned char memory[] = {0x23, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 54);
    QVERIFY(symulator->getLreg() == 33);
}

void SymulatorTest::testInstructionINXSP()
{
    symulator->reset();
    symulator->setSP(54);
    unsigned char memory[] = {0x33, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 55);
}

void SymulatorTest::testInstructionINRB()
{
    symulator->reset();
    symulator->setBreg(54);
    unsigned char memory[] = {0x04, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 55);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionINRD()
{
    symulator->reset();
    symulator->setDreg(54);
    unsigned char memory[] = {0x14, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 55);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionINRH()
{
    symulator->reset();
    symulator->setHreg(54);
    unsigned char memory[] = {0x24, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 55);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionINRM()
{
    symulator->reset();
    symulator->setLreg(5);
    symulator->setHreg(0);
    unsigned char memory[] = {0x34, 0x0, 0x0, 0x0, 0x0, 0x9, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
    QVERIFY(symulator->getMreg() == 0xa);
}

void SymulatorTest::testInstructionDCRB()
{
    symulator->reset();
    symulator->setBreg(54);
    unsigned char memory[] = {0x05, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 53);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionDCRD()
{
    symulator->reset();
    symulator->setDreg(54);
    unsigned char memory[] = {0x15, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 53);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionDCRH()
{
    symulator->reset();
    symulator->setHreg(54);
    unsigned char memory[] = {0x25, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 53);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionDCRM()
{
    symulator->reset();
    symulator->setLreg(5);
    symulator->setHreg(0);
    unsigned char memory[] = {0x35, 0x0, 0x0, 0x0, 0x0, 0x9, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
    QVERIFY(symulator->getMreg() == 0x8);
}

void SymulatorTest::testInstructionMVIB()
{
    symulator->reset();
    unsigned char memory[] = {0x06, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0x34);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMVID()
{
    symulator->reset();
    unsigned char memory[] = {0x16, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0x34);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMVIH()
{
    symulator->reset();
    unsigned char memory[] = {0x26, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0x34);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMVIM()
{
    symulator->reset();
    symulator->setLreg(5);
    symulator->setHreg(0);
    unsigned char memory[] = {0x36, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
    QVERIFY(symulator->getMreg() == 0x34);
}

void SymulatorTest::testInstructionRLC()
{
    symulator->reset();
    symulator->setAreg(0xf2);
    unsigned char memory[] = {0x07, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0xe5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRAL()
{
    symulator->reset();
    symulator->setAreg(0xb5);
    unsigned char memory[] = {0x17, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0x6a);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionDAA()
{
    symulator->reset();
    symulator->setAreg(0x9b);
    unsigned char memory[] = {0x27, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 0x1);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSTC()
{
    symulator->reset();
    unsigned char memory[] = {0x37, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0x0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionDADB()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(5);
    symulator->setBreg(0);
    symulator->setCreg(7);
    unsigned char memory[] = {0x09, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 7);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 12);
}

void SymulatorTest::testInstructionDADD()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(5);
    symulator->setDreg(0xff);
    symulator->setEreg(0xff);
    unsigned char memory[] = {0x19, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0xff);
    QVERIFY(symulator->getEreg() == 0xff);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 4);
}

void SymulatorTest::testInstructionDADH()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(5);
    unsigned char memory[] = {0x29, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 10);
}

void SymulatorTest::testInstructionDADSP()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(5);
    symulator->setSP(20);
    unsigned char memory[] = {0x39, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 25);
}

void SymulatorTest::testInstructionLDAXB()
{
    symulator->reset();
    symulator->setBreg(0);
    symulator->setCreg(3);
    unsigned char memory[] = {0x0a, 0x0, 0x0, 0xf, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 15);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 3);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionLDAXD()
{
    symulator->reset();
    symulator->setDreg(0);
    symulator->setEreg(3);
    unsigned char memory[] = {0x1a, 0x0, 0x0, 0xf, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 15);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 3);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionLHLD()
{
    symulator->reset();
    unsigned char memory[] = {0x2a, 0x4, 0x0, 0x0, 0x34, 0x54, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 3);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0x54);
    QVERIFY(symulator->getLreg() == 0x34);
}

void SymulatorTest::testInstructionLDA()
{
    symulator->reset();
    unsigned char memory[] = {0x3a, 0x4, 0x0, 0x0, 0x43, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 3);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0x43);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionDCXB()
{
    symulator->reset();
    symulator->setBreg(54);
    symulator->setCreg(32);
    unsigned char memory[] = {0x0b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 54);
    QVERIFY(symulator->getCreg() == 31);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionDCXD()
{
    symulator->reset();
    symulator->setDreg(54);
    symulator->setEreg(32);
    unsigned char memory[] = {0x1b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 54);
    QVERIFY(symulator->getEreg() == 31);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionDCXH()
{
    symulator->reset();
    symulator->setHreg(54);
    symulator->setLreg(32);
    unsigned char memory[] = {0x2b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 54);
    QVERIFY(symulator->getLreg() == 31);
}

void SymulatorTest::testInstructionDCXSP()
{
    symulator->reset();
    symulator->setSP(43);
    unsigned char memory[] = {0x3b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 42);
}

void SymulatorTest::testInstructionINRC()
{
    symulator->reset();
    symulator->setCreg(54);
    unsigned char memory[] = {0x0C, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 55);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionINRE()
{
    symulator->reset();
    symulator->setEreg(54);
    unsigned char memory[] = {0x1c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 55);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionINRL()
{
    symulator->reset();
    symulator->setLreg(54);
    unsigned char memory[] = {0x2c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 55);
}

void SymulatorTest::testInstructionINRA()
{
    symulator->reset();
    symulator->setAreg(54);
    unsigned char memory[] = {0x3c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 55);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionDCRC()
{
    symulator->reset();
    symulator->setCreg(54);
    unsigned char memory[] = {0x0d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 53);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionDCRE()
{
    symulator->reset();
    symulator->setEreg(54);
    unsigned char memory[] = {0x1d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 53);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionDCRL()
{
    symulator->reset();
    symulator->setLreg(54);
    unsigned char memory[] = {0x2d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 53);
}

void SymulatorTest::testInstructionDCRA()
{
    symulator->reset();
    symulator->setAreg(54);
    unsigned char memory[] = {0x3d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 53);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMVIC()
{
    symulator->reset();
    unsigned char memory[] = {0x0e, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0x34);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMVIE()
{
    symulator->reset();
    unsigned char memory[] = {0x1e, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0x34);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMVIL()
{
    symulator->reset();
    unsigned char memory[] = {0x2e, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0x34);
}

void SymulatorTest::testInstructionMVIA()
{
    symulator->reset();
    unsigned char memory[] = {0x3e, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0x34);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRRC()
{
    symulator->reset();
    symulator->setAreg(0xf2);
    unsigned char memory[] = {0x0f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0x79);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRAR()
{
    symulator->reset();
    symulator->setAreg(0x6a);
    symulator->setCF(1);
    unsigned char memory[] = {0x1f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0xb5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionCMA()
{
    symulator->reset();
    symulator->setAreg(0x6a);
    unsigned char memory[] = {0x2f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0x95);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionCMC()
{
    symulator->reset();
    symulator->setCF(1);
    unsigned char memory[] = {0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVBB()
{
    symulator->reset();
    symulator->setBreg(5);
    unsigned char memory[] = {0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 5);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVBC()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setCreg(8);
    unsigned char memory[] = {0x41, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 8);
    QVERIFY(symulator->getCreg() == 8);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVBD()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setDreg(8);
    unsigned char memory[] = {0x42, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 8);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 8);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVBE()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setEreg(8);
    unsigned char memory[] = {0x43, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 8);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 8);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVBH()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setHreg(8);
    unsigned char memory[] = {0x44, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 8);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 8);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVBL()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setLreg(8);
    unsigned char memory[] = {0x45, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 8);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 8);
}

void SymulatorTest::testInstructionMOVBM()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x46, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 4);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
    QVERIFY(symulator->getMreg() == 4);
}

void SymulatorTest::testInstructionMOVBA()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setAreg(8);
    unsigned char memory[] = {0x47, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 8);
    QVERIFY(symulator->getBreg() == 8);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVCB()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setCreg(8);
    unsigned char memory[] = {0x48, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 5);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVCC()
{
    symulator->reset();
    symulator->setCreg(8);
    unsigned char memory[] = {0x49, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 8);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVCD()
{
    symulator->reset();
    symulator->setDreg(5);
    symulator->setCreg(8);
    unsigned char memory[] = {0x4a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVCE()
{
    symulator->reset();
    symulator->setEreg(5);
    symulator->setCreg(8);
    unsigned char memory[] = {0x4b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 5);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVCH()
{
    symulator->reset();
    symulator->setHreg(5);
    symulator->setCreg(8);
    unsigned char memory[] = {0x4c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 5);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVCL()
{
    symulator->reset();
    symulator->setLreg(5);
    symulator->setCreg(8);
    unsigned char memory[] = {0x4d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionMOVCM()
{
    symulator->reset();
    symulator->setCreg(5);
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x4e, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 4);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
    QVERIFY(symulator->getMreg() == 4);
}

void SymulatorTest::testInstructionMOVCA()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setCreg(8);
    unsigned char memory[] = {0x4f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVDB()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setDreg(8);
    unsigned char memory[] = {0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 5);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVDC()
{
    symulator->reset();
    symulator->setCreg(5);
    symulator->setDreg(8);
    unsigned char memory[] = {0x51, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVDD()
{
    symulator->reset();
    symulator->setDreg(8);
    unsigned char memory[] = {0x52, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 8);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVDE()
{
    symulator->reset();
    symulator->setEreg(5);
    symulator->setDreg(8);
    unsigned char memory[] = {0x53, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 5);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVDH()
{
    symulator->reset();
    symulator->setHreg(5);
    symulator->setDreg(8);
    unsigned char memory[] = {0x54, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 5);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVDL()
{
    symulator->reset();
    symulator->setLreg(5);
    symulator->setDreg(8);
    unsigned char memory[] = {0x55, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionMOVDM()
{
    symulator->reset();
    symulator->setDreg(5);
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x56, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 4);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
    QVERIFY(symulator->getMreg() == 4);
}

void SymulatorTest::testInstructionMOVDA()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setDreg(8);
    unsigned char memory[] = {0x57, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVEB()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setEreg(8);
    unsigned char memory[] = {0x58, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 5);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 5);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVEC()
{
    symulator->reset();
    symulator->setCreg(5);
    symulator->setEreg(8);
    unsigned char memory[] = {0x59, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 5);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVED()
{
    symulator->reset();
    symulator->setDreg(5);
    symulator->setEreg(8);
    unsigned char memory[] = {0x5a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 5);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVEE()
{
    symulator->reset();
    symulator->setEreg(8);
    unsigned char memory[] = {0x5b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 8);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVEH()
{
    symulator->reset();
    symulator->setHreg(5);
    symulator->setEreg(8);
    unsigned char memory[] = {0x5c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 5);
    QVERIFY(symulator->getHreg() == 5);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVEL()
{
    symulator->reset();
    symulator->setLreg(5);
    symulator->setEreg(8);
    unsigned char memory[] = {0x5d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 5);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionMOVEM()
{
    symulator->reset();
    symulator->setEreg(5);
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x5e, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 4);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
    QVERIFY(symulator->getMreg() == 4);
}

void SymulatorTest::testInstructionMOVEA()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setEreg(8);
    unsigned char memory[] = {0x5f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 5);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVHB()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setHreg(8);
    unsigned char memory[] = {0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 5);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 5);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVHC()
{
    symulator->reset();
    symulator->setCreg(5);
    symulator->setHreg(8);
    unsigned char memory[] = {0x61, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 5);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVHD()
{
    symulator->reset();
    symulator->setDreg(5);
    symulator->setHreg(8);
    unsigned char memory[] = {0x62, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 5);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVHE()
{
    symulator->reset();
    symulator->setEreg(5);
    symulator->setHreg(8);
    unsigned char memory[] = {0x63, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 5);
    QVERIFY(symulator->getHreg() == 5);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVHH()
{
    symulator->reset();
    symulator->setHreg(8);
    unsigned char memory[] = {0x64, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 8);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVHL()
{
    symulator->reset();
    symulator->setLreg(5);
    symulator->setHreg(8);
    unsigned char memory[] = {0x65, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 5);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionMOVHM()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x66, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 4);
    QVERIFY(symulator->getLreg() == 1);
}

void SymulatorTest::testInstructionMOVHA()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setHreg(8);
    unsigned char memory[] = {0x67, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 5);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVLB()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setLreg(8);
    unsigned char memory[] = {0x68, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 5);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionMOVLC()
{
    symulator->reset();
    symulator->setCreg(5);
    symulator->setLreg(8);
    unsigned char memory[] = {0x69, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionMOVLD()
{
    symulator->reset();
    symulator->setDreg(5);
    symulator->setLreg(8);
    unsigned char memory[] = {0x6a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionMOVLE()
{
    symulator->reset();
    symulator->setEreg(5);
    symulator->setLreg(8);
    unsigned char memory[] = {0x6b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 5);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionMOVLH()
{
    symulator->reset();
    symulator->setHreg(5);
    symulator->setLreg(8);
    unsigned char memory[] = {0x6c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 5);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionMOVLL()
{
    symulator->reset();
    symulator->setLreg(8);
    unsigned char memory[] = {0x6d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 8);
}

void SymulatorTest::testInstructionMOVLM()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x6e, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 4);
}

void SymulatorTest::testInstructionMOVLA()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setLreg(8);
    unsigned char memory[] = {0x6f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionMOVMB()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(1);
    symulator->setBreg(5);
    unsigned char memory[] = {0x70, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 5);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
    QVERIFY(symulator->getMreg() == 5);
}

void SymulatorTest::testInstructionMOVMC()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(1);
    symulator->setCreg(5);
    unsigned char memory[] = {0x71, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
    QVERIFY(symulator->getMreg() == 5);
}

void SymulatorTest::testInstructionMOVMD()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(1);
    symulator->setDreg(5);
    unsigned char memory[] = {0x72, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
    QVERIFY(symulator->getMreg() == 5);
}

void SymulatorTest::testInstructionMOVME()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(1);
    symulator->setEreg(5);
    unsigned char memory[] = {0x73, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 5);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
    QVERIFY(symulator->getMreg() == 5);
}

void SymulatorTest::testInstructionMOVMH()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x74, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
    QVERIFY(symulator->getMreg() == 0);
}

void SymulatorTest::testInstructionMOVML()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x75, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
    QVERIFY(symulator->getMreg() == 1);
}

void SymulatorTest::testInstructionMOVMA()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(1);
    symulator->setAreg(5);
    unsigned char memory[] = {0x77, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
    QVERIFY(symulator->getMreg() == 5);
}

void SymulatorTest::testInstructionMOVAB()
{
    symulator->reset();
    symulator->setBreg(5);
    symulator->setAreg(8);
    unsigned char memory[] = {0x78, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 5);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVAC()
{
    symulator->reset();
    symulator->setCreg(5);
    symulator->setAreg(8);
    unsigned char memory[] = {0x79, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVAD()
{
    symulator->reset();
    symulator->setDreg(5);
    symulator->setAreg(8);
    unsigned char memory[] = {0x7a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVAE()
{
    symulator->reset();
    symulator->setEreg(5);
    symulator->setAreg(8);
    unsigned char memory[] = {0x7b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 5);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVAH()
{
    symulator->reset();
    symulator->setHreg(5);
    symulator->setAreg(8);
    unsigned char memory[] = {0x7c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 5);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionMOVAL()
{
    symulator->reset();
    symulator->setLreg(5);
    symulator->setAreg(8);
    unsigned char memory[] = {0x7d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionMOVAM()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x7e, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 4);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
    QVERIFY(symulator->getMreg() == 4);
}

void SymulatorTest::testInstructionMOVAA()
{
    symulator->reset();
    symulator->setAreg(8);
    unsigned char memory[] = {0x7f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 8);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionHLT()
{
    symulator->reset();
    symulator->setHLTType(0);
    unsigned char memory[] = {0x76, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getHLT() == 1);
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionADDB()
{
    symulator->reset();
    symulator->setAreg(8);
    symulator->setBreg(2);
    unsigned char memory[] = {0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 10);
    QVERIFY(symulator->getBreg() == 2);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionADDC()
{
    symulator->reset();
    symulator->setAreg(43);
    symulator->setCreg(12);
    unsigned char memory[] = {0x81, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 55);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 12);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionADDD()
{
    symulator->reset();
    symulator->setAreg(43);
    symulator->setDreg(255);
    unsigned char memory[] = {0x82, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 42);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 255);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionADDE()
{
    symulator->reset();
    symulator->setAreg(254);
    symulator->setEreg(2);
    unsigned char memory[] = {0x83, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 2);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionADDH()
{
    symulator->reset();
    symulator->setAreg(254);
    symulator->setHreg(2);
    unsigned char memory[] = {0x84, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 2);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionADDL()
{
    symulator->reset();
    symulator->setAreg(254);
    symulator->setLreg(2);
    unsigned char memory[] = {0x85, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 2);
}

void SymulatorTest::testInstructionADDM()
{
    symulator->reset();
    symulator->setAreg(34);
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x86, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 38);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
}

void SymulatorTest::testInstructionADDA()
{
    symulator->reset();
    symulator->setAreg(2);
    unsigned char memory[] = {0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 4);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionADCB()
{
    symulator->reset();
    symulator->setAreg(2);
    symulator->setBreg(2);
    symulator->setCF(1);
    unsigned char memory[] = {0x88, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 2);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionADCC()
{
    symulator->reset();
    symulator->setAreg(2);
    symulator->setCreg(2);
    unsigned char memory[] = {0x89, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 4);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 2);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionADCD()
{
    symulator->reset();
    symulator->setAreg(254);
    symulator->setDreg(2);
    symulator->setCF(1);
    unsigned char memory[] = {0x8a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 1);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 2);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionADCE()
{
    symulator->reset();
    symulator->setAreg(254);
    symulator->setEreg(2);
    symulator->setCF(1);
    unsigned char memory[] = {0x8b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 1);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 2);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionADCH()
{
    symulator->reset();
    symulator->setAreg(2);
    symulator->setHreg(2);
    unsigned char memory[] = {0x8c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 4);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 2);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionADCL()
{
    symulator->reset();
    symulator->setAreg(2);
    symulator->setLreg(3);
    unsigned char memory[] = {0x8d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 3);
}

void SymulatorTest::testInstructionADCM()
{
    symulator->reset();
    symulator->setAreg(2);
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x8e, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 7);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
}

void SymulatorTest::testInstructionADCA()
{
    symulator->reset();
    symulator->setAreg(2);
    symulator->setCF(1);
    unsigned char memory[] = {0x8f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSUBB()
{
    symulator->reset();
    symulator->setAreg(2);
    symulator->setBreg(1);
    unsigned char memory[] = {0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 1);
    QVERIFY(symulator->getBreg() == 1);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSUBC()
{
    symulator->reset();
    symulator->setAreg(2);
    symulator->setCreg(4);
    unsigned char memory[] = {0x91, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 1);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 254);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 4);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSUBD()
{
    symulator->reset();
    symulator->setAreg(23);
    symulator->setDreg(4);
    unsigned char memory[] = {0x92, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 19);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 4);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSUBE()
{
    symulator->reset();
    symulator->setAreg(23);
    symulator->setEreg(4);
    unsigned char memory[] = {0x93, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 19);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 4);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSUBH()
{
    symulator->reset();
    symulator->setAreg(23);
    symulator->setHreg(4);
    unsigned char memory[] = {0x94, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 19);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 4);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSUBL()
{
    symulator->reset();
    symulator->setAreg(23);
    symulator->setLreg(4);
    unsigned char memory[] = {0x95, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 19);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 4);
}

void SymulatorTest::testInstructionSUBM()
{
    symulator->reset();
    symulator->setAreg(23);
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x96, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 19);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
}

void SymulatorTest::testInstructionSUBA()
{
    symulator->reset();
    symulator->setAreg(233);
    unsigned char memory[] = {0x97, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSBBB()
{
    symulator->reset();
    symulator->setAreg(4);
    symulator->setBreg(2);
    symulator->setCF(1);
    unsigned char memory[] = {0x98, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 1);
    QVERIFY(symulator->getBreg() == 2);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSBBC()
{
    symulator->reset();
    symulator->setAreg(4);
    symulator->setCreg(2);
    unsigned char memory[] = {0x99, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 2);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 2);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSBBD()
{
    symulator->reset();
    symulator->setAreg(4);
    symulator->setDreg(4);
    symulator->setCF(1);
    unsigned char memory[] = {0x9a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 1);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 255);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 4);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSBBE()
{
    symulator->reset();
    symulator->setAreg(4);
    symulator->setEreg(4);
    unsigned char memory[] = {0x9b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 4);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSBBH()
{
    symulator->reset();
    symulator->setAreg(4);
    symulator->setHreg(2);
    unsigned char memory[] = {0x9c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 2);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 2);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSBBL()
{
    symulator->reset();
    symulator->setAreg(4);
    symulator->setLreg(3);
    unsigned char memory[] = {0x9d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 1);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 3);
}

void SymulatorTest::testInstructionSBBM()
{
    symulator->reset();
    symulator->setAreg(4);
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0x9e, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 2);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
}

void SymulatorTest::testInstructionSBBA()
{
    symulator->reset();
    symulator->setAreg(4);
    unsigned char memory[] = {0x9f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionANAB()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setBreg(3);
    unsigned char memory[] = {0xa0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 1);
    QVERIFY(symulator->getBreg() == 3);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionANAC()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setCreg(3);
    symulator->setCF(1);
    unsigned char memory[] = {0xa1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 1);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 3);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionANAD()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setDreg(3);
    unsigned char memory[] = {0xa2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 1);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 3);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionANAE()
{
    symulator->reset();
    symulator->setAreg(32);
    symulator->setEreg(4);
    unsigned char memory[] = {0xa3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 4);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionANAH()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setHreg(3);
    unsigned char memory[] = {0xa4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 1);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 3);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionANAL()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setLreg(3);
    unsigned char memory[] = {0xa5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 1);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 3);
}

void SymulatorTest::testInstructionANAM()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0xa6, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 4);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
}

void SymulatorTest::testInstructionANAA()
{
    symulator->reset();
    symulator->setAreg(5);
    unsigned char memory[] = {0xa7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionXRAB()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setBreg(3);
    unsigned char memory[] = {0xa8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 6);
    QVERIFY(symulator->getBreg() == 3);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionXRAC()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setCreg(3);
    symulator->setCF(1);
    unsigned char memory[] = {0xa9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 6);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 3);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionXRAD()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setDreg(3);
    unsigned char memory[] = {0xaa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 6);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 3);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionXRAE()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setEreg(9);
    unsigned char memory[] = {0xab, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 12);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 9);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionXRAH()
{
    symulator->reset();
    symulator->setAreg(9);
    symulator->setHreg(1);
    unsigned char memory[] = {0xac, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 8);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 1);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionXRAL()
{
    symulator->reset();
    symulator->setAreg(213);
    symulator->setLreg(32);
    unsigned char memory[] = {0xad, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 1);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 245);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 32);
}

void SymulatorTest::testInstructionXRAM()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setLreg(1);
    symulator->setHreg(0);
    unsigned char memory[] = {0xae, 0x7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 2);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
}

void SymulatorTest::testInstructionXRAA()
{
    symulator->reset();
    symulator->setAreg(5);
    unsigned char memory[] = {0xaf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionORAB()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setBreg(3);
    unsigned char memory[] = {0xb0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 7);
    QVERIFY(symulator->getBreg() == 3);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionORAC()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setCreg(3);
    symulator->setCF(1);
    unsigned char memory[] = {0xb1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 7);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 3);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionORAD()
{
    symulator->reset();
    symulator->setAreg(123);
    symulator->setDreg(54);
    unsigned char memory[] = {0xb2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 127);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 54);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionORAE()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setEreg(3);
    unsigned char memory[] = {0xb3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 7);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 3);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionORAH()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setHreg(33);
    unsigned char memory[] = {0xb4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 37);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 33);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionORAL()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setLreg(33);
    unsigned char memory[] = {0xb5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 37);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 33);
}

void SymulatorTest::testInstructionORAM()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0xb6, 0x43, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0x47);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
}

void SymulatorTest::testInstructionORAA()
{
    symulator->reset();
    symulator->setAreg(5);
    unsigned char memory[] = {0xb7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionCMPB()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setBreg(33);
    unsigned char memory[] = {0xb8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 1);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 33);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionCMPC()
{
    symulator->reset();
    symulator->setAreg(54);
    symulator->setCreg(5);
    unsigned char memory[] = {0xb9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 54);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 5);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionCMPD()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setDreg(5);
    unsigned char memory[] = {0xba, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionCMPE()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setEreg(255);
    unsigned char memory[] = {0xbb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 1);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 255);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionCMPH()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setHreg(255);
    unsigned char memory[] = {0xbc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 1);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 255);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionCMPL()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setLreg(5);
    unsigned char memory[] = {0xbd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionCMPM()
{
    symulator->reset();
    symulator->setAreg(5);
    symulator->setHreg(0);
    symulator->setLreg(1);
    unsigned char memory[] = {0xbe, 0x32, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 1);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 1);
}

void SymulatorTest::testInstructionCMPA()
{
    symulator->reset();
    symulator->setAreg(5);
    unsigned char memory[] = {0xbf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRNZ()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x17);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRNC()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x17);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRPO()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x17);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRP()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x17);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionPOPB()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xc1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0x5);
    QVERIFY(symulator->getCreg() == 0x16);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionPOPD()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xd1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0x5);
    QVERIFY(symulator->getEreg() == 0x16);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionPOPH()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0x5);
    QVERIFY(symulator->getLreg() == 0x16);
}

void SymulatorTest::testInstructionPOPPSW()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xf1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0x5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionJNZ()
{
    symulator->reset();
    unsigned char memory[] = {0xc2, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 4);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionJNC()
{
    symulator->reset();
    unsigned char memory[] = {0xd2, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 4);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionJPO()
{
    symulator->reset();
    unsigned char memory[] = {0xe2, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 4);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionJP()
{
    symulator->reset();
    unsigned char memory[] = {0xf2, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 4);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionJMP()
{
    symulator->reset();
    unsigned char memory[] = {0xc3, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 4);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionOUT()
{
    symulator->reset();
    symulator->setAreg(43);
    unsigned char memory[] = {0xd3, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 43);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getOutBuffer() == 43);
}

void SymulatorTest::testInstructionXTHL()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setHreg(0x7);
    symulator->setLreg(0x4);
    unsigned char memory[] = {0xe3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0x5);
    QVERIFY(symulator->getLreg() == 0x16);
    QVERIFY(symulator->getMemory()[10] == 0x4);
    QVERIFY(symulator->getMemory()[11] == 0x7);
}

void SymulatorTest::testInstructionDI()
{
    symulator->reset();
    unsigned char memory[] = {0xf3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getInterruptsEnabled() == false);
}

void SymulatorTest::testInstructionCNZ()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xc4, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x20);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 0);
    QVERIFY(symulator->getMemory()[8] == 2);
}

void SymulatorTest::testInstructionCNC()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xd4, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x20);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 0);
    QVERIFY(symulator->getMemory()[8] == 2);
}

void SymulatorTest::testInstructionCPO()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xe4, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x20);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 0);
    QVERIFY(symulator->getMemory()[8] == 2);
}

void SymulatorTest::testInstructionCP()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xf4, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x20);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 0);
    QVERIFY(symulator->getMemory()[8] == 2);
}

void SymulatorTest::testInstructionPUSHB()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setBreg(5);
    symulator->setCreg(2);
    unsigned char memory[] = {0xc5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 5);
    QVERIFY(symulator->getCreg() == 2);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 5);
    QVERIFY(symulator->getMemory()[8] == 2);
}

void SymulatorTest::testInstructionPUSHD()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setDreg(5);
    symulator->setEreg(2);
    unsigned char memory[] = {0xd5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 5);
    QVERIFY(symulator->getEreg() == 2);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 5);
    QVERIFY(symulator->getMemory()[8] == 2);
}

void SymulatorTest::testInstructionPUSHH()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setHreg(5);
    symulator->setLreg(2);
    unsigned char memory[] = {0xe5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 5);
    QVERIFY(symulator->getLreg() == 2);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 5);
    QVERIFY(symulator->getMemory()[8] == 2);
}

void SymulatorTest::testInstructionPUSHPSW()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setAreg(5);
    symulator->setCF(1);
    unsigned char memory[] = {0xf5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 5);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 5);
    QVERIFY(symulator->getMemory()[8] == 3);
}

void SymulatorTest::testInstructionADI()
{
    symulator->reset();
    symulator->setAreg(12);
    unsigned char memory[] = {0xc6, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 16);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSUI()
{
    symulator->reset();
    symulator->setAreg(12);
    unsigned char memory[] = {0xd6, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 8);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionANI()
{
    symulator->reset();
    symulator->setAreg(12);
    unsigned char memory[] = {0xe6, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 4);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionORI()
{
    symulator->reset();
    symulator->setAreg(12);
    unsigned char memory[] = {0xf6, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 12);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRST0()
{
    symulator->reset();
    unsigned char memory[] = {0xc7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRST2()
{
    symulator->reset();
    unsigned char memory[] = {0xd7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x11);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRST4()
{
    symulator->reset();
    unsigned char memory[] = {0xe7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x21);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRST6()
{
    symulator->reset();
    unsigned char memory[] = {0xf7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x31);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRZ()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setZ(1);
    unsigned char memory[] = {0xc8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x17);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRC()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setCF(1);
    unsigned char memory[] = {0xd8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x17);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRPE()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setP(1);
    unsigned char memory[] = {0xe8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x17);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRM()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setS(1);
    unsigned char memory[] = {0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x17);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 1);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRET()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xc9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x17);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionPCHL()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setHreg(0);
    symulator->setLreg(5);
    unsigned char memory[] = {0xe9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 6);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
}

void SymulatorTest::testInstructionSPHL()
{
    symulator->reset();
    symulator->setHreg(0);
    symulator->setLreg(5);
    unsigned char memory[] = {0xf9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 5);
    QVERIFY(symulator->getSP() == 5);
}

void SymulatorTest::testInstructionJZ()
{
    symulator->reset();
    symulator->setZ(1);
    unsigned char memory[] = {0xca, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 4);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionJC()
{
    symulator->reset();
    symulator->setCF(1);
    unsigned char memory[] = {0xda, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 4);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionJPE()
{
    symulator->reset();
    symulator->setP(1);
    unsigned char memory[] = {0xea, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 4);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionJM()
{
    symulator->reset();
    symulator->setS(1);
    unsigned char memory[] = {0xfa, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 4);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 1);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionIN()
{
    symulator->reset();
    symulator->setInBuffer(43);
    unsigned char memory[] = {0xdb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 43);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionXCHG()
{
    symulator->reset();
    symulator->setHreg(43);
    symulator->setLreg(23);
    symulator->setDreg(54);
    symulator->setEreg(76);
    unsigned char memory[] = {0xeb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 43);
    QVERIFY(symulator->getEreg() == 23);
    QVERIFY(symulator->getHreg() == 54);
    QVERIFY(symulator->getLreg() == 76);
}

void SymulatorTest::testInstructionEI()
{
    symulator->reset();
    unsigned char memory[] = {0xfb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 1);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getInterruptsEnabled() == true);
}

void SymulatorTest::testInstructionCZ()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setZ(1);
    unsigned char memory[] = {0xcc, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x20);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 1);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 0);
    QVERIFY(symulator->getMemory()[8] == 2);
}

void SymulatorTest::testInstructionCC()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setCF(1);
    unsigned char memory[] = {0xdc, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x20);
    QVERIFY(symulator->getCF() == 1);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 0);
    QVERIFY(symulator->getMemory()[8] == 2);
}

void SymulatorTest::testInstructionCPE()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setP(1);
    unsigned char memory[] = {0xec, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x20);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 0);
    QVERIFY(symulator->getMemory()[8] == 2);
}

void SymulatorTest::testInstructionCM()
{
    symulator->reset();
    symulator->setSP(10);
    symulator->setS(1);
    unsigned char memory[] = {0xfc, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x20);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 1);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 0);
    QVERIFY(symulator->getMemory()[8] == 2);
}

void SymulatorTest::testInstructionCALL()
{
    symulator->reset();
    symulator->setSP(10);
    unsigned char memory[] = {0xcd, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 48);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x20);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
    QVERIFY(symulator->getSP() == 8);
    QVERIFY(symulator->getMemory()[9] == 0);
    QVERIFY(symulator->getMemory()[8] == 2);
}

void SymulatorTest::testInstructionACI()
{
    symulator->reset();
    symulator->setAreg(12);
    symulator->setCF(1);
    unsigned char memory[] = {0xce, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 17);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionSBI()
{
    symulator->reset();
    symulator->setAreg(12);
    symulator->setCF(1);
    unsigned char memory[] = {0xde, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 7);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionXRI()
{
    symulator->reset();
    symulator->setAreg(12);
    symulator->setCF(1);
    unsigned char memory[] = {0xee, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 1);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 8);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionCPI()
{
    symulator->reset();
    symulator->setAreg(54);
    unsigned char memory[] = {0xfe, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 2);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 1);
    QVERIFY(symulator->getAreg() == 54);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRST1()
{
    symulator->reset();
    unsigned char memory[] = {0xcf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x09);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRST3()
{
    symulator->reset();
    unsigned char memory[] = {0xdf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x19);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRST5()
{
    symulator->reset();
    unsigned char memory[] = {0xef, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x29);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

void SymulatorTest::testInstructionRST7()
{
    symulator->reset();
    unsigned char memory[] = {0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    symulator->load(memory, 8);
    symulator->nextInst();
    QVERIFY(symulator->getPC() == 0x39);
    QVERIFY(symulator->getCF() == 0);
    QVERIFY(symulator->getP() == 0);
    QVERIFY(symulator->getZ() == 0);
    QVERIFY(symulator->getS() == 0);
    QVERIFY(symulator->getAC() == 0);
    QVERIFY(symulator->getAreg() == 0);
    QVERIFY(symulator->getBreg() == 0);
    QVERIFY(symulator->getCreg() == 0);
    QVERIFY(symulator->getDreg() == 0);
    QVERIFY(symulator->getEreg() == 0);
    QVERIFY(symulator->getHreg() == 0);
    QVERIFY(symulator->getLreg() == 0);
}

QTEST_APPLESS_MAIN(SymulatorTest)

#include "build/Desktop-Debug/tst_symulator.moc"
