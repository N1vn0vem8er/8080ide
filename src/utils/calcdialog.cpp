#include "calcdialog.h"
#include "ui_calcdialog.h"

#include <QKeyEvent>
#include <bitset>
#include <sstream>

CalcDialog::CalcDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CalcDialog)
{
    ui->setupUi(this);
    ui->binKeyboard->setVisible(false);
    ui->decKeyboard->setVisible(false);
    numBuffer = 0;
    opNumBuffer = 0;
    connect(ui->hexRadioButton, &QRadioButton::clicked, this, [this](){modeChanged(ModeIndex::HEX);});
    connect(ui->decRadioButton, &QRadioButton::clicked, this, [this](){modeChanged(ModeIndex::DEC);});
    connect(ui->binRadioButton, &QRadioButton::clicked, this, [this](){modeChanged(ModeIndex::BIN);});

    connect(ui->hex0Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_0);});
    connect(ui->hex1Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_1);});
    connect(ui->hex2Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_2);});
    connect(ui->hex3Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_3);});
    connect(ui->hex4Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_4);});
    connect(ui->hex5Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_5);});
    connect(ui->hex6Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_6);});
    connect(ui->hex7Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_7);});
    connect(ui->hex8Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_8);});
    connect(ui->hex9Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_9);});
    connect(ui->hexAButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_A);});
    connect(ui->hexBButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_B);});
    connect(ui->hexCButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_C);});
    connect(ui->hexDButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_D);});
    connect(ui->hexEButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_E);});
    connect(ui->hexFButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_F);});
    connect(ui->hexDelButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Backspace);});
    connect(ui->hexClearButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Delete);});
    connect(ui->hexAddButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Plus);});
    connect(ui->hexSubButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Minus);});
    connect(ui->hexDivButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Slash);});
    connect(ui->hexMulButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Asterisk);});
    connect(ui->hexSRButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_R);});
    connect(ui->hexSLButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_L);});
    connect(ui->hexEqButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Equal);});
    connect(ui->hexANDButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Ampersand);});
    connect(ui->hexORButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Bar);});
    connect(ui->hexXORButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_AsciiCircum);});
    connect(ui->hexCMPButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_AsciiTilde);});
    connect(ui->hexMODButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Percent);});

    connect(ui->dec0Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_0);});
    connect(ui->dec1Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_1);});
    connect(ui->dec2Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_2);});
    connect(ui->dec3Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_3);});
    connect(ui->dec4Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_4);});
    connect(ui->dec5Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_5);});
    connect(ui->dec6Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_6);});
    connect(ui->dec7Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_7);});
    connect(ui->dec8Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_8);});
    connect(ui->dec9Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_9);});
    connect(ui->decDelButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Backspace);});
    connect(ui->decClearButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Delete);});
    connect(ui->decAddButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Plus);});
    connect(ui->decSubButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Minus);});
    connect(ui->decDivButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Slash);});
    connect(ui->decMulButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Asterisk);});
    connect(ui->decSRButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_R);});
    connect(ui->decSLButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_L);});
    connect(ui->decEqButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Equal);});
    connect(ui->decANDButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Ampersand);});
    connect(ui->decORButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Bar);});
    connect(ui->decXORButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_AsciiCircum);});
    connect(ui->decCMPButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_AsciiTilde);});
    connect(ui->decMODButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Percent);});

    connect(ui->bin0Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_0);});
    connect(ui->bin1Button, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_1);});
    connect(ui->binDelButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Backspace);});
    connect(ui->binClearButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Delete);});
    connect(ui->binAddButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Plus);});
    connect(ui->binSubButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Minus);});
    connect(ui->binMulButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Asterisk);});
    connect(ui->binDivButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Slash);});
    connect(ui->binSRButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_R);});
    connect(ui->binSLButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_L);});
    connect(ui->binEqButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Equal);});
    connect(ui->binANDButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Ampersand);});
    connect(ui->binORButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Bar);});
    connect(ui->binXORButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_AsciiCircum);});
    connect(ui->binCMPButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_AsciiTilde);});
    connect(ui->binMODButton, &QPushButton::clicked, this, [this](){handleKey(Qt::Key_Percent);});
}

CalcDialog::~CalcDialog()
{
    delete ui;
}

void CalcDialog::modeChanged(int mode)
{
    currentMode = mode;
    switch(currentMode)
    {
    case ModeIndex::HEX:
        ui->hexKeyboard->setVisible(true);
        ui->binKeyboard->setVisible(false);
        ui->decKeyboard->setVisible(false);
        break;
    case ModeIndex::DEC:
        ui->hexKeyboard->setVisible(false);
        ui->binKeyboard->setVisible(false);
        ui->decKeyboard->setVisible(true);
        break;
    case ModeIndex::BIN:
        ui->hexKeyboard->setVisible(false);
        ui->binKeyboard->setVisible(true);
        ui->decKeyboard->setVisible(false);
        break;
    }
}

