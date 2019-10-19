#ifndef MYIP_GLOBAL_H
#define MYIP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYIP_LIBRARY)
#  define MYIP_EXPORT Q_DECL_EXPORT
#else
#  define MYIP_EXPORT Q_DECL_IMPORT
#endif

#endif // MYIP_GLOBAL_H
