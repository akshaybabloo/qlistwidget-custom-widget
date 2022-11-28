#include "customwidget.h"
#include "ui_customwidget.h"

CustomWidget::CustomWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomWidget)
{
    ui->setupUi(this);

    connect(this, &CustomWidget::sendRemoveItem, qobject_cast<MainWindow*>(parent), &MainWindow::removeItem);
}

CustomWidget::~CustomWidget()
{
    delete ui;
}

void CustomWidget::setText(const QString &text) {
    ui->label->setText(text);
}

void CustomWidget::on_toolButton_clicked()
{
    emit sendRemoveItem(ui->label->text());
}

QString CustomWidget::getText() {
    return ui->label->text();
}
