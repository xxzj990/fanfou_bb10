/*
 * MyNetworkRequest.h
 *
 *  Created on: 2014年9月6日
 *      Author: liulei
 */

#ifndef MYNETWORKREQUEST_H
#define MYNETWORKREQUEST_H

#include <QNetworkRequest>
#include <QList>
#include "parameter.h"

/**
 * @brief The Verb enum 请求类型
 */
enum Verb{GET, POST, PUT, DELETE};

class MyNetworkRequest : public QNetworkRequest
{
public:
    explicit MyNetworkRequest();

    /**
     * @brief getVerb 获取请求类型
     * @return
     */
    Verb getVerb();

    /**
     * @brief setVerb 设置请求类型
     * @param method
     */
    void setVerb(Verb method);

    /**
     * @brief getVerbName 获取请求类型名称
     * @return
     */
    QString getVerbName();

    /**
     * @brief addParameter 添加参数
     * @param key
     * @param value
     */
    void addParameter(QString key, QString value);

    /**
     * @brief getParameters 获取所有参数
     * @return
     */
    QList<Parameter*> getParameters();

private:
    Verb method;
    QList<Parameter*> params;
};

#endif // MYNETWORKREQUEST_H
