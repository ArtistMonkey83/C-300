1. Currency Converter (4 pts)

Write a program that will convert U.S. dollar amounts to Japanese yen and to euros, storing the conversion factors in the constants YEN_PER_DOLLAR and EUROS_PER_DOLLAR. Use the following exchange rates:

1 Dollar = 98.93 Yen

1 Dollar = 0.74 Euros

Format your currency amounts in fixed-point notation, with two decimal places of precision, and be sure the decimal point is always displayed.

#include<iostream>
#include<iomanip>

using namespace std;

  int main()
  {
     const double
     YEN_PER_DOLLAR = 98.93,
     EUROS_PER_DOLLAR = 0.74;

     double
     userEnteredDollar = 0.0
     dollarToYen = 0.0,
     dollarToEuro = 0.0;

     int
     yen = 0165,
     euro = 0128;

     cout << "This program converts U.S. dollars to Yen and Euros.\n";
     cout << "Please enter an amount in U.S dollars and cents to convert: \n";
     cin >> userEnteredDollar;

     dollarToYen = userEnteredDollar * YEN_PER_DOLLAR;
     dollarToEuro = userEnteredDollar * EUROS_PER_DOLLAR;

     cout << "The amount of $" << setprecision(2) << fixed << userEnteredDollar << " in Yen is :" << static_cast<char>(yen) << setprecision(2) << fixed << dollarToYen << endl;
     cout << "The amount of $" << setprecision(2) << fixed << userEnteredDollar << " in Euros is :" << static_cast<char>(euro) << setprecision(2) << fixed << dollarToYen << endl;

     return 0;
  }






2. Monthly Payment (6 pts)

The monthly payment on a loan may be calculated by the following formula:

payment =(rate * (1+rate)^n) / ((1+rate)^n - 1) *l


Rate is the monthly interest rate, which is the annual interest rate divided by 12. (12 percent annual interest would be 1 percent monthly interest.) N is the number of payments, and LoanAmount is the amount of the loan. Write a program that asks for these values then displays a report similar to:

Loan Amount:            $ 10000.00
Yearly Interest Rate:          12%
Monthly Interest Rate:          1%
Number of Payments:             36
Monthly Payment:        $   332.14
Amount Paid Back:       $ 11957.15
Interest Paid:          $  1957.15
Be sure to properly format your output. You should display 3 decimal places for floating point numbers.

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
  {
  //Yolie's program header
  cout << "\n\n********* YOLIE REYES *********\n";
  cout << "********** Project 2 **********\n";
  cout << "********** Problem 2 **********\n";


  //explaining to the user the function of this program.
    cout << "\n\nThe function of this program is to calculate monthly payments after user has\nentered annual interest, life of the loan and amount of the loan.\n";

  //declaring variables
    long double loanAmount = 0.0, monthlyPayment = 0.0, amountPaidBack = 0.0, interestPaid = 0.0, annualInterest = 0.0, monthlyInterest = 0.0;
    float interestRate = 0.0;
    int payments = 0, numOfPayments = 0;

  //get loan amount
    cout << "Enter the loan amount: \n\n";
    cin >> loanAmount;

  //get annual interest rate
    cout << "Enter the annual interest rate for the loan:\n\n";
    cin >> interestRate;

  //convert annual interest rate to monthly interest rate
    monthlyInterest = (interestRate / 12.0)/100; //

  //number of payments
    cout << "Enter the life of the loan in years:\n";
    cin >> payments;

  //convert life of loan to total montly Payments
    numOfPayments = payments * 12;

  //calculate monthly payment
    monthlyPayment = ( monthlyInterest * pow(1 + monthlyInterest, numOfPayments) ) / ( pow(1 + monthlyInterest, numOfPayments) - 1 ) * loanAmount;

  //calculate total amount paid back
    amountPaidBack = monthlyPayment * numOfPayments;

  //calculate total interest Paid
    interestPaid = (interestRate/100) * loanAmount;

  //end of program outputs

  cout << "\n\n\nLoan Amount: ";
  cout << setw(20) << setprecision(2) << fixed << right << loanAmount << endl;

  cout << "Annual Interest Rate: ";
  cout << setw(11) << setprecision(2) << fixed << right << (annualInterest * 100) << endl;

  cout << "Monthly Interest Rate: ";
  cout << setw(10) << setprecision(2) << fixed << right << static_cast<int>(monthlyInterest * 100) << endl;

  cout << "Number of Payments: ";
  cout << setw(13) << setprecision(2) << fixed << right << numOfPayments << endl;

  cout << "Monthly Payment: ";
  cout << setw(16) << setprecision(2) << fixed  << right << monthlyPayment << endl;

  cout << "Total cost of Interest: ";
  cout << setw(9) << setprecision(2) << fixed << right << interestPaid <<endl;

  cout << "Total cost of Loan: ";
  cout << setw(13) << setprecision(2) << fixed << right << amountPaidBack <<endl;

    return 0;
  }












