#include <QtTest>
#include "../../8080/assembler.h"

// add necessary includes here

class AssemblerUnitTest : public QObject
{
    Q_OBJECT

public:
    AssemblerUnitTest();
    ~AssemblerUnitTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testRemovingComments();
    void testConstants();
    void testApplayingConstants();
    void testIfs();
    void testIfsFalse();
    void testMacro();
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

};

AssemblerUnitTest::AssemblerUnitTest() {}

AssemblerUnitTest::~AssemblerUnitTest() {}

void AssemblerUnitTest::initTestCase()
{

}

void AssemblerUnitTest::cleanupTestCase()
{

}

void AssemblerUnitTest::testRemovingComments()
{
    QString code = "//commnet\nMOV A,B ;comment\n;comment\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    QVERIFY(resoult.size() == 3);
    QCOMPARE(resoult[0], "\n");
    QCOMPARE(resoult[1], "MOV A,B \n");
    QCOMPARE(resoult[2], "\n");
}

void AssemblerUnitTest::testConstants()
{
    QString code = "test: EQU 20\nsettest: SET 10\nMOV A,B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    QVERIFY(resoult.size() == 1);
    QCOMPARE(resoult[0], "MOV A,B\n");
}

void AssemblerUnitTest::testApplayingConstants()
{
    QString code = "test: EQU 20\nsettest: SET 10\nMOV A,B\nMVI A,test\nMVI B,settest\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    QVERIFY(resoult.size() == 3);
    QCOMPARE(resoult[0], "MOV A,B\n");
    QCOMPARE(resoult[1], "MVI A,20\n");
    QCOMPARE(resoult[2], "MVI B,10\n");
}

void AssemblerUnitTest::testIfs()
{
    QString code = "test: EQU 1\nIF test\nMOV A,B\nENDIF\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    QVERIFY(resoult.size() == 1);
    QCOMPARE(resoult[0], "MOV A,B\n");
}

void AssemblerUnitTest::testIfsFalse()
{
    QString code = "test: EQU 0\nIF test\nMOV A,B\nENDIF\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    QVERIFY(resoult.size() == 0);
}

void AssemblerUnitTest::testMacro()
{
    QString code = "test: MACRO\nMOV A,B\nENDM\nRRC\ntest\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    QVERIFY(resoult.size() == 2);
    QCOMPARE(resoult[0], "RRC\n");
    QCOMPARE(resoult[1], "MOV A,B\n");
}

void AssemblerUnitTest::testInstructionNOP()
{
    QString code = "NOP\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x0);
}

void AssemblerUnitTest::testInstructionLXIB()
{
    QString code = "LXI B,5412\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0x1);
    QVERIFY(assembled[1] == 0x12);
    QVERIFY(assembled[2] == 0x54);
}

void AssemblerUnitTest::testInstructionLXID()
{
    QString code = "LXI D,5412\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0x11);
    QVERIFY(assembled[1] == 0x12);
    QVERIFY(assembled[2] == 0x54);
}

void AssemblerUnitTest::testInstructionLXIH()
{
    QString code = "LXI H,5412\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0x21);
    QVERIFY(assembled[1] == 0x12);
    QVERIFY(assembled[2] == 0x54);
}

void AssemblerUnitTest::testInstructionLXISP()
{
    QString code = "LXI SP,5412\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0x31);
    QVERIFY(assembled[1] == 0x12);
    QVERIFY(assembled[2] == 0x54);
}

void AssemblerUnitTest::testInstructionSTAXB()
{
    QString code = "STAX B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x2);
}

void AssemblerUnitTest::testInstructionSTAXD()
{
    QString code = "STAX D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x12);
}

void AssemblerUnitTest::testInstructionSHLD()
{
    QString code = "SHLD 4368\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0x22);
    QVERIFY(assembled[1] == 0x68);
    QVERIFY(assembled[2] == 0x43);
}

void AssemblerUnitTest::testInstructionSTA()
{
    QString code = "STA 4368\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0x32);
    QVERIFY(assembled[1] == 0x68);
    QVERIFY(assembled[2] == 0x43);
}

void AssemblerUnitTest::testInstructionINXB()
{
    QString code = "INX B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x3);
}

