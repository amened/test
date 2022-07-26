#ifndef TWECLOCK_H
#define TWECLOCK_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QtMath>
#include <QTimer>
#include <QTime>
#include <QDebug>
#define PI 3.14
namespace Ui {
class TweClock;
}

class TweClock : public QWidget
{
    Q_OBJECT

public:
    explicit TweClock(QWidget *parent = nullptr);
    ~TweClock();
    void paintEvent(QPaintEvent *event);//重写绘制事件函数
    void Init_Parameter();//初始化参数函数
    void Init_Parameter(QTime time);//初始化参数函数,使用自定义时间
    void Set_Mask(QPainter *painter);//设置窗体透明
    void Draw_Clock(QPainter *painter);//绘制时钟
    void Draw_Broad(QPainter *painter);//绘制时钟盘
    void Draw_Dial(QPainter *painter);//绘制刻度盘
    void Draw_Text(QPainter *painter);//绘制刻度值
    void Draw_Pointer(QPainter *painter);//绘制指针


private:
    Ui::TweClock *ui;
    QTimer *timer;//定时器
    QPoint Center_pos;//时钟圆心坐标
    int R_Edge;//外部圆半径
    int R_Inside;//内部圆半径
    int R_Center;//中心小圆半径
    int R_Pointer;//中心指针圆半径
    QColor Color_Edge = QColor(0,0,0,255);//外部圆颜色
    QColor Color_Inside = QColor(255,255,255,255);//内部圆颜色
    QColor Color_Center = QColor(0,0,0,255);//中心小圆颜色
    int Div_Max = 12;//大刻度值
    int Div_Min = 5;//小刻度值
    float BaseAngle = 270;//基础仰角
    int H;//时
    int M;//分
    int S ;//秒
};

#endif // TWECLOCK_H
