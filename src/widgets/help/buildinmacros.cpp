#include "buildinmacros.h"
#include "ui_buildinmacros.h"

#include <QDirIterator>
#include <QStringListModel>

BuildinMacros::BuildinMacros(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BuildinMacros)
    , model(new QStringListModel(this))
{
    ui->setupUi(this);
    languageSuffix = (QLocale::system().name().startsWith("pl")) ? "_pl.html" : "_en.html";
    initTranslations();
    ui->listView->setModel(model);

    connect(ui->listView, &QListView::clicked, this, &BuildinMacros::onInstructionClicked);
}

BuildinMacros::~BuildinMacros()
{
    delete ui;
}


void BuildinMacros::initTranslations()
{
    QStringList translations{
        tr("PRINTCHAR"),
        tr("INCHAR"),
        tr("GCLEAR"),
        tr("GDRAW"),
        tr("GX"),
        tr("GY")
    };
    model->setStringList(translations);
}

void BuildinMacros::onInstructionClicked(const QModelIndex &index)
{
    if(!index.isValid() || index.row() >= helpPagesList.size())
        return;

    loadInstructionHelp(helpPagesList[index.row()]);
}

void BuildinMacros::loadInstructionHelp(const QString &instruction)
{
    QString filePath = QString(":/buildinmacros/helpPages/buildinmacros/%1%2").arg(instruction.toLower(), languageSuffix);

    QFile file(filePath);
    if(file.open(QFile::ReadOnly | QFile::Text))
        ui->textBrowser->setHtml(file.readAll());
    else
        ui->textBrowser->setText(tr("Help file not found."));
}