void AssemblerUnitTest::testInstructionINXD()
{
    QString code = "INX D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x13);
}

void AssemblerUnitTest::testInstructionINXH()
{
    QString code = "INX H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x23);
}

void AssemblerUnitTest::testInstructionINXSP()
{
    QString code = "INX SP\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x33);
}

void AssemblerUnitTest::testInstructionINRB()
{
    QString code = "INR B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x4);
}

void AssemblerUnitTest::testInstructionINRD()
{
    QString code = "INR D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x14);
}

void AssemblerUnitTest::testInstructionINRH()
{
    QString code = "INR H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x24);
}

void AssemblerUnitTest::testInstructionINRM()
{
    QString code = "INR M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x34);
}

void AssemblerUnitTest::testInstructionDCRB()
{
    QString code = "DCR B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x5);
}

void AssemblerUnitTest::testInstructionDCRD()
{
    QString code = "DCR D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x15);
}

void AssemblerUnitTest::testInstructionDCRH()
{
    QString code = "DCR H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x25);
}

void AssemblerUnitTest::testInstructionDCRM()
{
    QString code = "DCR M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x35);
}

void AssemblerUnitTest::testInstructionMVIB()
{
    QString code = "MVI B,34\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0x6);
    QVERIFY(assembled[1] == 0x34);
}

void AssemblerUnitTest::testInstructionMVID()
{
    QString code = "MVI D,34+4\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0x16);
    QVERIFY(assembled[1] == 0x38);
}

void AssemblerUnitTest::testInstructionMVIH()
{
    QString code = "MVI H,34-4\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0x26);
    QVERIFY(assembled[1] == 0x30);
}

void AssemblerUnitTest::testInstructionMVIM()
{
    QString code = "MVI M,4*2\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0x36);
    QVERIFY(assembled[1] == 0x8);
}

void AssemblerUnitTest::testInstructionRLC()
{
    QString code = "RLC\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x7);
}

void AssemblerUnitTest::testInstructionRAL()
{
    QString code = "RAL\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x17);
}

void AssemblerUnitTest::testInstructionDAA()
{
    QString code = "DAA\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x27);
}

void AssemblerUnitTest::testInstructionSTC()
{
    QString code = "STC\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x37);
}

void AssemblerUnitTest::testInstructionDADB()
{
    QString code = "DAD B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x9);
}

void AssemblerUnitTest::testInstructionDADD()
{
    QString code = "DAD D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x19);
}

void AssemblerUnitTest::testInstructionDADH()
{
    QString code = "DAD H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x29);
}

void AssemblerUnitTest::testInstructionDADSP()
{
    QString code = "DAD SP\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x39);
}

void AssemblerUnitTest::testInstructionLDAXB()
{
    QString code = "LDAX B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xa);
}

void AssemblerUnitTest::testInstructionLDAXD()
{
    QString code = "LDAX D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x1a);
}

void AssemblerUnitTest::testInstructionLHLD()
{
    QString code = "LHLD 4376\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0x2a);
    QVERIFY(assembled[1] == 0x76);
    QVERIFY(assembled[2] == 0x43);
}

void AssemblerUnitTest::testInstructionLDA()
{
    QString code = "LDA 4376\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0x3a);
    QVERIFY(assembled[1] == 0x76);
    QVERIFY(assembled[2] == 0x43);
}

void AssemblerUnitTest::testInstructionDCXB()
{
    QString code = "DCX B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xb);
}

void AssemblerUnitTest::testInstructionDCXD()
{
    QString code = "DCX D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x1b);
}

void AssemblerUnitTest::testInstructionDCXH()
{
    QString code = "DCX H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x2b);
}

void AssemblerUnitTest::testInstructionDCXSP()
{
    QString code = "DCX SP\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x3b);
}

void AssemblerUnitTest::testInstructionINRC()
{
    QString code = "INR C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xc);
}

void AssemblerUnitTest::testInstructionINRE()
{
    QString code = "INR E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x1c);
}

void AssemblerUnitTest::testInstructionINRL()
{
    QString code = "INR L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x2c);
}

void AssemblerUnitTest::testInstructionINRA()
{
    QString code = "INR A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x3c);
}

