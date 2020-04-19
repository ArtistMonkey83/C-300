#include<iostream>
#include<cctype>
#include<cstring>
#include<iomanip>

/*
  _____ _                   _
 / ____| |                 | |
| (___ | |_ _ __ _   _  ___| |_ _   _ _ __ ___  ___
 \___ \| __| '__| | | |/ __| __| | | | '__/ _ \/ __|
 ____) | |_| |  | |_| | (__| |_| |_| | | |  __/\__ \
|_____/ \__|_|   \__,_|\___|\__|\__,_|_|  \___||___/


*/

struct StudentData
{
  char Name[21];
  int IdNum;
  double *Tests,
         Average;
  char Grade;

};

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
int inputValidation(int);
double inputValidation(double);

void populateStructure(StudentData *, double *, int, int); //passing structure by reference to store data in the structure/test array
double populateAverage(double,int);

void displayDataBase(const StudentData *, int , int);

void yoliesProgramFooter();
void yoliesProgramHeader();
void displayExplanation();

/*
 __  __       _         ______                _   _
|  \/  |     (_)       |  ____|              | | (_)
| \  / | __ _ _ _ __   | |__ _   _ _ __   ___| |_ _  ___  _ __
| |\/| |/ _` | | '_ \  |  __| | | | '_ \ / __| __| |/ _ \| '_ \
| |  | | (_| | | | | | | |  | |_| | | | | (__| |_| | (_) | | | |
|_|  |_|\__,_|_|_| |_| |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|
*/

using namespace std;

