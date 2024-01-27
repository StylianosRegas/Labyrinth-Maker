#include "ShowMaze.h"
#include <iostream>

using namespace std;

void ShowMaze::printMaze(string array[]) {
    // writes maze to a file
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << array[i] << " ";

    }
    cout << endl;

}

void ShowMaze::saveMaze(ostream& out, string array[]) {

    // writes maze to a file
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            out << endl;
        }
        out << array[i] << " ";

    }
    out << endl;

}

void ShowMaze::loadMaze(istream& in) {
    string line;

    while (getline(in, line)) {

        cout << line << endl;

    }
}