void AssemblerUnitTest::testInstructionDCRC()
{
    QString code = "DCR C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xd);
}

void AssemblerUnitTest::testInstructionDCRE()
{
    QString code = "DCR E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x1d);
}

void AssemblerUnitTest::testInstructionDCRL()
{
    QString code = "DCR L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x2d);
}

void AssemblerUnitTest::testInstructionDCRA()
{
    QString code = "DCR A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x3d);
}

void AssemblerUnitTest::testInstructionMVIC()
{
    QString code = "MVI C,'T'\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0xe);
    QVERIFY(assembled[1] == 'T');
}

void AssemblerUnitTest::testInstructionMVIE()
{
    QString code = "MVI E,'T'+1\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0x1e);
    QVERIFY(assembled[1] == 'T'+1);
}

void AssemblerUnitTest::testInstructionMVIL()
{
    QString code = "MVI L,34/2\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0x2e);
    QVERIFY(assembled[1] == 0x34/2);
}

void AssemblerUnitTest::testInstructionMVIA()
{
    QString code = "MVI A,34\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0x3e);
    QVERIFY(assembled[1] == 0x34);
}

void AssemblerUnitTest::testInstructionRRC()
{
    QString code = "RRC\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xf);
}

void AssemblerUnitTest::testInstructionRAR()
{
    QString code = "RAR\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x1f);
}

void AssemblerUnitTest::testInstructionCMA()
{
    QString code = "CMA\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x2f);
}

void AssemblerUnitTest::testInstructionCMC()
{
    QString code = "CMC\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x3f);
}

void AssemblerUnitTest::testInstructionMOVBB()
{
    QString code = "MOV B,B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x40);
}

void AssemblerUnitTest::testInstructionMOVBC()
{
    QString code = "MOV B,C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x41);
}

void AssemblerUnitTest::testInstructionMOVBD()
{
    QString code = "MOV B,D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x42);
}

void AssemblerUnitTest::testInstructionMOVBE()
{
    QString code = "MOV B,E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x43);
}

void AssemblerUnitTest::testInstructionMOVBH()
{
    QString code = "MOV B,H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x44);
}

void AssemblerUnitTest::testInstructionMOVBL()
{
    QString code = "MOV B,L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x45);
}

void AssemblerUnitTest::testInstructionMOVBM()
{
    QString code = "MOV B,M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x46);
}

void AssemblerUnitTest::testInstructionMOVBA()
{
    QString code = "MOV B,A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x47);
}

void AssemblerUnitTest::testInstructionMOVCB()
{
    QString code = "MOV C,B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x48);
}

void AssemblerUnitTest::testInstructionMOVCC()
{
    QString code = "MOV C,C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x49);
}

void AssemblerUnitTest::testInstructionMOVCD()
{
    QString code = "MOV C,D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x4a);
}

void AssemblerUnitTest::testInstructionMOVCE()
{
    QString code = "MOV C,E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x4b);
}

void AssemblerUnitTest::testInstructionMOVCH()
{
    QString code = "MOV C,H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x4c);
}

void AssemblerUnitTest::testInstructionMOVCL()
{
    QString code = "MOV C,L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x4d);
}

void AssemblerUnitTest::testInstructionMOVCM()
{
    QString code = "MOV C,M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x4e);
}

void AssemblerUnitTest::testInstructionMOVCA()
{
    QString code = "MOV C,A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x4f);
}

void AssemblerUnitTest::testInstructionMOVDB()
{
    QString code = "MOV D,B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x50);
}

void AssemblerUnitTest::testInstructionMOVDC()
{
    QString code = "MOV D,C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x51);
}

void AssemblerUnitTest::testInstructionMOVDD()
{
    QString code = "MOV D,D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x52);
}

void AssemblerUnitTest::testInstructionMOVDE()
{
    QString code = "MOV D,E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x53);
}

void AssemblerUnitTest::testInstructionMOVDH()
{
    QString code = "MOV D,H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x54);
}

void AssemblerUnitTest::testInstructionMOVDL()
{
    QString code = "MOV D,L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x55);
}

void AssemblerUnitTest::testInstructionMOVDM()
{
    QString code = "MOV D,M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x56);
}

void AssemblerUnitTest::testInstructionMOVDA()
{
    QString code = "MOV D,A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x57);
}

