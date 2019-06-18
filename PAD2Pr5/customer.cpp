#include "customer.h"

//Method addTravel. Soll eine Travel dem Vektor travelList hinzufügen
void Customer::addTravel(Travel* travel) {
    travelList.push_back(travel);
};

//Method deleteObjects for deleting the dynamic objects in travellist
void Customer::deleteObjects() {
    for (unsigned int i {0}; i < travelList.size(); i++) {
        delete travelList[i];
    }
    travelList.clear();
}

//gibt die größe von travelList raus
unsigned long long Customer::countTravel() {
    unsigned long long i {};
    i = travelList.size();
    return i;
}
