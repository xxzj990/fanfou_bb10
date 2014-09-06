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
    void onLoginResult(QNetworkReply *reply);

public:
    Fanfou(QObject* parent = 0);
    virtual ~Fanfou();

    Q_INVOKABLE bool isLogin();
    Q_INVOKABLE void login(QString username, QString password);
    Q_INVOKABLE void logout();
    Q_INVOKABLE void setAsLogined();

    NetWorker *netWorker;

private:

    /**
     * 解析请求返回
     *
     * 返回空证明请求未成功
     */
    QString getResultString(QNetworkReply *reply);
};

#endif /* FANFOU_H_ */
