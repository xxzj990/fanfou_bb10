/*
 * Parameter.h
 *
 *  Created on: 2014年9月6日
 *      Author: liulei
 */

#ifndef PARAMETER_H
#define PARAMETER_H

#include <QString>

class Parameter
{
public:
    explicit Parameter(QString key, QString value);

    QString getName();
    QString getValue();

    QString asUrlEncodedPair();

private:
    QString key;
    QString value;
};

#endif // PARAMETER_H