void AssemblerUnitTest::testInstructionMOVEB()
{
    QString code = "MOV E,B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x58);
}

void AssemblerUnitTest::testInstructionMOVEC()
{
    QString code = "MOV E,C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x59);
}

void AssemblerUnitTest::testInstructionMOVED()
{
    QString code = "MOV E,D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x5a);
}

void AssemblerUnitTest::testInstructionMOVEE()
{
    QString code = "MOV E,E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x5b);
}

void AssemblerUnitTest::testInstructionMOVEH()
{
    QString code = "MOV E,H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x5c);
}

void AssemblerUnitTest::testInstructionMOVEL()
{
    QString code = "MOV E,L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x5d);
}

void AssemblerUnitTest::testInstructionMOVEM()
{
    QString code = "MOV E,M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x5e);
}

void AssemblerUnitTest::testInstructionMOVEA()
{
    QString code = "MOV E,A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x5f);
}

void AssemblerUnitTest::testInstructionMOVHB()
{
    QString code = "MOV H,B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x60);
}

void AssemblerUnitTest::testInstructionMOVHC()
{
    QString code = "MOV H,C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x61);
}

void AssemblerUnitTest::testInstructionMOVHD()
{
    QString code = "MOV H,D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x62);
}

void AssemblerUnitTest::testInstructionMOVHE()
{
    QString code = "MOV H,E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x63);
}

void AssemblerUnitTest::testInstructionMOVHH()
{
    QString code = "MOV H,H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x64);
}

void AssemblerUnitTest::testInstructionMOVHL()
{
    QString code = "MOV H,L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x65);
}

void AssemblerUnitTest::testInstructionMOVHM()
{
    QString code = "MOV H,M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x66);
}

void AssemblerUnitTest::testInstructionMOVHA()
{
    QString code = "MOV H,A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x67);
}

void AssemblerUnitTest::testInstructionMOVLB()
{
    QString code = "MOV L,B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x68);
}

void AssemblerUnitTest::testInstructionMOVLC()
{
    QString code = "MOV L,C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x69);
}

void AssemblerUnitTest::testInstructionMOVLD()
{
    QString code = "MOV L,D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x6a);
}

void AssemblerUnitTest::testInstructionMOVLE()
{
    QString code = "MOV L,E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x6b);
}

void AssemblerUnitTest::testInstructionMOVLH()
{
    QString code = "MOV L,H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x6c);
}

void AssemblerUnitTest::testInstructionMOVLL()
{
    QString code = "MOV L,L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x6d);
}

void AssemblerUnitTest::testInstructionMOVLM()
{
    QString code = "MOV L,M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x6e);
}

void AssemblerUnitTest::testInstructionMOVLA()
{
    QString code = "MOV L,A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x6f);
}

void AssemblerUnitTest::testInstructionMOVMB()
{
    QString code = "MOV M,B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x70);
}

void AssemblerUnitTest::testInstructionMOVMC()
{
    QString code = "MOV M,C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x71);
}

void AssemblerUnitTest::testInstructionMOVMD()
{
    QString code = "MOV M,D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x72);
}

void AssemblerUnitTest::testInstructionMOVME()
{
    QString code = "MOV M,E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x73);
}

void AssemblerUnitTest::testInstructionMOVMH()
{
    QString code = "MOV M,H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x74);
}

void AssemblerUnitTest::testInstructionMOVML()
{
    QString code = "MOV M,L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x75);
}

void AssemblerUnitTest::testInstructionMOVMA()
{
    QString code = "MOV M,A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x77);
}

void AssemblerUnitTest::testInstructionMOVAB()
{
    QString code = "MOV A,B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x78);
}

void AssemblerUnitTest::testInstructionMOVAC()
{
    QString code = "MOV A,C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x79);
}

void AssemblerUnitTest::testInstructionMOVAD()
{
    QString code = "MOV A,D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x7a);
}

void AssemblerUnitTest::testInstructionMOVAE()
{
    QString code = "MOV A,E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x7b);
}

void AssemblerUnitTest::testInstructionMOVAH()
{
    QString code = "MOV A,H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x7c);
}

void AssemblerUnitTest::testInstructionMOVAL()
{
    QString code = "MOV A,L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x7d);
}

