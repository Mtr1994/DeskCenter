#include "jscontext.h"
#include "Public/appsignal.h"

// test
#include <QDebug>

JsContext::JsContext(QObject *parent)
    : QObject{parent}
{

}

void JsContext::recvMsg(const QString &action, const QString &status, const QString &message)
{
     qDebug() << "recvMsg " << status << " " << message;

     if ((action == "init") && (action == "init"))
     {
         emit sgl_init_channel_finished();
     }
}
