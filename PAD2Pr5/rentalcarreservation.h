#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include "booking.h"

#include <iostream>

//===== Erbt von Booking =====

class RentalCarReservation : public Booking {
public:
    //========== Constructor ==========
    //Standartkonstruktor
    RentalCarReservation() : Booking() {
    }
    //Konstruktor mit Initialisierungsliste
    RentalCarReservation(long id, double price, std::string fromDate, std::string toDate, long travelId, std::string pickupLocation,
                         std::string returnLocation, std::string company, std::string insuranceType)

        : Booking(id, price, fromDate, toDate, travelId),
          pickupLocation{pickupLocation}, returnLocation{returnLocation}, company{company}, insuranceType{insuranceType}
    {
        abh = 0;
    }

    //Konstruktor mit Initialisierungsliste
    RentalCarReservation(long id, double price, std::string fromDate, std::string toDate, long travelId, std::string pickupLocation,
                         std::string returnLocation, std::string company, std::string insuranceType, std::string abhaengigkeit1)

        : Booking(id, price, fromDate, toDate, travelId),
          pickupLocation{pickupLocation}, returnLocation{returnLocation}, company{company}, insuranceType{insuranceType}, abhaengigkeit1{abhaengigkeit1}
    {
        abh = 1;
    }

    //Konstruktor mit Initialisierungsliste
    RentalCarReservation(long id, double price, std::string fromDate, std::string toDate, long travelId, std::string pickupLocation,
                         std::string returnLocation, std::string company, std::string insuranceType, std::string abhaengigkeit1, std::string abhaengigkeit2)

        : Booking(id, price, fromDate, toDate, travelId),
          pickupLocation{pickupLocation}, returnLocation{returnLocation}, company{company}, insuranceType{insuranceType}, abhaengigkeit1{abhaengigkeit1}, abhaengigkeit2{abhaengigkeit2}
    {
        abh = 1;
    }




    //Destruktor
    ~RentalCarReservation() {
    }
    //========== Getter ==========
    std::string showDetails();
    std::string getPickupLocation() const {return pickupLocation;}
    std::string getReturnLocation() const {return returnLocation;}
    std::string getCompany() const {return company;}
    std::string getInsuranceType() const {return insuranceType;}

    std::string getAbh1() const {return abhaengigkeit1;}
    std::string getAbh2() const {return abhaengigkeit2;}

    //========== Private ==========
private:
    std::string pickupLocation;
    std::string returnLocation;
    std::string company;
    std::string insuranceType;

    //abhängigkeiten
    std::string abhaengigkeit1;
    std::string abhaengigkeit2;
};


#endif // RENTALCARRESERVATION_H
