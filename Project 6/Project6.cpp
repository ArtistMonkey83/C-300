/*. Lo Shu Magic Square
The Lo Shu Magic Square is a grid with 3 rows and 3 columns shown in Figure 7-19. The Lo Shu Magic Square has the following properties:
• The grid contains the numbers 1 through 9 exactly.
• The sum of each row, each column, and each diagonal all add up to the same
number. This is shown in Figure 7-20.
In a program you can simulate a magic square using a two-dimensional array. Write a function that accepts a two-dimensional array as an argument, and determines whether the array is a Lo Shu Magic Square. Test the function in a program.



when row is == columns the diagonals will be refferenced and [2,0]&& [0,2]

try to find a relationship between the row and the columns

one increases and one decreases  and then the other one increases and decreases




 Programming Project on Chapter 7

 Arrays and Vectors

 1.

 Lo Shu Magic Square (8 pts) – LoShuMagicSquare.cpp





 The Lo Shu Magic Square is a grid with 3 rows and 3 columns shown in Figure 1.

 Lo Shu Magic Square

 Figure 1: Lo Shu Magic Square

 The grid contains the numbers 1 through 9 exactly.
 The sum of each row, each column, and each diagonal all add up to the same number. This is shown in Figure 2.
 Sums of rows, columns, diagonals

 Figure 2: Sums of rows, columns and diagonals

 In a program, you can simulate a magic square using a two-dimensional array. Write a function that accepts a two-dimensional array as an argument, and determines whether the array is a Lo Shu Magic Square. Test the function in a program. When you test the function, generate a square and then test whether it is a Lo Shu Magic Square.

 Hint: Use rand() to generate each element of the array. Make sure they are only between 1 and 9.
*/
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//function prototypes

void yoliesProgramHeader();
void displayExplanation();
void yoliesProgramFooter();


void getRandomNumbers();
void addNumberToArray(int);
void generateGrid();
bool isMagicSquare();
char validatedPlayAgain(char);

//global constants and variables
const int SIZE = 3,MAX_NUM = 9, MIN_NUM = 1;
int loShu[SIZE][SIZE] = {{0,0,0},{0,0,0},{0,0,0}};



/*
*
*   MAIN FUNCTION
*/


int main ()
{
  yoliesProgramHeader();
  displayExplanation();

  char playAgain;

  do
  {
    getRandomNumbers();
    generateGrid();
    if(isMagicSquare() == true)
      {
        cout << "\n\n\t********** THIS IS A LO SHU MAGIC SQUARE *********\n";
      }
    else
      {
        cout << "\n\n\t          Sorry this is not a Lo Shu Magic Square\n";

      }

    cout << "\n\nWould you like you try again? (y or n): ";
    cin  >> playAgain;
    playAgain = validatedPlayAgain(playAgain);


  }while(playAgain == 'y' || playAgain == 'Y')
  yoliesProgramFooter();

  return 0;
}






/*
*   FUNCTIONS OUTSIDE OF MAIN
*
*/
//function for displaying grid
void displayGrid(char loShu[SIZE][SIZE], int row)
  {
    cout << "\t\t\t   |   |   \n";
    cout << " " << loShu[0][0] << " | " << loShu[0][1] << " | " << loShu[0][2] << endl;

    cout << "___|___|___\n";
    cout << "   |   |   \n";

    cout << " " << loShu[1][0] << " | " << loShu[1][1] << " | " << loShu[1][2] << endl;

    cout << "___|___|___\n";
    cout << "   |   |   \n";

    cout << " " << loShu[2][0] << " | " << loShu[2][1] << " | " << loShu[2][2] << endl;

    cout << "   |   |   \n";
  }

void generateGrid()
{
  for(int i = 0; i < SIZE; i++)
  {
    for(int c = 0; c < SIZE; c++)
    {
      cout << loShu[i][c] << " ";
    }

    cout << endl;
  }
}



