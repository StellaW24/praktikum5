#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include "booking.h"

#include <iostream>
#include <string>

//===== Erbt von Booking =====

class FlightBooking : public Booking {
    //========== Public ==========
    public:
    //========== Constructors ==========
    //Standartkonstruktor
    FlightBooking() : Booking() {
    }
    //Konstruktor mit Initialisierungsliste
    FlightBooking(long id, double price, std::string fromDate, std::string toDate, long travelId,
                  std::string fromDest, std::string toDest, std::string airline, char seatPref)
        :
          Booking(id, price, fromDate, toDate, travelId),
          fromDest{fromDest}, toDest{toDest}, airline{airline}, seatPref{seatPref}
    {
        abh = 0;
    }
    //Konstruktor mit Initialisierungsliste und einer Abhaengigkeit
    FlightBooking(long id, double price, std::string fromDate, std::string toDate, long travelId,
                  std::string fromDest, std::string toDest, std::string airline, char seatPref, std::string abhaengigkeit1)
        :
          Booking(id, price, fromDate, toDate, travelId),
          fromDest{fromDest}, toDest{toDest}, airline{airline}, seatPref{seatPref}, abhaengigkeit1{abhaengigkeit1}
    {
        abh = 1;
    }
    //Konstruktor mit Initialisierungsliste und zwei Anhaengigkeiten
    FlightBooking(long id, double price, std::string fromDate, std::string toDate, long travelId,
                  std::string fromDest, std::string toDest, std::string airline, char seatPref, std::string abhaengigkeit1,std::string abhaengigkeit2)
        :
          Booking(id, price, fromDate, toDate, travelId),
          fromDest{fromDest}, toDest{toDest}, airline{airline}, seatPref{seatPref}, abhaengigkeit1{abhaengigkeit1}, abhaengigkeit2{abhaengigkeit2}
    {
        abh = 2;
    }

    //Destruktor
    ~FlightBooking() {
    }
    //========== Getter ==========
        std::string showDetails();
        std::string getFromDest() const {return fromDest;}
        std::string getToDest() const {return toDest;}
        std::string getAirline()const {return airline;}
        char getSeatPref() const {return seatPref;}

        std::string getAbh1() const {return abhaengigkeit1;}
        std::string getAbh2() const {return abhaengigkeit2;}

    //========== Private ==========
    private:
        std::string fromDest;
        std::string toDest;
        std::string airline;
        char seatPref;

        //abhängigkeiten
        std::string abhaengigkeit1;
        std::string abhaengigkeit2;
};



#endif // FLIGHTBOOKING_H
