/*
 * libmyIP
 * (c) 2019 by Felice Murolo, Salerno, Italia
 * All rigths reserved
 * email: linuxboy@giove.tk
 * Released under LGPL LICENSE V 3.0
 * Please, consult LICENSE file for more informations
 *
*/

#ifndef MYIP_GLOBAL_H
#define MYIP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYIP_LIBRARY)
#  define MYIP_EXPORT Q_DECL_EXPORT
#else
#  define MYIP_EXPORT Q_DECL_IMPORT
#endif

#endif // MYIP_GLOBAL_H
