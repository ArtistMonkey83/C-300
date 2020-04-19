#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
  {
  //Yolie's program header
  cout << setw(20) << "\n\n********* YOLIE REYES *********\n";
  cout << setw(20) << "********** Project 2 **********\n";
  cout << setw(20) << "********** Problem 2 **********\n";


  //explaining to the user the function of this program.
    cout << "\n\nThe function of this program is to calculate monthly payments after user has\nentered annual interest, life of the loan and amount of the loan.\n\n\n";

  //declaring variables
    long double loanAmount = 0.0, monthlyPayment = 0.0, amountPaidBack = 0.0, interestPaid = 0.0, annualInterest = 0.0, monthlyInterest = 0.0;
    float interestRate = 0.0;
    int payments = 0, numOfPayments = 0;

  //get loan amount
    cout << "Enter the loan amount: \n";
    cin >> loanAmount;

  //get annual interest rate
    cout << "Enter the annual interest rate for the loan:\n";
    cin >> interestRate;

  //convert annual interest rate to monthly interest rate
    monthlyInterest = ((interestRate / 12.0)/100); //

  //number of payments
    cout << "Enter the life of the loan in years:\n\n\n";
    cin >> payments;

  //convert life of loan to total montly Payments
    numOfPayments = payments * 12;

  //calculate monthly payment
    monthlyPayment = ( monthlyInterest * pow(1 + monthlyInterest, numOfPayments) ) / ( pow(1 + monthlyInterest, numOfPayments) - 1 ) * loanAmount;

  //calculate total interest Paid
    interestPaid = (interestRate/100) * loanAmount;

  //calculate total amount paid back
    amountPaidBack = interestPaid + loanAmount;

  //end of program outputs

  cout << "Loan Amount: \n";
  cout << setw(30) << setprecision(2) << fixed << right << loanAmount << endl;

  cout << "Monthly Interest Rate: \n";
  cout << setw(30) << setprecision(2) << fixed << right << monthlyInterest << endl;

  cout << "Number of Payments: \n";
  cout << setw(30) << setprecision(2) << fixed << right << numOfPayments << endl;

  cout << "Monthly Payment: \n";
  cout << setw(30) << setprecision(2) << fixed  << right << monthlyPayment << endl;

  cout << "Total interest: \n";
  cout << setw(30) << setprecision(2) << fixed << right << interestPaid <<endl;

  cout << setw(10) << "Total cost of Loan: \n";
  cout << setw(30) << setprecision(2) << fixed << right << amountPaidBack <<endl;

    return 0;
  }
