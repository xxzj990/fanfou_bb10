/*
 * BaseStringExtractor.cpp
 *
 *  Created on: 2014年9月6日
 *      Author: liulei
 */

#include <QList>
#include "basestringextractor.h"
#include "mynetworkrequest.h"
#include "parameter.h"

BaseStringExtractor::BaseStringExtractor(QObject *parent) :
    QObject(parent)
{
}

QString BaseStringExtractor::extract(MyNetworkRequest &request)
{
    // 排序
    QList<Parameter*> params = request.getParameters();
    qSort(params.begin(), params.end(), dereferencedLessThan);

    // 组合
    QString paramsString;
    for(int i=0; i<params.size(); i++) {
        Parameter *parmeter = params.at(i);
        paramsString.append('&').append(parmeter->asUrlEncodedPair());
    }
    paramsString = paramsString.right(paramsString.length()-1).toUtf8().toPercentEncoding();

    // 最终组装
    QString method = request.getVerbName().toUtf8().toPercentEncoding();
    QString url = request.url().toString().toUtf8().toPercentEncoding();
    QString result;
    result.append(method).append('&').append(url).append('&').append(paramsString);

    return result;
}

bool BaseStringExtractor::dereferencedLessThan(Parameter *o1, Parameter *o2) {
    return o1->getName() < o2->getName();
}

