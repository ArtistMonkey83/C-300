#include<iostream>

using namespace std;

int main()
  {

//explaining the function of the program to the user
    cout << "\n\nThe function of this program is to calculate a\n"
        << "mobile phone monthly bill after the user has entered\n"
        << "package A, B or C and monthly gigabyte usage.\n ";

//declaring constants and variables
    const double PACKAGE_A = 10.00, PACKAGE_B = 5.00;

    char userSelection;
    int monthlyUsage = 0;
    double monthlyBill = 0.0;

//Displaying package options
    cout << "\nPackage A: \n"
         <<"For $39.99 per month, 4 gigabytes are provided.\n"
         << "Additional data costs $10 per gigabyte."<< endl;

    cout << "\nPackage B: \n"
         << "For $59.99 per month, 8 gigabytes are provided.\n"
         << "Additional data costs $5 per gigabyte." << endl;

    cout << "\nPackage C: \n"
         << "For $69.99 per month, unlimited data is provided." << endl;

//getting user package and validating data
    cout << "\n\n\tPlease enter the package you purchase: ";
    cin >> userSelection;
    userSelection = toupper(userSelection);

    if ( userSelection == 'A' || userSelection == 'B'|| userSelection == 'C')
      {
//getting used gigabytes and validating data
          if ( userSelection != 'C')
              {
                cout << "\n\tPlease enter the amount of gigabyte tused: ";
                cin >> monthlyUsage;
              }
          while (monthlyUsage < 0 && userSelection != 'C')
            {
              cout << "\n\tPlease enter a positive number for gigabytes used: ";
              cin >> monthlyUsage;
            }
      }
    else
      {
          cout << "\n\tPlease enter a valid package A, B or C";
          cin >> userSelection;
      }

//switch statement to set up value of monthly bill
    switch (userSelection)
    {
      case 'a':
      case 'A': if (monthlyUsage > 4)
                {
                  monthlyUsage -= 4;
                  monthlyBill = monthlyUsage * PACKAGE_A + 39.99;
                  break;
                }
                else
                {
                  monthlyBill = 39.99;
                }

                break;
      case 'b':
      case 'B': if(monthlyUsage > 8)
                {
                  monthlyUsage -= 8;
                  monthlyBill = monthlyUsage * PACKAGE_B + 59.99;
                  break;
                }
                else
                  monthlyBill = 59.99;
                  break;

      default: monthlyBill = 69.99;
    }


//end of program outputs
    if ( userSelection != 'C')
        {
          cout << "\n\nYou selected package " << userSelection
          << ".\nYou used " << monthlyUsage << " gigabyte(s) this month." << endl;
          cout << "Total monthly bill: $"
           << monthlyBill << endl;
        }
    else
        {
        cout << "\nPackage C comes with unlimited data making your total monthly bill: $"
         << monthlyBill << endl;
        }
//a visual seperator for the end of the program
    cout << "\n\n**************** End of Program  ****************\n";


    return 0;
  }
