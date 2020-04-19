#include<iostream>
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
       << "your input, check the answer and then display the\n"
       << "correct answer if answered incorrectly.\n";

//declaring variables and seed for random function
  unsigned short random1 = 0, random2 = 0, userAnswer = 0, correctAnswer = 0;
  unsigned seed = time(0);

//setting up random function
  srand(seed);

//generating addition problem
  random1 = rand();
  random2 = rand();
  correctAnswer = random1 + random2;

  cout << "\n\n\t" << random1 << endl;
  cout << "+" << "\t" << random2 << endl;
  cout << "--------------\n";

//getting user answer
  cin >> userAnswer;
//validating user answer
  if ( userAnswer == correctAnswer)
    {
      cout << "\n\nGreat Job!";
    }
  else
    {
      cout << "\n\nYour answer is incorrect! Sorry but the correct answer is:"
           << correctAnswer;
    }


//a visual seperator for the end of the program
  cout << "\n\n**************** End of Program ****************\n";

    return 0;
  }