void AssemblerUnitTest::testInstructionMOVAM()
{
    QString code = "MOV A,M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x7e);
}

void AssemblerUnitTest::testInstructionMOVAA()
{
    QString code = "MOV A,A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x7f);
}

void AssemblerUnitTest::testInstructionHLT()
{
    QString code = "HLT\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x76);
}

void AssemblerUnitTest::testInstructionADDB()
{
    QString code = "ADD B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x80);
}

void AssemblerUnitTest::testInstructionADDC()
{
    QString code = "ADD C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x81);
}

void AssemblerUnitTest::testInstructionADDD()
{
    QString code = "ADD D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x82);
}

void AssemblerUnitTest::testInstructionADDE()
{
    QString code = "ADD E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x83);
}

void AssemblerUnitTest::testInstructionADDH()
{
    QString code = "ADD H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x84);
}

void AssemblerUnitTest::testInstructionADDL()
{
    QString code = "ADD L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x85);
}

void AssemblerUnitTest::testInstructionADDM()
{
    QString code = "ADD M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x86);
}

void AssemblerUnitTest::testInstructionADDA()
{
    QString code = "ADD A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x87);
}

void AssemblerUnitTest::testInstructionADCB()
{
    QString code = "ADC B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x88);
}

void AssemblerUnitTest::testInstructionADCC()
{
    QString code = "ADC C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x89);
}

void AssemblerUnitTest::testInstructionADCD()
{
    QString code = "ADC D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x8a);
}

void AssemblerUnitTest::testInstructionADCE()
{
    QString code = "ADC E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x8b);
}

void AssemblerUnitTest::testInstructionADCH()
{
    QString code = "ADC H \n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x8c);
}

void AssemblerUnitTest::testInstructionADCL()
{
    QString code = "ADC L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x8d);
}

void AssemblerUnitTest::testInstructionADCM()
{
    QString code = "ADC M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x8e);
}

void AssemblerUnitTest::testInstructionADCA()
{
    QString code = "ADC A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x8f);
}

void AssemblerUnitTest::testInstructionSUBB()
{
    QString code = "SUB B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x90);
}

void AssemblerUnitTest::testInstructionSUBC()
{
    QString code = "SUB C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x91);
}

void AssemblerUnitTest::testInstructionSUBD()
{
    QString code = "SUB D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x92);
}

void AssemblerUnitTest::testInstructionSUBE()
{
    QString code = "SUB E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x93);
}

void AssemblerUnitTest::testInstructionSUBH()
{
    QString code = "SUB H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x94);
}

void AssemblerUnitTest::testInstructionSUBL()
{
    QString code = "SUB L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x95);
}

void AssemblerUnitTest::testInstructionSUBM()
{
    QString code = "SUB M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x96);
}

void AssemblerUnitTest::testInstructionSUBA()
{
    QString code = "SUB A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x97);
}

void AssemblerUnitTest::testInstructionSBBB()
{
    QString code = "SBB B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x98);
}

void AssemblerUnitTest::testInstructionSBBC()
{
    QString code = "SBB C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x99);
}

void AssemblerUnitTest::testInstructionSBBD()
{
    QString code = "SBB D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x9a);
}

void AssemblerUnitTest::testInstructionSBBE()
{
    QString code = "SBB E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x9b);
}

void AssemblerUnitTest::testInstructionSBBH()
{
    QString code = "SBB H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x9c);
}

void AssemblerUnitTest::testInstructionSBBL()
{
    QString code = "SBB L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x9d);
}

void AssemblerUnitTest::testInstructionSBBM()
{
    QString code = "SBB M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x9e);
}

void AssemblerUnitTest::testInstructionSBBA()
{
    QString code = "SBB A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0x9f);
}

void AssemblerUnitTest::testInstructionANAB()
{
    QString code = "ANA B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xa0);
}

void AssemblerUnitTest::testInstructionANAC()
{
    QString code = "ANA C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xa1);
}

void AssemblerUnitTest::testInstructionANAD()
{
    QString code = "ANA D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xa2);
}

void AssemblerUnitTest::testInstructionANAE()
{
    QString code = "ANA E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xa3);
}

