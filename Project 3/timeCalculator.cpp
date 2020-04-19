#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
//Yolie's program header
    cout << "\n\n********* YOLIE REYES *********\n";
    cout << "********** Project 3 **********\n";
    cout << "********** Problem 1 **********\n";
    cout << "*********** 9-16-18 ***********\n";

//explaining the function of the program to the user.
    cout << "\n\nThe function of this program is to ask the user for an amount in seconds.\n";
    cout << "Then the program will calculate and display how many days, hours, minutes and seconds the entered value contains.\n\n";

//declaring variables
    const int DAY = 86400, HOUR = 3600, MIN = 60;
    long days = 0, hours = 0, minutes = 0,userSeconds = 0, enteredSeconds = 0;   

//getting user input and setting output variable
    cout << "Please enter a quantity of seconds:";
    cin >> userSeconds;
    enteredSeconds = userSeconds;
//calculating days in seconds
  days = userSeconds / DAY;
//calculating remainder into hours
  userSeconds = userSeconds % DAY;
  hours = userSeconds / HOUR;
//calculating remainder into minutes
  userSeconds = userSeconds % HOUR;
  minutes = userSeconds / MIN;
//setting remainder to seconds
  userSeconds = userSeconds % MIN;



//end of program outputs
  cout << enteredSeconds << " seconds breaks down into:\n\n";
  cout << days << " day(s)\n";
  cout << hours << " hour(s)\n";
  cout << minutes << " minute(s)\n";
  cout << userSeconds << " second(s)\n";

//a visual seperator for the end of the program
  cout << "\n\n**************** End of Program ****************\n";



  return 0;
}
