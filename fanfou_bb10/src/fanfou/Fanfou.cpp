/*
 * Fanfou.cpp
 *
 *  Created on: 2014年8月30日
 *      Author: liulei
 */

#include <src/fanfou/Fanfou.h>
#include <src/utils/AppSettings.h>
#include <src/utils/log.h>
#include <src/utils/Networker.h>
#include <bb/cascades/QmlDocument>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QByteArray>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QSslConfiguration>
#include <QUrl>

Fanfou::~Fanfou()
{
}

Fanfou::Fanfou(QObject* parent) :
        QObject(parent)
{
    netWorker = NetWorker::instance();
    connect(netWorker, SIGNAL(finished(QNetworkReply*)), this, SLOT(onGetReply(QNetworkReply*)));
}

bool Fanfou::isLogin()
{
    return AppSettings::isLogined();
}

void Fanfou::login()
{
    AppSettings::setAsLogined();

    netWorker->get("http://www.baidu.com");
}

void Fanfou::logout()
{
    AppSettings::removeLogin();
}

void Fanfou::onGetReply(QNetworkReply *reply)
{
    QString response;
    if (reply) {
        if (reply->error() == QNetworkReply::NoError) {
            const int available = reply->bytesAvailable();
            if (available > 0) {
                const QByteArray buffer(reply->readAll());
                response = QString::fromUtf8(buffer);
            }
        } else {
            response = "Error";
            qDebug() << response;
        }

        reply->deleteLater();
    }

    if (response.trimmed().isEmpty()) {
        response = "Unable to retrieve post response";
    }
    Log::d("Login process finish.");
    emit loginSuccess(response);
}
