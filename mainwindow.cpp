#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "customwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Creates a list of custom widgets
    for (int i = 0; i < 5; ++i) {
        auto item = new QListWidgetItem();

        auto widget = new CustomWidget(this);
        widget->setText(QString("text %1").arg(i));

        item->setSizeHint(widget->sizeHint());

        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, widget);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Removes the item from the list
 */
void MainWindow::removeItem(const QString &text) {

    for (int i = 0; i < ui->listWidget->count(); ++i) {
        auto item = ui->listWidget->item(i);
        auto itemWidget = dynamic_cast<CustomWidget*>(ui->listWidget->itemWidget(item));
        if (itemWidget->getText() == text){
            delete item;
            break;
        }
    }
}

