/*
 * OAuth10aService.h
 *
 *  Created on: 2014年9月6日
 *      Author: liulei
 */

#ifndef OAUTH10ASERVICE_H
#define OAUTH10ASERVICE_H

#define X_AUTH_USERNAME "x_auth_username"
#define X_AUTH_PASSWORD "x_auth_password"
#define X_AUTH_MODE "x_auth_mode"

#define TIMESTAMP "oauth_timestamp"
#define SIGN_METHOD "oauth_signature_method"
#define SIGNATURE "oauth_signature"
#define CONSUMER_SECRET "oauth_consumer_secret"
#define CONSUMER_KEY "oauth_consumer_key"
#define CALLBACK "oauth_callback"
#define VERSION "oauth_version"
#define NONCE "oauth_nonce"
#define PARAM_PREFIX "oauth_"
#define TOKEN "oauth_token"
#define TOKEN_SECRET "oauth_token_secret"
#define OUT_OF_BAND "oob"
#define VERIFIER "oauth_verifier"
#define HEADER "Authorization"
#define SCOPE "scope"


#include <QObject>
#include <QString>
#include "mynetworkrequest.h"
#include "oauthtoken.h"

class OAuth10aService : public QObject
{
    Q_OBJECT
public:
    explicit OAuth10aService(QObject *parent = 0);

    MyNetworkRequest getTokenRequest(QString username, QString password);
    void signRequest(MyNetworkRequest request, OAuthToken token);

private:
    QString getTimestampInSeconds();
    QString getNonce();
    QString getApiKey();
    QString getSignatureMethod();
    QString getVersion();
    QString getApiSecret();
    QString getSignature(MyNetworkRequest request, OAuthToken token);
};

#endif // OAUTH10ASERVICE_H
