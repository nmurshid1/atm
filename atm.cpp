#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

int UserSelection = -1;
int balance = 10000;
int PIN[1] = {1234};

/*void LoadingScreen()
{
	string loading = "Loading.........";
	for (int i = 0; i < 7; i++) {
		sleep(0.9f);
		cout << loading[i] << flush;
	}
	for (int i = 7; i < 14; i++) {
		sleep(1);
		cout << loading[i] << flush;
	}
	cout << "\n";	
}*/

void Authenticate()
{
	int auth;
	cout << "Please enter your PIN >> ";
	cin >> auth;
	if (auth != PIN[0]) {
		cout << "Wrong PIN entered!\n";
		Authenticate();
	} else {
		cout << "PIN Authenticated!\n";
	}
}

int UserSelect(int mode=0)
{
	switch (mode) {
		case 0: cout << ">> "; break;
		case 1: cout << ">> $"; break;
	}
	cin >> UserSelection;
	return UserSelection;
}

void MainMenu()
{
	cout << "1. Withdraw Money\n";
	cout << "2. Deposit Money\n";
	cout << "3. Balance Inquiry\n";
	cout << "4. Exit\n";
}

void SuccessfulTransaction(int mode)
{
	cout << "Transaction Successful!\n";
	if (mode == 1)
		cout << "New balance: $" << balance << "\n";
	if (mode == 2)
		cout << "New balance: $" << balance << "\n";
}

void FailedTransaction(int mode)
{
	cout << "Transaction failed!\n";
	if (mode == 1)
		cout << "Not enough balance available\n";
	if (mode == 2)
		cout << "Cannot deposit a value less than or equal to zero.\n";
}

bool WithdrawMoney(int withdrawal)
{
	if (balance - withdrawal >= 0) {
		balance -= withdrawal;
		return true;
	} else {
		return false;
	}
}

bool DepositMoney(int deposited)
{
	if (deposited > 0) {	 
		balance += deposited;
		return true;
	} else {
		return false;
	}
}

void BalanceInquiry()
{	
	//LoadingScreen();
	cout  << "Balance: $" << balance << "\n";
}

int main()
{
	Authenticate();
	while (true)
	{
		//LoadingScreen();
		MainMenu();
		UserSelect();
		switch (UserSelection)
		{
			case 1:	
				if (WithdrawMoney(UserSelect(1))) 
					SuccessfulTransaction(1);
				else
					FailedTransaction(1);
				break;
			case 2:	
				if (DepositMoney(UserSelect(1)))
					SuccessfulTransaction(2);
				else 
					FailedTransaction(2);
				break;
			case 3:	BalanceInquiry(); 	 		 break;
			case 4:	return 0;		     		 break;
			default: cout << "Wrong Input!\n";   break;
		}
	}
	return 0;
}
