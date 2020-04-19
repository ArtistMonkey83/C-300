#include<iostream>
#include<iomanip>

using namespace std;


//functions outside of main
void yoliesProgramHeader()
  {
    cout << "\n\n********* YOLIE REYES *********\n"
         << "********** Project 5 **********\n"
         << "********** Problem 3 **********\n"
         << "*********** 10-2-18 ***********\n"
         << "********** CISP 360 **********\n";
  }

void yoliesProgramFooter()
  {
    cout << "\n\n**************** End of Program ****************\n";
  }
void programExplanation()
  {
    cout << "\n\nThis program will calculte your your total hospital bill"
         << "\nafter you have selected in-patient/outpatient and any hospital services"
         << "\nrendered in addition to medications administered during your stay at \nTiciyotl Hospital.";
  }

void displayPatientChoice ()
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


//overloaded functions to calculate total hospital bill

double basicVisitCosts(int numDays, double chargePerDay, double medication,double services)
  {
    double sum = (numDays* chargePerDay) + medication + services;

    return sum;

  }

double basicVisitCosts(double medication, double services)
  {

    double sum = medication + services;

    return sum;
  }

//inpatient menu and user input function

void inpatientMenu()
  {
    int numDays = 0;
    double chargePerDay = 0.0, medicationCharges = 0.0, hospitalServicesCharges = 0.0;

    cout << "\n\n\tPlease enter the charge per day: ";
    cin  >> chargePerDay;

    chargePerDay = inputValidation(chargePerDay);

    cout << "\n\n\tPlease enter the number of days for your stay: ";
    cin  >> numDays;

    numDays = inputValidation(numDays);

    cout << "\n\n\tPlease enter the total charges for all medications administered during \n\tyour stay at Ticiyotl Hospital: ";
    cin  >> medicationCharges;

    medicationCharges = inputValidation(medicationCharges);

    cout << "\n\n\tPlease enter the total charges for all services rendered at \n\tTiciyotl Hospital: ";
    cin  >> hospitalServicesCharges;

    hospitalServicesCharges = inputValidation(hospitalServicesCharges);


//setting up output format
    cout << fixed << showpoint << setprecision(2);

    cout << "\n\n\tThe total for your stay at Ticiyotl Hospital is $"
         << basicVisitCosts(numDays,chargePerDay,medicationCharges,hospitalServicesCharges);

  }

//function for outpatient menu and user input

void outpatientMenu()
  {
    double medicationCharges = 0.0, hospitalServicesCharges = 0.0;

    cout << "\n\n\tPlease enter the total charges for all medications administered \n\tduring your stay at Ticiyotl Hospital: ";
    cin  >> medicationCharges;

    medicationCharges = inputValidation(medicationCharges);

    cout << "\n\n\tPlease enter the total charges for all services rendered at \n\tTiciyotl Hospital: ";
    cin  >> hospitalServicesCharges;

    hospitalServicesCharges = inputValidation(hospitalServicesCharges);

    cout << fixed << showpoint << setprecision(2);

    cout << "\n\n\tThe total for your stay at Ticiyotl Hospital is: $"
         << basicVisitCosts(medicationCharges, hospitalServicesCharges);
  }

//function for deciding inpatient or outpatient input functions
void patientMenu(char userSelection)
  {
    switch (userSelection)
     {
      case 'i':
      case 'I': inpatientMenu();
      break;

      case 'o':
      case 'O': outpatientMenu();
      break;

      case '0': cout << "Zero(0) is not a valid choice only I or O";
      break;


    }

  }




int main ()
{
//declaring variables
    char patientType = ' ';

//function for yolie's header
    yoliesProgramHeader();
//function explaining the function of the program to the user
    programExplanation();

//calling function for the user input of inpatient/outpatient choice
    displayPatientChoice();

    cin >> patientType;

//calling function for processing,validating user input and displaying total Bill
    patientMenu(patientType);

//function for yolie's footer
    yoliesProgramFooter();

  return 0;
}
