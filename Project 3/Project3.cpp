

1.time calculator - timeCalculator.cpp
// C# program to convert seconds
// into days, hours,minutes,seconds
using System;

class GFG {

    // function convert second into day
    // hours, minutes and seconds
    static void ConvertSectoDay(int n)
    {
        int day = userNum / (24 * 3600);

        userNum = userNum % (24 * 3600);
        int hour = userNum / 3600;

        userNum %= 3600;
        int minutes = userNum / 60 ;

        userNum %= 60;
        int seconds = userNum;

        Console.WriteLine( day + " "
              + "days " + hour + " "
          + "hours " + minutes + " "
        + "minutes " + seconds + " "
                        + "seconds ");
    }

    // Driver code
    public static void Main ()
    {

        // Given n is in seconds
        int n = 129600;

        ConvertSectoDay(n);
    }
}

// This code is contributed by vt_m.


1000000 seconds
 to
 1 day


 how many minutes are in the left over seconds
 how many minutes are in the left over days
 division and modulus

Write a program that asks the user to enter a number of seconds.
  there are 86,400 seconds in a day. If the number of seconds entered by the user is greater than or equal to 86,400, the program should display the number of days in that many seconds.

  There are 3,600 seconds in an hour. If the number of seconds entered by the user is greater than or equal to 3,600 the program should display the number of hours in that many seconds.

  There are 60 seconds in a minute. If the number of seconds entered by the user is greater than or equal to 60, the program should display the number of minutes in that many seconds.

  Sample output:

  Time Calculator
  Enter the seconds you would like to calculate into days, hours and minutes: 100000

        100000
        1 day(s)
        3 hour(s)
        46 minutes(s)
        40 seconds(s)

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

//explaing the function of the program to the user.
    cout << "\n\nThe function of this program is to ask the user for an amount in seconds.\n";
    cout << "Then the program will calculate and display how many days, hours, minutes and seconds the entered value contains.\n\n"

//declaring variables
    const int DAY = 86400, HOUR = 3600, MIN = 60;
    int days = 0, hours = 0, minutes = 0,userSeconds = 0,seconds = 0;   //seconds with no variable:?

//getting user input
    cout << "Please enter a quantity of seconds:";
    cin >> userSeconds

//calculating days in seconds
  days = userSeconds / DAY;
//calculating remainder into hours
  hours = (userSeconds % DAY) / HOUR;
//calculating remainder into minutes
  minutes = (userSeconds % HOUR;
//setting remainder to seconds
  seconds = ()(userSeconds % DAY) % HOUR)% MIN;


//end of program outputs
  cout << userSeconds << " seconds breaks down into:\n\n";
  cout << days << " day(s)\n";
  cout << hours << " hour(s)\n";
  cout << minutes << " minute(s)\n";
  cout << seconds << " second(s)\n";

//a visual seperator for the end of the program
  cout << "\n\n**************** End of Program ****************\n";



  return 0;
}








2. the speed of sound - speedOfSound.cpp

the time the user enters is the time you use to multiply for distance
choices are 1-5 swtich and else if statements for this problem.

The Speed of Sound in Gases

When sound travels through a gas, its speed depends primarily on the density of the medium. The less dense the medium, the faster the speed will be. The following table shows the spproximate speed of sound at 0 degrees centigrade, measured in meters per second. when traveling through carbon dioxide, air, helium, and hydrogen.

Carbon dioxide    258.0
Air               331.0
Helium            972.0
Hydrogen        1,270.0


Write a program that displays a menu allowing the user to select one of these four gases.

The Speed of Sound in Gases
  1. Calculate distance in Carbon dioxide
  2. Calculate distance in Air
  3. Calculate distance in Helium
  4. Calculate distance in Hydrogen
  5. Quit
  Enter your choice (1-5):


If the user selects 5 you should quit the program. If the user selects 1-4, you should ask the user to enter the number of seconds it took for the sound to travel in this medium from its source to the location at which it was detected. The program should then report how far away (in meters) the source of the sound was from the detection location.

Input Validation: Check that the user has selected one of the available menu choices.
Do not accept times less than 0 seconds or more than 30 seconds.


include<iostream>
#include<iomanip>

using namespace std;

