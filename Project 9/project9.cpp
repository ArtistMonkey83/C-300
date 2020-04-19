/*
Programming Project on Chapter 10: Characters, C-Strings and More on Strings
1.
C-Strings Manipulation: cStringManipulation.cpp – 20 pts
For this project, use pointers to character and pointer notation rather than array notation. For example, use *(ptr + i) instead of ptr[i] where ptr is a pointer to a char.

BackwardString: Write a function that accepts a pointer to a C-string as an argument and displays its contents backward. For instance, if the string argument is "Gravity in" the function should display "ni ytivarG". Call the function in your main that asks the user to input a string then passes it to the function. Note: This function does not make any changes to the original argument that you pass to the function.
Vowels: Write a function that accepts a pointer to a C-string as its argument. The function should count the number of vowels appearing in the string and return that number. Call the function from your main and pass the same string the user entered in a) and display the number of vowels in it. For example, if the string argument is "Gravity in", the function should return 3.
Consonants: Write a function that accepts a pointer to a C-string as its argument. This function should count the number of consonants appearing in the string and return that number. Call the function from your main and pass the same string the user entered in a) and display the number of vowels in it. For example, if the string argument is "Gravity in", the function should return 7.
ReverseString: Write a function that accepts a pointer to a C-string as its argument. This function should reverse the string argument. Call the function from main and pass the same string the user entered for a), then print the contents of the reversed string. Note: This function makes any changes to the original argument that you pass to the function.
*/

#include<iostream>
#include<cstring>
#include<string>

void backwardString (char *ptr, int size);
int vowels(char *ptr, int size);
int consonants(char *ptr, int size);
void reverseString( char *ptr, int size);

int main ()
{
  char myArray[size];
  int size = 11;

  cout <<"\n\n\tPlease enter a string of ten characters or less: ";
  cin.get(myArray);

  backwardString();
  cout << "\n\nThe number of vowels in the C-String " << myArray << " entered by the user is: " << vowels(myArray[],size) << endl;


  return 0;
}

void backwardString(char *mainFunctString, int sizeOfArray)
{
  for (int i = sizeOfArray; i >= 0; i--)
  {
    cout >> *(ptr + i)
  }
  cout >> endl;
}

int vowels(char *mainFunctString, int sizeOfArray)
{
  int vowels = 0;

  for (int i = 0; i < sizeOfArray; i++)
  {
    switch (*(mainFunctString + i))
    {
      case 65:
      case 97:  vowels +=1;
                break;
      case 69:
      case 101: vowels +=1;
                break;
      case 73:
      case 105: vowels +=1;
                break;
      case 79:
      case 111: vowels +=1;
                break;
      case 85:
      case 117: vowels +=1;
                break;
      case 89:
      case 121: vowels +=1;
                break;
    }
  }

  return vowels;
}


int consonants(char *mainFunctString, int sizeOfArray)
{
  int consonants = 0;

  for (int i = 0; i < sizeOfArray; i++)
  {
    switch (*(mainFunctString + i))
    {
      case 65:
      case 97:  break;

      case 69:
      case 101: break;

      case 73:
      case 105: break;

      case 79:
      case 111: break;

      case 85:
      case 117: break;

      case 89:
      case 121: break;

      default: if (isspace(*(mainFunctString + i)))
               break;
               else
               consonants +=1;
    }
  }

  return consonants;
}

void reverseString( char *mainFunctString, int sizeOfArray)
{
  string temp;
  int number = strlen(mainFunctString);

  for(int i = 0; i < number / 2 ; i++)
  {
    temp = *(mainFunctString + i);
    *(mainFunctString + i) = *(mainFunctString - i - number - 1);
    *(mainFunctString - i - number - 1) = temp;
  }

  cout << "\n\n\tThe string has been reversed!\n";
}
