#include<iostream>
#include<cstdlib>
#include<ctime>




using namespace std;


/*functions outside of main */


//function for Yolie's program header
void yoliesProgramHeader()
      {
        cout << "\n\n********* YOLIE REYES *********\n";
        cout << "********** Project 5 **********\n";
        cout << "********** Problem 2 **********\n";
        cout << "*********** 10-1-18 ***********\n";
        cout << "********** CISP 360 **********\n";
      }
//function explaining the function of the program to the user
void displayExplanation()
  {
    cout << "\n\nIn this program you can play a game of rock, paper, scissors with the computer.\n";
  }

//function for displaying menu
      void displayMenu()
        {
          cout << "\n\n\t1. Rock\n"
               << "\t2. Paper\n"
               << "\t3. Scissors\n"
               << "\t4. Quit\n"
               << "\nValid choices are 1 - 4";
        }


//function for validating user input
int validatedUserInput (int userChoice)
{
  while ((userChoice < 1) || (userChoice > 4))
  {
    cout << "Please enter a valid choice 1-3 or 4 to quit: ";
    cin >> userChoice;
  }

  if (userChoice == 4)
    {
      exit(0);
    }

  return userChoice;
}


//function validating user input
int getUserInput(int &userSelection)
{
  userSelection = validatedUserInput(userSelection);

  return userSelection;
}

//function for setting the computer's choice
void generateComputerChoice (int &compSelection)
      {
        const int MAX_VALUE = 4, MIN_VALUE = 1;
        unsigned int seed = time (0);

        srand(seed);

        compSelection = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;


      }

//function for selecting the winner
void selectWinner (int compChoice, int userChoice)
      {
        if ( compChoice == 1 && userChoice == 3) //scissors/rock winning comp
        {
          cout << "\n\n\tThe Computer has won!\n";
        }
        else if ( compChoice == 3 && userChoice == 1 ) //scissors/rock winning user
          cout << "\n\n\tYou have won!\n";

        else if ((userChoice == 1) && (compChoice == 2)) //rock/paper comp winning
          cout << "\n\n\tThe Computer has won!";

        else if ((compChoice == 1) && (userChoice == 2)) //rock/paper user winning
          cout << "\n\n\tYou have won!\n";

        else if ( compChoice == 3 && userChoice == 2 ) //paper/scissors comp winning
          cout << "\n\n\tThe Computer has won!";

        else if ( userChoice == 3 && compChoice == 2 ) //paper/scissors user winning
          cout << "\n\n\tThe You have won!";

        else
          cout << "\n\n\tThe Computer has chosen the same,this round ends in a tie!\n";
      }

//function for displaying the user and computers choices
void displayChoice(int npcChoice, int userChoice)
      {
        switch (userChoice)
        {
          case 1:
            cout << "\n\n\tYou have chosen Rock.\n";
            break;
          case 2:
            cout << "\n\n\tYou have chosen Paper.\n";
            break;
          case 3:
            cout << "\n\n\tYou have chosen Scissors.\n";
            break;

        }

        switch (npcChoice)
        {
          case 1:
            cout << "\n\n\tThe computer has chosen Rock.\n";
            break;
          case 2:
            cout << "\n\n\tThe computer has chosen Paper.\n";
            break;
          case 3:
            cout << "\n\n\tThe computer has chosen Scissors.\n";
            break;

        }
      }
//validating playAgain variable
void validatedUserInput(char &yesOrNo)
  {
    while (yesOrNo != 'y' && yesOrNo != 'Y' && yesOrNo != 'n' && yesOrNo !='N')
      {
        cout << "\n\nPlease enter if you would like to play again.\n(y) for yes or (n) for no: ";
        cin  >> yesOrNo;

      }
  }


//main function

int main ()
{

int userSelection,compSelection, gamecounter = 0;
char playAgain = ' ';

    yoliesProgramHeader();
    displayExplanation();
  do
    {



      if (gamecounter < 1 )
      {

      displayMenu();

      cout << "\n\n\tPlease enter a selection: ";
      cin  >> userSelection;

      if (userSelection == 4 || (playAgain == 'n' || playAgain == 'N'))
        {
          cout << "\n\nAnej! Which is Nahuatl for Good bye.";
          exit(0);
        }

      }
      else if (gamecounter > 0)
      {
        cout << "\n\n\t**********  Game "
             << gamecounter + 1
             << "  **********";
        displayMenu();

        cout << "\n\n\tPlease enter a selection: ";
        cin  >> userSelection;

        if (userSelection == 4 || (playAgain == 'n' || playAgain == 'N'))
          {
            cout << "\n\nAnej! Which is Nahuatl for Good bye.";
            exit(0);
          }
      }
      getUserInput(userSelection);

      generateComputerChoice(compSelection);

      displayChoice(compSelection,userSelection);

      selectWinner(compSelection,userSelection);

        cout << "\n\nIf you would like to play again please select (Y) for yes or (N) for no: ";
        cin  >> playAgain;
        validatedUserInput(playAgain);

        gamecounter++;

        cin.ignore();

        compSelection = 0;
        userSelection = 0;


    }while (userSelection != 4  && (playAgain == 'y' || playAgain =='Y'));


//a visual seperator for the end of the program
    cout << "\n\n**************** End of Program ****************\n";

  return 0;
}
