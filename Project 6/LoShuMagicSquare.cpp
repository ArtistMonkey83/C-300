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
//function for yolie's program footer
void yoliesProgramFooter()
  {
    cout << "\n\n\n********** END OF PROGRAM **********\n\n";

  }