void AssemblerUnitTest::testInstructionANAH()
{
    QString code = "ANA H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xa4);
}

void AssemblerUnitTest::testInstructionANAL()
{
    QString code = "ANA L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xa5);
}

void AssemblerUnitTest::testInstructionANAM()
{
    QString code = "ANA M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xa6);
}

void AssemblerUnitTest::testInstructionANAA()
{
    QString code = "ANA A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xa7);
}

void AssemblerUnitTest::testInstructionXRAB()
{
    QString code = "XRA B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xa8);
}

void AssemblerUnitTest::testInstructionXRAC()
{
    QString code = "XRA C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xa9);
}

void AssemblerUnitTest::testInstructionXRAD()
{
    QString code = "XRA D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xaa);
}

void AssemblerUnitTest::testInstructionXRAE()
{
    QString code = "XRA E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xab);
}

void AssemblerUnitTest::testInstructionXRAH()
{
    QString code = "XRA H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xac);
}

void AssemblerUnitTest::testInstructionXRAL()
{
    QString code = "XRA L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xad);
}

void AssemblerUnitTest::testInstructionXRAM()
{
    QString code = "XRA M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xae);
}

void AssemblerUnitTest::testInstructionXRAA()
{
    QString code = "XRA A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xaf);
}

void AssemblerUnitTest::testInstructionORAB()
{
    QString code = "ORA B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xb0);
}

void AssemblerUnitTest::testInstructionORAC()
{
    QString code = "ORA C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xb1);
}

void AssemblerUnitTest::testInstructionORAD()
{
    QString code = "ORA D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xb2);
}

void AssemblerUnitTest::testInstructionORAE()
{
    QString code = "ORA E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xb3);
}

void AssemblerUnitTest::testInstructionORAH()
{
    QString code = "ORA H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xb4);
}

void AssemblerUnitTest::testInstructionORAL()
{
    QString code = "ORA L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xb5);
}

void AssemblerUnitTest::testInstructionORAM()
{
    QString code = "ORA M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xb6);
}

void AssemblerUnitTest::testInstructionORAA()
{
    QString code = "ORA A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xb7);
}

void AssemblerUnitTest::testInstructionCMPB()
{
    QString code = "CMP B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xb8);
}

void AssemblerUnitTest::testInstructionCMPC()
{
    QString code = "CMP C\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xb9);
}

void AssemblerUnitTest::testInstructionCMPD()
{
    QString code = "CMP D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xba);
}

void AssemblerUnitTest::testInstructionCMPE()
{
    QString code = "CMP E\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xbb);
}

void AssemblerUnitTest::testInstructionCMPH()
{
    QString code = "CMP H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xbc);
}

void AssemblerUnitTest::testInstructionCMPL()
{
    QString code = "CMP L\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xbd);
}

void AssemblerUnitTest::testInstructionCMPM()
{
    QString code = "CMP M\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xbe);
}

void AssemblerUnitTest::testInstructionCMPA()
{
    QString code = "CMP A\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xbf);
}

void AssemblerUnitTest::testInstructionRNZ()
{
    QString code = "RNZ\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xc0);
}

void AssemblerUnitTest::testInstructionRNC()
{
    QString code = "RNC\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xd0);
}

void AssemblerUnitTest::testInstructionRPO()
{
    QString code = "RPO\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xe0);
}

void AssemblerUnitTest::testInstructionRP()
{
    QString code = "RP\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xf0);
}

void AssemblerUnitTest::testInstructionPOPB()
{
    QString code = "POP B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xc1);
}

void AssemblerUnitTest::testInstructionPOPD()
{
    QString code = "POP D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xd1);
}

void AssemblerUnitTest::testInstructionPOPH()
{
    QString code = "POP H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xe1);
}

void AssemblerUnitTest::testInstructionPOPPSW()
{
    QString code = "POP PSW\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xf1);
}

void AssemblerUnitTest::testInstructionJNZ()
{
    QString code = "JNZ 4365\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xc2);
    QVERIFY(assembled[1] == 0x65);
    QVERIFY(assembled[2] == 0x43);
}

void AssemblerUnitTest::testInstructionJNC()
{
    QString code = "JNC 4365\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xd2);
    QVERIFY(assembled[1] == 0x65);
    QVERIFY(assembled[2] == 0x43);
}

