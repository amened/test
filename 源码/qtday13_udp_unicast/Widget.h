#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_bindbtn_clicked();
    void on_sendbtn_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket* mSocket;
};

#endif // WIDGET_H
