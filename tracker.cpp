#include "tracker.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

//Mark Mietus CSCI 2270 Data Structures Final Project
//Virtual Checkers


string board [8][8];

tracker::tracker()
{
    //ctor
}

tracker::~tracker()
{
    //dtor
}

void tracker::newgame(){
    //initialize the board
    string newboard [8][8] = {"R","N","R","N","R","N","R","N","N","R","N","R","N","R","N","R"," ","N"," ","N"," ","N"," ","N","N"," ","N"," ","N"," ","N"," "," ","N"," ","N"," ","N"," ","N","N"," ","N"," ","N"," ","N"," ","B","N","B","N","B","N","B","N","N","B","N","B","N","B","N","B"};
    for(int i = 0; i < 8; i++){
        for(int j = 0; j<8; j++){
            board [i][j] = newboard [i][j];
        }
    }
    red = 8;
    black = 8;
}
void tracker::midpoint(){
    if(moverow > selectrow){
        removerow = selectrow + 1;
    }
    else{
        removerow = moverow + 1;
    }
    if(movecol > selectcol){
        removecol = selectcol + 1;
    }
    else{
        removecol = movecol + 1;
    }
}
void tracker::removepiece(){
    board [moverow][movecol] = board [selectrow][selectcol];
    board [selectrow][selectcol] = " ";
    if(blackturn == true){
        midpoint();
        board [removerow][removecol] = " ";
        red--;
    }
    else{
        midpoint();
        board [removerow][removecol] = " ";
        black--;
    }
}
void tracker::isvalid(){
    if(((selectrow-moverow) == 1) && ((abs(selectcol-movecol)) == 1) && (board[selectrow][selectcol] != "R")){
        if((board[moverow][movecol] == " ")){
            board [moverow][movecol] = board [selectrow][selectcol];
            board [selectrow][selectcol] = " ";
            blackturn = !blackturn;
            return;
        }
        else{
            cout<<" "<<endl;
            cout<<"Illegal Move! Try again."<<endl;
            cout<<" "<<endl;
            return;
        }
    }
    if(((selectrow-moverow) == -1) && ((abs(selectcol-movecol)) == 1) && (board[selectrow][selectcol] == "R")){
        if((board[moverow][movecol] == " ")){
            board [moverow][movecol] = board [selectrow][selectcol];
            board [selectrow][selectcol] = " ";
            blackturn = !blackturn;
            return;
        }
        else{
            cout<<" "<<endl;
            cout<<"Illegal Move! Try again."<<endl;
            cout<<" "<<endl;
            return;
        }
    }
    if((abs(selectrow-moverow) == 1) && ((abs(selectcol-movecol)) == 1) && ((board[selectrow][selectcol] == "KR") | (board[selectrow][selectcol] == "KB"))){
        if((board[moverow][movecol] == " ")){
            board [moverow][movecol] = board [selectrow][selectcol];
            board [selectrow][selectcol] = " ";
            blackturn = !blackturn;
            return;
        }
        else{
            cout<<" "<<endl;
            cout<<"Illegal Move! Try again."<<endl;
            cout<<" "<<endl;
            return;
        }
    }
    if((abs(selectrow-moverow)) == 2 && (abs(selectcol-movecol)) == 2 && (board[moverow][movecol] == " ")){
        midpoint();
        if((board[removerow][removecol] != " ") && ((board[selectrow][selectcol]) != (board[removerow][removecol]))){
            removepiece();
            blackturn = !blackturn;
            return;
        }
        else{
        cout<<" "<<endl;
        cout<<"Illegal Move! Try again."<<endl;
        cout<<" "<<endl;
        return;
        }
    }
    else{
        cout<<" "<<endl;
        cout<<"Illegal Move! Try again."<<endl;
        cout<<" "<<endl;
        return;
    }
}
void tracker::kingme(){
    for(int i = 0; i<8; i++){
        if(board[0][i]=="B"){
            board[0][i]="KB";
        }
    }
    for(int j = 0; j<8; j++){
        if(board[7][j]=="R"){
            board[7][j]="KR";
        }
    }
}
void tracker::selectpiece(){
    cout<<"Select a piece to move."<<endl;
    
    cout<<"=====\n"<<endl;
    cout<<"Row:";
    cin>>selectrow;
    cout<<"Col:";
    cin>>selectcol;
    while(selectrow > 7 | selectrow < 0 | selectcol > 7 | selectcol < 0){
        cout<<"\nPlease ensure inputs are from 0-7"<<endl;
        cout<<"\n====="<<endl;
        cout<<"Row:";
        cin>>selectrow;
        cout<<"Col";
        cin>>selectcol;
    }
    cout<<"\n======"<<endl;


    cout<<"Selected piece: "<<selectrow<<","<<selectcol<<" ("<<board[selectrow][selectcol]<<")"<<endl;
    if((board[selectrow][selectcol] == " ")){
        cout<<"No piece selected!"<<endl;
        selectpiece();
    }
    if(((board[selectrow][selectcol] == "B")|(board[selectrow][selectcol] == "KB")) && blackturn == false){
        cout<<" "<<endl;
        cout<<"Wait your turn Black!"<<endl;
        cout<<" "<<endl;
        selectpiece();
    }
    if(((board[selectrow][selectcol] == "R")|(board[selectrow][selectcol] == "KR")) && blackturn == true){
        cout<<" "<<endl;
        cout<<"Wait your turn Red!"<<endl;
        cout<<" "<<endl;
        selectpiece();
    }
}
void tracker::inputmove(){
    cout<<"Select a space to move to."<<endl;

    cout<<"=====\n"<<endl;
    cout<<"Row:";
    cin>>moverow;
    cout<<"Column:";
    cin>>movecol;
    while(moverow > 7 | moverow < 0 | movecol > 7 | movecol < 0){
        cout<<"\nPlease ensure inputs are from 0-7"<<endl;
        cout<<"\n====="<<endl;
        cout<<"Row:";
        cin>>moverow;
        cout<<"Column:";
        cin>>movecol;
    }
    cout<<"\n======"<<endl;
}