void AssemblerUnitTest::testInstructionJPO()
{
    QString code = "JPO 65\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xe2);
    QVERIFY(assembled[1] == 0x65);
    QVERIFY(assembled[2] == 0x00);
}

void AssemblerUnitTest::testInstructionJP()
{
    QString code = "JP 4365\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xf2);
    QVERIFY(assembled[1] == 0x65);
    QVERIFY(assembled[2] == 0x43);
}

void AssemblerUnitTest::testInstructionJMP()
{
    QString code = "JMP 4365\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xc3);
    QVERIFY(assembled[1] == 0x65);
    QVERIFY(assembled[2] == 0x43);
}

void AssemblerUnitTest::testInstructionOUT()
{
    QString code = "OUT 01\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0xd3);
    QVERIFY(assembled[1] == 0x01);
}

void AssemblerUnitTest::testInstructionXTHL()
{
    QString code = "XTHL\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xe3);
}

void AssemblerUnitTest::testInstructionDI()
{
    QString code = "DI\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xf3);
}

void AssemblerUnitTest::testInstructionCNZ()
{
    QString code = "CNZ 4365\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xc4);
    QVERIFY(assembled[1] == 0x65);
    QVERIFY(assembled[2] == 0x43);
}

void AssemblerUnitTest::testInstructionCNC()
{
    QString code = "CNC 5\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xd4);
    QVERIFY(assembled[1] == 0x05);
    QVERIFY(assembled[2] == 0x00);
}

void AssemblerUnitTest::testInstructionCPO()
{
    QString code = "CPO 4365\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xe4);
    QVERIFY(assembled[1] == 0x65);
    QVERIFY(assembled[2] == 0x43);
}

void AssemblerUnitTest::testInstructionCP()
{
    QString code = "CP 4365\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xf4);
    QVERIFY(assembled[1] == 0x65);
    QVERIFY(assembled[2] == 0x43);
}

void AssemblerUnitTest::testInstructionPUSHB()
{
    QString code = "PUSH B\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xc5);
}

void AssemblerUnitTest::testInstructionPUSHD()
{
    QString code = "PUSH D\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xd5);
}

void AssemblerUnitTest::testInstructionPUSHH()
{
    QString code = "PUSH H\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xe5);
}

void AssemblerUnitTest::testInstructionPUSHPSW()
{
    QString code = "PUSH PSW\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xf5);
}

void AssemblerUnitTest::testInstructionADI()
{
    QString code = "ADI 43\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0xc6);
    QVERIFY(assembled[1] == 0x43);
}

void AssemblerUnitTest::testInstructionSUI()
{
    QString code = "SUI 'Y'\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0xd6);
    QVERIFY(assembled[1] == 'Y');
}

void AssemblerUnitTest::testInstructionANI()
{
    QString code = "ANI 3\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0xe6);
    QVERIFY(assembled[1] == 0x03);
}

void AssemblerUnitTest::testInstructionORI()
{
    QString code = "ORI 43-2\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0xf6);
    QVERIFY(assembled[1] == 0x41);
}

void AssemblerUnitTest::testInstructionRST0()
{
    QString code = "RST 0\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xc7);
}

void AssemblerUnitTest::testInstructionRST2()
{
    QString code = "RST 2\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xd7);
}

void AssemblerUnitTest::testInstructionRST4()
{
    QString code = "RST 4\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xe7);
}

void AssemblerUnitTest::testInstructionRST6()
{
    QString code = "RST 6\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xf7);
}

void AssemblerUnitTest::testInstructionRZ()
{
    QString code = "RZ\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xc8);
}

void AssemblerUnitTest::testInstructionRC()
{
    QString code = "RC\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xd8);
}

void AssemblerUnitTest::testInstructionRPE()
{
    QString code = "RPE\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xe8);
}

void AssemblerUnitTest::testInstructionRM()
{
    QString code = "RM\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xf8);
}

void AssemblerUnitTest::testInstructionRET()
{
    QString code = "RET\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xc9);
}

void AssemblerUnitTest::testInstructionPCHL()
{
    QString code = "PCHL\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xe9);
}

