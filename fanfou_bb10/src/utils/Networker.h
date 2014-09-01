/*
 * Networker.h
 *
 *  Created on: 2014年9月1日
 *      Author: liulei
 */

#ifndef NETWORKER_H
#define NETWORKER_H

#include <QObject>

class QNetworkReply;

class NetWorker : public QObject
{
    Q_OBJECT
public:
    static NetWorker * instance();
    ~NetWorker();

    /**
     * @brief get GET 请求
     * @param url 请求地址
     */
     Q_INVOKABLE void get(const QString &url);

Q_SIGNALS:
    /**
     * @brief finished 请求异步回调
     * @param reply 返回内容
     */
    void finished(QNetworkReply *reply);

private:
    class Private;
    friend class Private;
    Private *d;

    explicit NetWorker(QObject *parent = 0);
//    NetWorker(const NetWorker &) Q_DECL_EQ_DELETE;
//    NetWorker& operator=(NetWorker rhs) Q_DECL_EQ_DELETE;
    NetWorker(const NetWorker &);
    NetWorker& operator=(NetWorker rhs);

};

#endif // NETWORKER_H
