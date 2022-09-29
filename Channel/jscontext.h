#ifndef JSCONTEXT_H
#define JSCONTEXT_H

#include <QObject>

class JsContext : public QObject
{
    Q_OBJECT
public:
    explicit JsContext(QObject *parent = nullptr);

signals:
    // 初始化完成
    void sgl_init_channel_finished();

    // add chart
    void sgl_load_new_chart(const QString &name);

public slots:
    void recvMsg(const QString &action, const QString &status, const QString &message);
};

#endif // JSCONTEXT_H
