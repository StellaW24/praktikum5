#ifndef LINKEDLIST_H
#define	LINKEDLIST_H
#include "node.h"
#include <stdexcept>
#include <iostream>
using namespace std;


template<class T>class LinkedList {

public:
    LinkedList();

    //normales einfügen
    void insertNode(Booking* data);

    //sortiertes einfügen
    void insertNodeS(Booking* data);

    bool isAtEnd();

    void advance();

    void deleteNode();

    void deleteAllNodes();

    Booking* getNode() const {
        return cursor->GetData();
    };


    void reset() {
        cursor = root;
       // cerr << "Cursor zurueckgesetzt auf root" << endl;
    };

    Node* suche(Booking* data);

    //gibt einen node nach dessen index zurück Methode funktioniert wie sie soll
    Node* getNodeByIndex(int index) {
        cursor = root;
        for (int i{0};i < size;i++) {
            if(cursor->getIndex() == index) {
                return cursor;
            }
            else {
                advance();
            }
        }
    }

    Booking*  operator[](int i) {

        //cursor an den Anfang der Liste anbringen
        cursor = root;

        //schleife die so oft durchgeht wie i zb i = 5 für stelle 5, curser geht an stelle 5, dh 4 mal advance
        for (int j{0};j < i;j++) {
            advance();  //curser springt so lange nach vorne wie i groß ist
        }
        return cursor->GetData();   //wenn der cursor stelle i erreicht hat soll die Buchunmg zurück gegeben werden.
    }

    //setter
    void setSize(int size) {this->size = size;}
    //getter
    unsigned int getSize() const {return size;}

protected:
    Node* root;
    Node* cursor;
    Node* end;
    unsigned int size;
    //index zähler für nodes, ähnliche funktion wie size?
    int nIndex;
    //counter für die Methode
    int sortCounter;

};

template<class T> LinkedList<T>::LinkedList() {
    root = NULL; // root darf nur bei einer leeren Liste gleich NULL sein
    //end = new Node("End of list");  // Dummyknoten
    end = new Node; //dieser erste Node braucht keinen Index
    cursor = end;

    //size und indexCounter für die einzelnen Nodes, hätte
    size = 0;
    nIndex = 0;
    sortCounter = 0;
}

template<class T> bool LinkedList<T>::isAtEnd() {
        return (cursor == end);
}

template<class T> void LinkedList<T>::advance() {
    if (cursor && cursor->GetNextNode()) {
        cursor = cursor->GetNextNode();
       // cerr << "Cursor weitergeschoben auf " << cursor << endl;
    } else {
    }
     //   cerr << "Cursor ist schon am Ende " << endl
}







template<class T> void LinkedList<T>::insertNode(Booking* data) {


    //neuer Node der einen Index braucht!
    Node* node = new Node(data, nIndex ); // erzeuge neuen Knoten, bei dem vorhergehender
    // und nachfolgender Knoten per Default auf nullptr
    // gesetzt sind (siehe Konstruktor von node)

    //size und indexC muss erhöht werden
    size ++;
    nIndex ++;

    //hier gehts normal weiter
    if (root == nullptr) {
        // Leere Liste: Der root-Knoten wird auf den neuen Knoten umgesetzt und der
        // neue Knoten wird mit dem end-Knoten verkettet:
        root = node;
        node->SetNextNode(end);
        end->SetPreviousNode(node);
    } else {
        // Der Nachfolger des neuen Knotens wird initialisiert mit dem Cursor-Knoten;
        // es wird also VOR dem aktuellen Element eingefuegt:
        node->SetNextNode(cursor);

        // Der Vorgaenger des neuen Knotens wird mit dem Vorgaenger des Cursors
        // initialisiert, auch wenn dieser nullptr ist:
        node->SetPreviousNode(cursor->GetPreviousNode());

        // Falls der Vorgaenger-Knoten existiert, wird der neue Knoten als
        // dessen Nachfolger eingesetzt:
        if (cursor->GetPreviousNode())
            cursor->GetPreviousNode()->SetNextNode(node);
        // Jetzt wird noch der neue Knoten als Vorgaenger des Cursor-Knotens
        // eingetragen:
        cursor->SetPreviousNode(node);
    }
    // Alle Links sind eingetragen; jetzt kann der cursor umgesetzt werden:
    cursor = node;

    // Falls der neue Knoten der erste in der Liste ist, wird root umgehängt:
    if (!cursor->GetPreviousNode())
        root = cursor;
}

