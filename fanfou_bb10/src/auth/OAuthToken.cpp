/*
 * OAuthToken.cpp
 *
 *  Created on: 2014年9月6日
 *      Author: liulei
 */

#include "oauthtoken.h"

OAuthToken::OAuthToken()
{
}

void OAuthToken::setToken(QString token) {
    this->token = token;
}

QString OAuthToken::getToken() {
    return token;
}

void OAuthToken::setSecret(QString secret) {
    this->secret = secret;
}

QString OAuthToken::getSecret() {
    return secret;
}

void OAuthToken::setExpiresAt(long expiresAt) {
    this->expiresAt = expiresAt;
}

long OAuthToken::getExpiresAt() {
    return expiresAt;
}

void OAuthToken::setUid(long uid) {
    this->uid = uid;
}

long OAuthToken::getUid() {
    return uid;
}

void OAuthToken::setUserName(QString userName) {
    this->userName = userName;
}

QString OAuthToken::getUserName() {
    return userName;
}

void OAuthToken::setRawResponse(QString rawResponse) {
    this->rawResponse = rawResponse;
}

QString OAuthToken::getRawResponse() {
    return rawResponse;
}

