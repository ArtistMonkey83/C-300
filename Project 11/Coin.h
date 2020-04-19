/*
  _____ _                  _____                   ______ _ _
 / ____| |                / ____|                 |  ____(_) |
| |    | | __ _ ___ ___  | (___  _ __   ___  ___  | |__   _| | ___
| |    | |/ _` / __/ __|  \___ \| '_ \ / _ \/ __| |  __| | | |/ _ \
| |____| | (_| \__ \__ \  ____) | |_) |  __/ (__  | |    | | |  __/
 \_____|_|\__,_|___/___/ |_____/| .__/ \___|\___| |_|    |_|_|\___|
                                | |
                                |_|
*/



#ifndef COIN_H //checking to see if the variable COIN_H is defined
#define COIN_H //the program will skip this file if COIN_H is defined
               //or define COIN_H if it doesnt already exist.


#include<string>  //header file for string class


using namespace std; //namespace std to resolve std:: requirements


class Coin      //Coin class declaration
{
  private:        //private  string attribute
    string sideUp;

  public:         //public behaviors
    Coin();       //default Constructor
    void Toss();    //Coin class mutator
    string getSideUp();//Coin class accessor
};

#endif //ending Coin class definition in the class specification file
