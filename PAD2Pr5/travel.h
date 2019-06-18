#ifndef TRAVEL_H
#define TRAVEL_H

#include "booking.h"
#include "graph.h"
#include"heap.h"
#include "algorithm"

#include "onegraph.h"


#include <iostream>
#include <vector>

//Aggregation zu Booking als Oberklasse
//Aggregation zu TravelAgency als Subklasse
//Aggregation zu Customer als Subklasse

class Travel
{
    //========== Public ==========
public:
    //========== Constructor ==========
    //Standard konstruktor
    Travel() {
    }
    //Konstruktor mit Initialisierungsliste
    Travel(long tId, long customerId, std::vector<Booking*> travelBookings) :
    tId{tId}, customerId{customerId}, travelBookings{travelBookings}    {
    }
    //Destruktor
    ~Travel() {

        travelBookings.clear();
    }
    //========== Methodes ==========
    void addBooking(Booking* booking);  //Wird dazu genutzt eine Buchung in den Vektor travelBookings zu speichern
    void deleteObjects();
    unsigned long long countBookings();

    //methode die sich um das erstellen der Graphen für jede Travel kümmert
    void createGraph();

    //========== Getter ==========
    long getTravelId() const {return tId;}
    long getCustomerId() const {return customerId;}
    //======== Private ========
private:
    long tId{};  //in dem Fall ist es die travelId aus Travelagency
    long customerId{};
    std::vector<Booking*> travelBookings; 

    Graph<Travel, 0>* graph; //platzhalter für einen Graphen pro Travel  Methode um die Graphen zu erstellen für jede Travel muss in Travelagency
                            //gemacht werden, eine UI aufruf in Mainwindow

    //std::vector<OneGraph> graphs;
};

#endif // TRAVEL_H



/*
 *
 *
 * #include <QCoreApplication>
#include "graph.h"
#include "algorithmen.cpp"
#include "heap.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    const int n = 10;
    Graph<string, n>* graph = new Graph<string, n>;
    node_data sortedArray[10];
    node_data node;

    graph->insertVertex(7, "Uhr");
    graph->insertVertex(9, "Unterhose");
    graph->insertVertex(2, "Hose");
    graph->insertVertex(6, "Hemd");
    graph->insertVertex(5, "Guertel");
    graph->insertVertex(4, "Krawatte");
    graph->insertVertex(1, "Schuhe");
    graph->insertVertex(8, "Socken");
    graph->insertVertex(3, "Sakko");

    graph->insertArc(9, 2);
    graph->insertArc(2, 5);
    graph->insertArc(6, 5);
    graph->insertArc(5, 3);
    graph->insertArc(6, 4);
    graph->insertArc(4, 3);
    graph->insertArc(8, 1);
    graph->insertArc(9, 1);
    graph->insertArc(2, 1);

    DepthFirstSearch(*graph);

    for (int i = 1; i <= 9; i++) {
        sortedArray[i].i = i;
        sortedArray[i].bezeichner = graph->getVertexValue(i);
        sortedArray[i].end = graph->getEnd(i);
    }

    Heap myHeap(sortedArray, 9);

    for (int i = 1; i <= 9; i++) {
        node = myHeap.pop();
        cout << i << " " << setw(15) << node.bezeichner << " " << node.end << endl;
    }
    return a.exec();
}
*/
