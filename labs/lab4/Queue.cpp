/*
 * Queue.cpp
 *
 * COMP15 Spring 2018
 * Lab 4 Starter Code
 * Queue as Template class
 */

#include <iostream>
#include "Queue.h"
#include "Patient.h"
using namespace std;

// Constructor (note the
// template<class E> as part of
// function declaration)
template<class E>
Queue<E>::Queue()
{
    front = NULL;
    rear = NULL;
}

// Destructor
template<class E>
Queue<E>::~Queue()
{
    NodeType<E> *temp;

    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
}

// Copy Constructor
template<class E>
Queue<E>::Queue(const Queue<E> &q)
{
    if (q.front == NULL)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        try
        {
            front = new NodeType<E>;
        }
        catch (bad_alloc exception)
        {
            cerr << "Could not copy queue\n";
            return;
        }
        front->value = q.front->value;
        NodeType<E> *curr = front;
        NodeType<E> *orig = q.front;
        while (orig->next != NULL)
        {
            try
            {
                curr->next = new NodeType<E>;
                curr->next->value = orig->next->value;
                orig = orig->next;
                curr = curr->next;
                rear = curr;
            }
            catch (bad_alloc exception)
            {
                cerr << "Could not copy queue\n";
                return;
            }
        }
    }
}

// Assignment operator
template<class E>
Queue<E> & Queue<E>::operator = (const Queue<E> &q)
{
    while (front != NULL)
    {
        NodeType<E> *temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
    if (q.front == NULL)
    {
        front = NULL;
    }
    else
    {
        try
        {
            front = new NodeType<E>;
            front->value = q.front->value;
            NodeType<E> *curr = front;
            NodeType<E> *orig = q.front;
            while (orig->next != NULL)
            {
                curr->next = new NodeType<E>;
                curr->next->value = orig->next->value;
                orig = orig->next;
                curr = curr->next;
                rear = curr;
            }
        }
        catch (bad_alloc exception)
        {
            cerr << "Could not copy queue\n";
        }
    }
    return *this;
}

// Empty out the queue and deallocate memory    
template<class E>
void Queue<E>::make_empty()
{
    NodeType<E> *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
}

// Attempt to allocate space
// Return false if we could (Queue not full)
// or true otherwise
template<class E>
bool Queue<E>::is_full() const
{
    NodeType<E> *location;
    try 
    {
        location = new NodeType<E>;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

// Queue is empty if front pointer is NULL
template<class E>
bool Queue<E>::is_empty() const
{
    return (front == NULL);
}

// Enqueue a new item onto the back of the queue
template<class E>
void Queue<E>::enqueue(E new_item)
{
    if (is_full())
        throw FullQueue();
    else
    {
        NodeType<E> *new_node;
        new_node = new NodeType<E>;
        new_node->value = new_item;
        new_node->next = NULL;
        if (rear == NULL)
            front = new_node;
        else
            rear->next = new_node;
        rear = new_node;
    }
}

// Count the number of nodes in the queue
template<class E>
int Queue<E>::get_length() const
{
    int count = 0;
    NodeType<E> *temp = front;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// Dequeue one item from the front of the queue
template<class E>
E Queue<E>::dequeue()
{
    if (is_empty())
        throw EmptyQueue();
    else
    {
        E item;
        NodeType<E> *temp;
        temp = front;
        item = front->value;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
        return item;
    }
}

// Template class specifications
template class Queue<Patient>;
template class Queue<int>;
template class Queue<double>;
