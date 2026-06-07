#include "helppseudoinstwidget.h"
#include "qstringlistmodel.h"
#include "ui_helppseudoinstwidget.h"

#include <QFile>

HelpPseudoInstWidget::HelpPseudoInstWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HelpPseudoInstWidget)
    , model(new QStringListModel(this))
{
    ui->setupUi(this);
    languageSuffix = (QLocale::system().name().startsWith("pl")) ? "_pl.html" : "_en.html";
    model->setStringList(instructionList);
    ui->listView->setModel(model);

    connect(ui->listView, &QListView::clicked, this, &HelpPseudoInstWidget::onInstructionClicked);
}

HelpPseudoInstWidget::~HelpPseudoInstWidget()
{
    delete ui;
}

void HelpPseudoInstWidget::openInstructionHelp(const QString &instruction)
{
    QString filePath = QString(":/pseudoinst/helpPages/pseudoinstructions/%1%2").arg(instruction.toLower(), languageSuffix);

    QFile file(filePath);
    if(file.open(QFile::ReadOnly | QFile::Text))
        ui->textBrowser->setHtml(file.readAll());
    else
        ui->textBrowser->setText(tr("Help file not found."));
}

void HelpPseudoInstWidget::onInstructionClicked(const QModelIndex &index)
{
    if(!index.isValid() || index.row() >= instructionList.size())
        return;

    openInstructionHelp(instructionList[index.row()]);
}
