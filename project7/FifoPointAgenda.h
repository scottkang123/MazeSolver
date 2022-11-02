// File name: FifoPointAgenda.h
// Author: Scott Kang
// userid: kangk
// Email: kyung.ho.kang@vanderbilt.edu
// Class: CS2201
// Assignment Number: #7
// Honor Statement:  I have not given or received unauthorized aid on this assignment
// Description: This class derives from the PointAgenda class via public inheritance. This class uses Queue to
// store agenda of points
// Last Changed: 2019 11/9


#ifndef FifoPointAgenda_H
#define FifoPointAgenda_H

#include "PointAgenda.h"
#include "Queue_t.h"


class FifoPointAgenda : public PointAgenda {

private:
    Queue<Point> pointAgenda;

public:

    virtual ~FifoPointAgenda() {

    }

    // isEmpty (pure virtual)
    // Checks if the agenda is empty
    virtual bool isEmpty() const{
        return pointAgenda.isEmpty();
    }

    // add (pure virtual)
    // adds a Point to the agenda.
    virtual void add(const Point& item){
        pointAgenda.enqueue(item);
    }

    // remove (pure virtual)
    // removes the next Point from the agenda.
    virtual void remove(){
        pointAgenda.dequeue();
    }

    // peek (pure virtual)
    // Returns the next Point from the agenda without removing it from the agenda.
    virtual Point peek() const{
        return pointAgenda.front();
    }

    // size (pure virtual)
    // Returns the number of Points in the agenda.
    virtual size_t size() const{
        return pointAgenda.size();
    }

};

#endif