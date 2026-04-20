#include <iostream>
#include <QCoreApplication>
class Transport
{
public:
    virtual ~Transport(){}
    virtual void deliver() const = 0;
};
class Truck :public Transport
{
public:
    void deliver() const override
    {
        std::cout << "the truck is driverring \n";
    }
};
class Ship :public Transport
{
public:
    void deliver()const override
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
    //ºËÐÄ
    virtual Transport * factoryMethod() = 0;
    void doSomething()
    {
       Transport* truck = factoryMethod();
        truck->deliver();
        delete truck;
       /*Transport* ship = factoryMethod();
        ship->deliver();
        delete ship;*/
    }
};
class TruckLigistics : public Logistics
{
public:
    ~TruckLigistics
    ()
    {
	}
    Transport * factoryMethod()  override
    {
		Transport* truck= new Truck();
		return truck  ;
        //ship->deliver();
        //delete ship;

        return truck;
	}
};
class ShipLogistics:public Logistics
{
public:
    ShipLogistics() {};
    ~ShipLogistics(){}// ://public Logistics();
    Transport * factoryMethod() override
    {
		Transport* ship = new Ship();
        return ship;


    }
private:

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
   TruckLigistics obj;
    obj.doSomething();
	ShipLogistics obj2;
	obj2.doSomething();
    return QCoreApplication::exec();
}
