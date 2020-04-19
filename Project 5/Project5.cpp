/*Write C++ programs for the following problems. Ensure that your program compiles and runs correctly. Upload the .cpp files. Name your files exactly as your instructor has asked. A .pdf version is attached herePreview the document.

Programming Project on Chapter 6

Functions

1.

Kinetic Energy (4 pts) – kineticEnergy.cpp





In physics, an object that is in motion is said to have kinetic energy. The following formula can be used to determine a moving object’s kinetic energy:

LaTeX: KE\:=\:\frac{1}{2}mv^2 K E = 1 2 m v 2
 KE = (1/2)mv^2

The variables in the formula are as follows: KE is the kinetic energy, m is the object’s mass in kilograms, and v is the object’s velocity, in meters per second.

Write a function named kineticEnergy that accepts an object’s mass (in kilograms) and velocity (in meters per second) as arguments. The function should return the amount of kinetic energy that the object has. Demonstrate the function by calling it in a program that asks the user to enter values for mass and velocity.
*/

#include<iostream>


using namespace std;

int main()
{
//Yolie's program header
        cout << "\n\n********* YOLIE REYES *********\n";
        cout << "********** Project 5 **********\n";
        cout << "********** Problem 1 **********\n";
        cout << "*********** 9-29-18 ***********\n";
        cout << "********** CISP 360 **********\n";

//explaining the function of the program to the user
    cout << "\n\nThe function of this program is to calculate the amount of kinetic energy\n an object has after the user has entered mass in kilograms and velocity in meters\n per second.\n"

//function prototypes:
    double kineticEnergy(double, double) //for calculating KE
    void inputValidationMass(double) // for validating mass
    void inputValidationVelocity(double) // for validating velcoity

//declaring variables
    double kilograms = 0.0, metersPerSecond = 0.0;

//getting user input for Mass

    cout << "\n\n\tPlease Enter a mass in kilograms: ";
    cin  >> kilograms;
    inputValidationMass(kilograms);


//getting user input for Velocity
    cout << "\n\n\tPlease Enter a velocity in meters per second: ";
    cin  >> metersPerSecond;
    userInputVelocity(metersPerSecond);




//end of program outputs
    cout << "\n\n\tAn object traveling "
         << metersPerSecond
         << " meters per second,\nwith a mass of "
         << kilograms
         << " kilograms will have a kinetic energy of\n"
         <<kineticEnergy(metersPerSecond, kilograms)
         << " meters per second squared";


//a visual seperator for the end of the program
        cout << "\n\n**************** End of Program ****************\n";


  return 0;
}




//input validation for kilograms
    void inputValidationMass(double userInputMass)
    {
        while (userInputMass < 0.0)
        {
            cout << "\n\n\tPlease enter a positive mass in kilograms: ";
            cin  >> userInputMass;

            if (userInputMass > 0.0)
            {
              kilograms = userInputMass;
            }
        }
      return 0;
    }



//getting user input for velocity
    cout << "\n\n\tPlease Enter a velocity in meters per second: ";
    cin  >> metersPerSecond;
    inputValidationVelocity(metersPerSecond);







//input validation for velocity
    void inputValidationVelocity(double userInputVelocity)
      {
        while (userInputVelocity < 0.0)
        {
              cout << "\n\n\tPlease enter a positive velocity in meters per second: ";
              cin  >> metersPerSecond;

              if (userInputVelocity > 0.0)
              {
                metersPerSecond = userInputVelocity;
              }
        }
        return 0;
      }



//function for calculating kinetic energy
    double kineticEnergy(double mass, double velocity)
      {
        energy =  0.5 * mass * (velocity * velocity) //KE = (1/2)mv^2
        return energy;
      }













/*
2.

Rock, Paper, Scissors game (10 pts) – rockPaperScissors.cpp



Write a program that lets the user play the game of Rock, Paper, Scissors against the computer. The program should work as follows:

1.    Display a menu and ask the user to enter his or her choice. Menu should look like this:

1. Rock
2. Paper
3. Scissors
4. Quit
Enter your choice (1 – 4):
Make sure you validate the input.


2.    Generate a random number in the range of 1 through 3 for the computer’s choice. If the number is 1, then the computer has chosen rock. If the number is 2, then the computer has chosen paper. If the number is 3, then the computer has chosen scissors. (Don’t display the computer’s choice yet.)

3.    Display the user’s choice

4.    Display the computer’s choice

5.    Select a winner is according to the following rules:

Rock smashes the scissors.
Scissors cut paper.
Paper wraps rock.
If both players make the same choice, it is a tie.
6.    Display the menu and repeat the program until the user selects 4 to Quit from the program.

Use the following function prototypes:

1. void displayMenu() – display the menu

2. int getUserInput() – get user input as one of the  menu choices and return it as an int

3. int generateComputerChoice() – generate the computers choice and return it as an int

4. void displayChoice(int) – display the choice the computer and the user made based on the menu

5. void selectWinner(int, int) – select the winner or tie based on the computer’s choice and the user’s input. Display the winner.

3
*/


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

      }
      else if (gamecounter > 0)
      {
        cout << "\n\n\t**********  Game "
             << gamecounter + 1
             << "  **********";
        displayMenu();

        cout << "\n\n\tPlease enter a selection: ";
        cin  >> userSelection;

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

  if (userSelection == 4 || (playAgain == 'n' || playAgain == 'N'))
    {
      cout << "\n\nAnej! Which is Nahuatl for Good bye.";
    }

//a visual seperator for the end of the program
    cout << "\n\n**************** End of Program ****************\n";

  return 0;
}



