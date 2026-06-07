#include "helpinstructionswidget.h"
#include "ui_helpinstructionswidget.h"

#include <QFile>

HelpInstructionsWidget::HelpInstructionsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HelpInstructionsWidget)
    , model(new QStringListModel(this))
{
    ui->setupUi(this);
    languageSuffix = (QLocale::system().name().startsWith("pl")) ? "_pl.html" : "_en.html";
    model->setStringList(instructionList);
    ui->listView->setModel(model);

    connect(ui->listView, &QListView::clicked, this, &HelpInstructionsWidget::onInstructionClicked);
}

HelpInstructionsWidget::~HelpInstructionsWidget()
{
    delete ui;
}

void HelpInstructionsWidget::onInstructionClicked(const QModelIndex &index)
{
    if(!index.isValid() || index.row() >= instructionList.size())
        return;

    openInstructionHelp(instructionList[index.row()]);
}

void HelpInstructionsWidget::openInstructionHelp(const QString &instruction)
{
    QString filePath = QString(":/instructions/helpPages/%1%2").arg(instruction.toLower(), languageSuffix);

    QFile file(filePath);
    if(file.open(QFile::ReadOnly | QFile::Text))
        ui->textBrowser->setHtml(file.readAll());
    else
        ui->textBrowser->setText(tr("Help file not found."));
}
