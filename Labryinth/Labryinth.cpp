// Labryinth maze by Stylianos Regas
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// loads the maze from a text file and displays it
void loadMaze(istream& in) {
    string line;

    while (getline(in, line)) {

        cout << line << endl;

    }
}

// saves the maze to a text file
void saveMaze(ostream& out, string array[]) {

    // writes maze to a file
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            out << endl;
        }
        out << array[i] << " ";

    }
    out << endl;

}

// prints out the maze to show the player
void printMaze(string array[]) {
    // writes maze to a file
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << array[i] << " ";

    }
    cout << endl;

}



int main()
{
    // initializes points
    int points = 0;

    // initializes the differnt objects in the maze
    string w = "*";
    string s = " ";
    string T = "#";
    string t = "$";
    string e = "E";
    string S = "^";

    // initializes the files
    ofstream mWrite;
    ifstream mLoad;

    // opens file
    mWrite.open("C:/Users/styli/OneDrive/Desktop/Object Oriented Programming/Extra credit/Labryinth/maze.txt");
    mLoad.open("C:/Users/styli/OneDrive/Desktop/Object Oriented Programming/Extra credit/Labryinth/maze.txt");

    // intializes the maze with all 100 objects
    string maze[100] = {w,w,w,w,w,w,w,w,e,w,
                        w,s,s,s,s,s,s,s,s,w,
                        w,s,w,T,T,w,w,w,w,w,
                        w,s,s,T,w,s,s,s,T,w, 
                        w,w,s,w,w,s,w,w,w,w, 
                        w,w,s,s,s,s,T,t,s,w, 
                        w,w,s,w,w,w,w,w,s,w, 
                        w,w,s,s,s,s,s,s,s,w, 
                        w,w,s,w,w,w,w,w,T,w, 
                        w,w,S,w,w,w,w,w,w,w,
    };

   
    // saves and displays the maze
    saveMaze(mWrite, maze);
    loadMaze(mLoad);

   

    cout << "Welcome to the labrnyth!" << endl;
    cout << "to move, type 'w' to go forward, 'a' to move left, 's' to move down, and 'd' to go right" << endl;

    // initializes the while loop for the game, and the input taken by the player
    bool play = true;
    string move;
    int place = 92;
    
    // runs until you lose or win
    while (play) {
        cin >> move;

        // will show an error if user inputs something other than w, s, a, or d
        if (move != "w" && move != "s" && move != "a" && move != "d")
            cout << "error, invalid input";
        
        //allows the player to go up
        if (move == "w") {

            if (maze[place - 10] == T) {
                cout << "You hit a trap!\nGAME OVER" << endl << "total points: " << points;
                play = false;
            }

            if (maze[place - 10] == e) {
                cout << "YOU WON!!" << endl << "total points: " << points;
                play = false;
            }

            if (maze[place - 10] == w) {
                cout << "error, you can't go that way";
            }

            if (maze[place - 10] == s || maze[place-10] == t) {
                maze[place] = s;
                maze[place - 10] = S;
                place -= 10;
                points += 10;
                if (maze[place - 10] == t) {
                    cout << "you found the treasure!" << endl;
                    points += 100;
                }
            }
            
        }

        // allows the player to go down
        if(move == "s") {

            if (place + 10 >= 100) {
                cout << "error, you can't go that way";
            }
            else{

                if (maze[place + 10] == T) {
                    cout << "You hit a trap!\nGAME OVER" << endl << "total points: " << points;
                    play = false;
                }

                if (maze[place + 10] == e) {
                    cout << "YOU WON!!" << endl << "total points: " << points;
                    play = false;
                }

                if (maze[place + 10] == w) {
                    cout << "error, you can't go that way";
                }

                if (maze[place + 10] == s || maze[place - 10] == t) {
                    maze[place] = s;
                    maze[place + 10] = S;
                    place += 10;
                    points += 10;
                    if (maze[place + 10] == t) {
                        cout << "you found the treasure!" << endl;
                        points += 100;
                    }
                }
            }

        }

        // allows the player to go left
        if (move == "a") {

            if (maze[place - 1] == T) {
                cout << "You hit a trap!\nGAME OVER" << endl << "total points: " << points;
                play = false;
            }

            if (maze[place - 1] == e) {
                cout << "YOU WON!!" << endl << "total points: " << points;
                play = false;
            }

            if (maze[place - 1] == w) {
                cout << "error, you can't go that way";
            }

            if (maze[place - 1] == s || maze[place - 10] == t) {
                maze[place] = s;
                maze[place - 1] = S;
                place -= 1;
                points += 1;
                
            }

            if (maze[place - 1] == t) {
                cout << "you found the treasure!" << endl;
                points += 100;
                maze[place - 1] = S;
                maze[place] = s;
                place -= 1;
            }

        }

        // allows the player to go right
        if (move == "d") {

            if (maze[place + 1] == T) {
                cout << "You hit a trap!\nGAME OVER" << endl << "total points: " << points;
                play = false;
            }

            if (maze[place + 1] == e) {
                cout << "YOU WON!!" << endl << "total points: " << points;
                play = false;
            }

            if (maze[place + 1] == w) {
                cout << "error, you can't go that way";
            }

            if (maze[place + 1] == s || maze[place - 10] == t) {
                maze[place] = s;
                maze[place + 1] = S;
                place += 1;
                points += 1;
                if (maze[place + 1] == t) {
                    cout << "you found the treasure!" << endl;
                    points += 100;
                }
            }

        }

       



        printMaze(maze);
    }

    mWrite.close();
    mLoad.close();

    return 0;
}