3. Word Game (5 pts)

Write a program that plays a word game with the user. The program should ask the user to enter the following:

Name

Age

City

College

Profession

After the user has entered these items, the program should display the following story, inserting the user’s input into the appropriate locations:

There once was a person named NAME who lived in CITY. At the age of AGE, NAME went to college at COLLEGE. NAME graduated and went to work as a PROFESSION.

Hint: You will need to use getline() to get inputs that have multiple words in them, for example, name, college etc.


#include<iostream>
#include<string>

using namespace std;

int main()

{

//explaining the function of this program to the user
  cout << "This program plays a word game with the user after the user has entered: Name, Age, City, College and Profession\n";

//declaring variables
  string name, city, college, profession;
  int age = 0;

//getting user input

  cout << "Please enter your name:\n";
  getline(cin,name);

  cout << "Please enter your hometown:\n";
  getline(cin,city);

  cout << "Please enter the college you are attending:\n";
  getline(cin,collge);

  cout << "What age did you start attending " << college << "?\n";
  cin >> age;

  cout << "Please enter your profession:\n";

//clearing keyboard buffer to hold profession
  cin.ignore();

  getlin(cin,profession);

//end of program outputs

  cout << "There once was a person named " << name << " who lived in " << city << ". At the age of " << age << ',' << name << " went to college at " << college << '.' << name << " graduated and went to work as a " << profession <<".\n";

  return 0;

}








4. Pizza Party

Suppose you are having a pizza party and need to decide how many pizzas you need to purchase if each person attending is expected to eat an average of four slices. The program should

Ask the user for the number of people who will be at the party

Ask the user for the diameter of the pizzas in inches to be ordered

Calculate and display the number of pizzas to purchase.

To calculate the number of slices in a pizza, use the following information:

Each slice should have an area of 14.125 inches.

To calculate the number of slices, simply divide the area of the pizza by 14.125.

The area of the pizza is calculated with this formula:

LaTeX: Area = \pi r^{2} A r e a = π r 2

Be sure to properly format your output. You should display 3 decimal places for floating point numbers.


#include<iostream>
#include<cmath>

using namespace std;

int main ()
  {

  //explaining to the user the function of this program
    cout << "The function of this program is to calculate how many pizzas will be needed for a   party after the user has entered number of people attending and diameter of pizzas to be   ordered."

  //defining constants and variables
    const double PI = 3.14159
    float diameter = 0.0, radius = 0.0, areaOfPizza = 0.0, numOfSlice = 0.0;
    int numOfPizzas = 0, numOfPeople = 0;

  //getting user inputs
    cout << "Please enter the number of people attending the party: \n";
    cin >> numOfPeople;

    cout << "Please enter the diameter of the pizzas (in inches) you wish to order: \n";
    cin >> diameter;

  //calculating area of the pizza
    radius =  diameter / 2;             //areaOfPizza = PI * pow((diameter /2),2)
    areaOfPizza = PI * pow(radius,2);

  //calculating number of slices per pizza
    numOfSlice = areaOfPizza / 14.125;

  //calculating the number of slices needed for party
  totalSliceCount = numOfPeople * 4;

  //calculating the number of pizzas for the party
  numOfPizzas = totalSliceCount / numOfSlice;

  //end of program outputs
    cout << "With " << numOfPeople << " people attending the party, if you order " << diameter << "\" pizzas you will need to order a minimum of " << numOfPizzas << " pizza(s) for everyone to have 4 slices.";

  return 0;

  }
