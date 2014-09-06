/*
 * MyNetworkRequest.cpp
 *
 *  Created on: 2014年9月6日
 *      Author: liulei
 */

#include <QList>
#include "mynetworkrequest.h"
#include "parameter.h"

MyNetworkRequest::MyNetworkRequest() :
    QNetworkRequest()
{
}

Verb MyNetworkRequest::getVerb() {
    return method;
}

void MyNetworkRequest::setVerb(Verb method) {
    this->method = method;
}

QString MyNetworkRequest::getVerbName() {
    switch (method) {
    case GET:
        return "GET";
    case POST:
        return "POST";
    case PUT:
        return "PUT";
    case DELETE:
        return "DELETE";
    default:
        break;
    }

    return "GET";
}

void MyNetworkRequest::addParameter(QString key, QString value) {
    Parameter *param = new Parameter(key, value);
    params.append(param);
}

QList<Parameter*> MyNetworkRequest::getParameters() {
    return params;
}
