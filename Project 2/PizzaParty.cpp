#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main ()
  {
  //Yolie's program header
    cout << "\n\n********* YOLIE REYES *********\n";
    cout << "********** Project 2 **********\n";
    cout << "********** Problem 4 **********\n";
    cout << "*********** 9-13-18 ***********\n";


  //explaining to the user the function of this program
    cout << "\n\nThe function of this program is to calculate how many pizzas will be needed for a party after the user has entered number of people attending and diameter of pizzas to be ordered.\n";

  //defining constants and variables
    const double PI = 3.14159;
    float diameter = 0.0, radius = 0.0, areaOfPizza = 0.0, numOfSlice = 0.0;
    int numOfPizzas = 0, numOfPeople = 0, totalSliceCount = 0;

  //getting user inputs
    cout << "\nPlease enter the number of people attending the party: \n";
    cin >> numOfPeople;

    cout << "\nPlease enter the diameter of the pizzas (in inches) you wish to order: \n";
    cin >> diameter;

  //calculating area of the pizza
    radius =  diameter / 2;             //areaOfPizza = PI * pow((diameter /2),2)
    areaOfPizza = PI * pow(radius,2.0);

  //calculating number of slices per pizza
    numOfSlice = areaOfPizza / 14.125; //constant

  //calculating the number of slices needed for party
  totalSliceCount = numOfPeople * 4;

  //calculating the number of pizzas for the party
  numOfPizzas = totalSliceCount / numOfSlice;


  //end of program outputs
    //cout << setprecision(3) << fixed; no rounding required this time
    cout << "\n\nWith " << numOfPeople << " people attending the party, if you order " << diameter << "\" pizzas you will need to order a minimum of " << numOfPizzas << " pizza(s) for everyone to have 4 slices.";

  //a visual seperator for the end of the program
    cout << "\n\n**************** End of Program ****************\n";
  return 0;

  }
