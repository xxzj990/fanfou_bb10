/*
 * Fanfou.h
 *
 *  Created on: 2014年8月30日
 *      Author: liulei
 */

#ifndef FANFOU_H_
#define FANFOU_H_

#include <src/utils/Networker.h>
#include <QObject>
#include <QNetworkReply>

class Fanfou : public QObject
{
    Q_OBJECT

Q_SIGNALS:
    void loginSuccess(QString msg);
    void loginFailed(QString msg);

private Q_SLOTS:
    void onGetReply(QNetworkReply *reply);

public:
    Fanfou(QObject* parent = 0);
    virtual ~Fanfou();

    Q_INVOKABLE bool isLogin();
    Q_INVOKABLE void login();
    Q_INVOKABLE void logout();

    NetWorker *netWorker;
};

#endif /* FANFOU_H_ */
