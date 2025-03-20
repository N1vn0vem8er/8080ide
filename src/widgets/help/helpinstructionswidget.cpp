#include "helpinstructionswidget.h"
#include "qdiriterator.h"
#include "qstringlistmodel.h"
#include "ui_helpinstructionswidget.h"

HelpInstructionsWidget::HelpInstructionsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HelpInstructionsWidget)
{
    ui->setupUi(this);
    QStringListModel* model = new QStringListModel(ui->listView);
    model->setStringList(instructionList);
    ui->listView->setModel(model);
    connect(ui->listView, &QListView::clicked, this, [=](const QModelIndex& index){openInstructionHelp(ui->listView->model()->data(index).toString().toLower());});
    QLocale l;
    language = l.name() == "pl_PL" ? "_pl.html" : "_en.html";
}

HelpInstructionsWidget::~HelpInstructionsWidget()
{
    delete ui;
}

void HelpInstructionsWidget::openInstructionHelp(QString instruction)
{
    QDirIterator iterator(":/instructions/helpPages", QDirIterator::Subdirectories);
    while(iterator.hasNext())
    {
        QString fileName = iterator.next();
        if(fileName == ":/instructions/helpPages/" + instruction + language)
        {
            QFile file(fileName);
            file.open(QFile::ReadOnly);
            if(file.isOpen())
            {
                ui->instDescriptionLabel->setText(file.readAll());
                file.close();
            }
        }
    }
}
