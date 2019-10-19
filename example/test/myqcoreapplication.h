/*
 * libmyIP
 * (c) 2019 by Felice Murolo, Salerno, Italia
 * All rigths reserved
 * email: linuxboy@giove.tk
 * Released under LGPL LICENSE V 3.0
 * Please, consult LICENSE file for more informations
 *
*/

#ifndef MYQCOREAPPLICATION_H
#define MYQCOREAPPLICATION_H

#include <QObject>
#include <QCoreApplication>
#include "myip.h"

class myQCoreApplication : public QCoreApplication
{
    Q_OBJECT
public:
    myQCoreApplication(int argc, char *argv[]);
    ~myQCoreApplication();

private slots:
    void printIP(ipdata);
};

#endif // MYQCOREAPPLICATION_H
