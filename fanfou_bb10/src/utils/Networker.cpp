/*
 * Networker.cpp
 *
 *  Created on: 2014年9月1日
 *      Author: liulei
 */

#include "Networker.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

/**
 * @brief The NetWorker::Private class 内部辅助类
 */
class NetWorker::Private
{
public:
    Private(NetWorker *q) :
            manager(new QNetworkAccessManager(q))
    {
    }

    QNetworkAccessManager *manager;
};

/**
 * @brief NetWorker::instance 获取单例对象方法
 * @return
 */
NetWorker *NetWorker::instance()
{
    static NetWorker netWorker;
    return &netWorker;
}

/**
 * @brief NetWorker::NetWorker 构造函数
 * @param parent
 */
NetWorker::NetWorker(QObject *parent) :
        QObject(parent), d(new NetWorker::Private(this))
{
//    connect(d->manager, SIGNAL(finished(QNetworkReply*), this, SLOT(finished(QNetworkReply*)));
    connect(d->manager, SIGNAL(finished(QNetworkReply*)), this, SIGNAL(finished(QNetworkReply*)));
}

/**
 * @brief NetWorker::~NetWorker 析构函数
 */
NetWorker::~NetWorker()
{
    delete d;
    d = 0;
}

/**
 * @brief NetWorker::get GET请求
 * @param url
 */
void NetWorker::get(const QString &url)
{
    d->manager->get(QNetworkRequest(QUrl(url)));
}

void NetWorker::doSend(MyNetworkRequest &request) {
    if(request.getVerb() == GET) {
        QString url = getCompleteUrl(request);
        request.setUrl(QUrl(url));
        d->manager->get(request);
        qDebug() << "send with get";
    } else if(request.getVerb() == POST) {
        d->manager->post(request, "body");
        qDebug() << "send with post";
    } else {
        qDebug() << "not send with other";
    }
}

QString NetWorker::getCompleteUrl(MyNetworkRequest &request) {
    QString rawUrl = request.url().toString();
    QList<Parameter*> params = request.getParameters();

    QString comParam;
    for(int i=0; i<params.size(); i++) {
        Parameter *param = params.at(i);
        comParam.append('&').append(param->asUrlEncodedPair());
    }
    comParam = comParam.right(comParam.length()-1);

    rawUrl.append('?').append(comParam);
    return rawUrl;
}

