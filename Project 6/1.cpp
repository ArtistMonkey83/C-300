#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


void getRandomNumbers();
void addNumberToArray(int);
void populateGrid();
bool isMagicSquare();

const int SIZE = 3,MAX_NUM = 9, MIN_NUM = 1;
int numbers[SIZE][SIZE] = {{0,0,0},{0,0,0},{0,0,0}};




int main ()
{
  getRandomNumbers();
  populateGrid();
  if(isMagicSquare() == true)
    {
      cout << "\n\n\t********** THIS IS A LO SHU MAGIC SQUARE *********\n";
    }
  else
    {
      cout << "\n\n\t          Sorry this is not a Lo Shu Magic Square\n";

    }


  return 0;
}

void populateGrid()
{
  for(int i = 0; i < SIZE; i++)
  {
    for(int c = 0; c < SIZE; c++)
    {
      cout << numbers[i][c] << " ";
    }

    cout << endl;
  }
}



bool isMagicSquare()
{
  int tempSum = numbers[0][0] + numbers[0][1] + numbers[0][2];
//comparing rows
  for(int i = 1; i < SIZE; i++)
  {
    if(numbers[i][0] + numbers[i][1] + numbers[i][2] != tempSum)
    {return false;}

  }
//comparing columns
  for(int i = 0; i < SIZE; i++)
  {
    if(numbers[0][i] + numbers[1][i] + numbers[2][i] != tempSum)
    {return false;}

  }
//diagonal left to right top to bottom
  if( (numbers[0][0] + numbers[1][1] + numbers [2][2] != tempSum))
  {return false;}
//diagonal right to left top to bottom
  if (numbers[2][0] + numbers[1][1] + numbers[0][2] != tempSum)
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

  for (int i = 1; i < 9; i++)
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
      if(numbers[i][c] == 0)
      {
        numbers[i][c] = number;
        return;
      }
    }
  }
}
