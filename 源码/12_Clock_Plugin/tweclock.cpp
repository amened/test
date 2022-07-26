#include "tweclock.h"

TweClock::TweClock(QWidget *parent) :
    QWidget(parent)
{

}


TweClock::~TweClock()
{
}

//重写绘制事件函数
void TweClock::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);//设置抗锯齿
    Draw_Clock(&painter);
}

//初始化参数函数,使用系统默认时间
void TweClock::Init_Parameter()
{
//    Center_pos = QPoint(this->width()/2,this->height()/2);//以窗体中心为圆心
//    R_Edge = this->height()/2;//以窗体高度的一半为半径

    Center_pos = QPoint(200,200);      //以窗体中心为圆心
    R_Edge = 200;     //以窗体高度的一半为半径,外部圆半径
    R_Inside = R_Edge-10;   //内部圆半径
    R_Center = 15;      //中心小圆半径
    R_Pointer = 6;      //中心指针圆半径
}

//初始化参数函数,使用系统默认时间
void TweClock::SetTime(QTime time)
{
    H=time.hour();//分别设置时、分、秒
    M=time.minute();
    S=time.second();
    repaint();
}


//设置窗体透明
void TweClock::Set_Mask(QPainter *painter)
{
    painter->save();//保存

    QBrush brush = QBrush(Qt::transparent);//设置画刷为透明
    painter->setBrush(brush);
    painter->fillRect(this->rect(),QColor(0,0,0,0));

    painter->restore();//恢复
}

//绘制时钟
void TweClock::Draw_Clock(QPainter *painter)
{
    Init_Parameter();
    Set_Mask(painter);

    Draw_Broad(painter);
    Draw_Dial(painter);
    Draw_Text(painter);
    Draw_Pointer(painter);
}

//绘制时钟盘
void TweClock::Draw_Broad(QPainter *painter)
{
    painter->save();

    QBrush brush = QBrush(Color_Edge);//绘制外部圆
    painter->setBrush(brush);
    painter->drawEllipse(Center_pos,R_Edge,R_Edge);

    brush = QBrush(Color_Inside);//绘制内部圆
    painter->setBrush(brush);
    painter->drawEllipse(Center_pos,R_Inside,R_Inside);

    brush = QBrush(Color_Center);//绘制中心小圆
    painter->setBrush(brush);
    painter->drawEllipse(Center_pos,R_Center,R_Center);

    painter->restore();
}

//绘制刻度盘
void TweClock::Draw_Dial(QPainter *painter)
{
    painter->save();

    for(int Loop = 0; Loop <= Div_Max*Div_Min; Loop++)
    {
        float Angle = BaseAngle + (360 / (Div_Max * Div_Min))*Loop;//从基础仰角开始绘制的每条刻度线对应的角度
        int R = R_Inside-1;
        int x_start = Center_pos.x() + R * cos((Angle / 180) * PI);
        int y_start = Center_pos.y() + R * sin((Angle / 180) * PI);

        if(Loop % Div_Min == 0)//判断是否为大刻度
        {
            QPen pen(Qt::black);
            pen.setWidth(4);
            painter->setPen(pen);
            R = R_Inside-20;
        }
        else  //判断是否为小刻度
        {
            QPen pen(Qt::black);
            pen.setWidth(2);
            painter->setPen(pen);
            R = R_Inside-15;
        }

        int x_end = Center_pos.x() + R * cos((Angle / 180) * PI);
        int y_end = Center_pos.y() + R * sin((Angle / 180) * PI);

        painter->drawLine(QPoint(x_start,y_start),QPoint(x_end,y_end));//绘制刻度线
    }


    painter->restore();
}

//绘制刻度值
void TweClock::Draw_Text(QPainter *painter)
{
    painter->save();

    QPen qPen(Qt::black);
    qPen.setWidth(5);   //设置画笔的粗细
    painter->setPen(qPen);
    QFont qFont("楷体",28,QFont::Bold,false);
    painter->setFont(qFont);

    int Dial_Text = 12;
    for(int Loop = 0;Loop < Div_Max;Loop++)
    {
        if(Dial_Text >12 )
            Dial_Text = 1;
        int R = R_Inside-60;
        float Angle = BaseAngle + (360 / Div_Max )*Loop;
        int x = Center_pos.x() + R * cos((Angle / 180) * PI);
        int y = Center_pos.y() + R * sin((Angle / 180) * PI);

        painter->drawText(QRect(x-20,y-20,80,80),QString::number(Dial_Text++));
    }
    if(H >= 0 && H <=13){
         painter->drawText(Center_pos.x()-20,Center_pos.y()-20,QStringLiteral("上午"));
    }
    else {
        painter->drawText(Center_pos.x()-20,Center_pos.y()-20,QStringLiteral("下午"));
    }

    painter->restore();
}


