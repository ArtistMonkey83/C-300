#include<iostream>
#include<cstdlib>

using namespace std;

//gloabl constants for array size
const int SIZE = 3;


//function prototypes
void yoliesProgramHeader();
void displayExplanation();
void yoliesProgramFooter();

void displayGrid(char [][SIZE]);

void checkSpot(char[][SIZE],int,int);

void displayWinner(char [][SIZE]);
bool spotAvailable(char [][SIZE],int,int);

int winnerIs = 4; //0 = player1, 1 = player2, 2 = tie, 4 initialization


/*
***** MAIN FUNCTION *****
*/
int main ()
{

  yoliesProgramHeader();
  displayExplanation();

  char ticTacToe[SIZE][SIZE] = {{'*','*','*'},{'*','*','*'},{'*','*','*'}}; //initializing grid to *

  int row, column;



do
{

  displayGrid(ticTacToe); //function to display the Tic Tac Toe board

  cout << "\n\n\tPlease select a row: ";
  cin  >> row;

  while((row - 1 < 0 || row - 1 > 3 )) //validating an existing row was selected
    {
      cout << "\n\n\tPlease enter a valid row (1-3): ";
      cin  >> row;
    }


  cout << "\n\n\tPlease select a column: ";
  cin  >> column;

  while(column - 1 < 0 || column - 1 > 3 ) //validating an existing column was selected
    {
      cout << "\n\n\tPlease enter a valid column (1-3): ";
      cin  >> column;
    }



  checkSpot(ticTacToe,row,column); //checking to see if spot is available

  spotAvailable(ticTacToe,row,column); //checking to see if there are still available spots or to end game


  displayWinner(ticTacToe);

}while(spotAvailable(ticTacToe,row,column) == 0);


  if(winnerIs == 0) //function in an if/else if statement to determine winner
    {cout << "\n\n\t********** Player 1 WINS! **********\n";}
  else if(winnerIs == 1)
    {cout << "\n\n\t********** Player 2 WINS! **********\n";}
  else
    if(winnerIs == 2)
    {cout << "\n\n\t********** This Game ends in a TIE! **********\n";}





  yoliesProgramFooter();
  return 0;
}










/*
*
*
* functions outside of main function
*
*
*/

//function for displaying the winner


void displayWinner(char ticTacToe[][SIZE])
{


//Checking Row 1
    if(ticTacToe[0][0] == ticTacToe[0][1] == ticTacToe[0][2])
    {
      if(ticTacToe[0][0] == 'X')
      {winnerIs = 0;}
      else
      {winnerIs = 1;}
    }
//Checking Row 2
    if(ticTacToe[1][0] == ticTacToe[1][1] == ticTacToe[1][2])
    {
      if(ticTacToe[1][0] == 'X')
      {winnerIs = 0;}
      else
      {winnerIs = 1;}
    }

//Checking Row 3
    if(ticTacToe[2][0] == ticTacToe[2][1] == ticTacToe[2][2])
    {
      if(ticTacToe[2][0] == 'X')
      {winnerIs = 0;}
      else
      {winnerIs = 1;}
    }

//Checking Column 1
    if(ticTacToe[0][0] == ticTacToe[1][0] == ticTacToe[2][0])
    {
        if(ticTacToe[0][0] == 'X')
        {winnerIs = 0;}
        else
        {winnerIs = 1;}
    }

//Checking Column 2
    if(ticTacToe[0][1] == ticTacToe[1][1] == ticTacToe[2][1])
    {
      if(ticTacToe[0][1] == 'X')
      {winnerIs = 0;}
      else
      {winnerIs = 1;}
    }

//Checking Column 3
    if(ticTacToe[0][2] == ticTacToe[1][2] == ticTacToe[2][2])
    {
      if(ticTacToe[0][2] == 'X')
      {winnerIs = 0;}
      else
      {winnerIs = 1;}
    }
//Checking diagonal 1
    if(ticTacToe[0][2] == ticTacToe[1][1] == ticTacToe[2][0])
    { if(ticTacToe[0][2] == 'X')
      {winnerIs = 0;}
      else
      {winnerIs = 1;}
    }
//Checking digaonal 2
    if(ticTacToe[0][0] == ticTacToe[1][1] == ticTacToe[2][2])
    {
      if(ticTacToe[0][0] == 'X')
      {winnerIs = 0;}
      else
      {winnerIs = 1;}
    }



  }


//function for checking spot availablity
bool spotAvailable(char ticTacToe[][SIZE], int row, int column)
  {
    bool openSpot = 0;

    if(ticTacToe[row-1][column-1] == '*')
    {openSpot = 1;}
    else
    {openSpot = 0;}

    return openSpot;
  }


//function for checking spot and assigning symbol to grid[][] in main
void checkSpot(char ticTacToe[][SIZE], int userRows, int userColumns)
  {
    char symbol; //variable to hold the symbol placed by player 1 or 2
    static int player = 0; //variable to hold player number and turn


    while((spotAvailable(ticTacToe,userRows, userColumns) == 0) )
      {
        cout <<"\n\n\t!!!!!!!!!! Sorry that spot is taken. !!!!!!!!!!\n";

        cout << "\n\nPlease enter a position with an '*' by row and column to play. Enter a row: ";

        cin  >> userRows;

        cout << "\n\nPlease enter a column: ";
        cin  >> userColumns;

      }

    while(spotAvailable(ticTacToe,userRows,userColumns))
      {

        switch(player) //switch statement to set the symbol to mark
        {
          case 0: symbol = 'X'; //player 1 symbol
                  break;
          case 1: symbol = 'O'; //player 2 symbol
        }

        ticTacToe[userRows-1][userColumns-1]= symbol;

        if(player == 0)
          {player++;}   //switching to next player
        else if(player == 1)
          {player--;}   //depending on the value of player variable

      }

  }

//function for displaying grid
void displayGrid(char ticTacToe[][SIZE])
  {
    cout << "   |   |   \n";
    cout << " " << ticTacToe[0][0] << " | " << ticTacToe[0][1] << " | " << ticTacToe[0][2] << endl;

    cout << "___|___|___\n";
    cout << "   |   |   \n";

    cout << " " << ticTacToe[1][0] << " | " << ticTacToe[1][1] << " | " << ticTacToe[1][2] << endl;

    cout << "___|___|___\n";
    cout << "   |   |   \n";

    cout << " " << ticTacToe[2][0] << " | " << ticTacToe[2][1] << " | " << ticTacToe[2][2] << endl;

    cout << "   |   |   \n";
  }

//function for Yolie's program header
void yoliesProgramHeader()
      {
        cout << "\n\n********* YOLIE REYES *********\n";
        cout << "********** Project 6 **********\n";
        cout << "********** Problem 2 **********\n";
        cout << "*********** 10-12-18 ***********\n";
        cout << "********** CISP 360 **********\n";
      }

//function explaining the function of the program to the user
void displayExplanation()
  {
    cout << "\n\nIn this program you can play a game of Tic-Tac-Toe with another player.\n";
  }

//function for Yolie's program footer
void yoliesProgramFooter()
{
    cout << "\n\n**************** End of Program ****************\n";
}
