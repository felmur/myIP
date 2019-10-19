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
#include "QObject"
#include "QString"
#include "qt/QtNetwork/QNetworkAccessManager"
#include "qt/QtNetwork/QNetworkReply"

#define DEBUG 0 // set to 1 if you want verbose debug

extern const char *libname;
extern const char *version;
extern const char *author;
extern const char *location;
extern const char *copyright;
extern const char *email;

extern const char *url;

class ipdata
{
public:
    ipdata();
    QString ip;
    uint32_t ipnum;
    QString country;
    QString cc;
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
