#include "helpidewidget.h"
#include "qdiriterator.h"
#include "qstringlistmodel.h"
#include "ui_helpidewidget.h"

HelpIDEWidget::HelpIDEWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HelpIDEWidget)
{
    ui->setupUi(this);
    QStringListModel* model = new QStringListModel(ui->listView);
    model->setStringList(translations);
    ui->listView->setModel(model);
    connect(ui->listView, &QListView::clicked, this, [=](const QModelIndex& index){openInstructionHelp(helpPagesList[index.row()].toLower());});
    QLocale l;
    language = l.name() == "pl_PL" ? "_pl.html" : "_en.html";
}

HelpIDEWidget::~HelpIDEWidget()
{
    delete ui;
}
void HelpIDEWidget::openInstructionHelp(QString instruction)
{
    QDirIterator iterator(":/ide/helpPages/ide", QDirIterator::Subdirectories);
    while(iterator.hasNext())
    {
        QString fileName = iterator.next();
        if(fileName == ":/ide/helpPages/ide/" + instruction + language)
        {
            QFile file(fileName);
            file.open(QFile::ReadOnly);
            if(file.isOpen())
            {
                ui->textBrowser->setText(file.readAll());
                file.close();
            }
        }
    }
}
