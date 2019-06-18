#include "hotelbooking.h"

std::string HotelBooking::showDetails() {
    std::string myString;
    if(smoke == true) {
        myString = "Smoke";
    }
    else {
        myString = "Smokeless";
    }
    return myString;
}
