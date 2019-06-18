#include "travelagency.h"
#include <string>
#include "linkedlist.h"


//Methode readFile should read a txt file and save bookings as objects in a vector of pointers

/**
 * @brief TravelAgency::readFile
 */
void TravelAgency::readFile() {

    //RowCounter reset zum start des Funktionsaufrufes
    rowCounter = 0;

    //======== Variables ========
    //Variablen zum auslesen der Daten
    std::string zeile;
    std::string typ, id, price, fromDate, toDate, fromDest, toDest, travelId, customerId, name, //bis hierhin immer gleich
            airline, hotel, town, pickupLocation, returnLocation, company, seatPref, insuranceType, smoke;
    std::string abhaengigkeit1, abhaengigkeit2;


    // Öffnen und lesen der Datei
    std::ifstream quelle("bookings_praktikum5.txt", std::ios::out); // Objekt für Eingabestrom, ios::out zum lesen
    //Kontrolle mit Fehlermeldung ob die Datei geöffnet werden kann
    if(!quelle.is_open()) {

        std::cerr << "TASK FAILED SUCCESFULLY" << std::endl;
        exit(-1);
    }

    //Einlesen der Datei
    while(getline(quelle, zeile)) {

        //Schleifenzähler um die Zeile des Fehlers festzustellen
        rowCounter +=1;

        //Stringstream um die Strings einzulesen
        std::stringstream iss(zeile);

        //zeile für zeile durchgehen und '|' zählen
        int c{0};
        for (unsigned int i {0}; i< zeile.size(); i++) {
            if(zeile[i] == '|') {
                c ++;
            }
        }

        //Error position
        errorPosition = c;

        //Ersten Buchstaben der Zeile lesen um herauszufinden um welchen Typ buchung es sich handelt
        getline(iss, typ, '|');

        //AUSNAHMEBEHANDLUNG ========
        if(typ != "F" && typ != "H" && typ != "R") {
            throw std::invalid_argument("Falsches Attribut");
        }

        //Testen nach Anzahl an Attributen, bzw '|'
        if(typ == "F" && (c < 11 || c > 13) ) {

            throw std::invalid_argument("Attribut fehlt!");
        }
        else if(typ == "H" && (c < 10 || c > 12) ) {

            throw std::invalid_argument("Attribut fehlt!");
        }
        else if (typ == "R" && (c < 11 || c > 13) ) {

            throw std::invalid_argument("Attribut fehlt!");
        }
        //AUSNAHMEBEHANDLUNG ========


        //Rest einlesen der unabhängig der Typen ist
        getline(iss, id, '|');
        getline(iss, price, '|');
        getline(iss, fromDate, '|');
        getline(iss, toDate, '|');
        getline(iss, travelId, '|');
        getline(iss, customerId, '|');
        getline(iss, name, '|');

        //umwandlung in int und long von string
        std::string::size_type sz;
        int myint{};
        myint = std::stoi(id);
        double mydouble = stod(price);
        long myTravelId = std::stol (travelId, &sz);
        long myCustomerId = std::stol (customerId, &sz);

        //========== Flightbooking ==========
        if(typ == "F") {

            //einlesen sder spezifischen Daten
            getline(iss, fromDest, '|');
            getline(iss, toDest, '|');
            getline(iss, airline, '|');
            getline(iss, seatPref, '|');

            //seatPfer von string zu char;
            char myChar;
            myChar = seatPref.at(0);
            if(c == 11) {
                //newFlightBooking wird erstellt
                FlightBooking* newFlightBooking = new FlightBooking(myint, mydouble, fromDate, toDate, myTravelId, fromDest, toDest, airline, myChar);

                //in die Liste speichern
                lAllBooking.insertNode(newFlightBooking);

                //Anzahl an Flightbookings
                setCSumF(cSumF += 1);

                //Preis berechnen
                setPSumF(pSumF += newFlightBooking->getPrice());
            }

            else if(c == 12) {

                //getline für die evtl. abhängigkeiten
                getline(iss, abhaengigkeit1, '|');

                //newFlightBooking wird erstellt
                FlightBooking* newFlightBooking = new FlightBooking(myint, mydouble, fromDate, toDate, myTravelId, fromDest, toDest, airline, myChar, abhaengigkeit1);

                //in die Liste speichern
                lAllBooking.insertNode(newFlightBooking);

                //Anzahl an Flightbookings
                setCSumF(cSumF += 1);

                //Preis berechnen
                setPSumF(pSumF += newFlightBooking->getPrice());
            }
            else if(c == 13) {

                //getline für die evtl. abhängigkeiten
                getline(iss, abhaengigkeit1, '|');
                getline(iss, abhaengigkeit2, '|');

                //newFlightBooking wird erstellt
                FlightBooking* newFlightBooking = new FlightBooking(myint, mydouble, fromDate, toDate, myTravelId, fromDest, toDest, airline, myChar, abhaengigkeit1, abhaengigkeit2);

                //in die Liste speichern
                lAllBooking.insertNode(newFlightBooking);

                //Anzahl an Flightbookings
                setCSumF(cSumF += 1);

                //Preis berechnen
                setPSumF(pSumF += newFlightBooking->getPrice());
            }
        }
        //========== HotelBooking ==========
        else if (typ == "H") {

            //einlesen der spezifischen Daten
            getline(iss, hotel, '|');
            getline(iss, town, '|');
            getline(iss, smoke, '|');

            //von smoke zu bool
            bool myBool{};
            int myint{};
            myint = std::stoi(smoke);
            myBool = myint;

            if(c == 10) {

            //Anlegen des Objektes
            HotelBooking* newHotelBooking = new HotelBooking(myint, mydouble, fromDate, toDate, myTravelId, hotel, town, myBool);

            //in Liste speichern
            lAllBooking.insertNode(newHotelBooking);

            //Anzahl an Hotelbookings
            setCSumH(cSumH += 1);
            //Preis berechnen
            setPSumH(pSumH += newHotelBooking->getPrice());
            }
            else if (c == 11) {

                //getline für die evtl. abhängigkeiten
                getline(iss, abhaengigkeit1, '|');

                //Anlegen des Objektes
                HotelBooking* newHotelBooking = new HotelBooking(myint, mydouble, fromDate, toDate, myTravelId, hotel, town, myBool, abhaengigkeit1);

                //in Liste speichern
                lAllBooking.insertNode(newHotelBooking);

                //Anzahl an Hotelbookings
                setCSumH(cSumH += 1);
                //Preis berechnen
                setPSumH(pSumH += newHotelBooking->getPrice());
                }
            else if (c == 12) {

                //getline für die evtl. abhängigkeiten
                getline(iss, abhaengigkeit1, '|');
                getline(iss, abhaengigkeit2, '|');

                //Anlegen des Objektes
                HotelBooking* newHotelBooking = new HotelBooking(myint, mydouble, fromDate, toDate, myTravelId, hotel, town, myBool, abhaengigkeit1, abhaengigkeit2);

                //in Liste speichern
                lAllBooking.insertNode(newHotelBooking);

                //Anzahl an Hotelbookings
                setCSumH(cSumH += 1);
                //Preis berechnen
                setPSumH(pSumH += newHotelBooking->getPrice());
                }
            }

        //Typ rentalcarreservation
        else if (typ == "R") {

            //einlesen der spezifischen Daten
            getline(iss, pickupLocation, '|');
            getline(iss, returnLocation, '|');
            getline(iss, company, '|');
            getline(iss, insuranceType, '|');

            if(c == 11) {

            //Anlegen des Objektes
            RentalCarReservation* newRentalCarReservation = new RentalCarReservation(myint, mydouble, fromDate, toDate, myTravelId, pickupLocation, returnLocation, company, insuranceType);

            //Im Vektor allBookings speichern
            //allBookings.push_back(newRentalCarReservation);

                                //in Liste speichern
                                lAllBooking.insertNode(newRentalCarReservation);

            //Anzahl an RentalCarReservations
            setCSumR(cSumR += 1);
            //Preis berechnen
            setPSumR(pSumR += newRentalCarReservation->getPrice());
            }
            else if (c == 12) {

                //getline für die evtl. abhängigkeiten
                getline(iss, abhaengigkeit1, '|');

                //Anlegen des Objektes
                RentalCarReservation* newRentalCarReservation = new RentalCarReservation(myint, mydouble, fromDate, toDate, myTravelId, pickupLocation, returnLocation, company, insuranceType, abhaengigkeit1);

                //in Liste speichern
                lAllBooking.insertNode(newRentalCarReservation);

                //Anzahl an RentalCarReservations
                setCSumR(cSumR += 1);
                //Preis berechnen
                setPSumR(pSumR += newRentalCarReservation->getPrice());
            }
            else if (c == 13) {

                //getline für die evtl. abhängigkeiten
                getline(iss, abhaengigkeit1, '|');
                getline(iss, abhaengigkeit2, '|');

                //Anlegen des Objektes
                RentalCarReservation* newRentalCarReservation = new RentalCarReservation(myint, mydouble, fromDate, toDate, myTravelId, pickupLocation, returnLocation, company, insuranceType, abhaengigkeit1, abhaengigkeit2);

                //in Liste speichern
                lAllBooking.insertNode(newRentalCarReservation);

                //Anzahl an RentalCarReservations
                setCSumR(cSumR += 1);
                //Preis berechnen
                setPSumR(pSumR += newRentalCarReservation->getPrice());
            }

        }//Ende der if-else bedingungen

        //========== Travel ==========
        {
            //Testen ob es schon eine Travel mit dieser id gibt
            if(findTravel(myTravelId) == nullptr) {

                //Keine Travel gefunden -> eine neue muss erstellt werden

                //neuer vektor wird erstellt
                std::vector<Booking*> travelBookings;

                //Travel wird erstellt
                Travel* newTravel = new Travel(myTravelId, myCustomerId, travelBookings);

                //zur Travel die Buchung hinzufügen
                newTravel->addBooking(findBooking(myint));    //unterschied je nach dem welche buchung existiert

                //Im Vektor all Travels einspeichern
                allTravels.push_back(newTravel);
            }
           else {
                //Travel mit einer bestehenden gefunden -> es muss keine neue erstellt werden, die Buchung wird in eine bestehnde eingespeichert
                findTravel(myTravelId)->addBooking(findBooking(myint));
            }
        }
        //========== Customer ==========
        {
            //Testen ob es den Customer schon gibt. im Vektor allCustomers suchen! wenn nicht dann diesen erstellen
            if(findCustomer(myCustomerId) == nullptr) {

                //neuer Vektor wird erstellt
                std::vector<Travel*> travelList;

                //Customer wird erstellt
                Customer* newCustomer = new Customer(myCustomerId, name, travelList);

                //Zum Customer die Travel hinzufügen
                newCustomer->addTravel(findTravel(myTravelId));

                //Im Vektor allCustomers speichern
                allCustomers.push_back(newCustomer);
            }
            else {
                //Existierender Customer gefunden -> es muss kei neuer erstellt werden, die travel wird in den bestehenden eingespeichert
                findCustomer(myCustomerId)->addTravel(findTravel(myTravelId));
            }
        }

    }//Ende der while schleife

    //schließen der Datei nachdem sie nicht mehr gebraucht wird
    quelle.close();
}




