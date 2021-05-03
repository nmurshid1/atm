#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

int UserSelection = -1;
int balance = 10000;

void LoadingScreen()
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

}

int UserSelect()
{
	cout << ">> ";
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

void WithdrawMoney(int withdrawal)
{
	if (balance - withdrawal >= 0) {
		LoadingScreen(); 	
		balance -= withdrawal;
		cout << "Transaction Successful!\n";
		cout << withdrawal << " dollars withdrawn.\n";
		cout << "New balance: $" << balance << "\n";
	} else {							
		cout << "Transaction failed!\n";
		cout << "Not enough balance available\n";
	}
}

void DepositMoney(int deposited)
{
	if (deposited > 0) {
		LoadingScreen(); 	 
		balance += deposited;
		cout << "Transaction Successful!\n";
		cout << deposited << " dollars deposited.\n";
		cout << "New balance: $" << balance << "\n";
	} else {
		cout << "Transaction failed!\n";
		cout << "Deposited amount is not greater than 0.\n";
	}

}

void BalanceInquiry()
{	
	LoadingScreen();
	cout  << "Balance: $" << balance << "\n";
}

int main()
{
	while (true)
	{
		LoadingScreen();
		MainMenu();
		UserSelect();
		switch (UserSelection)
		{
			case 1:	WithdrawMoney(UserSelect()); break;
			case 2:	DepositMoney(UserSelect());  break;
			case 3:	BalanceInquiry(); 	     break;
			case 4:	return 0;		     break;
			default: cout << "Wrong Input!";     break;
		}
	}
	return 0;
}
