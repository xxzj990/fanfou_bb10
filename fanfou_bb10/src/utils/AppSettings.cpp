/*
 * AppSettings.cpp
 *
 *  Created on: 2014年8月29日
 *      Author: liulei
 */

#include "AppSettings.h"
#include "const.h"

#include <src/auth/oauthtoken.h>
#include <src/auth/oauth10aservice.h>
#include <QString>
#include <QSettings>

void AppSettings::save(QString key, QString value)
{
    if (key.isEmpty() && value.isEmpty()) {
        return;
    }

    QSettings data(APP_COMPNEY, APP_NAME);
    data.setValue(key, value);
}

QString AppSettings::get(QString key)
{
    if (key.isEmpty()) {
        return "";
    }

    QSettings data(APP_COMPNEY, APP_NAME);
    QString value = data.value(key, "").toString();
    return value;
}

void AppSettings::saveBool(QString key, bool value)
{
    if (key.isEmpty()) {
        return;
    }

    QSettings data(APP_COMPNEY, APP_NAME);
    data.setValue(key, value);
}

bool AppSettings::getBool(QString key)
{
    if (key.isEmpty()) {
        return "";
    }

    QSettings data(APP_COMPNEY, APP_NAME);
    bool value = data.value(key, false).toBool();
    return value;
}

bool AppSettings::isLogined() {
    return getToken().isVaild();
}

void AppSettings::setAsLogined() {
    saveBool("isLogined", true);
}

void AppSettings::removeLogin() {
    saveBool("isLogined", false);
}

void AppSettings::saveToken(OAuthToken token) {
    save(TOKEN, token.getToken());
    save(TOKEN_SECRET, token.getSecret());
    save("token_json", token.getRawResponse());
}

OAuthToken AppSettings::getToken() {
    OAuthToken token;
    token.setToken(get(TOKEN));
    token.setSecret(get(TOKEN_SECRET));
    token.setRawResponse(get("token_json"));
    return token;
}