//Methode findBooking. Should find a specific Booking by going through the vector
/**
 * @brief TravelAgency::findBooking
 * @param id
 * @return
 */
Booking* TravelAgency::findBooking(long id) {
    //durch den ganzen Vektor allBookings gehen und nach der überegebene id suchen. wenn eine Buchung mit der id gefunden wurde
    //soll diese zurückgegeben werden.
    //Wenn nichts gefunden wird, wird eine 0 zurückgegeben
    for (unsigned int i {0}; i < lAllBooking.getSize(); i++) {
        if(lAllBooking[i]->getID() == id ) {
            return lAllBooking[i];
        }
        //dynamic_cast<FlightBooking*>(allBookings.at(0))-> ...  ; bsp für dynamic cast
    }
    return nullptr;
}




//Methode findTravel. Should find a specific Travel
/**
 * @brief TravelAgency::findTravel
 * @param id
 * @return
 */
Travel* TravelAgency::findTravel(long id) {
    for (unsigned int i {0}; i < allTravels.size(); i++) {
        if(allTravels.at(i)->getTravelId() == id ) {
            return allTravels.at(i);
        }
    }
    return nullptr;
}




//Methode findCustomer. Should find a specific Customer
/**
 * @brief TravelAgency::findCustomer
 * @param id
 * @return
 */
