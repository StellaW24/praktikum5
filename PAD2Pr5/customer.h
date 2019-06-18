#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "travel.h"

#include <iostream>
#include <vector>

//===== Aggregation zu Travel als Oberklasse =====
//===== Aggregation zu TravelAgency als Subklasse =====

class Customer
{
    //========== Public ==========
public:
    //========== Constructor ==========
    //Standartkonstruktor
    Customer() {
    }
    //Konstruktor mit Initialisierungsliste
    Customer(long cId, std::string name, std::vector<Travel*> travelList) :
        cId{cId}, name{name}, travelList{travelList} {
    }
    //Destruktor
    ~Customer() {

        travelList.clear();
    }
    //========== Methodes ==========
    void addTravel(Travel* travel);
    void deleteObjects();
    unsigned long long countTravel();
    //========== Getter ==========
    long getCustomerId() const {return cId;}
    std::string getCustomerName() const {return name;}
    //======== Private ========
private:
    long cId{};
    std::string name;
    std::vector<Travel*> travelList;
};

#endif // CUSTOMER_H
