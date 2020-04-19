/*

Programming Project on Chapter 11
Structured Data
1.

Course Grade: courseGrade.cpp – 20 pts





Write a program that uses a structure to store the following data:

Name: Student name

IdNum: Student ID number

Tests: Pointer to an array of test scores

Average: Average test score

Grade: Course grade

The program should keep a list of test scores for a group of students. It should ask the user how many students’ test scores it is going to keep track of and how many tests the students took. It should then dynamically allocate an array of structures. Each structure’s Tests member should point to a dynamically allocated array that will hold the test scores.

After the arrays have been dynamically allocated, the program should ask for the ID number and all the test scores for each student. The average test score should be calculated and stored in the average member of each structure. The course grade should be computed on the basis of the following grading scale:

Average Test Score

Grade

>= 90: A

>= 80 and < 90 : B

>= 70 and < 80 : C

>= 60 and < 70 : D

< 60 : F

The course grade should then be stored in the Grade member of each structure. Once all this data is calculated, a table should be displayed on the screen listing each student’s name, ID number, average test score, and course grade.

Input Validation: Be sure all the data for each student is entered. Do not accept negative numbers for any test score.

*/
#include<iostream>
#include<cctype>
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
int inputValidation(int);
double inputValidation(double);

void populateStructure(StudentData &, double *, int, int); //passing structure by reference to store data in the structure/test array

void displayDataBase(const StudentData &, int , int);

void yoliesProgramFooter();
void yoliesProgramHeader();
void displayExplanation();

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
  char Name[];
  int IdNum;
  double *Tests,
         Average;
  char Grade;

};



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
  double *ptrTests = nullptr, *ptrNextStu = nullptr;     //pointer to a double which will hold test scores

  yoliesProgramHeader();
  displayExplanation();

  cout << "\n\n\tPlease enter the number of students to compute average test score and course grade: ";
  cin >> numOfStudents;

  numOfStudents = inputValidation(numOfStudents);   //validaing user input of number of students to collect data on

  cin.ignore();   //ignoring the whitespace character left behind by enter.

  cout << "\n\n\tPlease enter the number of tests for each student: ";
  cin >> numOfTests;

  numOfTests = inputValidation(numOfTests);    //validating user input of number of tests

  stuDBase = new StudentData[numOfStudents];  //dynamically allocating space for structure array of StudentData tag type

  ptrTests = new double[numOfTests * numOfStudents];  //dynamically allocating space for test score array.

  populateStructure(stuDBase,ptrTests,numOfTests,numOfStudents); //calling function to populate StudentData Structure and test array.

  displayDataBase(stuDBase,numOfStudents, numOfTests); //calling function to display the final database



  delete [] ptrTests;     //deleting the memory for the test score array
  delete [] stuDBase;     //deleting the memory allocated for the structure array

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
void displayDataBase(const StudentData &arrayStruct, int mainFunctStu, int mainFunctTests)
{
  cout << "/n/n/tName /t/t/tId Number /t/t# of Tests /t/tAverage Test Grade /t/tCourse Grade" << endl;

  cout << "-------------------------------------------------------------------------------" << endl;

  for(int i = 0; i < mainFunctStu ; i++)
  {


    cout <<  *(arrayStruct + i).Name << "/t/t" << *(arrayStruct + i).IdNum << "/t/t" << mainFunctTests << "/t/t" << *(arrayStruct + i).Average << "/t/t" << *(arrayStruct + i ).Grade << endl;
  }
}


