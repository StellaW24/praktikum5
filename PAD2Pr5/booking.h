#ifndef BOOKING_H
#define BOOKING_H


#include <iostream>

//===== Aggregation zu TravelAgency als Subklasse =====
//===== Vererbt selber an RentalCarReservation, HotelBooking, FlightBooking =====

class Booking {
    //========== Public ==========
public:
    //========== Constructors ==========
    //Standartkonstruktor
    Booking() {

    }
    //Konstruktor mit Initialisierungsliste

    Booking(long id, double price, std::string fromDate, std::string toDate, long travelId )
        : id{id}, price{price}, fromDate{fromDate}, toDate{toDate}, travelId{travelId}  {
    }
    //Destruktor
    virtual ~Booking() {
        //std::cout << "destruktor von Booking aufgerufen" << std::endl;
    }
    //========== Methodes ==========
    virtual std::string showDetails() = 0;

    //========== Getter ==========
    long getID() const {return id;} //const {return id;}
    double getPrice() const { return price;}
    long getTravelId() const {return travelId;}
    std::string getFromDate() const {return fromDate;}
    std::string getToDate() const {return toDate;}


    int getAbhCount() const {return abh;}
    //========== Protected ==========
protected:
    long id{};
    double price{};
    std::string fromDate;
    std::string toDate;
    long travelId{};

    int abh;
};

#endif // BOOKING_H
