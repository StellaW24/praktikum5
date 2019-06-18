#include "test.h"

Test::Test(QObject* parent) : QObject (parent) {

}

void Test::testCompanyAvis() {
    TravelAgency travelagency;
    travelagency.readFile();
    QCOMPARE(travelagency.countAvisCompany(),5);
}

void Test::testUnitedAirlines() {
    TravelAgency travelagency;
    travelagency.readFile();
    QCOMPARE(travelagency.countUnitedAirlines(),3);
}

void Test::testBookingsWith1K() {
    TravelAgency travelagency;
    travelagency.readFile();
    QCOMPARE(travelagency.countBookingsWith1K(), 31);
}



//===============Eigene Unit tests=============================


void Test::testAllBookingSize() {
    TravelAgency travelagency;
    travelagency.readFile();
    std::vector<std::string> bookingdetails;
    std::string pickupL = "Atr1";
    std::string returnL = "Atr2";
    std::string company = "Atr3";
    std::string insurance = "Atr4";
    bookingdetails.push_back(pickupL);
    bookingdetails.push_back(returnL);
    bookingdetails.push_back(company);
    bookingdetails.push_back(insurance);

    char type = 'R';
    double price = 200;
    std::string fromDate = "20150102";
    std::string toDate = "20150203";
    long travelId = 14;

    travelagency.createBooking(type, price, fromDate, toDate, travelId, bookingdetails);

    //QCOMPARE(travelagency.getAllBookingSize(), 107);
}

void Test::testList() {
    TravelAgency travelagency;
    FlightBooking* newBooking = new FlightBooking(1, 20, "20190102", "20190203",2, "from", "to", "lufthansa", 'w');
    FlightBooking* newBooking1 = new FlightBooking(2, 20, "20190102", "20190203",3, "from", "to", "lufthansa", 'w');
    FlightBooking* newBooking2 = new FlightBooking(3, 20, "20190102", "20190203",6, "from", "to", "lufthansa", 'w');

/*

    travelagency.lAllBooking.reset();

    travelagency.lAllBooking.insertNodeS(newBooking1);
    travelagency.lAllBooking.insertNodeS(newBooking);
    travelagency.lAllBooking.insertNodeS(newBooking2);

    travelagency.lAllBooking.reset();

    QCOMPARE(travelagency.lAllBooking.getNode()->getTravelId(), 2);
    QCOMPARE(travelagency.lAllBooking.getNodeByIndex(0)->getIndex(),0);
    QCOMPARE(travelagency.lAllBooking.getSize(),3);
    QCOMPARE(travelagency.lAllBooking[0]->getTravelId(), 2);

*/

}
