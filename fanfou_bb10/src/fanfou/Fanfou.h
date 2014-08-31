/*
 * Fanfou.h
 *
 *  Created on: 2014年8月30日
 *      Author: liulei
 */

#ifndef FANFOU_H_
#define FANFOU_H_

#include <QObject>
#include <QString>

class Fanfou : public QObject
{
    Q_OBJECT

Q_SIGNALS:
    void loginSuccess(QString msg);
    void loginFailed(QString msg);

public:
    virtual ~Fanfou();
    Fanfou();

    Q_INVOKABLE bool isLogin();
    Q_INVOKABLE void login();
    Q_INVOKABLE void logout();


};

#endif /* FANFOU_H_ */
