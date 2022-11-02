// File name: Queue_t.cpp
// Author: 
// userid: 
// Email: 
// Class: 
// Assignment Number:
// Description:  
// Last Changed: 


#include <cstddef>
#include <stdexcept>


// Class Constructor
// post: queue is created & initialized to be empty

template <typename ItemType>
Queue<ItemType> :: Queue(): myTop(nullptr), queueSize(0){

}

// Copy Constructor
// pre: parameter object, rhs, exists
// post: queue is created to be a copy of the parameter queue

template <typename ItemType>
Queue<ItemType> :: Queue(const Queue<ItemType>& rhs): myTop(nullptr), queueSize(rhs.queueSize){

    if (rhs.myTop != nullptr) {
        myTop = new queue;
        myTop-> item = rhs.myTop-> item;
        myTop -> next = nullptr;

        queueNodePointer newPtr = myTop;

        //as long as the right stack does not reach the end, add a new node to the stack and copy the number

        for (queueNodePointer origPtr = rhs.myTop->next; origPtr != nullptr; origPtr = origPtr->next) {
            newPtr->next = new queue;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
            newPtr->next = nullptr;
        }
    }

}

// Class Deconstructor
// pre: the stack exists
// post: the stack is destroyed and any dynamic memory is returned to the system
template <typename ItemType>
Queue<ItemType> :: ~Queue(){

    queueSize = 0;

    // delete all the ItemType

    while (myTop != nullptr) {
        queueNodePointer temp = myTop;
        myTop = myTop->next;
        delete temp;
    }

}

// Assignment operator
// Assigns a queue to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template <typename ItemType>
const Queue<ItemType> &Queue<ItemType> :: operator= (const Queue<ItemType>& rhs){

    if (this != &rhs) {
        Queue<ItemType> temp(rhs);
        std::swap(myTop, temp.myTop);
        std::swap(queueSize, temp.queueSize);
    }

    return *this;

}

// isEmpty
// Checks if the queue is empty
// pre:  A queue exists.
// post: Returns true if it IS empty, false if NOT empty.
template <typename ItemType>
bool Queue<ItemType> :: isEmpty() const{

    return queueSize == 0;

}

// enqueue
// put an item on end of the stack.
// pre:  queue exists and item is passed.
// post: the item is placed on end of the queue, and size is incremented.

template <typename ItemType>
void Queue<ItemType> :: enqueue (const ItemType& item){

    // create a new nodeptr to store the item

    queueNodePointer newPtr = new queue;
    newPtr -> item = item;

    // insert the new node to the end of the linked list

    queueNodePointer prev = nullptr;

    queueNodePointer cur;

    for(cur = myTop; cur != nullptr; cur = cur -> next){
        prev = cur;
    }

    if(prev == nullptr){
        myTop = newPtr;
        myTop -> next = nullptr;
    }else{
        prev -> next = newPtr;
        newPtr -> next = nullptr;
    }

    queueSize++;

}

// dequeue
// return the first item off the queue.
// pre:  queue exists.
// post: Removes item on front of queue.  If the queue
//       was already empty, throws a std::underflow_error exception.
template <typename ItemType>
void Queue<ItemType> :: dequeue(){

    if(isEmpty()){
        throw std::underflow_error("The stack is empty");
    }else{
        queueNodePointer temp = myTop;
        myTop = temp -> next;
        delete temp;
        queueSize--;
    }

}

// front
// Returns the front item of the stack without deleting it.
// pre:  queue exists.
// post: Returns item on front of queue.  If the queue
//       was already empty, throws a std::underflow_error exception.
template <typename ItemType>
ItemType Queue<ItemType> :: front() const{
    if(isEmpty()){
        throw std::underflow_error("The stack is empty");
    }else{
        return myTop -> item;
    }
}

// size
// Returns the number of items on the queue.
// post: Returns size from the private section of class.
template <typename ItemType>
size_t Queue<ItemType> :: size() const{

    return queueSize;

}