Customer* TravelAgency::findCustomer(long id) {
    for (unsigned int i {0}; i < allCustomers.size(); i++) {
        if(allCustomers.at(i)->getCustomerId() == id) {
            return allCustomers.at(i);
        }
    }
    return nullptr;
}



//noch in den jeweiligen customer und travel die Buchung eintzragen



//Methode um eine einzige neue Buchung zu erstellen
/**
 * @brief TravelAgency::createBooking
 * @param type
 * @param price
 * @param start
 * @param end
 * @param travelId
 * @param bookingDetails
 * @return
 */
int TravelAgency::createBooking(char type, double price, std::string start, std::string end, long travelId, std::vector<std::string> bookingDetails) {

    long id {0};


    /*
    //id der Buchung muss vor dem anlege ermittelt werden: größte existierende id bestimmen, neue id soll um 1 größer sein
    for (unsigned int i {0}; i < allBookings.size(); i++) {
        if(id < allBookings.at(i)->getID()) {
            id = allBookings.at(i)->getID();
        }
    }
    id += 1;
    */
    id = lAllBooking.getSize() +1;
    if(id != 107) {
        throw std::invalid_argument("id ist nicht 107");
    }


    //Neue Buchung wird mit den übergebenen Werten erstellt und in allBookings gespeichert
    if(type == 'F') {

        //aus dem vektor bookingdetails das letzte holen und richtig umwandeln
        std::string fromDest = bookingDetails.at(0);
        std::string toDest = bookingDetails.at(1);
        std::string airline = bookingDetails.at(2);
        char seatPref;
        std::string myString = bookingDetails.at(3);
        seatPref = myString.at(0);

        std::cout <<"new booking" << " " <<  seatPref << std::endl;

        //Flightbooking erstellen
        FlightBooking* newFlightBooking = new FlightBooking(id, price, start, end, travelId, fromDest, toDest, airline, seatPref);
        //allBookings.push_back(newFlightBooking);


        findTravel(travelId)->addBooking(newFlightBooking);

        //Anzahl an Flightbookings
        setCSumF(cSumF += 1);
        //Preis berechnen
        setPSumF(pSumF += newFlightBooking->getPrice());

    }

    else if (type == 'H') {

        //aus dem vektor bookingdetails das letzte holen und richtig umwandeln
        bool myBool{};
        int myint{};
        myint = std::stoi(bookingDetails.at(2));
        myBool = myint;

        HotelBooking* newHotelBooking = new HotelBooking(id, price, start, end, travelId, bookingDetails.at(0), bookingDetails.at(1), myBool);
        //allBookings.push_back(newHotelBooking);
                lAllBooking.insertNodeS(newHotelBooking);

        findTravel(travelId)->addBooking(newHotelBooking);

        //Anzahl an Hotelbookings
        setCSumH(cSumH += 1);
        //Preis berechnen
        setPSumH(pSumH += newHotelBooking->getPrice());
    }
    else if (type == 'R') {
        RentalCarReservation* newRentalCarReservation = new RentalCarReservation(id, price, start, end, travelId, bookingDetails.at(0), bookingDetails.at(1), bookingDetails.at(2), bookingDetails.at(3));
        //allBookings.push_back(newRentalCarReservation);
                lAllBooking.insertNodeS(newRentalCarReservation);

        findTravel(travelId)->addBooking(newRentalCarReservation);

        //Anzahl an RentalCarReservations
        setCSumR(cSumR += 1);
        //Preis berechnen
        setPSumR(pSumR += newRentalCarReservation->getPrice());
    }

    //neue id dieser Buchung wird zurückgegeben
    return id;
}




