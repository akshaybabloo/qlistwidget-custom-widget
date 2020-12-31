#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>

namespace Ui {
class CustomWidget;
}

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomWidget(QWidget *parent = nullptr);
    ~CustomWidget();

    void setText(const QString &text);
    QString text();

signals:
    void sendRemoveItem(const QString &text);

private slots:
    void on_toolButton_clicked();

private:
    Ui::CustomWidget *ui;
};

#endif // CUSTOMWIDGET_H
