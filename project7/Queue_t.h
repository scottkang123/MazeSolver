// File name: Queue_t.h
// Author: Scott Kang
// userid: kangk
// Email: kyung.ho.kang@vanderbilt.edu
// Class: CS2201
// Assignment Number: #7
// Honor Statement: I have not given or received unauthorized aid on this assignment
// Description: This is a template header for class Queue. This class lists methods in Queue.cpp
// Last Changed: 2019 11/9



#ifndef QUEUE_T_H
#define QUEUE_T_H

#include <cstddef>   // make gcc & CLion happy

template <typename ItemType>
class Queue
{
private:

    struct queue{
        ItemType item;
        queue* next;
    };
    typedef queue* queueNodePointer;

    queueNodePointer myTop;
    size_t queueSize;


public:
    // Class Constructor
    Queue();

    // Copy Constructor
    // pre:  Class object, aQueue, exists
    // post: Object is initialized to be a copy of the parameter
    Queue(const Queue<ItemType>& Queue);

    // Class Destructor
    // Destroys a queue
    // pre:  Class object exists
    // post: Class object does not exist
    ~Queue();

    // Assignment operator
    // Assigns a queue to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class object
    const Queue& operator= (const Queue<ItemType>& rhs);

    // isEmpty
    // Checks if the queue is empty
    // pre:  A queue exists.
    // post: Returns true if it IS empty, false if NOT empty.
    bool isEmpty() const;

    // enqueue
    // enqueues an item to back of the queue.
    // pre:  DblQueue exists and item is passed.
    // post: adds the given item to the end of the queue.
    void enqueue(const ItemType& item);

    // dequeue
    // dequeues the front item off the queue
    // pre:  DblQueue exists.
    // post: Removes item on front of the queue. If the queue
    //       was already empty, throws an std::underflow_error exception.
    void dequeue();

    // front
    // Returns the front item of the queue without dequeueing it.
    // pre:  DblQueue exists.
    // post: Returns item at front of queue.  If the queue is empty,
    //       throws an std::underflow_error exception.
    ItemType front() const;

    // size
    // Returns the number of items on the queue.
    size_t size() const;

};

#include "Queue_t.cpp"

#endif
