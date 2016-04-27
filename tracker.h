#ifndef TRACKER_H
#define TRACKER_H
#include <iostream>

using namespace std;

//Mark Mietus CSCI 2270 Data Structures Final Project
//Virtual Checkers

class tracker
{
    public:
        tracker();
        ~tracker();
        void newgame(); //constructs a new game board
        void kingme(); //changes status of a piece from a pawn to a king
        void removepiece(); //removes pieces from the board accordingly as jumps occur (decrements red or black private variables)
        int gamestatus(); //determines if there is a victor after each turn. If red or black pieces remaining reaches 0 a victor is found.
        void midpoint(); //tracks the coordinates of the 'jumped' space when a user attempts a jump move
        void playertracker(); // tracks whether it is red's or black's turn to move.
        void selectpiece(); //asserts user input for which piece they would like to move
        void isvalid(); //asserts if the move chosen is valid
        void inputmove(); //prompts user for a new move
        void help(); //displays the instructions for the user
        void displayboard(); // displays the current state of the game board

    protected:
    private:
        bool blackturn = true;
        int red = 8;
        int black = 8;
        int moverow = 0;
        int movecol = 0;
        int selectrow = 0;
        int selectcol = 0;
        int removerow;
        int removecol;
};

#endif // TRACKER_H
