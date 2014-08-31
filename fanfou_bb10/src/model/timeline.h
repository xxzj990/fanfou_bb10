/*
 * timeline.h
 *
 *  Created on: 2014年8月17日
 *      Author: liulei
 */

#ifndef TIMELINE_H_
#define TIMELINE_H_

class Timeline
{
private:
    QString id;
    QString content;
public:
    Timeline();
    virtual ~Timeline();

    QString getContent();
    void setContent(QString content);

    QString getId();
    void setId(QString id);
};

#endif /* TIMELINE_H_ */