int main()
{

//Yolie's program header
  cout << "\n\n********* YOLIE REYES *********\n";
  cout << "********** Project 3 **********\n";
  cout << "********** Problem 2 **********\n";
  cout << "*********** 9-17-18 ***********\n";

//explaining the function of the program to the user.
  cout << "\n\nThe function of this program is to calculate\n"
       << "the distance a sound has traveled for a given medium.\n"
       << "The program will ask the user to select the \n"
       << "medium the sound traveled through.\n\n";
  cout << "Then display the distance traveled in meters\n"
       << "per second through that medium after user has \n"
       << "entered a time in seconds from the source to detection.\n\n";

//variable and constant declaration and intilization
  const double CARBON_DIOXIDE = 258.0, AIR = 331.0, HELIUM = 972.0, HYDROGEN = 1270.0;

  int choice = 0, seconds = 0;

  double distanceTraveled = 0;

//displaying menu and User input prompt
  cout << "\t\tSpeed of Sound in Gases:\n"
       << "1.Calculate distance in Carbon Dioxide.\n"
       << "2.Calculate distance in Air.\n"
       << "3.Calculate distance in Helium.\n"
       << "4.Calculate distance in Hydrogen.\n"
       << "5.Quit\n\n"
       << "Please enter 1 - 4 to run the program and 5 to quit: ";
  cin  >> choice;
//input validation for menu choices
  while (choice < 0 || choice > 5)
    {
      cout << "\nPlease enter a value between 1 - 4 or 5 to quit: ";
      cin  >>  choice;
    }
// breaking out of loop to quit program if choice is 5
  if (choice == 5)
    {

    }
  else
    {
//getting user time
      cout << "\nPlease enter a time between 0 and 30 seconds: ";
      cin  >> seconds;
    }
//input validation for 0-30 seconds of entered times
  while (seconds < 0 || seconds > 30) && choice != 5
    {
      cout << "\nPlease enter a time between 0 and 30 seconds: ";
      cin  >> seconds;

    }

//end of program out puts in nested if-else if statements
  if (choice == 1)
    {
  //setting distance traveled formula for choice 1
      distanceTraveled = CARBON_DIOXIDE * seconds;
      cout << "A sound taking " << seconds << " seconds to travel\n"
           << "through Carbon Dioxide will have traveled a distance of " << distanceTraveled << " meters per second.\n";
    }
  else if (choice == 2)
    {
  //setting distance traveled formula for choice 2
      distanceTraveled = AIR * seconds;
      cout << "A sound taking " << seconds << " seconds to travel\n"
           << "through Air will have traveled a distance of "
           << distanceTraveled << "meters per second.\n";
    }
  else if (choice == 3)
    {
  //setting distance traveled formula for choice 3
      distanceTraveled = HELIUM * seconds;
      cout << "A sound taking " << seconds << " seconds to travel\n"
           << "through Helium will have traveled a distance of "
           << distanceTraveled << "meters per second.\n";
    }
  else if (choice == 4)
    {
  //setting distance traveled formula for choice 4
      distanceTraveled = HYDROGEN * seconds;
      cout << "A sound taking " << seconds << " seconds to travel\n"
           << "throuh Hydrogen will have traveled a distance of "
           << distanceTraveled << " meters per seconds.\n";
    }
  else
  //quitting program for choice 5
    {
      cout << "Good bye or as the Nahuatl people would say Ye niauh!";

    }

//a visual seperator for the end of the program
  cout << "\n\n**************** End of Program ****************\n";



return 0;
}








3. math tutor - mathTutor.cpp

using rand and srand with ctime
integer not floating point.

Write a program that can be used as a math tutor for a young student. The program should display two random numbers that are to be added such as:

   247
  +129
-------

The program should wait for the student to enter the answer. If the answer is correct, a message of congratulations should be printed. If the answer is incorrect, a message should be printed showing the correct answer.


#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
  {
//Yolie's program header
  cout << "\n\n********* YOLIE REYES *********\n"
       << "********** Project 3 **********\n"
       << "********** Problem 3 **********\n"
       << "*********** 9-18-18 ***********\n";

//explaining the function of the program to the user
  cout << "\n\nThe function of this program is to tutor you in math.\n"
       << "This program will display two numbers to add, wait for\n"
       << "your input, check the answer and then display the\n "
       << "correct answer if answered incorrectly.\n";

//declaring variables and seed for random function
  int random1 = 0, random2 = 0, userAnswer = 0, correctAnswer = 0;
  unsigned seed = time(0);

//setting up random function
  srand(seed);

//generating addition problem
  random1 = rand();
  random2 = rand();
  correctAnswer = random1;

  cout >> right >> setw(6) >> random1 >> endl;
  cout >> right >> setw(6) >> random2 >> endl;
  cout >> left >> setw(6) >> "+\n"
  cout >> "------\n";

//getting user answer
  cin << userAnswer;
//validating user answer
  if ( userAnswer == correctAnswer)
    {
      cout >> "\n\nGreat Job!"
    }
  else
    {
      cout >> "\n\nThe correct answer is:"
           >> correctAnswer;
    }


//a visual seperator for the end of the program
  cout << "\n\n**************** End of Program ****************\n";

    return 0;
  }



4.mobile service provider - mobileService.cpp

 package c doesnt require a check for overage because it is unlimited and use char for the packages and validate data.

A mobile phone service provider has three different data plans for its customers:

  Package A: For $39.99 per month, 4 gigabytes are provided. Additional data costs $10 per gigabyte.

  Package B: For $59.99 per month, 8 gigabytes are provided. Additional data costs $5 per gigabyte.

  Package C: For $69.99 per month, unlimited data is provided.

Write a program that calculates a customers monthly bill. It should ask which package the customer has purchased and how many gigabytes were used. It should then display the total amount due.

Input Validation: Be sure the user only selects package A, B, or C.

#include<iostream>

using namespace std;

