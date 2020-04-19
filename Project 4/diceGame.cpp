#include<iostream>
#include<cstdlib>
#include<ctime>

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

  char again = 'y';

//seeding random function and generating random numbers
srand(seed);

do
{
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

    if (roundCounter == 11)
      {
        cout << "\n\n\t\tGAMES PLAYED: " << gamesPlayedCounter;
        cout << "\n\nWould you like to play again? Enter y or n: ";
        cin  >> again;
          if ((again == 'y') || (again =='Y'))
          {
            roundCounter = 0;
            player1Score = 0;
            player2Score = 0;
            gamesPlayedCounter += 1;

          }

          else
           cout << "\n\n\t\tGAMES PLAYED: " << gamesPlayedCounter;
            if(player1Score > player2Wins)
                {

                cout << "\n\n\t\tPlayer 1 wins the games! " << endl;
              }
            else
                {
                cout << "\n\n\t\tPlayer 2 wins the games! " << endl;
                }

      }

}while ((again == 'y' || again =='Y') && roundCounter == 0);

//a visual seperator for the end of the program
    cout << "\n\n**************** End of Program ****************\n";
  return 0;
}
