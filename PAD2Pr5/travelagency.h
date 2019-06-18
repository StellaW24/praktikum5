#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
#include "booking.h"
#include "travel.h"
#include "customer.h"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <array>

#include "linkedlist.h"



class TravelAgency {
    //========== Public ==========
public:
    //========== Constructor ==========
    //Standartkonstruktor
    TravelAgency() {

        rowCounter = 0;
    }
    //Destruktor
    ~TravelAgency() {
        std::cout << "Destruktor von Travelagency aufgerufen" << std::endl;
    }
    //========== Methodes ==========

    //Datei einlesen
    void readFile();

    //neue Datei schreiben
    void writeNewFile(std::string newFileName);

    //testMethode, wird nicht benutzt
    inline void testMethode() {std::cout << "Test methode aufgerufen";}

    //Alle drei Methoden sind dafür gedacht Objekte mit der übergebenen ID zu suchen
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);



    //Methode um den Namen eines Customers über den BookingIndex zu finden
    std::string findCustomerWIndex(TravelAgency* travelagency, unsigned int id);

    //Methode um den Namen eines Customers über eine bekannte Travel zu  finden
    std::string findCustomerWTravel(TravelAgency* travelagency, Travel* travel);

    //Soll eine neue Buchung vom typ type anlegen
    int createBooking(char type, double price, std::string start, std::string end, long travelId, std::vector<std::string> bookingDetails);

    //testet ob es eine Travel mit der übergebenen id existiert
    int checkTravelId(long travelId);

    //Test Methoden
    int countAvisCompany();
    int countUnitedAirlines();
    int countBookingsWith1K();

    //Hilfs-Methode zum löschen der dynamischen Objekte am Ende des Programms
    void deleteObjects();

    void createGraphs();

    //========== Getter ==========
    unsigned int getCSumF() const {return cSumF;}
    unsigned int getCSumH() const {return cSumH;}
    unsigned int getCSumR() const {return cSumR;}
    double getPSumF() const {return pSumF;}
    double getPSumH() const {return pSumH;}
    double getPSumR() const {return pSumR;}

    //unsigned int getAllBookingSize() const {return allBookings.size();}
    unsigned int getLAllBookingSize() const {return lAllBooking.getSize();}
    unsigned int getAllCustomerSize() const {return allCustomers.size();}
    unsigned int getAllTravelsSize() const {return allTravels.size();}

    double getCompleteSum() const {return pSumF + pSumH + pSumR;}

    Booking* getBooking(unsigned int i);

    Customer* getCustomer(unsigned int i);

    //getter for the error
    int getRowCount() const {return rowCounter;}
    int getErrorPosition() const {return errorPosition;}

    //========== Setter ==========
    void setCSumF(unsigned int cSumF) {this->cSumF = cSumF;}
    void setCSumH(unsigned int cSumH) {this->cSumH = cSumH;}
    void setCSumR(unsigned int cSumR) {this->cSumR = cSumR;}
    void setPSumF(double pSumF) {this->pSumF = pSumF;}
    void setPSumH(double pSumH) {this->pSumH = pSumH;}
    void setPSumR(double pSumR) {this->pSumR = pSumR;}

    int getListSize() const {lAllBooking.getSize();}

    //======== Private ========
private:
    //Variablen zum zählen der Bookings
    unsigned int cSumF{0};
    unsigned int cSumH{0};
    unsigned int cSumR{0};
    //Variablen zum Berechnen des Preises
    double pSumF{0};
    double pSumH{0};
    double pSumR{0};

    //Vektoren um die jeweiligen Objekte zu speichern

    //std::vector<Booking*> allBookings;
    std::vector<Customer*> allCustomers;
    std::vector<Travel*> allTravels;

    //linkedList
    LinkedList<Booking*> lAllBooking;
    //Für Fehler
    int rowCounter;
    int errorPosition;

};


#endif // TRAVELAGENCY_H
