# myIP
Library to get public network IP using myip.com service. Based on Qt libraries. Written in C++.

# Installation
Enter in directory myIP:

<em>$> qmake</em>

<em>$> make</em>

<em>$> sudo make install</em>

# Usage:
To use libmyIP in classic widgets application, you must connect the lybrary's signal IPready to a private or public slot created in the window/widget class.
The slot will receive an ipdata class from IPready signal. Please, look the ipdata structure in myip.h file for more informations.
Example:

<em>// initialize the library and contact myip.com site</em>

<em>MyIP *mip = new MyIP();</em>

<em>// now connect the library IPready signal to slot printIP of myQCoreApplication</em>

<em>QObject::connect(mip, SIGNAL(IPready(ipdata)), &a, SLOT(printIP(ipdata)));</em>

To use libmyIP in QTConsole application (like in the example), we have to subclass QCoreApplication in order to add printIP(ipdata) slot, which will print out the IP.
Please, look at myqcoreapplication.h and myqcoreapplication.cpp

# License:
This software is released under LGPL V 3.0 license. See "LICENSE" file for more informations.

# Credits:
Nothing here.

