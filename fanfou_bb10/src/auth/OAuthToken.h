/*
 * OAuthToken.h
 *
 *  Created on: 2014年9月6日
 *      Author: liulei
 */

#ifndef OAUTHTOKEN_H
#define OAUTHTOKEN_H

#include <QObject>

class OAuthToken
{
public:
    explicit OAuthToken();

    void setToken(QString token);
    QString getToken();

    void setSecret(QString secret);
    QString getSecret();

    void setExpiresAt(long expiresAt);
    long getExpiresAt();

    void setUid(long uid);
    long getUid();

    void setUserName(QString userName);
    QString getUserName();

    void setRawResponse(QString rawResponse);
    QString getRawResponse();

    bool isVaild();

private:
    QString token;
    QString secret;
    long expiresAt;
    long uid;
    QString userName;
    QString rawResponse;
};

#endif // OAUTHTOKEN_H
