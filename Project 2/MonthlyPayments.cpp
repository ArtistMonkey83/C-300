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
  cout << "*********** 9-13-18 ***********\n";


  //explaining to the user the function of this program.
    cout << "\n\nThe function of this program is to calculate monthly payments after user has\nentered annual interest, life of the loan and amount of the loan.\n";

  //declaring variables
    long double loanAmount = 0.0, monthlyPayment = 0.0, amountPaidBack = 0.0, interestPaid = 0.0, monthlyInterest = 0.0;
    float interestRate = 0.0;
    int payments = 0, numOfPayments = 0;

  //get loan amount
    cout << "\nEnter the loan amount: $";
    cin >> loanAmount;

  //get annual interest rate
    cout << "\nEnter the annual interest rate for the loan: ";
    cin >> interestRate;

  //convert annual interest rate to monthly interest rate
    monthlyInterest = (interestRate / 12.0)/100; //

  //number of payments
    cout << "\nEnter the life of the loan in years: ";
    cin >> payments;

  //convert life of loan to total montly Payments
    numOfPayments = payments * 12;

  //calculate monthly payment
    monthlyPayment = ( monthlyInterest * pow(1 + monthlyInterest, numOfPayments) ) / ( pow(1 + monthlyInterest, numOfPayments) - 1 ) * loanAmount;

  //calculate total amount paid back
    amountPaidBack = monthlyPayment * numOfPayments;

  //calculate total interest Paid
    interestPaid = amountPaidBack - loanAmount;

  //a visual seperator for the report generated
    cout << "\n\n********** Statistics for this loan **********\n";
  //end of program outputs

  cout << "\n\nLoan Amount: ";
  cout << setw(20) << setprecision(2) << fixed << right << loanAmount << endl;

  cout << "Annual Interest Rate: ";
  cout << setw(10) << setprecision(2) << fixed << right << static_cast<int>(interestRate) << '%' << endl;

  cout << "Monthly Interest Rate: ";
  cout << setw(9) << setprecision(2) << fixed << right << static_cast<int>(monthlyInterest * 100) << '%' << endl;

  cout << "Number of Payments: ";
  cout << setw(13) << setprecision(2) << fixed << right << numOfPayments << endl;

  cout << "Monthly Payment: ";
  cout << setw(10) << setprecision(2) << fixed  << right << '$' << monthlyPayment << endl;

  cout << "Total cost of Interest: ";
  cout << setw(2) << setprecision(2) << fixed << right << '$' << interestPaid <<endl;

  cout << "Total cost of Loan: ";
  cout << setw(5) << setprecision(2) << fixed << right << '$' << amountPaidBack <<endl;

//a visual seperator for the report generated
    cout << "\n\n**************** End of Report ****************\n";
    return 0;
  }
