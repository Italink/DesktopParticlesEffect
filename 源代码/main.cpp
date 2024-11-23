#include "bgwidget.h"
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BgWidget w;
    w.show();

    return a.exec();
}
