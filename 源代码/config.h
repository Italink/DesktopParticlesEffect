#ifndef CONFIG_H
#define CONFIG_H

#include <QColor>

namespace Config {
    const int num = 100;        //点的个数
    const double pointSize=6;   //点(圆)的像素大小
    const double maxLen_of_line=100;    //两点的距离小于此值时连线
    const double len_of_rate=2.5;       //点的运动速度范围（20ms移动多少像素）
    const double minRate=0.5;           //点的最小运动速度
    const QColor lineColor(85,171,228); //线的颜色
    const QColor effectColor(0,0,255);  //阴影的颜色
    const double len_of_link=20;        //鼠标移动时，目前位置与20ms前的位置的距离如果大于此值，将一个点移动到历史位置
}

#endif // CONFIG_H
