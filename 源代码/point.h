#ifndef POINT_H
#define POINT_H

#include <QRectF>
#include <math.h>
#include <config.h>
class Point
{
public:
    Point();
    Point(const double& x,const double& y);
    double getY() const;
    void setY(double value);

    double getX() const;
    void setX(double value);

    double getRate() const;
    void setRate(double value);


    double getSize() const;
    void setSize(double value);

    void run();
    double getDistance(Point& p);      //计算两点间的距离
    QRectF getRect();                   //获取显示矩形，也就是点（圆）

    double getAngle() const;
    void setAngle(double value);        //修改角度
    void reversalX();                   //反转水平角度
    void reversalY();                   //反转垂直角度
    void randRate();                    //设置随机速度
private:

    double x;
    double y;
    double rate;        //速度
    double angle[2];    //角度的x y分量
    double size;        //大小
};

#endif // POINT_H
