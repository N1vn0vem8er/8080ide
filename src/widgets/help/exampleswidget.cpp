#include "exampleswidget.h"
#include "ui_exampleswidget.h"

#include <QDirIterator>
#include <QStringListModel>

ExamplesWidget::ExamplesWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ExamplesWidget)
{
    ui->setupUi(this);
    QStringListModel* model = new QStringListModel(ui->listView);
    model->setStringList(translations);
    ui->listView->setModel(model);
    connect(ui->listView, &QListView::clicked, this, [&](const QModelIndex& index){openInstructionHelp(helpPagesList[index.row()].toLower());});
    QLocale l;
    language = l.name() == "pl_PL" ? "_pl.html" : "_en.html";
}

ExamplesWidget::~ExamplesWidget()
{
    delete ui;
}

void ExamplesWidget::openInstructionHelp(QString instruction) const
{
    QDirIterator iterator(":/ide/helpPages/examples", QDirIterator::Subdirectories);
    while(iterator.hasNext())
    {
        QString fileName = iterator.next().remove(' ');
        if(fileName == ":/ide/helpPages/examples/" + instruction + language)
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
