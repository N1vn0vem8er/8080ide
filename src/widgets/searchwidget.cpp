#include "searchwidget.h"
#include "ui_searchwidget.h"

SearchWidget::SearchWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchWidget)
{
    ui->setupUi(this);
    connect(ui->searchField, &QLineEdit::textChanged, this, [this](){emit searchFieldChanged(ui->searchField->text());});
    connect(ui->replaceAllButton, &QPushButton::clicked, this, [this](){emit replaceFieldChanged(ui->replaceField->text());});
    connect(ui->searchField, &QLineEdit::returnPressed, this, [this](){emit searchFieldChanged(ui->searchField->text());});
    connect(ui->fieldTextReplaceButton, &QPushButton::clicked, this, [this](){auto tmp = ui->searchField->text(); ui->searchField->setText(ui->replaceField->text()); ui->replaceField->setText(tmp);});
}

QString SearchWidget::getSearchFieldText()
{
    return ui->searchField->text();
}

QString SearchWidget::getReplaceFiedldText()
{
    return ui->replaceField->text();
}

SearchWidget::~SearchWidget()
{
    delete ui;
}
