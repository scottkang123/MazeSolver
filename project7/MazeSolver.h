// File name: MazeSolver.h
// Author: Scott Kang
// userid: kangk
// Email: kyung.ho.kang@vanderbilt.edu
// Class: CS2201
// Assignment Number: #7
// Honor Statement: I have not given or received unauthorized aid on this assignment
// Description: This class lists private and public instances for mazesolver class
// Last Changed: 2019 11/9


#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include "Maze.h"
#include "PointAgenda.h"

class MazeSolver
{

private:

    Maze maze;
    PointAgenda & agenda;
    size_t count;

public:

    MazeSolver(Maze& newMaze, PointAgenda& newAgenda);
    bool solve(bool trace);
    bool pointAvailable(Point p);
    void add(Point p);

};

#endif /* ifndef */