//travel id soll überprüft werden. wenn die id schon existiert soll -1 zurückgegeben werden und keine Buchung zurückgeben
/**
 * @brief TravelAgency::checkTravelId
 * @param travelId
 * @return
 */
int TravelAgency::checkTravelId(long travelId) {
    for (unsigned int i {0}; i < allTravels.size(); i++) {
        if(travelId == allTravels.at(i)->getTravelId()) {
            return -1;
        }
    }
    return 1;
}




//Methode deleteObjects. Should delete all dynamic objects at the end of the programm
//Löschen funktioniert jetzt wie geplant. Ruft aber den Destruktor von booking auf, nicht von den kind klassen
/**
 * @brief TravelAgency::deleteObjects
 */
void TravelAgency::deleteObjects() {

    //std::cout << "Loeschen aller Bookings aus allBookings" << std::endl;
    //Delete all Bookings
    for (unsigned int i {0}; i < lAllBooking.getSize(); i++) {
        //delete allBookings.at(i);

        lAllBooking.deleteAllNodes();

    }
    //allBookings.clear();

    //std::cout << "Loeschen aller Customer aus allCustomer" << std::endl;
    //Delete all Customers
    for (unsigned int i {0}; i < allCustomers.size(); i++) {
        delete allCustomers.at(i);
    }
    allCustomers.clear();

    //std::cout << "Loeschen aller Travels aus allTravels" << std::endl;
    //Delete all Travels
    for (unsigned int i {0}; i < allTravels.size(); i++) {
        delete allTravels.at(i);
    }
    allTravels.clear();


}



