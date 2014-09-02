/*
 * HMACSha1Signature.h
 *
 *  Created on: 2014年9月2日
 *      Author: liulei
 */

#ifndef HMACSHA1SIGNATURE_H
#define HMACSHA1SIGNATURE_H

#include <QObject>

class HMACSha1Signature : public QObject
{
    Q_OBJECT
public:
    explicit HMACSha1Signature(QObject *parent = 0);

    QString getSignature(QString baseString, QString apiSecret, QString tokenSecret);
private:
    QString hmacSha1(QByteArray key, QByteArray baseString);
};

#endif // HMACSHA1SIGNATURE_H

