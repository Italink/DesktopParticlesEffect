#include "widget.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    Thread *thread=new Thread;

    setGeometry(QApplication::desktop()->screenGeometry());
    initRand();
    initPoint(Config::num);
    connect(thread,&Thread::paintChange,[this](){
        run();
    });
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    //设置阴影距离
    shadow->setOffset(0,0);
    //设置阴影颜色
    QColor c(Config::effectColor);
    c.darker();
    qDebug()<<c<<Config::lineColor;
    shadow->setColor(c);
    //设置阴影圆角
    shadow->setBlurRadius(20);
    //给嵌套QWidget设置阴影
    this->setGraphicsEffect(shadow);
    thread->start();
}

Widget::~Widget()
{

}

void Widget::initPoint(const int &n)
{
    int w=rect().width()/n,
        h=rect().height()/2;

    for(int i=0;i<n;++i){
        points.push_back({w*i,h});
        points.back().setAngle(qrand()%360*PI/180);
        points.back().randRate();
    }
    points[0].setSize(0);
}

void Widget::initRand()
{

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

void Widget::collisionDetection()
{
    for(auto& point : points){
       Point p(point);
       p.run();
       if(p.getX()<0||p.getX()>rect().width()){
           point.reversalX();
       }
       if(p.getY()<0||p.getY()>rect().height()){
           point.reversalY();
       }
    }
}

void Widget::run()
{
    collisionDetection();

    points[0].setX(QCursor::pos().x());
    points[0].setY(QCursor::pos().y());
    for(int i=1;i<points.size();++i)
    {
        points[i].run();
    }
    int x=(lastPos-QCursor::pos()).x(),
        y=(lastPos-QCursor::pos()).y();
    if(sqrt(x*x+y*y)>Config::len_of_link)
    {
        int index=1+qrand()%(points.size()-1);
        points[index].setX(lastPos.x());
        points[index].setY(lastPos.y());
    }
    lastPos=QCursor::pos();
    update();
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    QPen pen;
    pen.setWidthF(1.2);
    painter.setPen(pen);
    QColor c(Config::lineColor);
    c.lighter();
    QPolygon p;
    for(unsigned int i=0;i<points.size();++i){
        for(unsigned int j=i+1;j<points.size();++j){
            if(points[i].getDistance(points[j])<Config::maxLen_of_line){
                c.setAlpha(Config::maxLen_of_line-points[i].getDistance(points[j]));
                pen.setBrush(c);
                painter.setPen(pen);
                painter.drawLine(points[i].getX(),points[i].getY(),points[j].getX(),points[j].getY());      //画线
                c.setAlpha((Config::maxLen_of_line-points[i].getDistance(points[j]))/3);
                painter.setBrush(c);
                for(int k=j+1;k<points.size();++k){
                    if(points[k].getDistance(points[i])<Config::maxLen_of_line&&points[k].getDistance(points[j])<Config::maxLen_of_line){
                        p.setPoints(3,int(points[i].getX()),int(points[i].getY()),int(points[j].getX()),int(points[j].getY()),int(points[k].getX()),int(points[k].getY()));
                        painter.drawPolygon(p);                                 //画三角形
                    }
                }
            }

        }

        painter.setBrush(QColor(252,251,243));
        painter.setPen(Qt::NoPen);
        if(i)           //画点，第一个点用作鼠标
            painter.drawEllipse(points[i].getRect());
    }

}

