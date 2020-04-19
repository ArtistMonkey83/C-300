/*
  _____ _
 / ____| |
| |    | | __ _ ___ ___
| |    | |/ _` / __/ __|
| |____| | (_| \__ \__ \
 \_____|_|\__,_|___/___/                           _        _   _
|_   _|               | |                         | |      | | (_)
  | |  _ __ ___  _ __ | | ___ _ __ ___   ___ _ __ | |_ __ _| |_ _  ___  _ __
  | | | '_ ` _ \| '_ \| |/ _ \ '_ ` _ \ / _ \ '_ \| __/ _` | __| |/ _ \| '_ \
 _| |_| | | | | | |_) | |  __/ | | | | |  __/ | | | || (_| | |_| | (_) | | | |
|_____|_| |_| |_| .__/|_|\___|_| |_| |_|\___|_| |_|\__\__,_|\__|_|\___/|_| |_|
|  ____(_) |    | |
| |__   _| | ___|_|
|  __| | | |/ _ \
| |    | | |  __/
|_|    |_|_|\___|
*/


#include<string>
#include<ctime>     //needed to use the time function
#include<cstdlib>   //needed to use the srand() and rand() functions
#include "Coin.h"   //needed to link the implentation file to the specification file


using namespace std; //namespace std to resolve std:: requirements

string sideUp;

Coin::Coin()
{
    unsigned tōtoltetl = time(0); //tōtoltetl is Nahuatl for egg
    srand(tōtoltetl);           // and is pronounced (tho-tho-the-tl)

    if(rand() % 2 != 0)       //random function seeded from the tōtoltetl 'egg' variable
    {sideUp = "cuaitl";}      //if the generated integer is even set sideup to 'head'

  else
    {sideUp = "kuitkotl";}    //else the integer is odd and sideUp is set to 'tail'

}

void Coin::Toss()
{
  if(rand() % 2 != 0)       //random function seeded from the tōtoltetl 'egg' variable
    {sideUp = "cuaitl";}      //if the generated integer is even set sideup to 'head'

  else
    if(rand()%2 ==0)
    {sideUp = "kuitkotl";}    //else the integer is odd and sideUp is set to 'tail'

}

string Coin::getSideUp()
{
  return sideUp;
}
