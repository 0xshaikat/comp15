/* COMP15
 * Shaikat Islam
 * HW4
 * 14-03-15
 * Heap.cpp
 */

#include <iostream>
#include "Heap.h"
using namespace std;

template <class E> Heap<E>::Heap()
{
    length = 0;
}

template <class E> Heap<E>::~Heap()
{

}

template <class E> bool Heap<E>::is_full() const
{
    return (length >= MAX_CAPACITY);
}

template <class E> bool Heap<E>::is_empty() const
{
    return (length == 0);
}

template <class E> int Heap <E>::get_parent_index(int c_i) const
{
    if (c_i == 0)
    {
        return 0;
    }
    else
    {
        return ((c_i - 1) / 2);
    }
}

template <class E> void Heap<E>::get_children_indices(int p, int &c1, int &c2) const
{
    int t = (p * 2) + 1;
    if (t <= (MAX_CAPACITY - 1))
    {
        c1 = t;
        t++;
        if (t <= (MAX_CAPACITY - 1))
        {
            c2 = t;
        }
        else
        {
            c2 = -1;
        }
    }
    else
    {
        c1 = -1;
        c2 = -1;
    }
}

template <class E> E Heap<E>::get_value_at(int i) const
{
    if (i < 0)
    {
        throw runtime_error("index is less than 0");
    }
    else if (i > (MAX_CAPACITY - 1))
    {
        throw runtime_error("index is greater than capacity");
    }
    else
    {
        return heap[i];
    }
}

template <class E> E Heap<E>::extract()
{
    if (length == 0)
    {
        throw EmptyHeap();
    }
    else
    {
        E temp = heap[0];
        heap[0] = heap[length - 1];
        length--;
        heapify_down(0);
        return temp;
    }
}

template <class E> void Heap<E>::insert_item(E item)
{
    if (length >= MAX_CAPACITY)
    {
        throw FullHeap();
    }
    else
    {
        heap[length] = item;
        length++;
        heapify_up(length - 1);
    }
}

template <class E> void Heap<E>::print() const
{
    cout << "Current Heap: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << i << " " << heap[i] << endl;
    }
}

template class Heap<int>;
template class Heap<double>;
template class Heap<Patient>;
