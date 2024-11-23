#ifndef WIDGET_H
#define WIDGET_H

#include "point.h"
#include "config.h"
#include <QTime>
#include <QWidget>
#include <vector>
#include <QDebug>
#include <QTimer>
#include <qevent.h>
#include "thread.h"
using namespace  std;
const double PI=3.1415926535;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    vector<Point> points;
    QSize winSize;
    QPoint lastPos;
    void initPoint(const int& n);   //初始化点

    void initRand();                //初始化随机数种子

    void collisionDetection();      //碰撞检测

    void run();
protected:
    void paintEvent(QPaintEvent *e);
};

#endif // WIDGET_H
