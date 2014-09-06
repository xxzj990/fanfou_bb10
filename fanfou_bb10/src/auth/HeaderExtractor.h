/*
 * HeaderExtractor.h
 *
 *  Created on: 2014年9月6日
 *      Author: liulei
 */

#ifndef HEADEREXTRACTOR_H
#define HEADEREXTRACTOR_H

#define PARAM_SEPARATOR ", "
#define PREAMBLE "OAuth "

#include <QObject>
#include <QString>
#include "mynetworkrequest.h"

class HeaderExtractor : public QObject
{
    Q_OBJECT
public:
    explicit HeaderExtractor(QObject *parent = 0);

    QString extract(MyNetworkRequest &request);
};

#endif // HEADEREXTRACTOR_H
