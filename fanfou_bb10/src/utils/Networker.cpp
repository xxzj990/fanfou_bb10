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

