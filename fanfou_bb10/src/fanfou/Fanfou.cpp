/*
 * Fanfou.cpp
 *
 *  Created on: 2014年8月30日
 *      Author: liulei
 */

#include "Fanfou.h"

#include <src/utils/AppSettings.h>
#include <src/utils/log.h>
#include <src/auth/HMACSha1Signature.h>
#include <src/auth/OAuth10aService.h>
#include <src/auth/TokenExtractor.h>
#include <src/auth/OAuthToken.h>
#include <bb/cascades/QmlDocument>
#include <QNetworkRequest>
#include <QByteArray>
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
}

bool Fanfou::isLogin()
{
    return AppSettings::isLogined();
}

void Fanfou::login(QString username, QString password)
{
    if(username.isEmpty() || password.isEmpty()) {
        Log::d("login request username or password is empty.");
        return;
    }

    QString msg = "login with username: ";
    msg.append(username).append(";password: ").append(password);
    Log::d(msg);

    OAuth10aService service;
    MyNetworkRequest request = service.getTokenRequest(username, password);

    connect(netWorker, SIGNAL(finished(QNetworkReply*)), this, SLOT(onLoginResult(QNetworkReply*)));
    netWorker->doSend(request);
}

void Fanfou::logout()
{
    AppSettings::removeLogin();
}

void Fanfou::setAsLogined()
{
    AppSettings::setAsLogined();
}

QString Fanfou::getResultString(QNetworkReply *reply) {
    QString response = "";
    if (reply) {
        if (reply->error() == QNetworkReply::NoError) {
            const int available = reply->bytesAvailable();
            if (available > 0) {
                const QByteArray buffer(reply->readAll());
                response = QString::fromUtf8(buffer);
            }
        } else {
            QString error;
            error.append("Code:").append(QString::number(reply->error())).append(";Message:").append(reply->errorString());
            Log::d(error);
        }

        reply->deleteLater();
    }

    if (response.trimmed().isEmpty()) {
        response = "";
    }
    return response;
}

void Fanfou::onLoginResult(QNetworkReply *reply)
{
    disconnect(netWorker, SIGNAL(finished(QNetworkReply*)), this, SLOT(onLoginResult(QNetworkReply*)));

    QString response = getResultString(reply);

    if(response.isEmpty()) {
        Log::d("empty response error");
        emit loginFailed("error");
    } else {
        Log::d("login response:" + response);

        // 储存token
        TokenExtractor extractor;
        OAuthToken token = extractor.extract(response);
        if(!token.isVaild()) {
            Log::d("empty token error");
            emit loginFailed("error");
            return;
        } else {
            AppSettings::saveToken(token);
        }

        // 获取用户信息

        emit loginSuccess(response);
    }

}
