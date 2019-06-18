#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H

#include "booking.h"

#include <iostream>

//===== Erbt von Booking =====

class HotelBooking : public Booking {
    //========== Public ==========
public:
    //========== Constructors ==========
    //Standartkonstruktor
    HotelBooking():Booking() {
    }
    //Konstruktor mit Initialisierungsliste
    HotelBooking(long id, double price, std::string fromDate, std::string toDate, long travelId,
                 std::string hotel, std::string town, bool smoke)
        :
          Booking(id, price, fromDate, toDate, travelId),
          hotel{hotel}, town{town}, smoke{smoke}
    {
        abh = 0;
    }

    //Konstruktor mit Initialisierungsliste und einer abhängigkeit
    HotelBooking(long id, double price, std::string fromDate, std::string toDate, long travelId,
                 std::string hotel, std::string town, bool smoke, std::string abhaengigkeit1)
        :
          Booking(id, price, fromDate, toDate, travelId),
          hotel{hotel}, town{town}, smoke{smoke}, abhaengigkeit1{abhaengigkeit1}
    {
        abh = 1;
    }

    //Konstruktor mit Initialisierungsliste und einer abhängigkeit
    HotelBooking(long id, double price, std::string fromDate, std::string toDate, long travelId,
                 std::string hotel, std::string town, bool smoke, std::string abhaengigkeit1, std::string abhaengigkeit2)
        :
          Booking(id, price, fromDate, toDate, travelId),
          hotel{hotel}, town{town}, smoke{smoke}, abhaengigkeit1{abhaengigkeit1}, abhaengigkeit2{abhaengigkeit2}
    {
        abh = 2;
    }

    //Destruktor
    ~HotelBooking() {
    }
    //========== Getter ==========
    std::string showDetails();
    std::string getHotel() const {return hotel;}
    std::string getTown() const {return town;}
    bool getSmoke() const {return smoke;}

    std::string getAbh1() const {return abhaengigkeit1;}
    std::string getAbh2() const {return abhaengigkeit2;}
    //========== Private ==========
private:
    std::string hotel;
    std::string town;
    bool smoke;

    //abhängigkeiten
    std::string abhaengigkeit1;
    std::string abhaengigkeit2;
};



#endif // HOTELBOOKING_H
