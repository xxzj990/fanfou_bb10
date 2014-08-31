/*
 * log.h
 *
 *  Created on: 2014年8月17日
 *      Author: liulei
 */

#ifndef LOG_H_
#define LOG_H_

extern const QString APP_LOG_TAG;
extern const QString APP_LOG_PATTERN;

class Log
{
public:
    Log();
    virtual ~Log();

    // Debug log
    static void d(QString msg);
};

#endif /* LOG_H_ */
