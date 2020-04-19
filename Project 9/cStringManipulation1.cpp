#include<iostream>
#include<cstring>
#include<string>

void backwardString (char *ptr, int );
int vowels(char *ptr, int );
int consonants(char *ptr, int );
void reverseString( char *ptr, int );
void yoliesProgramFooter();
void yoliesProgramHeader();
void displayExplanation();

using namespace std;

int main ()
{
  int size = 11;
  char myArray[size];

  yoliesProgramHeader();
  displayExplanation();

  cout <<"\n\n\tPlease enter a string of ten characters or less: ";
  cin.getline(myArray,11);

  cout << "\n\n\tThe C-String entered by the user backward is: ";
  backwardString(myArray,size);
  cout << endl;

  cout << "\n\n\tThe number of vowels in the C-String entered by the user is: " << vowels(myArray,size) << endl;

  cout << "\n\n\tThe number of consonants in the C-String entered by the user is: " <<consonants(myArray,size) << endl;

  reverseString(myArray,size);

  cout << "\n\n\tThe C-String now reads: ";

  for (int i = 0; i < strlen(myArray); i++)
  {
    cout << *(myArray + i);
  }



  yoliesProgramFooter();

  return 0;
}

void displayExplanation()
{
  cout << "\n\n\nThe purpose of this program is to test my ability to use C-strings, \nand manipulate the order of the elements after a user has entered a C-String.\n\n\n";
}


void yoliesProgramHeader()
{
  cout << "\n\n********* YOLIE REYES *********\n";
  cout << "********** Project 9 **********\n";
  cout << "*********** 11-13-18 ***********\n";
  cout << "********** CISP 360 **********\n";
}


void yoliesProgramFooter()
{
  cout << "\n\n\n**************** End of Program ****************\n\n\n\n";
}

void backwardString(char *mainFunctString, int sizeOfArray)
{
  for (int i = strlen(mainFunctString); i >= 0; i--)
  {
    cout << *(mainFunctString + i);
  }
  cout << endl;
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
  bool isVowel = false;

  for (int i = 0; i < strlen(mainFunctString); i++)
  {
    switch (*(mainFunctString + i))
    {
      case 65:
      case 97:
                isVowel = true;
                break;

      case 69:
      case 101: isVowel = true;
                break;

      case 73:
      case 105: isVowel = true;
                break;

      case 79:
      case 111: isVowel = true;
                break;

      case 85:
      case 117: isVowel = true;
                break;

      case 89:
      case 121: isVowel = true;
                break;

      default: if(!isVowel)
                {
                    if(!isspace(*(mainFunctString + i)) && !ispunct(*(mainFunctString + i)))
                        {consonants +=1;}
                }
    }

    isVowel = false;

  }


  return consonants;
}

void reverseString( char *mainFunctString, int sizeOfArray)
{
  char temp;
  int number = strlen(mainFunctString) - 1;

  for(int i = 0; i < number / 2 ; i++)
  {
    temp = *(mainFunctString + i);
    *(mainFunctString + i) = *(mainFunctString  + number - 1 - i);
   *(mainFunctString + number - 1 - i) = temp;
  }

  cout << "\n\n\tThe string has been reversed!\n";
}
