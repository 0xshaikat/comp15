/* COMP15
 * Shaikat Islam
 * HW 4
 * 14-03-15
 * MinHeap.h
 */

#include <iostream>
#include "MinHeap.h"
using namespace std;

// constructor
template <class E>MinHeap<E>::MinHeap()
{
}

// destructor
template <class E> MinHeap<E>::~MinHeap()
{
}

template <class E> void MinHeap<E>::heapify_up(int i)
{
    int p = this->get_parent_index(i);
    if (p == i)
    {
        return;
    }
    else if (this->heap[p] < this->heap[i])
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

template <class E> void MinHeap<E>::heapify_down(int i)
{
    int c1, c2;
    this->get_children_indices(i, c1, c2);
    if (c1 <= ((this->length) - 1))
    {
        if (c2 > ((this->length) - 1))
        {
            E l_v = this->heap[c1];
            if (l_v < this->heap[i])
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
                if (l_v < this->heap[i])
                {
                    this->heap[c1] = this->heap[i];
                    this->heap[i] = l_v;
                    heapify_down(c1);
                }
            }
            else
            {
                if (l_v < r_v)
                {
                    if (l_v < this->heap[i])
                    {
                        this->heap[c1] = this->heap[i];
                        this->heap[i] = l_v;
                        heapify_down(c1);
                    }
                }
                else
                {
                    if (r_v < this->heap[i])
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

// Declare types of MinHeap
template class MinHeap<int>;
template class MinHeap<double>;
template class MinHeap<Patient>;
