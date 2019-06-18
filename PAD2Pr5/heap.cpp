#include "heap.h"
#include <iostream>
#include <cmath>
using namespace std;

Heap::Heap(node_data a[], unsigned int size){
    data = new node_data[size + 1];
    for (unsigned int i = 1; i <= size; i++){
        data[i] = a[i];
    }
    pointer = size;

    //Heap-Ordnung herstellen, indem fur den letzten Knoten, der kein Blatt ist,
    //heapify augerufen wird:
    for (unsigned int i = size/2; i>= 1; i--)
        heapify(i);
}

void Heap::heapify(unsigned int start){
    int new_start;

    if (2 * start > this->pointer){
        return;  //Schon auf Blattebene angekommen
    }
    if (2 * start + 1 <= this->pointer  //Es gibt auch rechtes Kind
            && data[2*start+1].end > data[2*start].end){
        new_start = 2 * start + 1; //rechtes Kind als Vergleichsfeld nehmen
    } else {
        new_start = 2 * start;   //linkes Kind als Vergleichsfeld nehmen
    }
    if (data[start].end < data[new_start].end){
        node_data tmp = data[start];
        data[start] = data[new_start];
        data[new_start] = tmp;
        heapify(new_start);
    }
}

Heap::~Heap(){
    delete[] data;
}

node_data Heap::pop(){
    if (pointer < 1)
        throw underflow_error("Heap ist leer");
    node_data res = data[1];
    data[1] = data[pointer];
    pointer--;
    heapify(1);
    return res;
}
