#include "customwidget.h"

#include <QPushButton>

#include "mainwindow.h"
#include "ui_customwidget.h"

CustomWidget::CustomWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::CustomWidget)
{
    ui->setupUi(this);

    // Send the label text to MainWindow's removeItem method
    connect(this, &CustomWidget::sendRemoveItem, qobject_cast<MainWindow*>(parent), &MainWindow::removeItem);

    // Connect close button clicked to closeButtonClicked method
    connect(ui->closeButton, &QPushButton::clicked, this, &CustomWidget::closeButtonClicked);
}

CustomWidget::~CustomWidget() { }

void CustomWidget::setText(const QString& text)
{
    ui->label->setText(text);
}

QString CustomWidget::getText()
{
    return ui->label->text();
}

void CustomWidget::closeButtonClicked()
{
    emit sendRemoveItem(ui->label->text());
}
