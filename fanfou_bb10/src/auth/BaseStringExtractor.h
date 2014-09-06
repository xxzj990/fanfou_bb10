/*
 * BaseStringExtractor.h
 *
 *  Created on: 2014年9月6日
 *      Author: liulei
 */

#ifndef BASESTRINGEXTRACTOR_H
#define BASESTRINGEXTRACTOR_H

#include <QObject>

class Parameter;
class MyNetworkRequest;

class BaseStringExtractor : public QObject
{
    Q_OBJECT
public:
    explicit BaseStringExtractor(QObject *parent = 0);

    /**
     * @brief extract
     * @return
     */
    QString extract(MyNetworkRequest &request);
    static bool dereferencedLessThan(Parameter *o1, Parameter *o2);

};

#endif // BASESTRINGEXTRACTOR_H
