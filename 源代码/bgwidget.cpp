#include "bgwidget.h"
#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>

BgWidget::BgWidget(QWidget *parent) : QWidget(parent)
{  
    this->setAttribute(Qt::WA_TransparentForMouseEvents,true);                   //设置鼠标穿透 注意：这条语句必须放在最前
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);      //设置为无边框窗口
    this->setAttribute(Qt::WA_TranslucentBackground);                            //设置背景透明
    setGeometry(QApplication::desktop()->screenGeometry());                      //设置窗口大小为屏幕大小
    Widget *ww=new Widget(this);
}