void CalcDialog::handleKey(int key)
{
    if((key >= 48 && key <= 57) || (key >= 65 && key <= 70))
    {
        if(currentMode==ModeIndex::DEC && key >= 48 && key <= 57)
        {
            displayBuffer += QChar(key);
            if(key != 48)
            {
                int pow = 1;
                int tmp = key-48;
                while(pow <= tmp)
                {
                    pow *= 10;
                    numBuffer = numBuffer*pow+tmp;
                }
            }
            else
                numBuffer*=10;
        }
        else if(currentMode==ModeIndex::BIN && key >= 48 && key <= 49)
        {
            displayBuffer += QChar(key);
            numBuffer = numBuffer << 1;
            numBuffer+= key-48;
        }
        else if(currentMode==ModeIndex::HEX)
        {
            displayBuffer += QChar(key);
            int pow = 0;
            numBuffer = 0;
            for(int i=displayBuffer.length()-1;i>=0;i--)
            {
                if(displayBuffer[i].toLatin1() >= 48 && displayBuffer[i].toLatin1() <= 57)
                    numBuffer+=std::pow(16,pow)*(displayBuffer[i].toLatin1()-48);
                else if(displayBuffer[i].toLatin1() >= 65 && displayBuffer[i].toLatin1() <= 70)
                    numBuffer+=std::pow(16,pow)*(displayBuffer[i].toLatin1()-55);
                pow++;
            }
        }
    }
    else
        switch(key)
        {
        case Qt::Key_Delete:
            displayBuffer.clear();
            numBuffer = 0;
            break;
        case Qt::Key_Backspace:
            displayBuffer.chop(1);
            switch(currentMode)
            {
            case ModeIndex::DEC:
                numBuffer /= 10;
                break;
            case ModeIndex::HEX:
                numBuffer /= 16;
                break;
            case ModeIndex::BIN:
                numBuffer = numBuffer >> 1;
                break;
            default:
                throw std::range_error("Mode index out of range");
                break;
            }
            break;
        case Qt::Key_Plus:
            operationBuffer = Operations::ADD;
            opNumBuffer = numBuffer;
            numBuffer = 0;
            displayBuffer.clear();
            break;
        case Qt::Key_Minus:
            operationBuffer = Operations::SUB;
            opNumBuffer = numBuffer;
            numBuffer = 0;
            displayBuffer.clear();
            break;
        case Qt::Key_Slash:
            operationBuffer = Operations::DIV;
            opNumBuffer = numBuffer;
            numBuffer = 0;
            displayBuffer.clear();
            break;
        case Qt::Key_Asterisk:
            operationBuffer = Operations::MUL;
            opNumBuffer = numBuffer;
            numBuffer = 0;
            displayBuffer.clear();
            break;
        case Qt::Key_R:
            operationBuffer = Operations::SR;
            doMath();
            break;
        case Qt::Key_L:
            operationBuffer = Operations::SL;
            doMath();
            break;
        case Qt::Key_Equal:
            doMath();
            break;
        case Qt::Key_Ampersand:
            operationBuffer = numBuffer;
            numBuffer = 0;
            operationBuffer = Operations::AND;
            displayBuffer.clear();
            break;
        case Qt::Key_Bar:
            operationBuffer = Operations::OR;
            opNumBuffer = numBuffer;
            numBuffer = 0;
            displayBuffer.clear();
            break;
        case Qt::Key_AsciiCircum:
            opNumBuffer = numBuffer;
            numBuffer = 0;
            operationBuffer = Operations::XOR;
            displayBuffer.clear();
            break;
        case Qt::Key_Percent:
            opNumBuffer = numBuffer;
            numBuffer = 0;
            operationBuffer = Operations::MOD;
            displayBuffer.clear();
            break;
        case Qt::Key_AsciiTilde:
            operationBuffer = Operations::CMP;
            doMath();
            break;
        }
    ui->lineEdit->setText(displayBuffer);
}

void CalcDialog::doMath()
{
    switch(operationBuffer)
    {
    case Operations::ADD:
        numBuffer = opNumBuffer + numBuffer;
        displayResoults();
        break;
    case Operations::SUB:
        numBuffer = opNumBuffer - numBuffer;
        displayResoults();
        break;
    case Operations::MUL:
        numBuffer = opNumBuffer * numBuffer;
        displayResoults();
        break;
    case Operations::DIV:
        numBuffer = opNumBuffer / numBuffer;
        displayResoults();
        break;
    case Operations::SL:
        numBuffer = numBuffer << 1;
        displayResoults();
        break;
    case Operations::SR:
        numBuffer = numBuffer >> 1;
        displayResoults();
        break;
    case Operations::AND:
        numBuffer = opNumBuffer & numBuffer;
        displayResoults();
        break;
    case Operations::OR:
        numBuffer = opNumBuffer | numBuffer;
        displayResoults();
        break;
    case Operations::XOR:
        numBuffer = opNumBuffer ^ numBuffer;
        displayResoults();
        break;
    case Operations::MOD:
        numBuffer = opNumBuffer % numBuffer;
        displayResoults();
        break;
    case Operations::CMP:
        numBuffer = ~numBuffer;
        displayResoults();
        break;
    }
}

void CalcDialog::displayResoults()
{
    switch(currentMode)
    {
    case ModeIndex::HEX:
    {
        std::stringstream ss;
        ss << std::hex << numBuffer;
        displayBuffer = QString::fromStdString(ss.str()).toUpper();
    }
        break;
    case ModeIndex::DEC:
        displayBuffer = QString::number(numBuffer);
        break;
    case ModeIndex::BIN:
        displayBuffer = QString::fromStdString(std::bitset<32>(numBuffer).to_string());
        break;
    }
}


void CalcDialog::keyPressEvent(QKeyEvent *event)
{
    switch(currentMode)
    {
    case ModeIndex::HEX:
        handleKey(event->key());
        break;
    case ModeIndex::DEC:
        handleKey(event->key());
        break;
    case ModeIndex::BIN:
        handleKey(event->key());
        break;
    }

    QWidget::keyPressEvent(event);
}
