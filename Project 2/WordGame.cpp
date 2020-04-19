#include<iostream>
#include<string>

using namespace std;

int main()

{
//Yolie's program header
  cout << "\n\n********* YOLIE REYES *********\n";
  cout << "********** Project 2 **********\n";
  cout << "********** Problem 3 **********\n";
  cout << "*********** 9-13-18 ***********\n";

//explaining the function of this program to the user
  cout << "\n\nThis program plays a word game with the user after the user has entered: \n";
  cout << "Name, Age, City, College and Profession.\n\n\n";

//declaring variables
  string name, city, college, profession;
  int age = 0;

//getting user input

  cout << "Please enter your name:\n";
  getline(cin,name);

  cout << "Please enter your hometown:\n";
  getline(cin,city);

  cout << "Please enter the college you are attending:\n";
  getline(cin,college);

  cout << "What age did you start attending " << college << "?\n";
  cin >> age;

  cout << "Please enter your profession:\n";

//clearing keyboard buffer to hold profession entered by user
  cin.ignore();

  getline(cin,profession);

//end of program outputs

  cout << "\n\n\n\There once was a person named " << name << " who lived in " << city << ". At the age of " << age << ',' << name << " went to college at " << college << '.' << name << " graduated and went to work as a " << profession <<".\n";

//a visual seperator for the end of the program
     cout << "\n\n**************** End of Program ****************\n";
  return 0;

}
