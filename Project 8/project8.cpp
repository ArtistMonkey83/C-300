/*keep track of the size of the list, and number of elements in list!!!

string *strPtr = new string[]

*(str + index) = userInput

and increment the number of elements, pass by reference so its reflected back into the main

this is like the midterm you have to insert and shift elements to the right
make sure you are inserting up to the num of elements

you could use just three functions that are slightly different to do all of the project

check the element is in a valid range

use getline() because you are dealing with strings



do
{
  printMenu();
  ask for user choice;

  call a function based on the user choice; // they return boolean values
  1 insert at end of list
  2 insert at 0
  3 insert at provided index
}while()

before you call your functions you should check of maxSize and numElements are the same because that means you need to expand your array. CHECK SIZE EXPAND IF NEEDED

numElements will hold the location of the very end of the ARRAY you must increment it when you add a value.

*(strPtr + numelements) = item; // item is string input passed to function
return true;


OPTION 2
you have to shift it forward one space after the first iteration

insertAt(strPtr, numElements, item) option 2
insertAt(strPtr, numElements, item, index) option 3 if they choose the zero



index can not be < 0 and cannot be greater then the list. return false



TO REMOVE FROM THE END

removeFromEnd(strPtr,numElems)

you have to decrement the num of elemnts and set the last element to an empty string " "

TO REMOVE FROM A PROVIDED INDEX

removeFrom(strPtr, numElems, index)

you have to start at the index and replace it with the value next to it and then set the last element in the string to an empty string. and decrease the numElements






Programming Project on Chapter 9

Pointers

1.

Dynamic String Array: dynamicString.cpp – 20 pts
*******
*****
****
***
**
*     PROJECT 8 go!
*
**
***
****
*****
******




For this project, use pointer notation rather than array notation rather than array notation. For example, use *(ptr + i) instead of ptr[i] where ptr is a pointer to a string.

The logic similar to what the vector C++ object uses.

In main, create a loop that asks for a user choice and prints the following menu:

Please choose from the following menu choices
1) Insert a new element to the end of the list.
2) Insert a new element at the beginning of the list.
3) Insert an element into the list at a given index.
4) Remove an element from the end of the list.
5) Remove an element from the list at a given index.
6) Sort the list.
7) Print the contents of the list.
8) Exit.
Implement each option in the menu.  Use the following function prototypes for your design:

void printMenu();
void printList(string *p, int size);
string *expand(string *p, int &size);
bool insertAtZero(string *p, string item, int count);
bool insertAt(string *p, string item, int index, int count);
bool insertAtEnd(string *p, string item, int count);
bool removeFromEnd(string *p, int count);
bool removeFrom(string *p, int index, int count);
void sort(string *p, int count);


Note, size is the current size of the dynamic array which may be empty, or (partially) filled; and count is the number of elements currently in the list. When the list is empty, count = 0. When the list is full, count = size; otherwise it is somewhere in between.

For your insertAt function (option 3 in the menu), make sure the index given is not greater than the count of integers currently in the list.  If the index is out of bounds, return false. Otherwise, return true and update the count of elements in the list.

For your removeFrom function, make sure the index is valid.  If the index is not valid, return false.  If the removal succeeds, return true and update the count of elements in the list.

For your sort function, you can use any sorting algorithm you like.  Be sure to use pointer notation rather than array notation for your algorithm.

You may combine insertAtZero, insertAtEnd and insertAt if you wish, since you could just pass an index of 0 (or index of numElems) into insertAt to accomplish the same task.

Use the example shown in class with the int array for hints. This code is posted on the Canvas Knowledge Building page for Module 09. Remember to expand the array when the size is equal to the count.

Make sure you use "new" to dynamically allocate your arrays.  If you allocate them on the stack by declaring them normally the addresses will not be valid when the functions return.

Note that expand() returns the pointer to the newly expanded array.  This means that expand should be called from main so the pointer to the array in main can be updated.

Don't forget to free up your dynamic pointers when the program completes to avoid memory leaks.*/

#include<iostream>
#include<string>


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
void yoliesProgramHeader();
void displayExplanation();


void printMenu();
void printList(string *p, int size);

string *expand(string *p, int &size);

bool insertAtZero(string *p, string item, int count);
bool insertAt(string *p, string item, int index, int count);
bool insertAtEnd(string *p, string item, int count);
bool removeFromEnd(string *p, int &count);
bool removeFrom(string *p, int index, int count);

