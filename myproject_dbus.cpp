#include <QDBusConnection>
#include <QDebug>
#include <myproject_dbus.h>

MyProjectDBus::MyProjectDBus()
{
    // The code below could also be moved to outside this class.
    auto bus = QDBusConnection::sessionBus();
    bus.registerObject("/", this);
    bus.registerService("myproject.MyProject");
}

int MyProjectDBus::foo()
{
    qDebug() << "Foo called";
    return 42;
}