int main()
  {

//explaining the function of the program to the user
    cout << "\n\nThe function of this program is to calculate a\n"
        << "mobile phone monthly bill after the user has entered\n"
        << "package A, B or C and monthly gigabyte usage.\n ";

//declaring constants and variables
    const double PACKAGE_A = 10.00, PACKAGE_B = 5.00;

    char userSelection;
    int monthlyUsage = 0;
    double monthlyBill = 0.0;
    bool isOver = false;
//Displaying package options
    cout << "\nPackage A: \n"
         <<"For $39.99 per month, 4 gigabytes are provided.\n"
         << "Additional data costs $10 per gigabyte."<< endl;

    cout << "\nPackage B: \n"
         << "For $59.99 per month, 8 gigabytes are provided.\n"
         << "Additional data costs $5 per gigabyte." << endl;

    cout << "\nPackage C: \n"
         << "For $69.99 per month, unlimited data is provided." << endl;

//getting user package and validating data
    cout << "\n\n\tPlease enter the package you purchase: ";
    cin >> userSelection;
    userSelection = toupper(userSelection);

    while (userSelection != 'A'|| userSelection != 'B' || userSelection != 'C')
      {
        cout << "\n\n\tPlease enter a valid mobile package (A,B or C): ";
        cin >> userSelection;
      }

//getting used gigabytes and validating data
    cout << "\nPlease enter the amount of gigabytes used: ";
    cin >> monthlyUsage;

    while (monthlyUsage < 0)
      {
        cout << "Please enter a positive number for gigabytes used: ";
        cin >> monthlyUsage;
      }


//switch statement to set up value of monthly bill
    switch (userSelection)
    {
      case 'a':
      case 'A': if (monthlyUsage > 4)
                monthlyUsage -= 4;

                monthlyBill = monthlyUsage * PACKAGE_A + 39.99;
                break;
      case 'b':
      case 'B': if(monthlyUsage > 8)
                monthlyUsage -= 8;
                monthlyBill = monthlyUsage * PACKAGE_B + 59.99;
                break;
      default: monthlyBill = 69.99;
    }


//end of program outputs
    cout << "\n\nYou selected package " << userSelection
         << ".\nYou used " << monthlyUsage << " gigabyte(s) this month." << endl;

    cout << "Total monthly bill: "
         << monthlyBill << endl;
//a visual seperator for the end of the program
    cout << "\n\n**************** End of Program  ****************\n";


    return 0;
  }



////with if statements
********
*******
*******
*********
*****
*********

#include<iostream>

using namespace std;

int main()
  {

//explaining the function of the program to the user
    cout << "\n\nThe function of this program is to calculate a\n"
        << "mobile phone monthly bill after the user has entered\n"
        << "package A, B or C and monthly gigabyte usage.\n ";

//declaring constants and variables
    const double PACKAGE_A = 10.00, PACKAGE_B = 5.00;

    char userSelection;
    int monthlyUsage = 0;
    double monthlyBill = 0.0;
    bool isOver = false;
//Displaying package options
    cout << "\nPackage A: \n"
         <<"For $39.99 per month, 4 gigabytes are provided.\n"
         << "Additional data costs $10 per gigabyte."<< endl;

    cout << "\nPackage B: \n"
         << "For $59.99 per month, 8 gigabytes are provided.\n"
         << "Additional data costs $5 per gigabyte." << endl;

    cout << "\nPackage C: \n"
         << "For $69.99 per month, unlimited data is provided." << endl;

//getting user package and validating data
    cout << "\n\n\tPlease enter the package you purchase: ";
    cin >> userSelection;
    userSelection = toupper(userSelection);

    if ( userSelection = 'A' || userSelection = 'B'|| userSelection = 'C')
      {
//getting used gigabytes and validating data
          cout << "\nPlease enter the amount of gigabyte  used: ";
          cin >> monthlyUsage;

          while (monthlyUsage < 0)
            {
              cout << "Please enter a positive number fo  gigabytes used: ";
              cin >> monthlyUsage;
            }
      }
    else
      {
          cout << "Please enter a valid package A, B or C"
          cin >> userSelection
      }

//switch statement to set up value of monthly bill
    switch (userSelection)
    {
      case 'a':
      case 'A': if (monthlyUsage > 4)
                {
                  monthlyUsage -= 4;
                  monthlyBill = monthlyUsage * PACKAGE_A + 39.99;
                  break;
                }
                else
                {
                  monthlyBill = 39.99
                }

                monthlyBill = monthlyUsage * PACKAGE_A + 39.99;
                break;
      case 'b':
      case 'B': if(monthlyUsage > 8)
                {
                  monthlyUsage -= 8;
                  monthlyBill = monthlyUsage * PACKAGE_B + 59.99;
                  break;
                }
                else
                  monthlyBill = 59.99
                  break;

      default: monthlyBill = 69.99;
    }


//end of program outputs
    cout << "\n\nYou selected package " << userSelection
         << ".\nYou used " << monthlyUsage << " gigabyte(s) this month." << endl;

    cout << "Total monthly bill: "
         << monthlyBill << endl;
//a visual seperator for the end of the program
    cout << "\n\n**************** End of Program  ****************\n";


    return 0;
  }
