/*
 * libmyIP
 * (c) 2019 by Felice Murolo, Salerno, Italia
 * All rigths reserved
 * email: linuxboy@giove.tk
 * Released under LGPL LICENSE V 3.0
 * Please, consult LICENSE file for more informations
 *
*/

#include "myip.h"
#include "json/json.h"


const char *libname="myip";
const char *version="1.0.1";
const char *author="Felice Murolo";
const char *location="Salerno, Italy";
const char *copyright="(c) 2019 - All rights reserved";
const char *email="linuxboy@giove.tk";
const char *url = "https://api.myip.com";

ipdata::ipdata()
{
    ip = "";
    ipnum = 0;
    country = "";
    cc = "";
}

static ipdata myip;

MyIP::~MyIP(){

}

MyIP::MyIP(QObject *parent) : QObject(parent)
{
    init();
}

void MyIP::init(){
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkRequest request;

    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    request.setSslConfiguration(config);
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ServerHeader, "application/json");

    manager->get(request);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(setIP(QNetworkReply*)));
}

void MyIP::setIP(QNetworkReply *r){
    QString s;
    myip.err = r->error();
    if (r->error() == QNetworkReply::NoError) {
        s = r->readAll();
        const int rawJsonLength = static_cast<int>(s.length());
        JSONCPP_STRING err;
        Json::Value root;
        Json::CharReaderBuilder builder;
        const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
        if (reader->parse(s.toUtf8().data(), s.toUtf8().data() + rawJsonLength, &root, &err)) {
            myip.ip = root["ip"].asString().data();
            myip.country = root["country"].asString().data();
            myip.cc = root["cc"].asString().data();
            QStringList p = myip.ip.split(".");
            myip.ipnum = static_cast<uint32_t> (256*256*256*p[0].toInt() + 256*256*p[1].toInt() + 256*p[2].toInt() + p[3].toInt());
            if (DEBUG) {
                qDebug("My public IP is: %s", myip.ip.toUtf8().data());
                qDebug("My public numerical IP is: %d", myip.ipnum);
                qDebug("My country is: %s", myip.country.toUtf8().data());
                qDebug("My cc country is: %s", myip.cc.toUtf8().data());
            }
            emit IPready(myip);
        }
    }
}

QString MyIP::getVersion() {
    qDebug("%s v%s\n%s by %s %s\nemail: %s", libname, version, copyright, author, location, email);
    return version;
}