//function for getting input to store in the Student Data structure array
void populateStructure(StudentData &arrayStruct, double *heapArrayTests, int mainFunctTests, int mainFunctStu)
{

  for(int i = 0; i < mainFunctStu; i++)
  {
    cout << "\n\n\tPlease enter a student name up to 20 characters: ";
    cin.getline(*(arrayStruct + i).Name, 21);
//assigning the Student name to the Name member of the Student Data structure

    cout << "\n\n\tPlease enter " << *(arrayStruct + i).Name << "'s student ID number: ";
    cin  >> *(arrayStruct + i).IdNum;
//assigning the Student Id to the IdNum member of the Student Data structure


//for loop to gather test scores for the
//student using user input of number of tests

    for(int i2 = 0; i2 < mainFunctTests; i2++)
    {
      cout << "\n\n\tPlease enter the score for test " << i2+1 << " of " << mainFunctTests << ": ";
      cin  >> *(heapArrayTests + i2);   //assigning the value for the test in the array on the heap

      *(heapArrayTests + i2) = inputValidation(*(heapArrayTests + i2)); //input validation on test score

      *(heapArrayTests + i2).Average += *(heapArrayTests + i2);   //using the average member of the structure to sum tests
    }

    *(heapArrayTests + i2).Average %= mainFunctTests; //setting the average member of the structure to the correct average

//nested if else if statements to change
    if(*(heapArrayTests + i2).Average >= 90)
    {*(heapArrayTests + i2).Grade = 'A';}
    else if(*(heapArrayTests + i2).Average >= 80)
    {*(heapArrayTests + i2).Grade = 'B';}
    else if(*(heapArrayTests + i2).Average >= 70)
    {*(heapArrayTests + i2).Grade = 'C';}
    else if(*(heapArrayTests + i2).Average >= 60)
    {*(heapArrayTests + i2).Grade = 'D';}
    else
    {*(heapArrayTests + i2).Grade = 'F';}
  }
}


//function for the validation of the test scores entered by the user
double inputValidation(double mainFunctInput)
{
  while( mainFunctInput < 0 && isalpha(static_cast<char>(mainFunctInput)) == 0 && ispunct(static_cast<char>(mainFunctInput)) == 0)
  {
    cout << "\n\n\tPlease enter a valid test score greater than ZERO: ";
    cin  >> mainFunctInput;
  }
  return mainFunctInput;
}

//function for validating user input of number of students and tests > 0
int inputValidation(int mainFunctInput)
{
  while(mainFunctInput < 0 && isdigit(static_cast<char>(mainFunctInput)) == 0 ) //checking to see if the input is negative or not a digit
  {
    cout << "\n\n\tPlease enter a valid positive integer for us to continue: "
    cin >> mainFunctInput;
  }

  return mainFunctInput;
}



void displayExplanation()
{
  cout << "\n\n\nThe purpose of this program is to test my ability to create and manipulate structures.\nWith input from you and my fancy computing skills we will calculate the average test score and course grade for a user entered amount of students.\nFirst we need to figure out how many students and tests we will be computing for.\n\n\n";
}


void yoliesProgramHeader()
{
  cout << "\n\n******************* YOLIE REYES *******************\n";
  cout << "******************** Project 10 *******************\n";
  cout << "********************* 11-19-18 ********************\n";
  cout << "******************* CISP 360 ********************\n";
}


void yoliesProgramFooter()
{
  cout << "\n\n\n**************** End of Program ****************\n\n\n\n";
  cout << "\t*** NAHUATL WORD OF THE DAY ***\n\n";
  cout << "\t*** Chīuhpōhualhuaztiliztli ***\n\n\n";
  cout << "\t*** English - Computing: Activity requiring, benefitting from, or creating computers.\n\n";
  cout << "\t*** Spanish - Informática: Ciencia que estudia métodos, procesos, técnicas, con el fin de almacenar, procesar y transmitir información y datos en formato digital.\n\n";
  cout << "\t*** German - Rechnen: Tätigkeiten, die auf Computern beziehungsweise algorithmischen Prozessen aufbauen.\n\n";
  cout << "\t*** Russian - компьютинг: Деятельность, требующая, использующая или создающая компьютеры.\n\n";
  cout << "\t*** French - Technologies de l'information: Activité nécessitant, bénéficiant de, ou créant des ordinateurs.\n\n";
}
