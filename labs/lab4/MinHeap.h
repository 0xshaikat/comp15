/*
 * MinHeap.h
 *
 * COMP15
 * Spring 2018
 *
 * Derived class for MinHeap type
 * Inherits from abstract Heap class
 *
 */

#include "Heap.h"

#ifndef MINHEAP_H_
#define MINHEAP_H_

template<class E> class MinHeap : public Heap<E>
{
public:
    MinHeap();
    ~MinHeap();

private:    
    // Overriding purely virtual functions
    void heapify_up(int);
    void heapify_down(int);
};

#endif
