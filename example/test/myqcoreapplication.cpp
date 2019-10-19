/*
 * libmyIP
 * (c) 2019 by Felice Murolo, Salerno, Italia
 * All rigths reserved
 * email: linuxboy@giove.tk
 * Released under LGPL LICENSE V 3.0
 * Please, consult LICENSE file for more informations
 *
*/

#include "myqcoreapplication.h"

myQCoreApplication::myQCoreApplication(int argc, char *argv[]) : QCoreApplication(argc, argv)
{
}

myQCoreApplication::~myQCoreApplication(){
}

void myQCoreApplication::printIP(ipdata ipd){
    qDebug("My IP is: %s", ipd.ip.toUtf8().data());
    qDebug("My numeric IP is: %d", ipd.ipnum);
    qDebug("My country is: %s", ipd.country.toUtf8().data());
    qDebug("My cc country is: %s", ipd.cc.toUtf8().data());
}