void AssemblerUnitTest::testInstructionSPHL()
{
    QString code = "SPHL\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xf9);
}

void AssemblerUnitTest::testInstructionJZ()
{
    QString code = "JZ 4764\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xca);
    QVERIFY(assembled[1] == 0x64);
    QVERIFY(assembled[2] == 0x47);
}

void AssemblerUnitTest::testInstructionJC()
{
    QString code = "JC 4764\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xda);
    QVERIFY(assembled[1] == 0x64);
    QVERIFY(assembled[2] == 0x47);
}

void AssemblerUnitTest::testInstructionJPE()
{
    QString code = "JPE 4764\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xea);
    QVERIFY(assembled[1] == 0x64);
    QVERIFY(assembled[2] == 0x47);
}

void AssemblerUnitTest::testInstructionJM()
{
    QString code = "JM 4764\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xfa);
    QVERIFY(assembled[1] == 0x64);
    QVERIFY(assembled[2] == 0x47);
}

void AssemblerUnitTest::testInstructionIN()
{
    QString code = "IN 0\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0xdb);
    QVERIFY(assembled[1] == 0x00);
}

void AssemblerUnitTest::testInstructionXCHG()
{
    QString code = "XCHG\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xeb);
}

void AssemblerUnitTest::testInstructionEI()
{
    QString code = "EI\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xfb);
}

void AssemblerUnitTest::testInstructionCZ()
{
    QString code = "CZ 4764\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xcc);
    QVERIFY(assembled[1] == 0x64);
    QVERIFY(assembled[2] == 0x47);
}

void AssemblerUnitTest::testInstructionCC()
{
    QString code = "CC 4764\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xdc);
    QVERIFY(assembled[1] == 0x64);
    QVERIFY(assembled[2] == 0x47);
}

void AssemblerUnitTest::testInstructionCPE()
{
    QString code = "CPE 4764\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xec);
    QVERIFY(assembled[1] == 0x64);
    QVERIFY(assembled[2] == 0x47);
}

void AssemblerUnitTest::testInstructionCM()
{
    QString code = "CM 4764\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xfc);
    QVERIFY(assembled[1] == 0x64);
    QVERIFY(assembled[2] == 0x47);
}

void AssemblerUnitTest::testInstructionCALL()
{
    QString code = "CALL 4764\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 3);
    QVERIFY(assembled[0] == 0xcd);
    QVERIFY(assembled[1] == 0x64);
    QVERIFY(assembled[2] == 0x47);
}

void AssemblerUnitTest::testInstructionACI()
{
    QString code = "ACI 47\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0xce);
    QVERIFY(assembled[1] == 0x47);
}

void AssemblerUnitTest::testInstructionSBI()
{
    QString code = "SBI 47\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0xde);
    QVERIFY(assembled[1] == 0x47);
}

void AssemblerUnitTest::testInstructionXRI()
{
    QString code = "XRI 47\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0xee);
    QVERIFY(assembled[1] == 0x47);
}

void AssemblerUnitTest::testInstructionCPI()
{
    QString code = "CPI 47\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 2);
    QVERIFY(assembled[0] == 0xfe);
    QVERIFY(assembled[1] == 0x47);
}

void AssemblerUnitTest::testInstructionRST1()
{
    QString code = "RST 1\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xcf);
}

void AssemblerUnitTest::testInstructionRST3()
{
    QString code = "RST 3\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xdf);
}

void AssemblerUnitTest::testInstructionRST5()
{
    QString code = "RST 5\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xef);
}

void AssemblerUnitTest::testInstructionRST7()
{
    QString code = "RST 7\n";
    Assembler a;
    auto resoult = a.toVector(code.toStdString());
    resoult = a.decodeConstants(resoult);
    resoult = a.decodeIfsAndMacros(resoult);
    resoult = a.applyMacros(resoult);
    resoult = a.decodeLabels(resoult, 0);
    resoult = a.decodeOperands(resoult);
    unsigned char* assembled = a.assemble(resoult);
    ushort size = a.getCompCodeSize();
    QVERIFY(size == 1);
    QVERIFY(assembled[0] == 0xff);
}

QTEST_APPLESS_MAIN(AssemblerUnitTest)

#include "tst_assemblerunittest.moc"
