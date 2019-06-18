#include "travel.h"

//Method addBooking. Soll eine Booking dem Vektor travelBookings von eines Objekts der Klasse Travel hinzufügen
void Travel::addBooking(Booking* booking) {
    travelBookings.push_back(booking);
};

//Method for deleting all dynamic objects in travelBookings
void Travel::deleteObjects() {
    for (unsigned int i {0}; i < travelBookings.size(); i++) {
        delete travelBookings[i];
    }
    travelBookings.clear();
}

//Gibt die größe von travelBookings raus
unsigned long long Travel::countBookings() {
    unsigned long long i {};
    i = travelBookings.size();
    return i;
}


void Travel::createGraph() {

//travelBookings
//die Buchungen in TravelBookings bilden die einzelnen Knoten des Graphen
    //for (unsigned int i{0}; i < travelBookings.size(); i++) {

    //}

    //Graph<string, n>* graph = new Graph<string, n>;

//const int n = travelBookings.size();

//Graph<Travel, n>* graph = new Graph <Travel,


}
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
