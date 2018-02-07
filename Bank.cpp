#include "Bank.h"



Bank::Bank()
{
	//Set bankmoney equal to a random number!
	_bankMoney = makeMoney();

}
void Bank::printBank() {
	cout << string(100, '\n');
	cout << "	 ______________________________________\n";
	cout << "	/-----------------BANK-----------------\\" << endl;
	cout << "	|......___________.....................|\n";
	cout << "	|.....|BANK HAS:  |....................|\n";
	cout << "	|.....|$" << _bankMoney << "       |....................|\n";
	cout << "	|.....|           |....................|\n";
	cout << "	|......-----------.....................|\n";
	cout << "	|......................................|\n";
	cout << "	|......................................|\n";
	cout << "	|......................................|\n";
	cout << "	|......................................|\n";
	cout << "	|......................................|\n";
	cout << "	|......................................|\n";
	cout << "	|______________________________________|\n";

}


void Bank::askLoan() {
	//ColaMachine object
	ColaMachine cola;
	//How much the user wants to get
	
	bool loanGranted = false;

	cout << string(100, '\n');
	cout << "You do not have enough money!\n\n";
	cout << "Would you like to take a loan?\n\n(1)-Yes\n(2)-No\n\n\n";
	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		//Call a function that prints the bank and prompts user to enter how much they wish to borrow.!

		//Print the bank menu!

		printBank();
		while (loanGranted != true) {
			cout << "Enter the amount to lend: $";
			cin >> _loanValue;
			if (_loanValue < _bankMoney) {
				break;
			}
			else {
				cout << "You entered too much! Try again..." << endl;
			}
		}
		//

		//TAKE A LOAN CODE
		break;
	case 2:
		//User does not want to take a loan! Quit the game!
		break;
	default:
		cout << "Bad input! Please retry..." << endl;
	}

}

int Bank::makeMoney() {
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> money(20, 500);

	_bankMoney = money(randomEngine);
	return _bankMoney;

}


Bank::~Bank()
{
}
