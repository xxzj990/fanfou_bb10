/*
 * TokenExtractor.h
 *
 *  Created on: 2014年9月7日
 *      Author: liulei
 */

#ifndef TOKENEXTRACTOR_H_
#define TOKENEXTRACTOR_H_

#define TOKEN_REGEX "oauth_token=([^&]+)"
#define SECRET_REGEX "oauth_token_secret=([^&]*)"

#include <QObject>
#include <QRegExp>

class OAuthToken;

class TokenExtractor : public QObject
{
    Q_OBJECT
public:
    explicit TokenExtractor(QObject *parent = 0);

    OAuthToken extract(QString raw);

private:
    QString extract(QString raw, QRegExp rx);
};

#endif /* TOKENEXTRACTOR_H_ */
