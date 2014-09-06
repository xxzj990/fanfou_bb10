/*
 * TokenExtractor.cpp
 *
 *  Created on: 2014年9月7日
 *      Author: liulei
 */

#include <src/auth/TokenExtractor.h>
#include "oauthtoken.h"

TokenExtractor::TokenExtractor(QObject *parent) :
    QObject(parent)
{
}

OAuthToken TokenExtractor::extract(QString raw) {

    QString pattern(TOKEN_REGEX);
    QRegExp rx(pattern);

    QString token = extract(raw, rx);

    QString pattern1(SECRET_REGEX);
    QRegExp rx1(pattern1);

    QString secret = extract(raw, rx1);

    OAuthToken tokenObj;
    tokenObj.setToken(token);
    tokenObj.setSecret(secret);
    tokenObj.setRawResponse(raw);

    return tokenObj;
}

QString TokenExtractor::extract(QString raw, QRegExp rx) {
    int pos = rx.indexIn(raw);
    if(pos > -1) {
        return rx.cap(1);
    }
    return "";
}
