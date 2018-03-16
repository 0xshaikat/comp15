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

//is_full()
//Params: none
//Returns: bool
//Purpose: determines if every element in heap array is filled
template <class E> bool Heap<E>::is_full() const
{
    return (length >= MAX_CAPACITY);
}

//is_empty()
//Params: none
//Returns: bool
//Purpose: determines if heap array is empty
template <class E> bool Heap<E>::is_empty() const
{
    return (length == 0);
}

//get_parent_index
//Params: int
//Returns: int
//Purpose: calculates index of parent based on index of child
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

//get_children_indices
//Params: int, int &, int &
//Returns: void
//Purpose: calculates indices of left and right children given index of parent
// and updates variables
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
//get_value_at
//Params: int
//Returns: Element type of heap
//Purpose: returns element at given index in heap array
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

//extract
//Params: none
//Returns: element type of heap
//Purpose: returns topmost element of heap and adjusts it to balance
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

//insert_item
//Params: element type of heap
//Returns: void
//Purpose: inserts item in heap array and updates heap to balance it
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

//print
//Params: none
//Returns: void
//Purpose: prints every element in heap array
template <class E> void Heap<E>::print() const
{
    cout << "Current Heap: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << i << " " << heap[i] << endl;
    }
}

//declare types of Heap
template class Heap<int>;
template class Heap<double>;
template class Heap<Patient>;
