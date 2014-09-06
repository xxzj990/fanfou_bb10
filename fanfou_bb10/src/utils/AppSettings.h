/*
 * AppSettings.h
 *
 *  Created on: 2014年8月29日
 *      Author: liulei
 */

#ifndef APPSETTINGS_H_
#define APPSETTINGS_H_

#include <QObject>
#include <src/auth/oauthtoken.h>

class AppSettings : public QObject
{
    Q_OBJECT
public:
    static void save(QString key, QString value);
    static QString get(QString key);

    static void saveBool(QString key, bool value);
    static bool getBool(QString key);

    static bool isLogined();
    static void setAsLogined();
    static void removeLogin();

    static void saveToken(OAuthToken token);
    static OAuthToken getToken();
};

#endif /* APPSETTINGS_H_ */