//Gibt eine Booking zurück anhand dem Index im Vektor
/**
 * @brief TravelAgency::getBooking
 * @param i
 * @return
 */
Booking* TravelAgency::getBooking(unsigned int i) {
    return lAllBooking[i];
}



//Gibt einen Customer zurück anhand dem Index im Vektor
/**
 * @brief TravelAgency::getCustomer
 * @param i
 * @return
 */
Customer* TravelAgency::getCustomer(unsigned int i) {
    return allCustomers.at(i);
}




//gibt den Namen eines Customers zur dazugehörigen Buchung und deren Buchungs id
/**
 * @brief TravelAgency::findCustomerWTravel
 * @param travelagency
 * @param id
 * @return
 */
std::string TravelAgency::findCustomerWIndex(TravelAgency* travelagency, unsigned int id) {
    return travelagency->findCustomer(travelagency->findTravel(travelagency->getBooking(id)->getTravelId())->getCustomerId())->getCustomerName();
}

std::string TravelAgency::findCustomerWTravel(TravelAgency *travelagency, Travel* travel) {
    return travelagency->findCustomer(travel->getCustomerId())->getCustomerName();
}



void TravelAgency::writeNewFile(std::string newFileName) {

    std::ofstream file (newFileName);
    if(!file.good()) {
        std::cerr << newFileName << "Kann nicht beschrieben werden";
    }
    else {

        //alle Buchungen sollen in die Datei eingeschrieben werden. Einzelne Attribute mit | trennen
        //dynamic cast um zu testen welcher typ und dann die Attribute umwandeln und einzeln
        //verknüpfen als String

        for (unsigned int i {0};i < lAllBooking.getSize();i++) {
            //nach dem Typ testen
            if(dynamic_cast<FlightBooking*>(lAllBooking[i]) != nullptr) {

                //temp objekt erstellen
                FlightBooking* tempF = new FlightBooking;
                tempF = dynamic_cast<FlightBooking*>(lAllBooking[i]);

                //long, double, string,   string, long,     string,   string, string,  char
                //id,   price,  fromDate, toDate, travelId, fromDest, toDest, airline, seatPref

                //umwandlung zu strings
                std::string id = std::to_string(tempF->getID());
                std::string price = std::to_string(tempF->getPrice());
                std::string travelId = std::to_string(tempF->getTravelId());
                std::string seatPref = std::to_string(tempF->getSeatPref());

                //einlesen der Datei
                file << "F|" + id + "|" + price + "|" + tempF->getFromDate() + "|" + tempF->getToDate() + "|" + travelId + "|" + tempF->getFromDest() + "|" + tempF->getToDest() + "|" + tempF->getAirline() + "|" + seatPref + "\n";

                //temp objekt löschen
                delete tempF;
            }
            else if(dynamic_cast<HotelBooking*>(lAllBooking[i]) != nullptr) {

                //temp objekt erstellen
                HotelBooking* tempH = new HotelBooking;
                tempH = dynamic_cast<HotelBooking*>(lAllBooking[i]);

                //long, double, string,   string, long,      string, string, bool
                //id,   price,  fromDate, toDate, travelId,  hotel, town, smoke

                //umwandlung zu strings
                std::string id = std::to_string(tempH->getID());
                std::string price = std::to_string(tempH->getPrice());
                std::string travelId = std::to_string(tempH->getTravelId());

                //einlesen der Datei
                file << "H|" + id + "|" + price + "|" + tempH->getFromDate() + "|" + tempH->getToDate() + "|" + travelId + "|" + tempH->getHotel() + "|" + tempH->getTown() + "|" + tempH->showDetails() + "\n";

                //temp objekt löschen
                delete tempH;
            }
            else if (dynamic_cast<RentalCarReservation*>(lAllBooking[i]) != nullptr) {

                //temp objekt erstellen
                RentalCarReservation* tempR = new RentalCarReservation;
                tempR = dynamic_cast<RentalCarReservation*>(lAllBooking[i]);

                //long, double, string,   string, long,     string, string, string, string
                //id,   price,  fromDate, toDate, travelId, pickupL, returnL, company, insurance

                //umwandlung zu strings
                std::string id = std::to_string(tempR->getID());
                std::string price = std::to_string(tempR->getPrice());
                std::string travelId = std::to_string(tempR->getTravelId());

                //einlesen der Datei
                file << "R|" + id + "|" + price + "|" + tempR->getFromDate() + "|" + tempR->getToDate() + "|" + travelId + "|" + tempR->getPickupLocation() + "|" + tempR->getReturnLocation() + "|" + tempR->getCompany() + "|" + tempR->getInsuranceType() + "\n";

                //temp objekt löschen
                delete tempR;
            }
        }//end von for loop
        file.close();
    }
}
//========== Test Methoden ==========