int main()
{
  int numOfStudents = 0, numOfTests = 0;
  StudentData *stuDBase = nullptr;    //pointer to a structure of the tag type StudentData.
  double *ptrTests = nullptr;     //pointer to a double which will hold test scores
  char ch;

  yoliesProgramHeader();
  displayExplanation();

  cout << "\n\nEnter the number of students to compute grades for: ";
  cin >> numOfStudents;

  cin.ignore();

  while(!numOfStudents)
   {cout << "\nPlease enter a valid number of students no special characters: "; cin >> numOfTests; cin.ignore();}

  numOfStudents = inputValidation(numOfStudents);   //validaing user input of number of students to collect data on

  cout << "\n\nPlease enter the number of tests for each student: ";
  cin >> numOfTests;

  cin.ignore();   //ignoring the whitespace character left behind by enter.
  while(!numOfTests)
   {cout << "\nPlease enter a valid test score consisting of just numeral values: "; cin >> numOfTests; cin.ignore();}
    numOfTests = inputValidation(numOfTests);    //validating user input of number of tests

  stuDBase = new StudentData[numOfStudents];  //dynamically allocating space for structure array of StudentData tag type

  ptrTests = new double[numOfTests * numOfStudents];  //dynamically allocating space for test score array.

  populateStructure(stuDBase,ptrTests,numOfTests,numOfStudents); //calling function to populate StudentData Structure and test array.

  displayDataBase(stuDBase,numOfStudents, numOfTests); //calling function to display the final database

  delete [] ptrTests;     //deleting the memory for the test score array
  delete [] stuDBase;     //deleting the memory allocated for the structure array

  cout << "\n\n******************* Pressing [ENTER] will terminate program ********************\n\n";
  cin.get(ch);

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


//function for displaying the Student Data Structure database
void displayDataBase(const StudentData *arrayStruct, int mainFunctStu, int mainFunctTests)
{
  int countdown = mainFunctStu;
  cout << "\n\n************************ Student Data Base Information ************************\n\n";
  do
  {
    for(int i = 0; i < mainFunctStu; i++)
    {
      cout << setw(20) << left << "\nName" << setw(12) << left << "Id Number" << setw(20) << "Average Test Score" << setw(10) << "Course Grade" << endl;
      cout << setw(20) << (*(arrayStruct + i)).Name << setw(12) << (*(arrayStruct + i)).IdNum << setprecision(2) << fixed << setw(10) << right << (*(arrayStruct + i)).Average << setw(15) << right << (*(arrayStruct + i)).Grade << endl;

      /*cout << setw(20) << "Average Test Score" << setw(10) << "Course Grade" << endl;
      cout << setprecision(2) << fixed << setw(22) << (*(arrayStruct + i)).Average << setw(22) << (*(arrayStruct + i)).Grade << endl;
      */
      countdown--;
    }
  } while(countdown > 0);
}

//function for getting input to store in the Student Data structure array
void populateStructure(StudentData *arrayStruct, double *heapArrayTests, int mainFunctTests, int mainFunctStu)
{
  double testSum = 0.0;
  int testCounter = 1;

  for(int i = 0; i < mainFunctStu; i++)
  {
    cout << "\n\t\t*** Student " << i + 1 << " of " << mainFunctStu << " ***" << endl;
    cout << "\n\n\nPlease enter a student name up to 20 characters: ";
    cin.getline((*(arrayStruct + i)).Name, 21);
//assigning the Student name to the Name member of the Student Data structure

    cout << "\n\n\tPlease enter the 7 digit student ID number for " << (*(arrayStruct + i)).Name << ": ";
    cin  >> (*(arrayStruct + i)).IdNum;
//assigning the Student Id to the IdNum member of the Student Data structure


//validating input for just integer values
    while(!(*(arrayStruct + i)).IdNum)
    {
        cout << "\nPlease enter a valid ID number consisting of just numeral values: ";
        cin.clear();
        cin.ignore(100000,'\n');
        cin >> (*(arrayStruct + i)).IdNum;
    }

    cin.ignore();
//for loop to gather test scores for the
//student using user input of number of tests
    testSum = 0.0;


    for(int i2 = (mainFunctTests * i); i2 < (mainFunctTests *(i + 1)); i2++)
    {
      cout << "\n\n\tPlease enter the score for test " << testCounter << " of " << mainFunctTests << ": ";
      cin  >> *(heapArrayTests + i2);   //assigning the value for the test in the array on the heap

      while(!*(heapArrayTests + i2) )   //testing for invalid datatype
      {
          if(*(heapArrayTests + i2) == 0.0 ) //exluding the value of 0.0
          {break;}

          cout << "\nPlease enter a valid test score in the format 100.00 : ";
          cin.clear();
          cin.ignore(10000000,'\n');
          cin >>*(heapArrayTests + i2);
        }
//validating input for just integer values

      *(heapArrayTests + i2) = inputValidation(*(heapArrayTests + i2)); //input validation on test score

      testSum += *(heapArrayTests + i2);   //using double variable to sum tests

      testCounter++;
    }

    cin.ignore();

    (*(arrayStruct + i)).Average=(testSum / mainFunctTests);

    if((testSum / mainFunctTests)>= 90)
    {(*(arrayStruct + i)).Grade = 'A';}
    else
      if((testSum / mainFunctTests)>= 80)
      {(*(arrayStruct + i)).Grade = 'B';}
      else
        if((testSum / mainFunctTests)>= 70)
        {(*(arrayStruct + i)).Grade = 'C';}
        else
          if((testSum / mainFunctTests)>= 60)
          {(*(arrayStruct + i)).Grade = 'D';}
          else
          {(*(arrayStruct + i)).Grade = 'F';}

    testCounter = 1;
  }
}

//function for the validation of the test scores entered by the user
double inputValidation(double mainFunctInput)
{
  while( (mainFunctInput > 100.0 || mainFunctInput < 0.0) )
  {
    cout << "\n\n\tPlease enter a valid test score greater than 0 and less than 100: ";
    cin  >> mainFunctInput;
  }

  return mainFunctInput;
}

//function for validating user input of number of students and tests > 0
int inputValidation(int mainFunctInput)
{
  while(mainFunctInput < 0) //checking to see if the input is negative or not a digit
  {
    cout << "\n\n\tPlease enter a valid positive integer for us to continue: ";
    cin >> mainFunctInput;
  }

  return mainFunctInput;
}



void displayExplanation()
{
  cout << "\n\n\nThe purpose of this program is to test my ability to create and manipulate \nstructures. With input from you and my fancy computing skills we will calculate \nthe average test score and course grade for a user entered amount of students.\nLet's figure out how many students and tests we will be computing for.\n\n\n";
}


void yoliesProgramHeader()
{
  cout << "\n\n********************************* YOLIE REYES **********************************\n";
  cout << "********************************** Project 10 **********************************\n";
  cout << "*********************************** 11-29-18 ***********************************\n";
  cout << "*********************************** CISP 360 ***********************************\n";
}


void yoliesProgramFooter()
{
  cout << "\t\t****** NAHUATL WORD OF THE DAY ******\n\n";
  cout << "\t\t****** Chīuhpōhualhuaztiliztli ******\n\n\n";
  cout << "English - Computing: Activity requiring, benefitting from or creating computers.\n\n";
  cout << "Spanish - Informática: Ciencia que estudia métodos, procesos, técnicas,con el \nfin de almacenar, procesar y transmitir información y datos en \nformato digital.\n\n";
  cout << "German - Rechnen: Tätigkeiten, die auf Computern beziehungsweise \nalgorithmischen Prozessen aufbauen.\n\n";
  cout << "Russian - компьютинг: Деятельность, требующая, использующая или \nсоздающая компьютеры.\n\n";
  cout << "French - Technologies de l'information: Activité nécessitant, \nbénéficiant de, ou créant des ordinateurs.\n\n";
  cout << "\n******************************** End of Program ********************************\n\n\n";
}
