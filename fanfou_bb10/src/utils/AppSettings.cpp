/*
 * AppSettings.cpp
 *
 *  Created on: 2014年8月29日
 *      Author: liulei
 */

#include <src/utils/AppSettings.h>
#include <src/utils/const.h>
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
    return getBool("isLogined");
}

void AppSettings::setAsLogined() {
    saveBool("isLogined", true);
}

void AppSettings::removeLogin() {
    saveBool("isLogined", false);
}
