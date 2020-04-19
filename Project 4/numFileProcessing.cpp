#include<iostream>
#include<fstream> //preprocessor directive for input file processing

using namespace std;

int main ()
{

//Yolie's program header
    cout << "\n\n********* YOLIE REYES *********\n";
    cout << "********** Project 4 **********\n";
    cout << "********** Problem 3 **********\n";
    cout << "*********** 9-26-18 ***********\n";
    cout << "********** CISP 360 **********\n";

//explaining the function of the program to the user

    cout << "\n\nThis program tests my ability to open a file, "
         << "read data from it \nand then display the following:\n"
         << "\n\nThe number of numbers in the file. \nThe sum of all the"
         << " numbers in the file.\nThe average of all the numbers in the file.\n";


//declaring variables and input file object
    ifstream inputFile;

    double sum = 0.0, valueReadIn = 0.0, average = 0.0;
    int quantity = 0;

//opening file object to test student compentancy
    inputFile.open("/Users/Yolanda/Desktop/Random.txt");

//if-else loop to make sure the file was opened properly
    if(inputFile)
        {
//extracting data from file
          while (inputFile >> valueReadIn)
              {
//incrementing quantity variable
                ++quantity;
//performing sum/running total calculation
                sum += valueReadIn;
              }

          average = (sum / quantity);
//end of program outputs
          cout << "\n\nThis file contained "
                << quantity
                << " numbers.\n";
                cout << "\nThe sum of these "
                << quantity
                << " numbers is "
                << sum
                << ".\n";
                cout << "The average of these "
                << quantity
                << " numbers is "
                << average
                <<".\n";


        }
//else part of if loop displaying an error message if input file is not opened
    else
        {
          cout << "Error in opening the file!\n";
        }


//a visual seperator for the end of the program

        cout << "\n\n**************** End of Program ****************\n";

//closing input file
  inputFile.close();

  return 0;

}
