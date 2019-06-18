#include "mainwindow.h"
#include <QApplication>
#include "test.h"
#include "travelagency.h"


int main(int argc, char *argv[])
{

    /*
    TravelAgency travelagency;
    FlightBooking* newBooking = new FlightBooking(1, 20, "20190102", "20190203",2, "from", "to", "lufthansa", 'w');
    FlightBooking* newBooking1 = new FlightBooking(2, 20, "20190102", "20190203",3, "from", "to", "lufthansa", 'w');
    FlightBooking* newBooking2 = new FlightBooking(3, 20, "20190102", "20190203",6, "from", "to", "lufthansa", 'w');


    travelagency.lAllBookings.reset();

    travelagency.lAllBookings.insertNodeS(newBooking1);
    travelagency.lAllBookings.insertNodeS(newBooking);
    travelagency.lAllBookings.insertNodeS(newBooking2);


    travelagency.lAllBookings.reset();

    travelagency.lAllBookings.getNode()->getTravelId();
    travelagency.lAllBookings.getNodeByIndex(0)->getIndex();
    travelagency.lAllBookings.getSize();
    travelagency.lAllBookings[0]->getTravelId();



    FlightBooking* newBooking = new FlightBooking(1, 20, "20190102", "20190203",2, "from", "to", "lufthansa", 'w');
    FlightBooking* newBooking1 = new FlightBooking(2, 20, "20190102", "20190203",3, "from", "to", "lufthansa", 'w');
    FlightBooking* newBooking2 = new FlightBooking(3, 20, "20190102", "20190203",6, "from", "to", "lufthansa", 'w');
    HotelBooking* newHotelBooking = new HotelBooking(5, 13, "20190405", "20190607", 7, "hotel", "town", true);
    RentalCarReservation* newRentalCarReservation = new RentalCarReservation(10, 20000, "20190607", "20190102", 5, "1", "2", "3", "4");


    int z = 4;
    double b = 30;
    std::string c = "test";
    std::string d = "test2";
    long e = 14;
    std::string f = "from";
    std::string g = "to";
    std::string h = "lufthansa";
    char i = 'w';
    FlightBooking* newFlightBooking = new FlightBooking(z, b, c, d, e, f, g, h, i);

    std::cout << "test" << std::endl;

    TravelAgency travelagency;

    travelagency.lAllBookings.reset();

    travelagency.lAllBookings.insertNodeS(newBooking1);
    travelagency.lAllBookings.insertNodeS(newBooking);
    travelagency.lAllBookings.insertNodeS(newBooking2);
    travelagency.lAllBookings.insertNodeS(newFlightBooking);
    travelagency.lAllBookings.insertNodeS(newHotelBooking);
    travelagency.lAllBookings.insertNodeS(newRentalCarReservation);

    std::cout << travelagency.lAllBookings.getSize() << std::endl;



    std::cout << "Test ende" << std::endl;
    */

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //Test t;
    //QTest::qExec(&t);

    return a.exec();
}
