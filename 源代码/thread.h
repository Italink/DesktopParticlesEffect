#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = nullptr);
protected:
    void run();

signals:
    void paintChange();
public slots:
};

#endif // THREAD_H
