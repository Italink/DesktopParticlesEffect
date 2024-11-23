#include "point.h"

Point::Point()
{

}

Point::Point(const double &x,const  double &y)
    : size(Config::pointSize)
{
    this->x=x;
    this->y=y;
}

double Point::getY() const
{
    return y;
}

void Point::setY(double value)
{
    y = value;
}

double Point::getX() const
{
    return x;
}

void Point::setX(double value)
{
    x = value;
}

double Point::getRate() const
{
    return rate;
}

void Point::setRate(double value)
{
    rate = value;
}

void Point::run()
{
    x=x+rate*angle[0];
    y=y+rate*angle[1];
}

double Point::getDistance(Point &p)
{
    return sqrt(pow(x-p.x,2)+pow(y-p.y,2));
}

QRectF Point::getRect()
{
    double r=(Config::pointSize*rate-Config::minRate)/(Config::len_of_rate);
    return {x-r/2,y-r/2,r,r};
}

double Point::getAngle() const
{
    return asin(angle[0]);
}

void Point::setAngle(double value)
{
    angle[0] = cos(value);
    angle[1] = sin(value);
}

void Point::reversalX()
{
    angle[0]*=-1;
    randRate();
}

void Point::reversalY()
{
    angle[1]*=-1;
    randRate();
}

void Point::randRate()
{
    rate=Config::minRate+qrand()%int(Config::len_of_rate*10)/10.0;
}


double Point::getSize() const
{
    return size;
}

void Point::setSize(double value)
{
    size = value;
}
