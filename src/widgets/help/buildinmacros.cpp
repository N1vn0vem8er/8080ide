#include "buildinmacros.h"
#include "ui_buildinmacros.h"

#include <QDirIterator>
#include <QStringListModel>

BuildinMacros::BuildinMacros(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BuildinMacros)
{
    ui->setupUi(this);
    QStringListModel* model = new QStringListModel(ui->listView);
    model->setStringList(translations);
    ui->listView->setModel(model);
    connect(ui->listView, &QListView::clicked, this, [&](const QModelIndex& index){openInstructionHelp(helpPagesList[index.row()].toLower());});
    QLocale l;
    language = l.name() == "pl_PL" ? "_pl.html" : "_en.html";
}

BuildinMacros::~BuildinMacros()
{
    delete ui;
}


void BuildinMacros::openInstructionHelp(QString instruction) const
{
    QDirIterator iterator(":/buildinmacros/helpPages/buildinmacros", QDirIterator::Subdirectories);
    while(iterator.hasNext())
    {
        QString fileName = iterator.next();
        if(fileName == ":/buildinmacros/helpPages/buildinmacros/" + instruction + language)
        {
            QFile file(fileName);
            if(file.open(QFile::ReadOnly))
            {
                ui->textBrowser->setText(file.readAll());
                file.close();
            }
        }
    }
}