template<class T> void LinkedList<T>::insertNodeS(Booking *data) {

    cursor = root;  //cursor auf den Anfgang setzen

    if(sortCounter != 0) {  //wenn schon mindestens ein Element in der Liste ist

        //wenn nur eine Sache drin ist, ist getnext null
        while (cursor->GetNextNode() != nullptr) { //Solange der Cursor nicht am Ende ist (es noch einen Knoten weiter vorne gibt)

        //if (data < cursor->GetNextNode()->GetData())    //vllt sowas wie if(booking.travelId < cursor->GetNextNode().GetData().TravelID
            if(data->getTravelId() > cursor->GetNextNode()->GetData()->getTravelId()) {
                advance();
                //break;
            }
            else {
                break;
                cursor = cursor->GetNextNode();
            }

        /*
        break;
        cursor = cursor->GetNextNode();
        */
        }
    }

    Node* node = new Node(data,nIndex); // erzeuge neuen Knoten, bei dem vorhergehender
    // und nachfolgender Knoten per Default auf nullptr
    // gesetzt sind (siehe Konstruktor von node)

    //sitze erhöhen für jede neue Buchung erhöhen
    size ++;
    //index erhöhen für nachfolgende Nodes
    nIndex ++;

    if (root == nullptr) {
        // Leere Liste: Der root-Knoten wird auf den neuen Knoten umgesetzt und der
        // neue Knoten wird mit dem end-Knoten verkettet:
        root = node;
        node->SetNextNode(end);
        end->SetPreviousNode(node);
    } else {
        // Der Nachfolger des neuen Knotens wird initialisiert mit dem Cursor-Knoten;
        // es wird also VOR dem aktuellen Element eingefuegt:
        node->SetNextNode(cursor);

        // Der Vorgaenger des neuen Knotens wird mit dem Vorgaenger des Cursors
        // initialisiert, auch wenn dieser nullptr ist:
        node->SetPreviousNode(cursor->GetPreviousNode());

        // Falls der Vorgaenger-Knoten existiert, wird der neue Knoten als
        // dessen Nachfolger eingesetzt:
        if (cursor->GetPreviousNode())
            cursor->GetPreviousNode()->SetNextNode(node);
        // Jetzt wird noch der neue Knoten als Vorgaenger des Cursor-Knotens
        // eingetragen:
        cursor->SetPreviousNode(node);
    }
    // Alle Links sind eingetragen; jetzt kann der cursor umgesetzt werden:
    cursor = node;

    // Falls der neue Knoten der erste in der Liste ist, wird root umgehängt:
    if (!cursor->GetPreviousNode())
        root = cursor;

    //counter erhöhen, es wurde schon mehr als einmal ein Knoten hinzufgefügt
    sortCounter ++;
}


template<class T> void LinkedList<T>::deleteNode() {
    Node* tmpPrevious; // temporaere Variablen, fuer den Fall, dass der
    Node* tmpNext;     // zu loeschende Knoten in der Mitte der Liste ist

    if (root == nullptr) {
        // Liste leer, nichts zu loeschen
        throw underflow_error("Versuch aus leerer Liste zu loeschen");
    } else {
        if (cursor->GetPreviousNode() == nullptr) {
            if (cursor->GetNextNode() == end) {
                // Fall 1: Die Liste besteht nur aus einem einzigen Knoten
                // Knoten loeschen, Speicher freigeben,Zeiger root und cursor loeschen

                delete cursor->GetData();   //erst Objekt löschen aus dem Node
                delete cursor;
                root = nullptr;
                end->SetPreviousNode(nullptr);
                cursor = end;
            } else {
                // Fall 2: Die Liste besteht aus mehreren Knoten, von denen der
                // erste (also der root-Knoten) geloescht werden soll.
                // Anschliessend wird der Speicherplatz wieder freigegeben

                // Zeiger auf den naechsten Knoten setzen
                cursor = cursor->GetNextNode();

                delete root->GetData(); //erst Objekt löschen aus dem Node
                delete (root);

                // Cursor-Knoten ist jetzt erster Knoten: Vorgaenger auf NULL setzen:
                cursor->SetPreviousNode(nullptr);

                // Neuen root-Knoten setzen:
                root = cursor;
            }
        } else { //cursor.getPrevious() == nullptr)
            if (cursor->GetNextNode() == end) {
                // Fall 3: Die Liste besteht aus mehreren Knoten, von denen der
                // letzte geloescht werden soll.
                // Anschliessend wird der Speicherplatz fuer diesen Knoten
                // wieder freigegeben

                // cursor-Knoten auf den Endknoten setzen
                tmpPrevious = cursor->GetPreviousNode();

                delete cursor->GetData();       //erst Objekt löschen aus dem Node
                delete cursor;
                cursor = end;
                end->SetPreviousNode(tmpPrevious);
                tmpPrevious->SetNextNode(end);
            } else {//cursor->GetNext() == end)
                // Fall 4: Die Liste besteht aus mehreren Knoten.
                // Es wird weder der erste noch der letzte Knoten geloescht.
                // Die Adresse des vorhergehenden Knotens in tmpPrevious sichern,
                // und die Adresse des naechsten Knotens in tmpNext sichern.
                tmpPrevious = cursor->GetPreviousNode();
                tmpNext = cursor->GetNextNode();
                // Den aktuellen Knoten loeschen

                delete cursor->GetData();       //erst Objekt löschen aus dem Node
                delete cursor;

                // Die Knoten tmpPrevious und tmpNext verketten
                tmpPrevious->SetNextNode(tmpNext);
                tmpNext->SetPreviousNode(tmpPrevious);

                // Den Zeiger auf das Element nach dem alten Knoten setzen7
                cursor = tmpNext;
            }
        }
    }
    return;
}




//suche muss noch nach einem Attribut angepasst werden. zb id
template<class T> Node* LinkedList<T>::suche(Booking* data) {
    reset();
    while (cursor != end) {
        if (cursor->GetData() == data)
            return cursor;
        else
            cursor = cursor->GetNextNode(); // cursor auf Folgeelement setzen
    }
    return nullptr; // nicht gefunden
};


template<class T> void LinkedList<T>::deleteAllNodes() {

cursor = root;
    for (unsigned int i{0};i < size; i++) {
        deleteNode();
    }

}














#endif	/* LINKEDLIST_H */
/*
 *LinkedList();

    void insertNode(string data);

    bool isAtEnd() {
        return (cursor == end);
    };

    void advance() {
        if (cursor && cursor->GetNextNode()) {
            cursor = cursor->GetNextNode();
           // cerr << "Cursor weitergeschoben auf " << cursor << endl;
        } else
         //   cerr << "Cursor ist schon am Ende " << endl
            ;
    };

    void deleteNode();

    string getNode() {
        return cursor->GetData();
    };

    void reset() {
        cursor = root;
       // cerr << "Cursor zurueckgesetzt auf root" << endl;
    };

    Node* suche(string data);

protected:
    Node* root;
    Node* cursor;
    Node* end;
*/
