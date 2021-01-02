#include "customwidget.h"
#include "ui_customwidget.h"

CustomWidget::CustomWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomWidget)
{
    ui->setupUi(this);

    connect(this, SIGNAL(sendRemoveItem(const QString &)), parent, SLOT(removeItem(const QString &)));
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
