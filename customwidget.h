#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>

namespace Ui {
class CustomWidget;
}

class CustomWidget : public QWidget {
    Q_OBJECT

public:
    explicit CustomWidget(QWidget* parent = nullptr);
    ~CustomWidget();

    void setText(const QString& text);
    QString getText();

signals:
    void sendRemoveItem(const QString& text);

private slots:
    void closeButtonClicked();

private:
    std::unique_ptr<Ui::CustomWidget> ui;
};

#endif // CUSTOMWIDGET_H
