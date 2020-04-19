

#include<iostream>
#include<string>
#include<fstream>
#include<cctype>

using namespace std;

//Global Constants and Search Counters
const int SIZE = 40;
int LINEAR_COUNTER = 0, BINARY_COUNTER = 0;


/*
 ______                _   _               _____           _     _______
|  ____|              | | (_)             |  __ \         | |   |__   __|
| |__ _   _ _ __   ___| |_ _  ___  _ __   | |__) | __ ___ | |_ ___ | |_   _ _ __   ___  ___
|  __| | | | '_ \ / __| __| |/ _ \| '_ \  |  ___/ '__/ _ \| __/ _ \| | | | | '_ \ / _ \/ __|
| |  | |_| | | | | (__| |_| | (_) | | | | | |   | | | (_) | || (_) | | |_| | |_) |  __/\__ \
|_|   \__,_|_| |_|\___|\__|_|\___/|_| |_| |_|   |_|  \___/ \__\___/|_|\__, | .__/ \___||___/
                                                                      __/ | |
                                                                     |___/|_|
*/


void yoliesProgramHeader();
void displayExplanation();


int linearSearch(string mainFunctInput, string[SIZE]);
int binarySearch(string mainFunctInput, string[SIZE]);

void displayResults(int linear, int binary, string mainFunctInput);

void yoliesProgramFooter();


/*
 __  __       _         ______                _   _
|  \/  |     (_)       |  ____|              | | (_)
| \  / | __ _ _ _ __   | |__ _   _ _ __   ___| |_ _  ___  _ __
| |\/| |/ _` | | '_ \  |  __| | | | '_ \ / __| __| |/ _ \| '_ \
| |  | | (_| | | | | | | |  | |_| | | | | (__| |_| | (_) | | | |
|_|  |_|\__,_|_|_| |_| |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|
*/

int main ()
{

  string namesDbase[SIZE];
  string searchName;

  ifstream inputFile;
  inputFile.open("The/ Brain\\Users\\Yolanda\\Desktop\\names.txt");

  int counter = 0;

  while((inputFile >> namesDbase[counter])  &&  counter < SIZE)
  {counter++;}

  inputFile.close();

  //int linSearch, binSearch;

  yoliesProgramHeader();
  displayExplanation();


  cout << "\n\n\tPlease enter a name to search the database for: ";
  getline(cin,searchName);

  for(int index = 0; index < searchName.size(); index++)
    {searchName[index] = toupper(searchName[index]);}

  displayResults(linearSearch(searchName,namesDbase),binarySearch(searchName,namesDbase),searchName);

  yoliesProgramFooter();

  return 0;
}


/*
 ______                _   _
|  ____|              | | (_)
| |__ _   _ _ __   ___| |_ _  ___  _ __  ___
|  __| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
| |  | |_| | | | | (__| |_| | (_) | | | \__ \
|_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
*/
/*void ascendingSort(vector<double> prices,vector<string> ite)
{
  bool swap;
  int tempItem, tempPrice;

  do
  {
    swap = false;

    for(int count = 0; count < prices.size() - 1; count++)
    {
      if(prices[count] > prices[count + 1])
      {
        tempPrice = prices[count];
        prices[count] = prices[count + 1];
        prices[count + 1] = tempPrice;

        tempItem = item[count];
        item[count] = item[count + 1];
        item[count + 1] = tempItem;

        swap = true;
      }
    }

  }while(swap);
}
*/

int linearSearch(string mainFunctInput, string namesDbase[SIZE])
{
  int index = 0;
  int position = -1;
  bool found = false;

  while(index < SIZE && !found)
  {
    if(namesDbase[index] == mainFunctInput)
    {
      found = true;
      position = index;
    }
    index++;
    while(LINEAR_COUNTER <= SIZE)
    {LINEAR_COUNTER++;}
  }

  return position;
}

int binarySearch(string mainFunctInput, string mainFunctDbase[SIZE])
{
  int first = 0, last = SIZE - 1, middle, position = -1;
  bool found = false;

  while(!found && first <= last)
  {
    middle = (first + last) / 2;

    if(mainFunctDbase[middle] == mainFunctInput)
    {
      found = true;
      position = middle;
    }
    else if(mainFunctInput > mainFunctDbase[middle])
    {
      first = middle + 1;
    }
    else
      last = middle - 1;

    while(LINEAR_COUNTER <= SIZE)
      {LINEAR_COUNTER++;}

  }

  return position;
}

void displayResults(int linear, int binary, string mainFunctInput)
{
  if(linear == -1 && binary == -1)
  {cout << "\n\n\t****** Sorry this name was not found in the file ******\n";}
  else
  {
    cout << "\n\n\tUsing linear search the name "
         << mainFunctInput
         << " was found at subscript "
         << linear
         << " and it took "
         << LINEAR_COUNTER
         << " comparison(s) to find.\n";

    cout << "\n\n\tUsing binary search the name "
         << mainFunctInput
         << " was found at subscript "
         << binary
         << " and it took "
         << BINARY_COUNTER
         << " comparison(s) to find,\n";
  }
}

void yoliesProgramHeader()
{
  cout << "\n\n********* YOLIE REYES *********\n";
  cout << "********** Project 7 **********\n";
  cout << "********** Problem 1 **********\n";
  cout << "*********** 10-21-18 ***********\n";
  cout << "********** CISP 360 **********\n";
}

void yoliesProgramFooter()
{
  cout << "\n\n**************** End of Program ****************\n";
}

void displayExplanation()
{
  cout << "\n\n\nThe purpose of this program is to test my ability to open a file, and save its contents to an array.\nAfter I have read the names from the file to an array the program will ask you for a name to search the file/array for.\nIf the name is found the program will display the number of itterations performed by a binary and linear search algorithm as well as the subscript in which the name was found\n.";
}
