/*
 * log.cpp
 *
 *  Created on: 2014年8月17日
 *      Author: liulei
 */

#include <src/utils/log.h>
#include <QString>
#include <QDebug>
#include <QDateTime>

const QString APP_LOG_TAG = "[fanfou_bb10]";
//const QString APP_LOG_PATTERN =
//        "[%{if-debug}D%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}]"
//        ": %{file}:%{line} - %{message}";

void Log::d(QString msg) {
    // 获取时间对象
    QDateTime time;
    time = QDateTime::currentDateTime();

    // 组织格式
    QString log;
    log.append("[D][").append(time.toString("yyyy-MM-dd HH:mm:ss")).append("]").append(APP_LOG_TAG).append(":")
            .append(msg);
    qDebug() << log;
}

