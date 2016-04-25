# CSCI-2270-Final-Project-Mark-M.
CSCI 2270 Final Project -- Virtual Checkers
Team Members - Mark Mietus (solo)

Project Description (for use with Unbuntu):
The project is a simulated checkers board that uses a 2 dimensional array to store information about the board.
The information stored is as follows: R - Red player
                                      B - Black player
                                      N - Null space (spaces where no pieces are allowed to play in)
                                      KR - King Red Player
                                      KB - King Black Player
                                      " " - Blank Space (indicating a space available for play)
                                      
Main Menu includes 3 options: New Game - Start a new game
                              Instructions - Brief command overview and summary of the game of checkers
                              Quit - exits the program
                              
  Game is designed for 2 players (users) computer vs. user is not currently implemented.
  
Program consists of 11 public members in the class "tracker" which handle the game mechanics
Members are as follows:
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
        
Program mechanics are as follows:
1.) User selects "New game mode"
2.) Black piece starts first and the desired piece is selected with the appropriate coordinates
3.) User is then prompted to input coordinates to move the piece to the desired space
4.) Red/Black turns alternate as pieces are moved
5.) In the event of a jump move, the program asserts if the space selected for the move is empty and if there is a piece of the opposite color to remove else the move is illegal and the user must select a new move
6.) In the event a player makes it to the opposite side of the board, the piece is changed from R to KR or B to KB denoting a king piece. A king piece is granted forwards and backwards movement, where a pawn can only move forward.
7.) Game continues until either red or black pieces reach 0
8.) Return to main menu
