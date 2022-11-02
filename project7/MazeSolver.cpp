// File name: MazeSolver.cpp
// Author: Scott Kang
// userid: kangk
// Email: kyung.ho.kang@vanderbilt.edu
// Class: CS2201
// Assignment Number: #7
// Honor Statement: I have not given or received unauthorized aid on this assignment
// Description:  This class solves the maze. It shows if the solution is found and how many nodes are visited.
// Last Changed: 2019 11/9

#include <stdexcept>
#include <cstdlib>
#include "MazeSolver.h"


MazeSolver ::MazeSolver (Maze& newMaze, PointAgenda& newAgenda): maze(newMaze), agenda(newAgenda), count(0){

}

bool MazeSolver::solve(bool trace){

    if(trace){
    }

    Point start = maze.getStartLocation();
    agenda.add(start);
    maze.markVisited(start);

    while(!agenda.isEmpty()){
        Point cur = agenda.peek();
        std:: cout << cur << "->";
        agenda.remove();
        count++;
        if(cur == maze.getEndLocation()){
            std:: cout << "solution found " << "number of points visited is " << count << std::endl;
            return true;
        }

        add(Point(cur.x + 1, cur.y));
        add(Point(cur.x - 1, cur.y));
        add(Point(cur.x, cur.y - 1));
        add(Point(cur.x, cur.y + 1));
    }

    std:: cout << "solution not found "  << std::endl;
    return false;

}

//check if the point is available
//pre: point is inside the maze
//return true if the point is within the maze and it is open

bool MazeSolver :: pointAvailable(Point p){
    return maze.isOpen(p.x, p.y) && p.x < maze.getNumRows() && p.y < maze.getNumCols() && p.x > -1 && p.y > -1;
}

// add point to the agenda if the point has not been visited and is available
// pre: pointAvailable method and hasBeenVisited method should work correctly

void MazeSolver :: add(Point p) {
    if(!maze.hasBeenVisited(p) && pointAvailable(p)){
        agenda.add(p);
        maze.markVisited(p);
    }
}