



/*
1. Dice game -



srand and rand

make a range of values 1-6 for 6 sided dice

for loop to execute the 11 times requested

comparison between player one and player two to see who won.

then use another loop outside of base game and allow the users to continue with the game if they say 'y'

and keep score of how many times each player has one.

Dice Game (10 pts) – diceGame.cpp





a.    Write a program using loops that simulates two players playing a dice game for 11 turns. For each turn, you roll two dices and add up the numbers. When the total is even, player1 gets a point and when it is odd, player2 gets a point. You must keep track of how many points each player gets. At the end you need to determine and display which player won. Use random numbers to generate the dice roll for each turn. Don't forget to seed your random number generator.

Note: This part of your program does not require any user input.

 b.    Extend your program by using a loop around your game that asks the users whether they want to play again (y or n) and runs the whole game again if they enter ‘y’ or ‘Y’ and exits if they press anything else. At the end, you should display how many rounds of games each player won.

 */

 #include<iostream>
 #include<cstdlib>
 #include<ctime>
 #include<iomanip>

 using namespace std;

 int main()
 {
 //Yolie's program header
       cout << "\n\n********* YOLIE REYES *********\n";
       cout << "********** Project 4 **********\n";
       cout << "********** Problem 1 **********\n";
       cout << "*********** 9-23-18 ***********\n";
       cout << "********** CISP 360 **********\n";

 //explaining the function of the program to the user
   cout << "\n\nThis program is a dice game, for two players."
        << "Each player rolls two dice,\nthe total of all four "
        << "dice is added. When the total is even Player1 is\n"
        << "awarded the amount rolled. When the total is odd "
        << "Player2 is \nawarded the amount rolled. \nThere are 11 "
        << "rolls per game.The winner is determined"
        << " by the\ntotal of all 11 dice rolls per game.\n";

 //declaring variables
   const int DICE_MIN = 1, DICE_MAX = 6;

   unsigned int seed = time(0);

   int player1Dice1 = 0, player1Dice2 = 0, player2Dice1 = 0, player2Dice2 = 0, diceTotal = 0;

   int roundCounter = 0, player1Wins = 0, player2Wins = 0, player1DiceTotal = 0, player2DiceTotal = 0, gamesPlayedCounter = 1,player1Score = 0, player2Score = 0;


 //seeding random function and generating random numbers
 srand(seed);



 //getting random numbers to add for the rounds
 while ( roundCounter <= 10 )
   {
     player1Dice1 = (rand()% (DICE_MAX - DICE_MIN +1)) +DICE_MIN;
     player2Dice1 = (rand()% (DICE_MAX - DICE_MIN +1)) +DICE_MIN;
     player1Dice2 = (rand()% (DICE_MAX - DICE_MIN +1)) +DICE_MIN;
     player2Dice2 = (rand()% (DICE_MAX - DICE_MIN +1)) +DICE_MIN;

     player1DiceTotal = player1Dice1 + player1Dice2;

     player2DiceTotal = player2Dice1 + player2Dice2;

     diceTotal = player1DiceTotal + player2DiceTotal;
     roundCounter++;

     if ((diceTotal % 2) == 0)
       {
         player1Wins += 1; //running total of wins per player
         player1Score += diceTotal; //total dice amount accumulated per player

       }
     else
       {
         player2Wins += 1; //running total of wins per player
         player2Score += diceTotal; //total dice amount accumulated per player
       }
 //displaying the results from the round
     cout << "\n\n\t****The results from roll "
          << roundCounter << " out of 11***" <<endl;
     cout << "\n\tPlayer 1 dice 1: "
          << player1Dice1 << endl;
     cout << "\tPlayer 1 dice 2: "
          << player1Dice2 << endl;
     cout << "\n\tPlayer 1 total: "
          << player1DiceTotal << endl;



     cout << "\n\n\tPlayer 2 dice 1:"
          << player2Dice1 << endl;
     cout << "\tPlayer 2 dice 2:"
          << player2Dice2 << endl;
     cout << "\n\tPlayer 2 total : "
          << player2DiceTotal << endl;


     cout << "\n\n\tThe total for this round is: "
          << diceTotal;




 //displaying total wins per player
     cout << "\n\n\t\tPlayer 1 Wins: "
          << player1Wins << endl;

     cout << "\t\tPlayer 1 Score: "
          << player1Score;


     cout << "\n\n\t\tPlayer 2 Wins: "
          << player2Wins << endl;
     cout << "\t\tPlayer 2 Score: "
          << player2Score;



   }
   if (player1Score > player2Score)
     {
       cout << "\n\n\nThe winner of this game is "
            << "Player 1!"<< endl;
     }
   else
     {
       cout << "\n\n\nThe winner of this game is "
            << "Player 2!" << endl;
     }

 //a visual seperator for the end of the program
     cout << "\n\n**************** End of Program ****************\n";


   return 0;
 }





















2.

get rows and then validate it requires nested loop

Pattern Display (5 pts) – patternDisplay.cpp



Write a program that asks the user how many rows of pattern they would like to display and use loops to draw the pattern with the specified number of rows.  For example, if the user inputs 5, the pattern would appear as follows:

#
*#
**#
***#
****#
Input Validation: Do not accept number of rows less than 1 or more than 20. Use nested loops, do not simply display using a single loop and /or cout statements.



#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{

//Yolie's program header
        cout << "\n\n********* YOLIE REYES *********\n";
        cout << "********** Project 4 **********\n";
        cout << "********** Problem 2 **********\n";
        cout << "*********** 9-23-18 ***********\n";
        cout << "********** CISP 360 **********\n";



  //explaing the function of the program to the user
    cout << "\n\nThe function of this program is to generate a pattern of *s after user has entered number of rows between 1- 20.\n";

    cout << "\tPlease enter number of rows to print: "
    cin  >> rows;



      //declaring variables
        int rows = 0, star =0

        for (int rows = 0; rows <= 20; rows++)
          {
            for (int star = 1; star <= rows; star++)
              {
                cout << "*";
                cout << endl;

                break;
              }
              cout << endl;
          }





//a visual seperator for the end of the program

      cout << "\n\n**************** End of Program ****************\n";

  return 0;
}


















3. FILES a random txt file used to read and find how many numbers there are and then average

Numeric Processing using Files (5 pts) – numFileProcessing.cpp



I have provided a a file named Random.txtPreview the document with this project. This file contains a long list of random numbers. Copy the file to your system, then write a program that opens the file, reads all the numbers from the file, and calculates the following:

A.    The number of numbers in the file

B.    The sum of all the numbers in the file (a running total)

C.   The average of all the numbers in the file

The program should display the number of random numbers found in the file, the sum of the numbers, and the average of the numbers.


#include<iostream>
#include<ifstream> //preprocessor directive for input file processing

using namespace std;

int main ()
{

//Yolie's program header
    cout << "\n\n********* YOLIE REYES *********\n";
    cout << "********** Project 4 **********\n";
    cout << "********** Problem 3 **********\n";
    cout << "*********** 9-26-18 ***********\n";
    cout << "********** CISP 360 ***********\n";

//explaining the function of the program to the user

    cout << "\n\nThis program tests my ability to open a file, "
         << "read data from it \nand then display the following:\n"
         << "The number of numbers in the file. \nThe sum of all the"
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
                << " number is "
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