/*
Overloaded Hospital (6 pts) – hospital.cpp



Write a program that computes and displays the charges for a patient’s hospital stay. First, the program should ask if the patient was admitted as an inpatient or an outpatient. If the patient was an inpatient, the following data should be entered:

The number of days spent in the hospital
The daily rate
Hospital medication charges
Charges for hospital services (lab tests, etc.)
The program should ask for the following data if the patient was an outpatient:

Charges for hospital services (lab tests, etc.)
Hospital medication charges


The program should use two overloaded functions to calculate the total charges. One of the functions should accept arguments for the inpatient data, while the other function accepts arguments for outpatient information. Both functions should return the total charges.

Input Validation: Do not accept negative numbers for any data.
*/

#include<iostream>

using namespace std;


//functions outside of main
void yoliesProgramHeader()
  {
    cout << "\n\n********* YOLIE REYES *********\n";
         << "********** Project 5 **********\n"
         << "********** Problem 3 **********\n"
         << "*********** 10-2-18 ***********\n"
         << "********** CISP 360 **********\n"
  }

void programExplanation()
  {
    cout << "\n\nThis program will calculte your your total hospital bill"
         << "\nafter you have selected in-patient/outpatient and any hospital services"
         << "\nrendered in addition to medications administered during your stay at Ticiyotl Hospital.";
  }

int displayPatientChoice ()
  {
    cout << "\n\n\tPlease enter if your visit was an inpatient (I) or outpatient(O): ";
  }

//inputValidation function

double inputValidation(double userInput)
  {
    while (userInput<0.0)
      {
          cout << "\n\n\tPlease enter a valid amount greater then $0.0: ";
          cin  >> userInput;
      }
    return userInput;
  }
//function for accepting validated user input and calculating total

void hospitalBillTotal(int,double, double, double)
  {


  }

void hospitalBillTotal(double,double)
  {


  }


//inpatient menu and user input function

void inpatientMenu()
  {
    int numDays = 0;
    double chargePerDay = 0.0, medicationCharges = 0.0, hospitalServicesCharges = 0.0, totalHospitalBill = 0.0;

    cout << "\n\n\tPlease enter the charge per day: ";
    cin  >> chargePerDay;

    chargePerDay = inputValidation(chargePerDay);

    cout << "\n\n\tPlease enter the total charges for all medications administered during your stay: ";
    cin  >> medicationCharges;

    medicationCharges = inputValidation(medicationCharges);

    cout << "\n\n\tPlease enter the total charges for all services rendered at Ticiyotl Hospital: ";
    cin  >> hospitalServicesCharges;

    hospitalServicesCharges = inputValidation(hospitalServicesCharges);




    cout << "\n\n\tWith a $"
         << chargePerDay
         << " charge per day, at "
         << numDays
         << " total days in our fine hospital, added to your medication costs of $"
         << medicationCharges
         << " Plus services rendered at $"
         << hospitalServicesCharges
         << "brings your total Bill for your visit : $"
         << totalHospitalBill;
  }

//function for outpatient menu and user input

void outpatientMenu()
  {
    double medicationCharges = 0.0, hospitalServicesCharges = 0.0, totalHospitalBill = 0.0;

    cout << "\n\n\tPlease enter the total charges for all medications administered during your stay: ";
    cin  >> medicationCharges;

    medicationCharges = inputValidation(medicationCharges);

    cout << "\n\n\tPlease enter the total charges for all services rendered at Ticiyotl Hospital: ";
    cin  >> hospitalServicesCharges;

    hospitalServicesCharges = inputValidation(hospitalServicesCharges);

    cout << "\n\n\tWith medication charges at $"
         << medicationCharges
         << " and Hospital Services charges at $"
         << hospitalServicesCharges
         << " The total for your stay at Ticiyotl Hospital is: $"
         << totalHospitalBill;
  }

//function for deciding inpatient or outpatient input functions
void patientMenu(char userSelection)
  {
    switch (userSelection)
     {
      case i:
      case I: inpatientMenu();

      break;

      case o:
      case O: outpatientMenu();

      case 0: cout << "Zero(0) is not a valid choice only I or O"
      break;


    }

  }




int main ()
{
//declaring variables
    char patientType = null;


//function explaining the function of the program to the user
    programExplanation();

//calling function for the user input of inpatient/outpatient choice
    displayPatientChoice();

    cin >> patientType;

//calling function for processing,validating user input and displaying total Bill
    patientMenu(patientType);



  return 0;
}
