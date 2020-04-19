#include<iostream>

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
         << "\nrendered in addition to medications administered during your stay at Ticiyotl Hospital.";
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

//function for calculating hospital services and medication charges

double basicVisitCosts()
  {
    double sum = 0.0, medication = 0.0, services = 0.0;

    cout << "\n\n\tPlease enter the total charges for all medications administered during your stay: ";
    cin  >> medication;

    medication = inputValidation(medication);

    cout << "\n\n\tPlease enter the total charges for all services rendered at Ticiyotl Hospital: ";
    cin  >> services;

    services = inputValidation(services);

    sum = medication + services;

    return sum;
  }
//inpatient menu and user input function

void inpatientMenu()
  {
    int numDays = 0;
    double chargePerDay = 0.0, totalHospitalBill = 0.0;

    cout << "\n\n\tPlease enter the charge per day: ";
    cin  >> chargePerDay;

    chargePerDay = inputValidation(chargePerDay);

    cout << "\n\n\tPlease enter the number of days for your stay: "
    cin  >> numDays;



    totalHospitalBill = chargePerDay + basicVisitCosts();


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
