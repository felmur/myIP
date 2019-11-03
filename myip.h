/*
 * libmyIP
 * (c) 2019 by Felice Murolo, Salerno, Italia
 * All rigths reserved
 * email: linuxboy@giove.tk
 * Released under LGPL LICENSE V 3.0
 * Please, consult LICENSE file for more informations
 *
*/

#ifndef MYIP_H
#define MYIP_H

#include "myIP_global.h"
#include "QtCore/QObject"
#include "QtCore/QString"
#include "QtNetwork/QNetworkAccessManager"
#include "QtNetwork/QNetworkReply"


#define DEBUG 0 // set to 1 if you want verbose debug

extern const char *libname;
extern const char *libversion;
extern const char *libauthor;
extern const char *liblocation;
extern const char *libcopyright;
extern const char *libemail;

extern const char *liburl;

class ipdata
{
public:
    ipdata();
    QString ip;
    uint32_t ipnum_le;  // low endian format numeric ipnum
    uint32_t ipnum_be;  // big endian format numeric ipnum
    uint32_t ipnum;      // same as ipnum_le, for compatibility
    QString country;
    QString cc;
    QNetworkReply::NetworkError err;
};

class MYIP_EXPORT MyIP  : public QObject
{
    Q_OBJECT

public:
    explicit MyIP(QObject *parent = nullptr);
    ~MyIP();
    void init();
    QString getVersion();

signals:
    void IPready(ipdata);

public slots:

private slots:
    void setIP(QNetworkReply *r);

};

#endif // MYIP_H