bool isMagicSquare()
{
  int tempSum = loShu[0][0] + loShu[0][1] + loShu[0][2];
//comparing rows
  for(int i = 1; i < SIZE; i++)
  {
    if(loShu[i][0] + loShu[i][1] + loShu[i][2] != tempSum)
    {return false;}

  }
//comparing columns
  for(int i = 0; i < SIZE; i++)
  {
    if(loShu[0][i] + loShu[1][i] + loShu[2][i] != tempSum)
    {return false;}

  }
//diagonal left to right top to bottom
  if( (loShu[0][0] + loShu[1][1] + loShu [2][2] != tempSum))
  {return false;}
//diagonal right to left top to bottom
  if (loShu[2][0] + loShu[1][1] + loShu[0][2] != tempSum)
  {return false;}

  return true; //if none of the above conditions happen it is a magic square

}



//getting random numbers
void getRandomNumbers()
{
  int number = 0;

  int usedNumbers[MAX_NUM]= {0,0,0,0,0,0,0,0,0};//array to hold a number we have already choosen

  srand(time(0));

  bool wasNumberUsed = true; //flag we will change to t or f if the number is already used

  for (int i = 0; i < 9; i++)
  {
    do
    {
      wasNumberUsed = true;

      number = (rand()%(MAX_NUM - MIN_NUM + 1)+1);

      if(usedNumbers[number-1]== 0) //checking to see if the number was picked
      {
        usedNumbers[number - 1] = number;
        wasNumberUsed = false;
      }
    }while(wasNumberUsed);

    addNumberToArray(number);

  }

}

void addNumberToArray(int number)
{
  for(int i = 0; i<SIZE; i++)
  {
    for(int c = 0; c<SIZE; c++)
    {
      if(loShu[i][c] == 0)
      {
        loShu[i][c] = number;
        return;
      }
    }
  }
}

//yolies program header

      void yoliesProgramHeader()
        {
          cout << "\n\n\n********** Yolie Reyes **********\n"
               << "********* 10 - 11 - 18 **********\n"
               << "*********** CISP 360 ************\n"
               << "******** Project 6 Prob 1 *******\n";

        }

//function for explaining to the user the function of the program
void displayExplanation()
  {
      cout << "\n\nThis program will generate a 3x3 grid, randomly assign numbers 1-9 to each space\nand then test to see if the grid generated is considered a Lo Shu Magic Square.\nIn a Lo Shu Magic Square each row, column and diagonal add up to the same number\nusing numbers 1-9 only once.\n\n\n\n\n";
  }

//function for validating the varible for playing again
char validatedPlayAgain(char userInput)
  {
    while(userInput != 'y' || userInput != 'Y' || userInput != 'n' || userInput != 'N')
      {
        cout << "\n\nIf you would like to play again please enter Y for yes, or N for no: ";

        cin  >> userInput;
      }
    return userInput;
  }

