/*
 * File:   item.h
 * Author: arnim
 *
 * Created on 11. Dezember 2013, 17:53
 */

#ifndef NODE_H
#define	NODE_H
#include <string>
#include "booking.h"

using namespace std;

class Node {

public:
    Node(){}

    //Konstruktor in dem der Index mit angegeben werden muss
    Node(Booking* data, int index) : data(data),previousNode(nullptr),nextNode(nullptr),index(index) {
    }

    Node* GetNextNode() const {
        return nextNode;
    }

    void SetNextNode(Node* nextNode) {
        this->nextNode = nextNode;
    }

    Node* GetPreviousNode() const {
        return previousNode;
    }

    void SetPreviousNode(Node* previousNode) {
        this->previousNode = previousNode;
    }

    Booking* GetData() const {
        return data;
    }

    void SetData(Booking* data) {
        this->data = data;
    }

    int getIndex() const {return index;}

private:
    Booking* data;
    Node* previousNode;
    Node* nextNode;
    //jeder neue Node bekommt einen Index mit dem man den Node identifizieren kann
    int index;
};






/*
public:
    Node(){}

    Node(string data) : data(data),previousNode(nullptr),nextNode(nullptr) {
    }

    Node* GetNextNode() const {
        return nextNode;
    }

    void SetNextNode(Node* nextNode) {
        this->nextNode = nextNode;
    }

    Node* GetPreviousNode() const {
        return previousNode;
    }

    void SetPreviousNode(Node* previousNode) {
        this->previousNode = previousNode;
    }

    string GetData() const {
        return data;
    }

    void SetData(string data) {
        this->data = data;
    }

private:
    string data;
    Node* previousNode;
    Node* nextNode;
};
*/

#endif	/* NODE_H */

