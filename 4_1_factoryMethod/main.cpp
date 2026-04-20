#include <iostream>
#include <QCoreApplication>
class Transport
{
public:
    virtual ~Transport(){}
    virtual void deliver() const = 0;
};
class Truck
{
public:
    void deliver() const
    {
        std::cout << "the truck is driverring \n";
    }
};
class Ship
{
public:
    void deliver()const
    {
        std::cout << "the ship is delivering \n";
    }
};

class Logistics
{
public:
    virtual ~Logistics()
    {

    }
    void doSomething()
    {
        Truck truck;
        truck.deliver();
        Ship ship;
        ship.deliver();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call QCoreApplication::quit() or QCoreApplication::exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to QCoreApplication::exec() or use the Non-Qt Plain C++ Application template.
    Logistics obj;
    obj.doSomething();
    return QCoreApplication::exec();
}
