#include "searchwidget.h"
#include "ui_searchwidget.h"

SearchWidget::SearchWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchWidget)
{
    ui->setupUi(this);
    connect(ui->searchField, &QLineEdit::textChanged, this, [this](){ui->onlySelectedCheckBox->isChecked() ? emit searchInSelected(ui->searchField->text()) : emit searchFieldChanged(ui->searchField->text());});
    connect(ui->replaceAllButton, &QPushButton::clicked, this, [this](){ui->onlySelectedCheckBox->isChecked() ? emit replaceInSelected(ui->replaceField->text()) : emit replaceFieldChanged(ui->replaceField->text());});
    connect(ui->searchField, &QLineEdit::returnPressed, this, [this](){emit searchFieldChanged(ui->searchField->text());});
    connect(ui->fieldTextReplaceButton, &QPushButton::clicked, this, [this](){auto tmp = ui->searchField->text(); ui->searchField->setText(ui->replaceField->text()); ui->replaceField->setText(tmp);});
    connect(ui->caseSensitiveCheckBox, &QCheckBox::checkStateChanged, this, [&]{ui->onlySelectedCheckBox->isChecked() ? emit searchInSelected(ui->searchField->text()) : emit searchFieldChanged(ui->searchField->text());});
    connect(ui->onlySelectedCheckBox, &QCheckBox::checkStateChanged, this, [&]{ui->onlySelectedCheckBox->isChecked() ? emit searchInSelected(ui->searchField->text()) : emit searchFieldChanged(ui->searchField->text());});
}

QString SearchWidget::getSearchFieldText() const
{
    return ui->searchField->text();
}

QString SearchWidget::getReplaceFiedldText() const
{
    return ui->replaceField->text();
}

bool SearchWidget::isCaseSensitive() const
{
    return ui->caseSensitiveCheckBox->isChecked();
}

SearchWidget::~SearchWidget()
{
    delete ui;
}
