#include "Widget.h"
#include "ui_widget.h"

#include <QDateTime>
#include <QHostInfo>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);
    //
    mSocket->bind(QHostAddress::AnyIPv4,9966,QAbstractSocket::ShareAddress);

    // 设置ttl为64
    mSocket->setSocketOption(QAbstractSocket::MulticastTtlOption,QVariant(64));
    ui->leavebtn->setEnabled(false);

    //  绑定接受消息信号
    connect(mSocket,&QUdpSocket::readyRead,this,[this](){
        // 判断是否有数据报
        while (mSocket->hasPendingDatagrams()) {
            char str[1024] = {0};
            mSocket->readDatagram(str,sizeof(str));
            QString date = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss dddd");
            ui->textEdit->append(date+'\n'+ str);  // 显示消息
        }

    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_joinbtn_clicked()
{
    // 注意:UDP预留组播地址 例如:239.0.0.0-239.255.255.255
    // 还存在别的地址
    QString groupIp = ui->groupip->text();  // 组播地址
    bool flag = mSocket->joinMulticastGroup(QHostAddress(groupIp));

    if(flag){
        //
        QMessageBox::information(this,"提示","加入组播成功");
        isinGroup = true;
        ui->leavebtn->setEnabled(true);
        ui->joinbtn->setEnabled(false);
    }else {
        QMessageBox::information(this,"提示","加入组播失败");
    }
}

void Widget::on_leavebtn_clicked()
{
    // 组播地址
    QString groupIp = ui->groupip->text();
    bool flag = mSocket->leaveMulticastGroup(QHostAddress(groupIp));
    if(flag){
        //
        QMessageBox::information(this,"提示","退出组播成功");
        ui->leavebtn->setEnabled(false);
        ui->joinbtn->setEnabled(true);
        isinGroup = false;
    }else {
        QMessageBox::information(this,"提示","退出组播失败");
    }
}


void Widget::on_sendbtn_clicked()
{
    if(!isinGroup){
        return;
    }
    QString text = QHostInfo::localHostName() + ":" + ui->sendedit->text();
    QString groupIP = ui->groupip->text();
    mSocket->writeDatagram(text.toUtf8(),QHostAddress(groupIP),9966);
}
