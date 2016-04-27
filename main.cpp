#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "tracker.h"

using namespace std;

//Mark Mietus CSCI 2270 Data Structures Final Project
//Virtual Checkers

int main()
{
    int n = 0;
    tracker game;
        cout<<"===Virtual Checkers==="<<endl;
        cout<<"1. New Game"<<endl;
        cout<<"2. Instructions"<<endl;
        cout<<"3. Quit"<<endl;
    while(cin>>n){
        switch(n){
            case 1:
                game.newgame();
                while(game.gamestatus()!=0){
                    game.displayboard();
                    game.selectpiece();
                    game.inputmove();
                    game.isvalid();
                    game.kingme();
                }
                game.displayboard();
            break;
            case 2:
                game.help();
                break;
            case 3:
                cout<<"Goodbye!"<<endl;
                return 0;
            default:
                cout<<"Please enter a number 1-2"<<endl;
            break;
        }
        cout<<"===Virtual Checkers==="<<endl;
        cout<<"1. New Game"<<endl;
        cout<<"2. Instructions"<<endl;
        cout<<"3. Quit"<<endl;
    }
}
