//Sales Tax

#include<iostream> //Preprocessor directives
#include<cmath>

using namespace std;  //Namespace of the program


int main() // Main program function

{
  const float SALES_TAX = 0.04, COUNTY_TAX = 0.02;  //Constants for tax rates
  double salesTaxTotal = 0.0, countTaxTotal = 0.0, purchasePrice = 95.0, taxTotal = 0.0;   // variable declaration and initialization

   countTaxTotal = purchasePrice * COUNTY_TAX; /* Setting countTaxTotal equal to the value of a mathematical expression */
   salesTaxTotal = purchasePrice * SALES_TAX;  /*Setting salesTaxTotal equal to the value of a mathematical expression */
   taxTotal = countTaxTotal + salesTaxTotal;


   return 0; //End of Main program function
}
