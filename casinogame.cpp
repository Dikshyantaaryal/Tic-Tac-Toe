#include<iostream>
#include<string>
#include<ctime>
#include<conio.h>
using namespace std;

void start() // initial set of rules 
{
  system("cls");
  cout << "\n\t\t Rules to be followed for the game.\n\n";
  cout << "Choose between 1-10 numbers." <<endl << endl;
  cout << "If you win you will get double the amount you'd bet." << endl << endl;
  cout << "If you loose you will lose all your betting amount." <<endl <<endl;
}

int gamefunction(int total, int bet, string name) //dice = rand()%10 + 1;
{
  int pnumber,rnumber;
  srand(time(0)); // seed the random generator
  if (total >= bet)
  {
    cout << "Hello, " << name <<endl;
    cout << "Please Choose a number between 1 and 10." <<endl;
    label1:
    cin >> pnumber;
    if (pnumber < 10 && pnumber > 0)
    {
      rnumber = rand()%10 + 1;
      cout << "The number was: " << rnumber << endl;
      if (pnumber == rnumber)
        return 1;
      else return -1;
    }
    else 
      {
         cout << "Invlalid number! Please enter number between 1 and 10." << endl;
         goto label1;
      }
  }
  else
    return 0;
}

int play_again()
{
  char x;
  cout << "Do you want to play again?(y/n) "<<endl;
  cin >> x;
  if (x == 'Y' || x == 'y')
    return 1;
  else return 0;
}


int main()
{
  string pname;
  int tamount, betamount, result, choice;
  start:
  system("cls");
  system("color F5");
  cout << "\n\t\t CASINO GAME \n\n\n" ;
  cout << "Please Enter your name: ";
  getline(cin, pname);
  cout << "Enter your total deposit amount: ";
  cin >> tamount;

  start();
  cout << "Enter any key to continue :-) " <<endl;
  cin.get();
  cin.clear();

  initial:
  if (tamount > 0)
  {
  cout << "Your total amount is: Nrs" << tamount <<endl;
  cout << "Enter your betting amount: ";
  cin >> betamount;

  result = gamefunction(tamount, betamount, pname);
  switch (result)
  {
    {
      case 1:
      cout << "CONGRATULATIONS YOU WON!" << endl;
      tamount += 2*betamount;
      choice = play_again();
      if ( choice == 1)
        goto initial;
      break;
    }
    {
      case -1:
      cout << "SORRY YOU LOSE! Better luck next time." <<endl;
      tamount -= betamount;
      choice = play_again();
      if (choice == 1 )
        goto initial;
      break;
    }
    {
      case 0:
      cout << "SORRY! But you don't have enough money! :-( "<<endl;
      choice = play_again();
      if (choice == 1 )
        goto initial;
      break;
    }
  }
}
else 
  {cout << "\n\n\nYou don't have money please bring some next time.";
cin.get();
cin.ignore();
    goto start;}
}
