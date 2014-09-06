/*
 * HeaderExtractor.cpp
 *
 *  Created on: 2014年9月6日
 *      Author: liulei
 */

#include <QString>
#include <QList>
#include "headerextractor.h"
#include "parameter.h"

HeaderExtractor::HeaderExtractor(QObject *parent) :
    QObject(parent)
{
}

QString HeaderExtractor::extract(MyNetworkRequest &request)
{
    QList<Parameter*> params = request.getParameters();
    QString header;

    header.append(PREAMBLE);
    QString prefix = PREAMBLE;
    for(int i=0; i<params.size(); i++) {
        Parameter *param = params.at(i);
        if(header.length() > prefix.length()) {
            header.append(PARAM_SEPARATOR);
        }

        header.append(param->getName()).append('=').append('"').append(param->getValue().toUtf8().toPercentEncoding()).append('"');
    }
    return header;
}

