#include<iostream>

using namespace std;

int main ()
{

//Yolie's program header
        cout << "\n\n********* YOLIE REYES *********\n";
        cout << "********** Project 4 **********\n";
        cout << "********** Problem 3 **********\n";
        cout << "*********** 9-27-18 ***********\n";
        cout << "********** CISP 360 **********\n";



//explaing the function of the program to the user
    cout << "\n\nThe function of this program is to generate a pattern of *s after user \nhas entered number of rows between 1- 20.\n";

//declaring variable
    int numRows;

//getting number of rows from user
    cout << "\t\n\nPlease enter number of rows to print: ";
    cin  >> numRows;



while (numRows < 1 || numRows >20)
    {
        cout << "\n\nPlease enter a valid number of rows to print 1-20: ";
        cin  >> numRows;
    }


if ( numRows > 0 && numRows < 21)
    {
        for (int rows = 0; rows < numRows; rows++)
      {
        for (int cols = 0; cols <= rows; cols++)
          {
          cout << "*";
          }
        cout << endl;
      }
    }






//a visual seperator for the end of the program

      cout << "\n\n**************** End of Program ****************\n";

  return 0;
}
