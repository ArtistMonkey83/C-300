
//Miles Per Gallon

#include<iostream>
#include<cmath>

using namespace std;

int main ()
  {
    const double GALLONS = 15.0, MILES = 375.0;
    double mpg = 0.0;

    mpg = (MILES /GALLONS);

    cout<<"This car has a "<<GALLONS<<" gallon gas tank"<<endl;
    cout<<"and gets "<<MILES<<" miles to the tank."<<endl;
    cout<<"Giving this car an average of "<<mpg<<" miles per gallon.";


  return 0;
  }
