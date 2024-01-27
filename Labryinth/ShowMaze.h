#pragma once
#include <iostream>
#ifndef ShowMaze_h
#define ShowMaze_h

using namespace std;

class ShowMaze {
public:
	void printMaze(string);
	void saveMaze(ostream&, string);
	void loadMaze(istream&);

};
#endif