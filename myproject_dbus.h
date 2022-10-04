#ifndef MINIMAL_DBUS_QT_EXAMPLE_MYPROJECT_DBUS_H
#define MINIMAL_DBUS_QT_EXAMPLE_MYPROJECT_DBUS_H

#include <QObject>

class MyProjectDBus : public QObject {
    Q_OBJECT
public:
    MyProjectDBus();

public Q_SLOTS:
    Q_SCRIPTABLE int foo();
};

#endif //MINIMAL_DBUS_QT_EXAMPLE_MYPROJECT_DBUS_H
