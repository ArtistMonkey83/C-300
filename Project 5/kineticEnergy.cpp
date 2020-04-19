#include<iostream>


using namespace std;

//function prototypes:
double kineticEnergy(double, double); //for calculating KE
void inputValidationMass(double&); // for validating mass with an & for passing by reference
void inputValidationVelocity(double&); // for validating velcoity

int main()
{
//Yolie's program header
        cout << "\n\n********* YOLIE REYES *********\n";
        cout << "********** Project 5 **********\n";
        cout << "********** Problem 1 **********\n";
        cout << "*********** 9-29-18 ***********\n";
        cout << "********** CISP 360 **********\n";

//explaining the function of the program to the user
    cout << "\n\nThe function of this program is to calculate the amount of kinetic energy\nan object has after the user has entered mass in kilograms and velocity in \nmeters per second.\n";


//declaring variables
    double kilograms = 0.0, metersPerSecond = 0.0;

//getting user input for Mass

    cout << "\n\n\tPlease Enter a mass in kilograms: ";
    cin  >> kilograms;
    inputValidationMass(kilograms);


//getting user input for Velocity
    cout << "\n\n\tPlease Enter a velocity in meters per second: ";
    cin  >> metersPerSecond;
    inputValidationVelocity(metersPerSecond);




//end of program outputs
    cout << "\n\n\nAn object traveling "
         << metersPerSecond
         << " meters per second, with a mass of "
         << kilograms
         << " \nkilograms will have a kinetic energy of "
         <<kineticEnergy( kilograms, metersPerSecond)
         << " joule(s).";


//a visual seperator for the end of the program
        cout << "\n\n**************** End of Program ****************\n";


  return 0;
}




//input validation for kilograms
    void inputValidationMass(double &userInputMass)
    {
        while (userInputMass < 0.0)
        {
            cout << "\n\n\tPlease enter a positive mass in kilograms: ";
            cin  >> userInputMass;

        }
    }






//input validation for velocity
    void inputValidationVelocity(double &userInputVelocity)
      {
        while (userInputVelocity < 0.0)
        {
              cout << "\n\n\tPlease enter a positive velocity in meters per second: ";
              cin  >> userInputVelocity;


        }

      }



//function for calculating kinetic energy
    double kineticEnergy(double mass, double velocity)
      {
       double energy =  0.5 * mass * (velocity * velocity); //KE = (1/2)mv^2
        return energy;
      }
