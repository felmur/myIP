/*
 * libmyIP
 * (c) 2019 by Felice Murolo, Salerno, Italia
 * All rigths reserved
 * email: linuxboy@giove.tk
 * Released under LGPL LICENSE V 3.0
 * Please, consult LICENSE file for more informations
 *
*/

/*
 * To use libmyIP in classic widgets application, you must connect the lybrary's
 * signal IPready to a private or public slot created in the window/widget class.
 * The slot will receive an ipdata class from IPready signal.
 * Please, look the ipdata structure in myip.h file for more informations.
 *
 * To use libmyIP in QTConsole application (like here), we have to subclass
 * QCoreApplication in order to add printIP(ipdata) slot, which will print
 * out the IP.
 * Please, look at myqcoreapplication.h and myqcoreapplication.cpp
 *
*/

#include "myqcoreapplication.h"
#include "myip.h"


int main(int argc, char *argv[])
{
    myQCoreApplication a(argc, argv);

    qDebug("Simple libmyip sample\n");

    MyIP *mip = new MyIP(); // initialize the library and contact myip.com site

    // now connect the library IPready signal to slot printIP of myQCoreApplication
    QObject::connect(mip, SIGNAL(IPready(ipdata)), &a, SLOT(printIP(ipdata)));

    mip->getVersion(); // finally, print out library version
    qDebug("\n");

    return a.exec();
}

