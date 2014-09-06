/*
 * Parameter.cpp
 *
 *  Created on: 2014年9月6日
 *      Author: liulei
 */

#include "parameter.h"

Parameter::Parameter(QString key, QString value)
{
    this->key = key;
    this->value = value;
}

QString Parameter::getName() {
    return key;
}

QString Parameter::getValue() {
    return value;
}

QString Parameter::asUrlEncodedPair() {
   QString result = key.toUtf8().toPercentEncoding();
   result.append('=');
   result.append(value.toUtf8().toPercentEncoding());
   return result;
}
