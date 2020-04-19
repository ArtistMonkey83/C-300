#include<iostream>
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
  cout << "\tSpeed of Sound in Gases:\n"
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

  if (choice != 5)
    {
//getting user time
      cout << "\nPlease enter a time between 0 and 30 seconds: ";
      cin  >> seconds;
    }
//input validation for 0-30 seconds of entered times
  while ((choice != 5) && (seconds < 0 || seconds > 30))
    {
      cout << "\nPlease enter a time between 0 and 30 seconds: ";
      cin  >> seconds;

    }

//end of program out puts in nested if-else if statements
  if (choice == 1)
    {
  //setting distance traveled formula for choice 1
      distanceTraveled = CARBON_DIOXIDE * seconds;
      cout << "\n\n A sound taking " << seconds << " seconds to travel through\n"
           << " Carbon Dioxide will have traveled a distance of \n ";
      cout << distanceTraveled << " meters per second.\n";
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
      cout << "\n\nGood bye or as the Nahuatl people would say Ye niauh!";

    }

//a visual seperator for the end of the program
  cout << "\n\n**************** End of Program ****************\n";



return 0;
}