void sort(string *p, int count);


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
  int choice = 0,
      elementsInArray = 0,
      index = 0,
      size = 3;

  string namesForPets[size], petName,
         *pNewString = nullptr;

  yoliesProgramHeader();
  displayExplanation();

  do
  {
    printMenu();
    cin >> choice;

    if(choice > 0 && choice < 4)
    {
      cout << "\n\n\tPlease enter a pet name to add to the list: ";
      getline(cin,petName);
    }

    if(elementsInArray == size)
    {pNewString = expand(namesForPets,size);}

    switch(choice)
    {
      case 1: if(insertAtEnd(namesForPets,petName,index,elementsInArray))
              {cout << "\n\n\tThe pet name " << petName << " was added at the end of the list.\n"; elementsInArray++; break;}

      case 2: if(inserAt(namesForPets,petName,index,elementsInArray))
              {cout << "\n\n\tThe pet name " << petName << " was added at the beginning of the list.\n"; elementsInArray++; break;}

      case 3: if(insertAt(namesForPets,petName,index,elementsInArray))
              {cout << "\n\n\tThe pet name " << petName << " was added at the subscript " << index << ".\n"; elementsInArray++; break;}

      case 4: if(!removeFromEnd(namesForPets,elementsInArray))
              {cout << "\n\n\tThe list is empty therefore you cannot remove!\n"; break;}
              else if(removeFromEnd(namesForPets,elementsInArray))

              {elementsInArray--; cout << "\n\n\tThe last name in the list was removed, there are now " << elementsInArray << " element(s) in the pet names list.\n";break;}

      case 5: while(!removeFrom(namesForPets,index,elementsInArray))
              {cout << "\n\n\tYou must enter a valid subscript, currently the subscripts range from 0 to " << elementsInArray << ".\n"
              cin >> index;}

              if(removeFrom(namesForPets,index,elementsInArray))
              {elementsInArray--; cout << "\n\n\tThe pet name located at subscript " << index << " was removed! There are now " << elementsInArray " element(s) in the pet names list.\n"; break;}

      case 6: sort(namesForPets,elementsInArray)
              cout << "\n\n\tThe list has been sorted!\n";
              break;

      case 7: cout << "\n\n\tThe list of pet names is: \n";
              printList(namesForPets,SIZE);
              break;

      case 8: cout << "\n\n\tYou have decided to quit the program Anej! Which is Nahuatl for Goodbye!\n"; break;

      default: cout << "\n\n**********Please enter a valid choice from 1-8 **********\n";
              cin >> choice;
    }



  }while(choice != 8 && elementsInArray < SIZE)

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

void sort(string namesForPets[], int elementsInArray)
{
  string *minVal;
  int minIndex;

  for(int i =0; i < (elementsInArray - 1); i++)
  {
    minVal = namesForPets[start];
    minIndex = i;

    for(int i2 = i + 1; i2 < elementsInArray; i2++)
    {
      if(*namesForPets[i2] < *minVal)
      {
        minVal = namesForPets[i2];
        minIndex = i2;
      }
    }

    namesForPets[minIndex] = namesForPets[i];
    namesForPets[i] = minVal;
  }

}

void printList(string namesForPets[], int elementsInArray)
{
  for(int i = 0; i <= elementsInArray; i++)
  {
    cout << "\n\n\t" << i + 1 << ".\t" << *(namesForPets + i) << endl;
  }
}


bool removeFrom(string namesForPets[], int index, int elementsInArray)
{
  for(int i = index; i <= namesForPets.length; i++)
  {
    *(namesForPets + index) = *(namesForPets + (index + 1);

    elementsInArray--;
  }
  return 1;
}


bool removeFromEnd(string namesForPets[], int elementsInArray)
{
  *(namesForPets + elementsInArray) = " ";
  return 1;
}


bool insertAt(string namesForPets[], string mainFunctChoice, int index, int elementsInArray)
{
  for(int i = index; i <= namesForPets.length ; i++)
  {
    *(namesForPets +(elementsInArray + 1)) = *(namesForPets + elementsInArray);

    elementsInArray--;
  }

  *(namesForPets + index) = mainFunctChoice;

  return 1;
}


bool insertAtEnd(string namesForPets[], string mainFunctChoice, int elementsInArray)
{
  *(namesForPets +(elementsInArray +1)) = mainFunctChoice;

  return 1;
}


bool insertAtZero(string namesForPets[], string mainFunctChoice, int elementsInArray)
{
  for(int index = 0; index <= namesForPets.length ; index ++)
  {
  *(namesForPets + 1) = *(namesForPets + elementsInArray);
  elementsInArray--;
  }
  *(namesForPets) = mainFunctChoice;

  return 1;
}


string *expand(string namesForPets[],int &size)
{
  string *temp = nullptr;
  int numElems = maxSize;

  maxSize *= 2;
  temp = new string[maxSize];

  for(int location = 0; location < index; location++)
  {*(temp + location) = *(namesForPets + location);}

  delete [] namesForPets;

  namesForPets = temp;
}


void printMenu()
{
  cout << "\n\n\n\tPlease choose from the following menu choices:\n";
  cout << "\t1) Insert a new pet name to the end of the list.\n";
  cout << "\t2) Insert a new pet name at the beginning of the list.\n";
  cout << "\t3) Insert a new pet name into the list at a given index.\n";
  cout << "\t4) Remove a pet name from the end of the list.\n";
  cout << "\t5) Remove a pet name from the list at a given index.\n";
  cout << "\t6) Sort the list.\n";
  cout << "\t7) Print the contents of the list.\n";
  cout << "\t8) Exit.\n";
}


void displayExplanation()
{
  cout << "\n\n\nThe purpose of this program is to test my ability to use pointers with an array of strings, \ndynamically allocate a new array if the current array is full, and edit an array using pointer notation.\nI decided to use pet names for my string input.\n";
}


void yoliesProgramHeader()
{
  cout << "\n\n********* YOLIE REYES *********\n";
  cout << "********** Project 8 **********\n";
  cout << "*********** 11-2-18 ***********\n";
  cout << "********** CISP 360 **********\n";
}


void yoliesProgramFooter()
{
  cout << "\n\n**************** End of Program ****************\n";
}
