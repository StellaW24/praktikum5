/*
 * File:   heap.h
 * Author: arnim
 *
 * Created on 13. Dezember 2013, 07:51
 */

#ifndef HEAP_H
#define	HEAP_H
#include <stdexcept>
#include <string>

struct node_data {
    int i;
    std::string bezeichner;
    int end;
};

class Heap {
public:
    // Erstelle einen Heap aus dem Array a[] mit size Elementen
    Heap(node_data a[], unsigned int size);
    ~Heap();
    node_data pop();

private:
    void heapify(unsigned int start);
    node_data* data;
    unsigned int pointer;
};
#endif	/* HEAP_H */

