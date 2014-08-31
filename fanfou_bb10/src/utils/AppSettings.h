/*
 * AppSettings.h
 *
 *  Created on: 2014年8月29日
 *      Author: liulei
 */

#ifndef APPSETTINGS_H_
#define APPSETTINGS_H_

#include <QObject>

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
};

#endif /* APPSETTINGS_H_ */
