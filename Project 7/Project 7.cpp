Programming Project on Chapter 8

Searching and Sorting

/*
1.

Search Benchmark: searchBenchmark.cpp





Write a program that reads a list of names stored in a file to an array and asks for the user to enter a name to locate in the array. The “names.txt”Preview the document is a txt file consisting of names in each line.

The program should call a function that uses the linear search algorithm to locate the search item. The function should keep a count of the number of comparisons it makes until it finds the value or reaches the end of the array.
The program then should call a function that uses the binary search algorithm to locate the same value. It should also keep count of the number of comparisons it makes.
Display these values on the screen.
Hint: Don't forget to use getline() to read the names both from the file and from the standard input device. You can use toupper() or tolower() functions to make the string comparisons.
*/


#include<iostream>
#include<string>

using namespace std;

//Global Constants and Search Counters
const int SIZE = 40, LINEAR_COUNTER = 0, BINARY_COUNTER = 0;


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

void readNamesToArray(string[SIZE]);
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
  string userName = " ";
  string namesDbase[SIZE];

  //int linSearch, binSearch;

  yoliesProgramHeader();
  displayExplanation();

  readNamesToArray(namesDbase);

  cout << "\n\n\tPlease enter a name to search the database for: ";
  getline(cin,userName);

  displayResults(linearSearch(userName,namesDbase),binarySearch(userName,namesDbase));

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

void readNamesToArray(string names[SIZE])
{
  #include<fstream>

  ifstream inputFile;
  inputFile.open("The/ Brain\\Users\\Yolanda\\Desktop\\names.txt")

  int counter = 0;

  while(count < SIZE && inputFile >> names[count])
  {count++;}

  inputFile.close();
}

int linearSearch(string mainFunctInput, string [SIZE])
{
  int index = 0;
  int position = -1;
  bool found = false;

  while(index < SIZE && !found)
  {
    if(string[index] == mainFunctInput)
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

/*
2.

Selection Sort on Parallel Vectors (12 pts) – selectionSortParallelVectors.cpp



Suppose you went grocery shopping and you have a list of items that you purchased. You also have another list that holds the prices of the items you purchased.

vector<string> items {"pen", "paper", "milk", "cupcakes", "carrots", "salmon", "ice-cream", "butter", "sugar", "eggs"};

vector<double> prices {6.49, 11.99, 3.19, 5.99, 1.49, 19.67, 4.59, 4.99, 3.49, 1.99};
The two vectors are parallel, that is, their positions are related to each other. For example, price of “milk” is 3.19 (subscript 2 of each vector).

Modify the Selection Sort algorithm to sort the items vector alphabetically and sort the prices vector along with it so the corresponding entries are still matching. This means that you are sorting and comparing the string vector alphabetically and mirroring the swap operations in the prices vector rather than just sorting them independently.  For example, 3.19 corresponds to the price of "milk".  So, if "milk" gets moved to a different position of the string vector, 3.19 should also get moved to the same position in its own vector. Read the program 8-7 on page 495 for a reference on how to sort vectors and 8-6 on page 491 for a reference on sorting parallel arrays.

When your program starts, call a function to show the two unsorted vectors.  Call your parallel sorting function to sort the vectors. Then call your function to show the sorted vectors.

Add another parallel sort function to sort the vectors so that the prices vector is in ascending order. Call your new sorting function to sort the vectors. Then call your function to show the sorted vectors.
*/

/*
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int binarySearch(vector<int>, int);
void display(int, string, double);

int main ()
{
  vector<int> id{122,144,233,339,689}

  vector<string> names {}


  bool found = false;





  return 0;

}

int binarySearch
*/



#include<string>
#include<iostream>
#include<vector>

using namespace std;

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

void display(vector<double> prices,vector<string> items)

void ascendingSort(vector<double> prices,vector<string> items)
void alphabeticSort(vector<string> item,vector<double> price)



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
  vector<double> prices{6.49,11.99,3.19,5.99,1.49,19.67,4.59,4.99,3.49,3.99};
  vector<string> items{"pen", "paper", "milk", "cupcakes", "carrots", "salmon", "ice-cream", "butter", "sugar", "eggs"};

  yoliesProgramHeader();
  displayExplanation();
  cin.get();

  display(prices,items);

  accendingSort(prices,items);
  display(prices,items);

  alphabeticalSort(items,prices);
  display(prices,items);

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

void display(vector<double> prices,vector<string> items)
{
  for(int i =0; i < prices.size(); i++)
  {
    cout << items[i]
         <<": $"
         << prices[i];
  }
  cout << endl;
}

void ascendingSort(vector<double> prices,vector<string> items)
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

void alphabeticSort(vector<string> item,vector<double> price)
{
  bool swap;
  int tempItem, tempPrice;

  do
  {
    swap = false;
    for(int count = 0; count < string.size() - 1; count++)
    {
      if(item[count]< item[count+1])
      {
        tempItem = item[count];
        item[count] = item[count + 1];
        item[count + 1] = tempItem;

        tempPrice = price[count];
        price[count] = price[count + 1];
        prices[count + 1] = tempPrice;

        swap = true;
      }
    }
  } while(swap);
}



void yoliesProgramHeader()
{
  cout << "\n\n********* YOLIE REYES *********\n";
  cout << "********** Project 7 **********\n";
  cout << "********** Problem 2 **********\n";
  cout << "*********** 10-22-18 ***********\n";
  cout << "********** CISP 360 **********\n";
}

void yoliesProgramFooter()
{
  cout << "\n\n**************** End of Program ****************\n";
}

void displayExplanation()
{
  cout << "\n\n\nThe purpose of this program is to test my ability to search and sort vectors. In this program there are two vectors, one storing the prices of items purchased, and one to store the name of the item. This program will display the unsorted vectors, and then sort them in ascending order by price and display the vectors. Then the program will sort the items alphabetically and display the results. Hit enter to continue.\n";
}
