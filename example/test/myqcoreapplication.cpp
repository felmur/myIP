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
    if (ipd.err == QNetworkReply::NoError ) {
        qDebug("My IP is: %s", ipd.ip.toUtf8().data());
        qDebug("My little_endian numeric IP is: %d", ipd.ipnum_le);
        qDebug("My big_endian numeric IP is: %d", ipd.ipnum_be);
        qDebug("My country is: %s", ipd.country.toUtf8().data());
        qDebug("My cc country is: %s", ipd.cc.toUtf8().data());
    }
    else {
        qCritical("Library has returned error: %d", ipd.err);
        qCritical("See https://doc.qt.io/qt-5/qnetworkreply.html#NetworkError-enum for more information");
    }
    qDebug("\nPress CTRL-C to break");
}