//function for yolie's program footer
void yoliesProgramFooter()
  {
    cout << "\n\n\n********** END OF PROGRAM **********\n\n";

  }








 18. Tic-Tac-Toe Game
 Write a program that allows two players to play a game of tic-tac-toe. Use a two- dimensional char array with three rows and three columns as the game board. Each element of the array should be initialized with an asterisk (*). The program should run a loop that
 • Displays the contents of the board array
 • Allows player 1 to select a location on the board for an X. The program should ask
 Programming Challenges 453
 TIP: Read the contents of the WorldSeriesWinners.txt file into an array or vector. When the user enters the name of a team, the program should step through the array or vector counting the number of times the selected team appears.

 the user to enter the row and column number.
 454 Chapter 7
 Arrays
 • Allows player 2 to select a location on the board for an O. The program should ask the user to enter the row and column number.
 • Determines whether a player has won, or a tie has occurred. If a player has won, the program should declare that player the winner and end. If a tie has occurred, the program should say so and end.
 Player 1 wins when there are three Xs in a row on the game board. The Xs can appear in a row, in a column, or diagonally across the board. A tie occurs when all of the locations on the board are full, but there is no winner.


 make sure to minimize user row and column selection by 1
  and make sure that the position is == to the control variable * and ask for them to input another spot if it is occupied.

  same function for checking for winning as the lo LoShuMagicSquare

  display tie if there is a tie.

  function to display to the board and to check for a winner, valid move and valid input

  global constants work really well for this validation


 2.

 Tic, Tac, Toe game (12 pts) – ticTacToe.cpp



 Write a program that allows two players to play a game of tic-tac-toe. Use a two-dimensional char array with three rows and three columns as the game board. Each element of the array should be initialized with an asterisk (*). The program should run a loop that does the following:

 Displays the contents of the board array.
 Allows player 1 to select a location on the board for an X. The program should ask the user to enter the row and column numbers.
 Allows player 2 to select a location on the board for an O. The program should ask the user to enter the row and column numbers.
 Determines whether a player has won, or a tie has occurred. If a player has won, the program should declare that player the winner and end. If a tie has occurred, the program should display an appropriate message and end.
 Player 1 wins when there are three Xs in a row on the game board. The Xs can appear in a row, in a column, or diagonally across the board. Player 2 wins when there are three Os in a row on the game board. The Os can appear in a row, in a column, or diagonally across the board. A tie occurs when all of the locations on the board are full, but there is no winner.


 #include<iostream>
 #include<cstdlib>

 using namespace std;

 char grid[SIZE][SIZE] = {{0,0,0},{0,0,0},{0,0,0}}};
 char con;
 int checkwin();
 void board();

 int main ()
 {
   int player = 1 , i, choice;
   char mark;
   do
   {
         board();
         player = (player%2) ?1 :2;

         cout << "\n\n\nPlayer " << player << ", enter a position: ";
         cin >> choice;

         mark = (player  == 1) ? 'X' : 'O';

         if (choice == 1 && square[1] == '1')
           {square[1] = mark;}

         else if (choice ==2 && square[2] == '2')
           {square[2] = mark;}

         else if (choice == 3 && square[3] =='3')
           {square[3] = mark;}

         else if (choice == 4 && square[4] == '4')
           {square[4] = mark;}

         else if (choice == 5 && square[5] == '5')
           {square[5]= mark;}

         else if (choice == 6 && square[6] == '6')
           {square[6] = mark;}

         else if (choice == 7 && square [7] =='7')
           {square[7] = mark;}

         else if (choice == 8 && square[8] =='8')
           {square[8] = mark;}

         else if (choice == 9 && square[9] =='9')
           {square[9] = mark;}

         else
         {
           cout << "\n\n\tInvalid move ";

           player--;
           cin.ignore();

           cout << "\n\nPlease enter a valid move for an available position: ";
           cin >> choice;
         }

         i = checkwin();

         player++;


   } while(i == -1);

   board();

   if(i==1)
     {cout << " \n\n\n\a\a\a********** Player " << --player << " wins! ********** ";}

   else
     {cout << "\n\n\n\a********** Game ends in a TIE! **********";}

   cin.ignore();
   cin.get();

   return 0;

 }

 int checkwin()
 {

   if(square[1] == square[2] && square[2] == square[3]) //checking row 1
     {return 1;}

   else if (square[4] == square[5] && square[5] == square[6]) //checking row 2
     {return 1;}

   else if (square[7] == square[8] && square[8] == square[9]) //checking row 3
     {return 1;}

   else if(square[1] == square[4] && square[4] == square[7]) //checking column 1
     {return 1;}

   else if(square[2] == square[5] && square[5] == square[8]) //checking column 2
     {return 1;}

   else if(square[3] == square[6] && square[6] == square[9]) //checking column 3
     {return 1;}

   else if(square[1] == square[5] && square[5] == square[8]) //checking diagonal1
     {return 1;}

   else if(square[3] == square[5] && square[5] == square[7]) //checking diagonal2
     {return 1;}

   else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' & square[7] != '7' && square[8] != '8' && square[9] != '9')
     {return 0;}

   else
     {return -1;}

 }
 void board()
   {

     cout << "\n\n\tTic Tac Toe\n\n";

     cout <<"Player 1 (X) --- Player 2 (0)\n\n\n\n";

     cout << "   |   |   \n";
     cout << " " << square[1] << " | " << square[2] << " | " << square[3] << endl;

     cout << "___|___|___\n";
     cout << "   |   |   \n";

     cout << " " << square[4] << " | " << square[5] << " | " << square[6] << endl;

     cout << "___|___|___\n";
     cout << "   |   |   \n";

     cout << " " << square[7] << " | " << square[8] << " | " << square[9] << endl;

     cout << "   |   |   \n";

   }