//绘制指针
void TweClock::Draw_Pointer(QPainter *painter)
{
    painter->save();

    QBrush qBrush = QBrush(QColor(Qt::black));
    painter->setBrush(qBrush);
    QPen qPen(Qt::black);
    qPen.setWidth(2);   //设置画笔的粗细
    painter->setPen(qPen);
//**********绘制秒针***********************************************************************************
    float Angle = BaseAngle + (360 / (Div_Max * Div_Min))*S;
    float RightAngle = Angle + 90;//右侧角度
    float LeftAngle = Angle - 90;//左侧角度
    int R = R_Inside-1;
    int x_start = Center_pos.x() + R * cos((Angle / 180) * PI);
    int y_start = Center_pos.y() + R * sin((Angle / 180) * PI);

    R = R_Pointer-1;
    int x_end1 = Center_pos.x() + R * cos(RightAngle * 3.14 / 180);//过圆心的右侧切点
    int y_end1 = Center_pos.y() + R * sin(RightAngle * 3.14 / 180);
    int x_end2 = Center_pos.x() + R * cos(LeftAngle * 3.14 / 180);//过圆心的左侧切点
    int y_end2 = Center_pos.y() + R * sin(LeftAngle * 3.14 / 180);

    QPointF qTriangle_S[3] = {QPoint(x_start,y_start),QPoint(x_end1,y_end1),QPoint(x_end2,y_end2)};
    painter->drawPolygon(qTriangle_S,3);
//**********绘制分针***********************************************************************************
    Angle = BaseAngle + (360 / (Div_Max * Div_Min))*M;
    RightAngle = Angle + 90;//右侧角度
    LeftAngle = Angle - 90;//左侧角度
    R = R_Inside-60;
    x_start = Center_pos.x() + R * cos((Angle / 180) * PI);
    y_start = Center_pos.y() + R * sin((Angle / 180) * PI);

    R = R_Pointer-1;
    x_end1 = Center_pos.x() + R * cos(RightAngle * 3.14 / 180);//过圆心的右侧切点
    y_end1 = Center_pos.y() + R * sin(RightAngle * 3.14 / 180);
    x_end2 = Center_pos.x() + R * cos(LeftAngle * 3.14 / 180);//过圆心的左侧切点
    y_end2 = Center_pos.y() + R * sin(LeftAngle * 3.14 / 180);

    QPointF qTriangle_M[3] = {QPoint(x_start,y_start),QPoint(x_end1,y_end1),QPoint(x_end2,y_end2)};
    painter->drawPolygon(qTriangle_M,3);
//**********绘制时针***********************************************************************************
    Angle = BaseAngle + (360 / Div_Max)*H;
    RightAngle = Angle + 90;//右侧角度
    LeftAngle = Angle - 90;//左侧角度
    R = R_Inside-120;
    x_start = Center_pos.x() + R * cos((Angle / 180) * PI);
    y_start = Center_pos.y() + R * sin((Angle / 180) * PI);

    R = R_Pointer-1;
    x_end1 = Center_pos.x() + R * cos(RightAngle * 3.14 / 180);//过圆心的右侧切点
    y_end1 = Center_pos.y() + R * sin(RightAngle * 3.14 / 180);
    x_end2 = Center_pos.x() + R * cos(LeftAngle * 3.14 / 180);//过圆心的左侧切点
    y_end2 = Center_pos.y() + R * sin(LeftAngle * 3.14 / 180);

    QPointF qTriangle_H[3] = {QPoint(x_start,y_start),QPoint(x_end1,y_end1),QPoint(x_end2,y_end2)};
    painter->drawPolygon(qTriangle_H,3);

    painter->restore();
}
