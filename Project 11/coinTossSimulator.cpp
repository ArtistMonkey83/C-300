#include<iostream>
#include<string>
#include "Coin.h"
#include "Coin.cpp"

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
void yoliesProgramFooter();

void displayExplanation();

void displayResult();

/*
 __  __       _         ______                _   _
|  \/  |     (_)       |  ____|              | | (_)
| \  / | __ _ _ _ __   | |__ _   _ _ __   ___| |_ _  ___  _ __
| |\/| |/ _` | | '_ \  |  __| | | | '_ \ / __| __| |/ _ \| '_ \
| |  | | (_| | | | | | | |  | |_| | | | | (__| |_| | (_) | | | |
|_|  |_|\__,_|_|_| |_| |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|
*/

using namespace std;


int cuaitlCount = 0, kuitkotlCount = 0;   //global accumulator variable for heads/tails

int main()
{
  Coin tomīn;                   //tomīn is Nahuatl for coin/money
  int cuaitl = 0, kuitkotl = 0; //and is pronounced (tho-meen)
  char ch;           //char variable for pause

  yoliesProgramHeader();
  displayExplanation();
  cout << "\n\n\t\t*** Press [ENTER] to continue ***\n ";

  cin.get(ch);    //pausing till user input to continue

  cout << "\n\n ******* The tomīn (coin) is currently displaying the "
       << tomīn.getSideUp() << " side. ***********";

 for(int i = 0; i < 20; i++)            //for loop to toss 20 times
  {
    cout << "\n\n\t********** Toss " << i + 1 << " of 20 ********\n";
    tomīn.Toss();
    if(tomīn.getSideUp()== "cuaitl")            //using accessor function of class Coin
    {cout << "\t\tCuaitl (heads)";cuaitlCount++;}
    else
    if(tomīn.getSideUp() == "kuitkotl")         //using accessor function of class Coin
    {cout << "\t\tKuitkotl (tails)";kuitkotlCount++;}

  }

  displayResult();

  cout << "\n\n********************* Press [ENTER] to exit the program ***********************\n";

  cin.get(ch);      //pausing till user input to continue

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

void displayResult()
{
    cout << "\n\n************************** Results of the tomīn flips **************************\n";
    cout << "\n\t\tCuaitl (heads): " << cuaitlCount - 1 << endl;       //must subtract one to account for the initial addition of 1
    cout << "\t\tKuitkotl (tails): " << kuitkotlCount -1 << endl;    //when the variable tomīn was defined.
}

void displayExplanation()
{
  cout << "\n\n\nThe function of this program is to demonstrate my ability to define and use a \nclass.I have gathered the required class specification file as well as the class\nheader file. The class is a coin, known as tomīn in Nahuatl. The tomīn has a \ncuaitl side (head) as well a kuitkotl side (tails). The program will flip the \ntomīn 20 times and display the side that is showing. At the end of the program \nI will display the total number of times each side faced up.\n\n\n";
}


void yoliesProgramHeader()
{
  cout << "\n\n********************************* YOLIE REYES **********************************\n";
  cout << "********************************** Project 11 **********************************\n";
  cout << "*********************************** 12-7-18 ************************************\n";
  cout << "*********************************** CISP 360 ***********************************\n";
}


void yoliesProgramFooter()
{
  cout << "\t\t****** NAHUATL WORD OF THE DAY ******\n\n";
  cout << "\t\t\t*** Tlapōhuallōtl ***\n\n\n";
  cout << "English - Arithmetic: the branch of mathematics concerned with numerical calculations, such as addition, subtraction, multiplication, and division\n\n";
  cout << "Spanish - Aritmética: la rama de las matemáticas relacionada con los cálculos numéricos, como la suma, resta, multiplicación y división\n\n";
  cout << "German - Arithmetik: Der zweig der mathematik, der sich mit numerischen berechnungen befasst, wie addition, subtraktion, multiplikation und division\n\n";
  cout << "Russian - Aрифметика: ветвь математики, связанная с численными вычислениями, такая как сложение, вычитание, умножение и деление\n\n";
  cout << "French - Arithmétique: branche des mathématiques concernée par les calculs numériques, tels que l'addition, la soustraction, la multiplication et la division\n\n";
  cout << "\n******************************** End of Program ********************************\n\n\n";
}
