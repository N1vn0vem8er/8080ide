#include "helppseudoinstwidget.h"
#include "qdiriterator.h"
#include "qstringlistmodel.h"
#include "ui_helppseudoinstwidget.h"

HelpPseudoInstWidget::HelpPseudoInstWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HelpPseudoInstWidget)
{
    ui->setupUi(this);
    QStringListModel* model = new QStringListModel(ui->listView);
    model->setStringList(instructionList);
    ui->listView->setModel(model);
    connect(ui->listView, &QListView::clicked, this, [=](const QModelIndex& index){openInstructionHelp(ui->listView->model()->data(index).toString().toLower());});
    QLocale l;
    language = l.name() == "pl_PL" ? "_pl.html" : "_en.html";
}

HelpPseudoInstWidget::~HelpPseudoInstWidget()
{
    delete ui;
}
void HelpPseudoInstWidget::openInstructionHelp(QString instruction)
{
    QDirIterator iterator(":/pseudoinst/helpPages/pseudoinstructions", QDirIterator::Subdirectories);
    while(iterator.hasNext())
    {
        QString fileName = iterator.next();
        if(fileName == ":/pseudoinst/helpPages/pseudoinstructions/" + instruction + language)
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
