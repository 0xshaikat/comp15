/* COMP15
 * Shaikat Islam
 * HW 4
 * 14-03-18
 * MaxHeap.cpp
 */

#include <iostream>
#include "MaxHeap.h"
using namespace std;

// constructor
template <class E> MaxHeap<E>::MaxHeap()
{

}

// destructor
template <class E> MaxHeap<E>::~MaxHeap()
{

}

//heapify_up
//Params: int
//Returns: void
//Purpose: takes element in given index of heap and determines
//whether to keep moving itself in order to balance the heap.
template <class E> void MaxHeap<E>::heapify_up(int i)
{
    int p = this->get_parent_index(i);
    if (p == i)
    {
        return;
    }
    else if (this->heap[p] > this->heap[i])
    {
        return;
    }
    else if (this->heap[p] == this->heap[i])
    {
        return;
    }
    else
    {
        E temp = this->heap[p];
        this->heap[p] = this->heap[i];
        this->heap[i] = temp;
        heapify_up(p);
    }
}
//heapify_down
//Params: int
//Return: void
//Purpose: takes element in given index of heap and determines
// whether or not to keep moving down in order to preserve balance.
template <class E> void MaxHeap<E>::heapify_down(int i)
{
    int c1, c2;
    this->get_children_indices(i, c1, c2);
    if (c1 <= ((this->length) - 1))
    {
        if (c2 > ((this->length) - 1))
        {
            E l_v = this->heap[c1];
            if (l_v > this->heap[i])
            {
                this->heap[c1] = this->heap[i];
                this->heap[i] = l_v;
                heapify_down(c1);
            }
        }
        else
        {
            E l_v = this->heap[c1];
            E r_v = this->heap[c2];
            if (l_v == r_v)
            {
                if (l_v > this->heap[i])
                {
                    this->heap[c1] = this->heap[i];
                    this->heap[i] = l_v;
                    heapify_down(c1);
                }
            }
            else
            {
                if (l_v > r_v)
                {
                    if (l_v > this->heap[i])
                    {
                        this->heap[c1] = this->heap[i];
                        this->heap[i] = l_v;
                        heapify_down(c1);
                    }
                }
                else
                {
                    if (r_v > this->heap[i])
                    {
                        this->heap[c2] = this->heap[i];
                        this->heap[i] = r_v;
                        heapify_down(c2);
                    }
                }
            }
        }
    }
}

// Declare types of MaxHeap
template class MaxHeap<int>;
template class MaxHeap<double>;
template class MaxHeap<Patient>;
