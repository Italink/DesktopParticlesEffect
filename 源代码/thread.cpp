#include "thread.h"
#include <QDebug>
Thread::Thread(QObject *parent) : QThread (parent)
{

}

void Thread::run()
{
    while (true) {
        msleep(30);
        emit paintChange();
    }
}