///////////////////////

#include<iostream>

using namespace std;

//function prototypes
void yoliesProgramHeader();
void displayExplanation();
void yoliesProgramFooter();
void displayGrid(int [][], int,int);

void checkSpot(int[][],int,int);

int displayWinner(int [][],int,int)
bool spotAvailable(int [][],int, int);

//gloabl constants for array size
const int SIZE = 3;









/*
***** MAIN FUNCTION *****
*/
int main ()
{

  yoliesProgramHeader();
  displayExplanation();

  int grid[SIZE][SIZE]= {{*,*,*},{*,*,*},{*,*,*}}; //initializing grid to *

  int row, column;


do
{
  displayGrid(grid[][],SIZE,SIZE); //function to display the Tic Tac Toe board

  cout << "\n\n\tPlease select a row: "
  cin  >> row;

  while((row - 1 < 0 || row - 1 > 2 )) //validating an existing row was selected
    {
      cout << "\n\n\tPlease enter a valid row (1-3): ";
      cin  >> row;
    }


  cout << "\n\n\tPlease select a column: "
  cin  >> column;

  while(column - 1 < 0 || column - 1 > 2 ) //validating an existing column was selected
    {
      cout << "\n\n\tPlease enter a valid column (1-3): ";
      cin  >> column;
    }


  checkSpot(grid[][],SIZE,SIZE,row,column); //checking to see if spot is available

  spotAvailable(grid[][],SIZE,SIZE);
}while(spotAvailable())


  if(displayWinner(grid[][],SIZE,SIZE) == 0) //function in an if/else if statement to determine winner
    {cout << "\n\n\t********** Player 1 WINS! **********\n";}
  else if(displayWinner(grid[],SIZE,SIZE) == 1)
    {cout << "\n\n\t********** Player 2 WINS! **********\n";}
  else
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


//function for checking spot availablity
bool spotAvailable(int ticTacToe[][], int row, int column)
  {
    for(i = 0; i < SIZE; i++)
      {
        for(i = 0; i < SIZE; i++)
          {
            if(ticTacToe == '*')
              {return 1;}
            else
              {return 0;}

          }
      }
  }


//function for checking spot and assigning symbol to grid[][] in main
void checkSpot(int ticTacToe[][], int userRow, int userColumns)
  {
    char symbol; //variable to hold the symbol placed by player 1 or 2
    static int player = 0; //variable to hold player number and turn


    while(ticTacToe[userRows-1][userColumns-1] == 'X' || ticTacToe[userRows-1][userColumns-1] == 'O')
      {
        cout <<"\n\n\t!!!!!!!!!! Sorry that spot is taken. !!!!!!!!!!\n";

        cout << "\n\n\tPlease enter a position with an '*' by row and column to play: ";
        cin  >> userRows,userColumns;

      }

    while(ticTacToe[userRows-1][userColumns-1] == '*')
      {

        switch(player) //switch statement to set the symbol to mark
        {
          case 0: symbol = 'X' //player 1 symbol
                  break;
          case 1; symbol = 'O' //player 2 symbol
        }

        ticTacToe[userRows-1][userColumns-1]= symbol;

        if(player = 0)
          {player++;}   //switching to next player
        else if(player = 1)
          {player--;}   //depending on the value of player variable

      }

  }

//function for displaying grid
void displayGrid(int ticTacToe[][], int row,int column);
  {
    cout << "   |   |   \n";
    cout << " " << ticTacToe[0][0] << " | " << ticTacToe[0][1]] << " | " << ticTacToe[0][2]] << endl;

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



///
/////
/////
////
////
//////////////
/////////////////




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
bool emptyTicTacToe(char [][SIZE);

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

}while(spotAvailable(ticTacToe,row,column) == 0 && emptyTicTacToe(ticTacToe)== 0);


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

//function for checking to see if game is over
bool emptyTicTacToe(char ticTacToe[][SIZE)
  {
    int empty;

    for(int r = 0; r < SIZE; r++)
      {
        for(int c = 0; c < SIZE; c++)
        {
          if(ticTacToe[r][c] == '*')
          {empty = 0;}
          break;

          else
          {empty = 1}
        }
      }

    return empty;
  }


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
