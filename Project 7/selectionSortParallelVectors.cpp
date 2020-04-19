

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

void display(vector<double> prices,vector<string> items);

void ascendingSort(vector<double> &prices,vector<string> &items);
void alphabeticSort(vector<string> &item,vector<double> &price);

void yoliesProgramHeader();
void yoliesProgramFooter();
void displayExplanation();

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

  ascendingSort(prices,items);
  display(prices,items);

  alphabeticSort(items,prices);
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

void ascendingSort(vector<double> &prices,vector<string> &items)
{
  bool swap;
  double tempPrice;
  string tempItem;

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

        tempItem = items[count];
        items[count] = items[count + 1];
        items[count + 1] = tempItem;

        swap = true;
      }
    }

  }while(swap);
}

void alphabeticSort(vector<string> &items,vector<double> &prices)
{
  bool swap;
  double tempPrice;
  string tempItem;

  do
  {
    swap = false;
    for(int count = 0; count < items.size() - 1; count++)
    {
      if(items[count]< items[count+1])
      {
        tempItem = items[count];
        items[count] = items[count + 1];
        items[count + 1] = tempItem;

        tempPrice = prices[count];
        prices[count] = prices[count + 1];
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
