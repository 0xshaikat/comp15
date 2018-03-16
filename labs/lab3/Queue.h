/* 
 * Queue.h
 *
 * COMP15
 * Spring 2018
 * Interface for a Queue class
 * Used as auxiliary data structure by the Binary Trees
 * 
 */

#include <exception>
#include <string>

using namespace std;

#ifndef QUEUE_H_
#define QUEUE_H_

class FullQueue : public exception{
public:
    const char * what() const throw() {return "Oh no, the queue is full!\n";}; 
};

class EmptyQueue : public exception{
public:
    const char * what() const throw() {return "Sad, the queue is empty!\n";}
};

typedef string TreeItem;

struct BinaryNode
{
    TreeItem info;
    BinaryNode *left;
    BinaryNode *right;
};

struct NodeType
{
    BinaryNode *value;
    NodeType *next;
};

class Queue
{
private:
    NodeType *front;
    NodeType *rear;

public:
    Queue();
    ~Queue();
    Queue(const Queue &);
    Queue & operator = (const Queue &);

    void enqueue(BinaryNode *);
    bool is_full() const;

    BinaryNode* dequeue();
    bool is_empty() const;
};

#endif
