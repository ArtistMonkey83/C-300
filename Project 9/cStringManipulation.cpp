#include<iostream>
#include<cstring>



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

void backwardString (char *ptr);
int vowels(char *ptr);
int consonants(char *ptr);
void reverseString( char *ptr);
void yoliesProgramFooter();
void yoliesProgramHeader();
void displayExplanation();

using namespace std;


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
  int size = 11;
  char myArray[size];

  yoliesProgramHeader();
  displayExplanation();

  cout <<"\n\n\tPlease enter a string of ten characters or less: ";
  cin.getline(myArray,11);

  cout << "\n\n\tThe C-String entered by the user backward is: ";
  backwardString(myArray);

  cout << "\n\n\tThe number of vowels in the C-String entered by the user is: " << vowels(myArray) << endl;

  cout << "\n\n\tThe number of consonants in the C-String entered by the user is: " <<consonants(myArray) << endl;

  reverseString(myArray);

  cout << "\n\n\tThe C-String now reads: ";

  for (int i = 0; i < strlen(myArray); i++)
  {
    cout << *(myArray + i);
  }



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


void displayExplanation()
{
  cout << "\n\n\nThe purpose of this program is to test my ability to use C-strings, \nand manipulate the order of the elements after a user has entered a C-String.\n\n\n";
}


void yoliesProgramHeader()
{
  cout << "\n\n********* YOLIE REYES *********\n";
  cout << "********** Project 9 **********\n";
  cout << "*********** 11-18-18 ***********\n";
  cout << "********** CISP 360 **********\n";
}


void yoliesProgramFooter()
{
  cout << "\n\n\n**************** End of Program ****************\n\n\n\n";
}

void backwardString(char *mainFunctString)
{
  for (int i = strlen(mainFunctString); i >= 0; i--)
  {
    cout << *(mainFunctString + i);
  }
  cout << endl;
}

int vowels(char *mainFunctString)
{
  int vowels = 0;

  for (int i = 0; i < strlen(mainFunctString); i++)
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


int consonants(char *mainFunctString)
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
                    if(!isspace(*(mainFunctString + i)) && !ispunct(*(mainFunctString + i)) && isdigit(*(mainFunctString + i)) == 0)
                        {consonants +=1;}
                }
    }

    isVowel = false;

  }


  return consonants;
}

void reverseString( char *mainFunctString)
{
  char temp;
  int number = strlen(mainFunctString);

  for(int i = 0; i < number / 2 ; i++)
  {
    temp = *(mainFunctString + i);
    *(mainFunctString + i) = *(mainFunctString  + number - 1 - i);
   *(mainFunctString + number - 1 - i) = temp;
  }

  cout << "\n\n\tThe string has been reversed!\n";
}
