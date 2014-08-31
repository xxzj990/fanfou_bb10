/*
 * Fanfou.cpp
 *
 *  Created on: 2014年8月30日
 *      Author: liulei
 */

#include <src/fanfou/Fanfou.h>
#include <src/utils/AppSettings.h>
#include <src/utils/log.h>
#include <bb/cascades/QmlDocument>

Fanfou::~Fanfou()
{
}

Fanfou::Fanfou()
{
}

bool Fanfou::isLogin() {
    return AppSettings::isLogined();
}

void Fanfou::login() {
    AppSettings::setAsLogined();

    Log::d("Login process finish.");

    emit loginSuccess("OK");
}

void Fanfou::logout() {
    AppSettings::removeLogin();
}
