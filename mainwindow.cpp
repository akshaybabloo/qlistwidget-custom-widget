#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "customwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font;
    font.setPixelSize(1); // this can't be zero

    // Creates a list of custom widgets
    for (int i = 0; i < 5; ++i) {
        auto item = new QListWidgetItem();

        auto widget = new CustomWidget(this);
        auto text = QString("text %1").arg(i);
        widget->setText(text);
        widget->setObjectName(QString("object %1").arg(i));

        item->setSizeHint(widget->sizeHint());
        item->setText(text); // this super-imposes on the custom widget
        item->setFont(font); // to make the text very small

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
    qDebug() << text;
    auto item = ui->listWidget->findItems(text, Qt::MatchExactly).last(); // I cannot use this unless I set #L23
    delete ui->listWidget->takeItem(ui->listWidget->row(item));
}

