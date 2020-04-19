#include<iostream>
#include<iomanip>

using namespace std;

  int main()
  {
  //Yolie's program header
    cout << "\n\n********* YOLIE REYES *********\n";
    cout << "********** Project 2 **********\n";
    cout << "********** Problem 1 **********\n";
    cout << "*********** 9-13-18 ***********\n";

  //explaining the function of the program to the user
    cout << "\n\nThis program converts U.S. dollars to Yen and Euros.\n\n";

  //declaring and intializing constants and variables
    const double YEN_PER_DOLLAR = 98.93, EUROS_PER_DOLLAR = 0.74;
    long double userEnteredDollar = 0.0, dollarToYen = 0.0, dollarToEuro = 0.0;
    int yen = 0165, euro = 128;

  //getting user input
     cout << "Please enter an amount in U.S dollars and cents to convert: $";
     cin >> userEnteredDollar;

  //converting dollars to Yen and Euros
     dollarToYen = userEnteredDollar * YEN_PER_DOLLAR;
     dollarToEuro = userEnteredDollar * EUROS_PER_DOLLAR;

  //end of program outputs with static casting the Euro and Yen symbols
     cout << "\n\nThe amount of $" << setprecision(2) << fixed << userEnteredDollar << " in Yen is :" << (char)165 << setprecision(2) << fixed << dollarToYen << endl;
     cout << "\nThe amount of $" << setprecision(2) << fixed << userEnteredDollar << " in Euros is :" << (char)euro << setprecision(2) << fixed << dollarToEuro << endl;

  //a visual seperator for the end of the program
     cout << "\n\n**************** End of Program ****************\n";
     return 0;
  }
