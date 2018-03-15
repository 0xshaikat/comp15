/* COMP15
 * Shaikat ISlam
 * HW4
 * 14-03-18
 * MaxHeap.h
 */

#include "Heap.h"

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

template<class E> class MaxHeap : public Heap <E>
{
 public:
    //construct and destruct
    MaxHeap();
    ~MaxHeap();

    //override virtual
    void heapify_up(int);
    void heapify_down(int);
};

#endif