//Anzahl an Avis companys bekommen
int TravelAgency::countAvisCompany() {

    int counter {0};

    for (unsigned int i{0}; i < lAllBooking.getSize(); i++) {
        if(dynamic_cast<RentalCarReservation*>(lAllBooking[i]) != nullptr) {
            if(dynamic_cast<RentalCarReservation*>(lAllBooking[i])->getCompany() == "Avis") {
                counter++;
            }
        }
    }
    return counter;
}

//Anzahl an United Airlines
int TravelAgency::countUnitedAirlines() {

    int counter{0};

    for (unsigned int i{0}; i < lAllBooking.getSize(); i++) {
        if(dynamic_cast<FlightBooking*>(lAllBooking[i]) != nullptr) {
            if(dynamic_cast<FlightBooking*>(lAllBooking[i])->getAirline() == "United Airlines") {
                counter++;
            }
        }
    }
    return counter;
}

int TravelAgency::countBookingsWith1K() {

    int counter{0};

    for (unsigned int i{0}; i < lAllBooking.getSize(); i++) {
        if(lAllBooking[i]->getPrice() >= 1000) {
            counter++;
        }
    }
    return counter;
}

void TravelAgency::createGraphs() {

    //durch jede Travel durchgehen und von dort die Methode createGraph aufrufen

    for (unsigned int i{0}; i < allTravels.size(); i++) {
        allTravels.at(i)->createGraph();
    }


}







