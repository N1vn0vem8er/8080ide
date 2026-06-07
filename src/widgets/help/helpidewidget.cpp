#include "helpidewidget.h"
#include "ui_helpidewidget.h"

#include <QFile>

HelpIDEWidget::HelpIDEWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HelpIDEWidget)
    , model(new QStringListModel)
{
    ui->setupUi(this);
    languageSuffix = (QLocale::system().name().startsWith("pl")) ? "_pl.html" : "_en.html";
    initTranslations();
    ui->listView->setModel(model);

    connect(ui->listView, &QListView::clicked, this, &HelpIDEWidget::onInstructionClicked);
}

HelpIDEWidget::~HelpIDEWidget()
{
    delete ui;
}
void HelpIDEWidget::openInstructionHelp(const QString &instruction)
{
    QString filePath = QString(":/ide/helpPages/ide/%1%2").arg(instruction.toLower(), languageSuffix);

    QFile file(filePath);
    if(file.open(QFile::ReadOnly | QFile::Text))
        ui->textBrowser->setHtml(file.readAll());
    else
        ui->textBrowser->setText(tr("Help file not found."));
}

void HelpIDEWidget::onInstructionClicked(const QModelIndex &index)
{
    if(!index.isValid() || index.row() >= helpPagesList.size())
        return;

    openInstructionHelp(helpPagesList[index.row()]);
}

void HelpIDEWidget::initTranslations()
{
    QStringList translations{
        tr("Welcome"),
        tr("Projects"),
        tr("Assembler"),
        tr("Labels"),
        tr("Graphics Screen"),
        tr("Random Number Generator")
    };
    model->setStringList(translations);
}
