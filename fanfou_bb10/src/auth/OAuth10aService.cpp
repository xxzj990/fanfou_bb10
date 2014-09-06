/*
 * OAuth10aService.cpp
 *
 *  Created on: 2014年9月6日
 *      Author: liulei
 */

#include <QString>
#include <QDateTime>
#include <QDebug>
#include "oauth10aservice.h"
#include "mynetworkrequest.h"
#include "basestringextractor.h"
#include "hmacsha1signature.h"
#include "oauthtoken.h"
#include "headerextractor.h"

OAuth10aService::OAuth10aService(QObject *parent) :
    QObject(parent)
{
}

MyNetworkRequest OAuth10aService::getTokenRequest(QString username, QString password) {
    MyNetworkRequest request;

    // method
    request.setVerb(GET);

    // URL
    request.setUrl(QUrl("http://fanfou.com/oauth/access_token"));

    // add XAuth Params
    request.addParameter(X_AUTH_USERNAME, username);
    request.addParameter(X_AUTH_PASSWORD, password);
    request.addParameter(X_AUTH_MODE, "client_auth");
    request.addParameter(TIMESTAMP, getTimestampInSeconds());
    request.addParameter(NONCE, getNonce());
    request.addParameter(CONSUMER_KEY, getApiKey());
    request.addParameter(SIGN_METHOD, getSignatureMethod());
    request.addParameter(VERSION, getVersion());
    request.addParameter(SIGNATURE, getSignature(request, OAuthToken()));

    // add Header
    HeaderExtractor extrator;
    QString headerKey = HEADER;
    QString header = extrator.extract(request);
    request.setRawHeader(headerKey.toUtf8(), header.toUtf8());

    return request;
}

void OAuth10aService::signRequest(MyNetworkRequest request, OAuthToken token) {

    // add Token
    request.addParameter(TOKEN, token.getToken());

    // add OAuth Params
    request.addParameter(TIMESTAMP, getTimestampInSeconds());
    request.addParameter(NONCE, getNonce());
    request.addParameter(CONSUMER_KEY, getApiKey());
    request.addParameter(SIGN_METHOD, getSignatureMethod());
    request.addParameter(VERSION, getVersion());
    request.addParameter(SIGNATURE, getSignature(request, token));

    // add Header
    HeaderExtractor extrator;
    QString headerKey = HEADER;
    QString header = extrator.extract(request);
    request.setRawHeader(headerKey.toUtf8(), header.toUtf8());
}

QString OAuth10aService::getTimestampInSeconds() {
    // 当前毫秒值除以1000（Java）,QT的currentDateTime直接返回的时间到秒
    return QString::number(QDateTime::currentDateTime().toTime_t());
}

QString OAuth10aService::getNonce() {
    qsrand(QDateTime::currentMSecsSinceEpoch());
    return QString::number(qrand() + QDateTime::currentDateTime().toTime_t());
}

QString OAuth10aService::getApiKey() {
    return "e5dd03165aebdba16611e1f4849ce2c3";
}

QString OAuth10aService::getApiSecret() {
    return "2a14fcbdebfb936a769840b4d5a9263b";
}

QString OAuth10aService::getSignatureMethod() {
    return "HMAC-SHA1";
}

QString OAuth10aService::getVersion() {
    return "1.0";
}

QString OAuth10aService::getSignature(MyNetworkRequest request, OAuthToken token) {
    // Base string
    BaseStringExtractor extractor;
    QString basestring = extractor.extract(request);

    qDebug() << "     Base string:" << basestring;

    // Signature string
    HMACSha1Signature signtool;
    QString result = signtool.getSignature(basestring, getApiSecret(), token.getSecret());

    qDebug() << "Signature string:" << result;

    return result;
}