void tracker::help(){
    cout<<"Welcome to Virtual Checkers!"<<endl;
    cout<<"First, start a new game!"<<endl;
    cout<<"Black is the first to move"<<endl;
    cout<<"To move a piece, enter coordinates in the order of row then column when prompted"<<endl;
    cout<<"Capture opponent pieces by performing a 'jump' over them to the next available blank space"<<endl;
    cout<<"Multiple jumps per turn are not allowed in this version"<<endl;
    cout<<"Reach the other side with your pawn to make it a king"<<endl;
    cout<<"King pieces can move forwards and backwards while pawns can only move forwards"<<endl;
    cout<<"The first player to capture their opponent's pieces is the winner!"<<endl;
}
int tracker::gamestatus(){
    if(red == 0){
        cout<<" "<<endl;
        cout<<"Black Wins!"<<endl;
        cout<<" "<<endl;
        return 0;
    }
    else if(black == 0){
        cout<<" "<<endl;
        cout<<"Red Wins!"<<endl;
        cout<<" "<<endl;
        return 0;
    }
    else{
        if(blackturn){
            cout<<" "<<endl;
            cout<<"Black's turn to move"<<endl;
            cout<<" "<<endl;
        }
        else{
            cout<<" "<<endl;
            cout<<"Red's turn to move"<<endl;
            cout<<" "<<endl;
        }
        return 1;
    }
}
void tracker::displayboard(){
    cout<<"   0__1_2__3_4__5_6__7_"<<endl;
    cout<<"0:|"<<board[0][0]<<" == "<<board[0][2]<<" == "<<board[0][4]<<" == "<<board[0][6]<<" ==|"<<endl;
    cout<<"1:|== "<<board[1][1]<<" == "<<board[1][3]<<" == "<<board[1][5]<<" == "<<board[1][7]<<"|"<<endl;
    cout<<"2:|"<<board[2][0]<<" == "<<board[2][2]<<" == "<<board[2][4]<<" == "<<board[2][6]<<" ==|"<<endl;
    cout<<"3:|== "<<board[3][1]<<" == "<<board[3][3]<<" == "<<board[3][5]<<" == "<<board[3][7]<<"|"<<endl;
    cout<<"4:|"<<board[4][0]<<" == "<<board[4][2]<<" == "<<board[4][4]<<" == "<<board[4][6]<<" ==|"<<endl;
    cout<<"5:|== "<<board[5][1]<<" == "<<board[5][3]<<" == "<<board[5][5]<<" == "<<board[5][7]<<"|"<<endl;
    cout<<"6:|"<<board[6][0]<<" == "<<board[6][2]<<" == "<<board[6][4]<<" == "<<board[6][6]<<" ==|"<<endl;
    cout<<"7:|== "<<board[7][1]<<" == "<<board[7][3]<<" == "<<board[7][5]<<" == "<<board[7][7]<<"|"<<endl;
    cout<<"  |___________________|"<<endl;
}

