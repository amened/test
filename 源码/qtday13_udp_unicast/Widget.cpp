#include "Widget.h"
#include "ui_widget.h"

#include <QMessageBox>


/*
 * TCP:传输控制协议
 * 特点:
 * 1、有明确的的客户端和服务器的概念
 * 2、通信前需建立服务器和苦短连接
 * 3、传输时数据的可靠性和安全性高
 *
 * UDP：用户数据包协议
 * 特点：
 * 1、没有明确的客户端与服务端概念
 * 2、是一种轻量级传输协议 当对数据量及速度要求过高时 UDP是较好的选择
 * 3、传输时数据的可靠性和安全性较TCP低
 * 4、有三种通信模式:
 *      (1) 单播 （一台机器只能和一台机器通信）
 *      (2) 组播  （一对一个组中的机器通信）
 *     （3） 广播  （一对局域网中的所有机器通信）
 */
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);
    ui->sendbtn->setEnabled(false);

    //  绑定接受消息信号
    connect(mSocket,&QUdpSocket::readyRead,this,[this](){
        char str[1024] = {0};
        mSocket->readDatagram(str,sizeof(str));

        ui->textEdit->append(str);  // 显示消息
    });


}

Widget::~Widget()
{
    delete ui;
}


// 发送消息
void Widget::on_sendbtn_clicked()
{
    QString ip = ui->ipedit->text();
    int port = ui->portedit->text().toInt();
    QString text = ui->sendEdit->text();        // 发送内容
    mSocket->writeDatagram(text.toUtf8(),QHostAddress(ip),port);

}

// 绑定端口号
void Widget::on_bindbtn_clicked()
{
    int port = ui->portedit->text().toInt();

    // 允许接受自己发出的消息
    bool flag = mSocket->bind(port,QAbstractSocket::ShareAddress);
    if(flag){
        QMessageBox::information(this,"提示","绑定端口成功");
        ui->sendbtn->setEnabled(true);  // 启用发送按钮
        ui->bindbtn->setEnabled(false); //禁用绑定按钮
    }else {
        QMessageBox::information(this,"提示","绑定端口失败");
    }
}


