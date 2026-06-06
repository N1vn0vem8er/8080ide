#include "exampleswidget.h"
#include "ui_exampleswidget.h"

#include <QDirIterator>
#include <QStringListModel>

ExamplesWidget::ExamplesWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ExamplesWidget)
    , model(new QStringListModel(this))
{
    ui->setupUi(this);
    languageSuffix = (QLocale::system().name().startsWith("pl")) ? "_pl.html" : "_en.html";
    initTranslations();
    ui->listView->setModel(model);

    connect(ui->listView, &QListView::clicked, this, &ExamplesWidget::onInstructionClicked);
}

ExamplesWidget::~ExamplesWidget()
{
    delete ui;
}

void ExamplesWidget::loadInstructionHelp(const QString &instruction)
{
    QString filePath = QString(":/examples/helpPages/examples/%1%2").arg(instruction.toLower(), languageSuffix);

    QFile file(filePath);
    if(file.open(QFile::ReadOnly | QFile::Text))
        ui->textBrowser->setHtml(file.readAll());
    else
        ui->textBrowser->setText(tr("Help file not found."));
}

void ExamplesWidget::onInstructionClicked(const QModelIndex &index)
{
    if(!index.isValid() || index.row() >= helpPagesList.size())
        return;

    loadInstructionHelp(helpPagesList[index.row()]);
}

void ExamplesWidget::initTranslations()
{
    QStringList translations{
        tr("Hello World"),
        tr("Hello World 2"),
        tr("Draw line"),
        tr("Draw circle"),
        tr("Draw figure"),
        tr("Fill screen"),
        tr("Fill screen with colors"),
        tr("Generate random number"),
        tr("Draw random colors on screen"),
        tr("Guessing game")
    };
    model->setStringList(translations);
}
