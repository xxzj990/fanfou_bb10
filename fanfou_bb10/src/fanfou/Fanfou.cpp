/*
 * Fanfou.cpp
 *
 *  Created on: 2014年8月30日
 *      Author: liulei
 */

#include "Fanfou.h"

#include <src/utils/AppSettings.h>
#include <src/utils/log.h>
#include <src/utils/HMACSha1Signature.h>
#include <bb/cascades/QmlDocument>
#include <QNetworkRequest>
#include <QByteArray>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QSslConfiguration>
#include <QUrl>
#include <QString>

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

    HMACSha1Signature signer;
    QString result = signer.getSignature("http://api.fanfou.com", "dscadcadacsdcadscasd", "vasdrafaw3easddscasdc");

    qDebug() << result;

    netWorker->get("http://api.fanfou.com/statuses/public_timeline.json");
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
            response = "Error:" + reply->errorString();
            qDebug() << response;
            qDebug() << "Code:" << reply->error();
        }

        reply->deleteLater();
    }

    if (response.trimmed().isEmpty()) {
        response = "Unable to retrieve post response";
    }
    Log::d("Login process finish.");
    emit loginSuccess(response);
}
