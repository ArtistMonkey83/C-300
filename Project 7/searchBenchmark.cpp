#include<fstream>
#include<string>
#include<iostream>

using namespace std;

const int SIZE = 40;


void yoliesProgramHeader();
void displayExplanation();
void readNamesToArray(string[SIZE]);
void nameValidation(string &);
void displayResults(int,int,int, string);
int linearSearch(string,string[SIZE]);
int binarySearch(string,string[SIZE],int );

void yoliesProgramFooter();


int main()
{
  int binaryCounter = 0, endOfArray = 0, count = 0;
  string namesDbase[SIZE];
  string userName;

  yoliesProgramHeader();
  displayExplanation();

  ifstream inputFile;
  inputFile.open("USERS//Desktop/names.txt");

  while (count < endOfArray && inputFile >> namesDbase[count])
  {
    endOfArray++;
    count ++;
  }

  inputFile.close();

  cout << "\n\n\tPlease enter a name to search for: ";
  getline(cin,userName);

  nameValidation(userName);

  displayResults(linearSearch(userName,namesDbase), binarySearch(userName,namesDbase, binaryCounter),binaryCounter, userName);

  yoliesProgramFooter();


  return 0;
}

void nameValidation(string &userName)
{
  for(int i = 0; i < ; i++)
  {userName[i]= toupper(userName[i]);}

}

void displayResults(int linear, int binary, int bCounter, string searchName)
{
  if (linear == -1)
  {cout << "\n\n\t********** Sorry This name was not found in the file **********\n";}
  else
  {
    cout << " \n\n\tUsing the linear search, the name " << searchName
         << " was found at subscript " << linear << " and it took "
         << linear +1 << " interations to find.\n";

    cout << "\n\n\tUsing the binary search, the name "<< searchName
         << " was found at subscript " << binary << " and it took "
         << bCounter << " interations to find.\n";


  }
}

int linearSearch(string searchName, string mainDbase[SIZE])
{
  bool found = false;
  int position = -1;
  int index = 0;

  while (index < SIZE && !found)
  {
    if(mainDbase[index] == searchName)
    {
      found = true;
      position = index;
    }
    index++;
  }
  return position;
}

int binarySearch(string searchName, string mainDbase[SIZE], int binaryCounter)
{
  int first = 0,
  last = (SIZE - 1),
  midpoint = (first + last) / 2,
  position = -1;

  bool found = false;

  while(!found && first <= last)
  {
    if(mainDbase[midpoint] == searchName)
    {found = true; position = midpoint;}
    else if(mainDbase[midpoint] > searchName)
    {last = midpoint -1;}
    else
    {first = midpoint + 1;}
  }

  return position;
}
