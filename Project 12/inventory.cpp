#include<fstream>
#include<iostream>
#include<cstring>

/*
  _____ _       _           _
 / ____| |     | |         | |
| |  __| | ___ | |__   __ _| |
| | |_ | |/ _ \| '_ \ / _` | |
| |__| | | (_) | |_) | (_| | |
 \_____|_|\___/|_.__/ \__,_|_|        _
 / ____|              | |            | |
| |     ___  _ __  ___| |_ __ _ _ __ | |_ ___
| |    / _ \| '_ \/ __| __/ _` | '_ \| __/ __|
| |___| (_) | | | \__ \ || (_| | | | | |_\__ \
 \_____\___/|_| |_|___/\__\__,_|_| |_|\__|___/
*/
const int SIZE = 21,
          COUNTER = 0,
          IDSIZE = 7;

/*
  _____ _                   _
 / ____| |                 | |
| (___ | |_ _ __ _   _  ___| |_ _   _ _ __ ___  ___
 \___ \| __| '__| | | |/ __| __| | | | '__/ _ \/ __|
 ____) | |_| |  | |_| | (__| |_| |_| | | |  __/\__ \
|_____/ \__|_|   \__,_|\___|\__|\__,_|_|  \___||___/


*/

struct Product
{
    char description[SIZE];
    char productId[IDSIZE];
    int onHand;
    double wholeCost;
    double retailCost;

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
using namespace std;

void yoliesProgramHeader();
void yoliesProgramFooter();

void displayExplanation();
void displayMenu();

int inputValidation(int);
double inputValidation(double);

int searchRecord(fstream &, char *);
void changeRecord(fstream &, char *);

/*
 __  __       _         ______                _   _
|  \/  |     (_)       |  ____|              | | (_)
| \  / | __ _ _ _ __   | |__ _   _ _ __   ___| |_ _  ___  _ __
| |\/| |/ _` | | '_ \  |  __| | | | '_ \ / __| __| |/ _ \| '_ \
| |  | | (_| | | | | | | |  | |_| | | | | (__| |_| | (_) | | | |
|_|  |_|\__,_|_|_| |_| |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|
*/



int main()
{
  int choice;
  char again,
       userInput[SIZE];


  yoliesProgramHeader();
  displayExplanation();

  Product myInventory;  //declaring a structure of the Product type called myInventory to hold data enter by user
  fstream myFile;       //declaring an fstream object called myFile, which will access the productList file
  myFile.open("The Brain/Users/Yolanda/Desktop/productList.txt", ios::in | ios::out | ios::binary);  //linking the myFile fstream object to the productList.txt file
                  //and opening that file in input/output binary mode
  do
  {
    displayMenu();
    cin >> choice;    //getting user menu choice
    choice = inputValidation(choice);   //validating user menu choice

    switch (choice)     //switch statement to handle user menu selection
    {
        case 1: cout << "\n\n\tPlease enter an item description up to 20 characters: ";
                cin.getline(myInventory.description,SIZE);
                cout << "\n\n\tPlease enter a 6 character product id: ";
                cout << "\n\n\tPlease enter a 6 character product id: ";
                cin.getline(myInventory.productId,SIZE);
                cout << "\n\n\tPlease enter the on hand quantity of product ID "
                     << myInventory.productId; << ": ";
                cin  >> myInventory.onHand;
                cout << "\n\n\tPlease enter the wholesale cost of product ID "
                     << myInventory.productId; << ": ";
                cin  >> myInventory.wholeCost;
                cout << "\n\n\tPlease enter the retail cost of product ID "
                     << myInventory.productId; << ": ";
                cin  >> myInventory.retailCost;
                break;  //breaking out of case 1 adding a record to the file
        case 2: cout << "\n\n\tPlease enter a six character product ID to search the file for:";
                cin.getline(myInventory.productId,SIZE);
                if((searchRecord(&myFile,userInput[SIZE]) )== -1) //calling function to search a record in the file
                {
                    cout << "\n\n\tThe search did not find the product " <<
                    for (int i = 0; i < SIZE -1;i++)
                        {cout << *(userInput+i).productId;}
                    cout << endl;
                }
                break;
        case 3: cout << "\n\n\tPlease enter a six character product ID to search the file for:";
                cin.getline(myInventory.productId,SIZE);
                changeRecord(&myFile,userInput[SIZE]); //calling function to change a record in the file
                break;
        case 4: return 0; //quitting program
    }

    cout << "\n\tWould you like to see the menu again ('Y' or 'y') anything else will quit the program: ";
    cin  >> again;


  }while((choice != 4) && (again == 'y' || again == 'Y'));    //do - while: choice isn't quit and again is equal to Yes

  myFile.close();
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

void changeRecord(fstream &fp, char *searchId)
{
  Product myInventory;

  fp.seekp(*sizeof(Product), ios::beg);

  cout << "Enter product ID: ";
  cin  >> myInventory.productId;
  fp.write(reinterpret_cast<char *>(&myInventory), sizeof(Product));
}


int searchRecord(fstream &fp, char *searchId)
{
  Product inventoryRec;
  bool found = false;
  int recNum = 0;

  fp.read(reinterpret_cast<char *>(&inventoryRec), sizeof(inventoryRec));

  while(!fp.eof() && !found)
  {
      recNum++;
      if(strcmp(inventoryRec.productId, searchId) == 0)
      {
          found = true;
          cout << "Description: " << inventoryRec.description << endl;
          cout << "Id: " << inventoryRec.productId << endl;
          cout << "On Hand: " << inventoryRec.onHand << endl;
          cout << "Wholesale Cost: " << inventoryRec.wholeCost << endl;
          cout << "Retail Cost: " << inventoryRec.retailCost << endl;
      }
      fp.read(reinterpret_cast<char *>(&inventoryRec), sizeof(inventoryRec));

  }
  if(found)
      return recNum;
  else
      return -1;
}


double inputValidation(double mainFunctInput)
{
  while(mainFunctInput < 0.0)
  {
    cout << "\n\tPLEASE ENTER A VALID POSITIVE INTEGER: ";
    cin  >> mainFunctInput;

  }

  return mainFunctInput;
}


int inputValidation(int mainFunctInput)
{
  while(mainFunctInput < 1 || mainFunctInput > 4)
  {
    cout << "\n\tPLEASE ENTER A VALID MENU CHOICE 1-4: ";
    cin  >> mainFunctInput;
  }

  return mainFunctInput;
}


void displayMenu()
{
  cout << "\n\t ****   ****   ****   ***** Please make a selection *****   ****   ****   ****  \n\n"
       << "\n\t      ***** 1. Add new records to the file *****\n"
       << "\n\t      ***** 2. Search product ID and display the record *****\n"
       << "\n\t      ***** 3. Change a record in the file *****\n"
       << "\n\t      ***** 4. Quit *****\n";
}


void displayExplanation()
{
  cout << "\n\n\nThe purpose of this program is to test my ability to create and manipulate \nstructures. I will also be demonstrating to you my ability to create, append \nand close a file. We will be entering information on products, the id number, \nwholesale and retail cost as well as description will need to be entered by the \nuser.\n\n\n";
}


void yoliesProgramHeader()
{
  cout << "\n\n********************************* YOLIE REYES **********************************\n";
  cout << "********************************** Project 12 **********************************\n";
  cout << "*********************************** 12-20-18 ***********************************\n";
  cout << "*********************************** CISP 360 ***********************************\n";
}


void yoliesProgramFooter()
{
  cout << "\t\t****** NAHUATL WORD OF THE DAY ******\n\n";
  cout << "\t\t****** Huitzilin (weet-see-leen) ******\n\n\n";
  cout << "English - Hummingbird: A small nectar-feeding tropical American bird that is able to hover and fly backward, typically having colorful iridescent plumage. In Nahuatl culture the goddess Xochiquetzal, patron of artists, is usually accompanied by hummingbirds.\n\n";
  cout << "Spanish - Colibrí: Un pequeño pájaro tropical que se alimenta de néctar y es capaz de flotar y volar hacia atrás, por lo general tiene un colorido plumaje iridiscente. En la cultura Náhuatl, la diosa Xochiquetzal, patrona de los artistas, suele ir acompañada de colibríes.\n\n";
  cout << "German - Kolibri: Ein kleiner amerikanischer Vogel, der Nektar füttert, der in der Lage ist, rückwärts zu schweben und zu fliegen, normalerweise mit einem bunt schillernden Gefieder. In Nahuatls Kultur wird die Göttin Xochiquetzal, Schutzpatronin der Künstler, in der Regel von Kolibris begleitet\n\n";
  cout << "Russian - Колибри: небольшая тропическая американская птица, питающаяся нектаром, способная парить и летать назад, обычно с ярким переливающимся оперением. В науатльской культуре богиня Шочикецаль, покровитель художников, обычно сопровождается колибри\n\n";
  cout << "French - Le colibri: Est un petit oiseau américain tropical qui se nourrit de nectar et qui est capable de planer et de voler en arrière, avec un plumage coloré et irisé. Dans la culture Nahuatl, la déesse Xochiquetzal, patronne des artistes, est généralement accompagnée de colibris\n\n";
  cout << "\n******************************** End of Program ********************************\n\n\n";
}
