/*
 * timeline.cpp
 *
 *  Created on: 2014年8月17日
 *      Author: liulei
 */

#include <src/model/timeline.h>
#include <QString>

Timeline::Timeline()
{
}

Timeline::~Timeline()
{
}

QString Timeline::getContent() {
    return content;
}

void Timeline::setContent(QString content) {
    this->content = content;
}

QString Timeline::getId() {
    return id;
}

void Timeline::setId(QString id) {
    this->id = id;
}
