#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

double money;
double balance;
string rbInput;
double stake;
int win = 2;
int boardChance = rand() % 36 + 0;
int choice;

void CheckInput();

void DepoLoop()
{
	bool fail;

	do
	{
		cout << "DEPOSIT: ";
		cin >> money;

		fail = cin.fail();
		
		CheckInput();

		if (fail == true)
		{
			cout << "inavlid input! - Numeric Values Only!\n";
		}
	}
	while(fail == true);

	system("cls");
	balance += money;
	cout << "THANK YOU, YOUR BALANCE IS NOW: " << balance << endl;
}

void ChanceLoop()
{
	while (true)
	{
		int rbChance = rand() % 2 + 1;

		if (balance <= 0)
		{
			cout << "YOU ARE OUT OF MONEY!\n";
			DepoLoop();
		}

		cout << "Enter your stake (0 to quit): ";
		cin >> stake;

		while (stake > balance)
		{
			cout << "Stake is larger than your balance.\n";
			cout << "Please re-stake: ";
			cin >> stake;
		}

		if (stake == 0)
			break;

		balance -= stake;

		cout << "Red or Black? ";
		cin >> rbInput;

		while (rbInput != "red" && rbInput != "black")
		{
			cout << "input red or black input only!\n";
			cin >> rbInput;
		}

		if (rbChance == 1 && rbInput == "red")
		{
			cout << "RED! WELL DONE!" << endl;
			stake *= win;
			balance += stake;
		}

		else if (rbChance == 2 && rbInput == "black")
		{
			cout << "BLACK! WELL DONE!" << endl;
			stake *= win;
			balance += stake;
		}

		else
		{
			cout << "UNLUCKY!\n";
		}

		cout << "Your balance: " << balance << endl;
	}
}

void CheckInput()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
	srand(time(NULL));

	cout << "WELCOME TO ROULETTE!\n";
	cout << "PLEASE DEPOSIT SOME MONEY!\n";

	DepoLoop();
	ChanceLoop();

	cout << "\nTHANK YOU FOR PLAYING!\n";
	cout << "Your balance: " << balance << endl;

	cin.ignore(2);
}