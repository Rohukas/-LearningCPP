#include "ColaMachine.h"
#include <ctime>



ColaMachine::ColaMachine()
{

}

void ColaMachine::init(int cola, int water, int sprite, int fanta, int beer) {
	//Initialize everything
	_pcola = 0;
	_pwater = 0;
	_psprite = 0;
	_pfanta = 0;
	_pbeer = 0;
	//Randomly generate the user money.
	moneyMaker();
	_cola = cola;
	_water = water;
	_sprite = sprite;
	_fanta = fanta;
	_beer = beer;
	//Game has just begun so true
	_end = false;
}
void ColaMachine::printInv() {
	//Print the current user inventory.
	cout << "You have: \n";
	cout << "Cola x" << _pcola << endl;
	cout << "Sprite x" << _psprite << endl;
	cout << "Fanta x" << _pfanta << endl;
	cout << "Water x" << _pwater << endl;
	cout << "Beer x" << _pbeer << endl;

}

ColaMachine::~ColaMachine()
{
	//Just in case. Might need it.
}

void ColaMachine::outOfStock(bool test) {
	//Printed if the store is out of stock!
	if (test == true) {
		cout << "	 ______________________________________\n";
		cout << "	/------------Vending Machine-----------\\" << endl;
		cout << "	|......................................|\n";
		cout << "	|..00...U..U..TTTTT......00....FFFF....|\n";
		cout << "	|.0..0..U..U....T.......0..0...F.......|\n";
		cout << "	|.0..0..U..U....T.......0..0...FFF.....|\n";
		cout << "	|..00....UU.....T........00....F.......|\n";
		cout << "	|................................._____|\n";
		cout << "	|..SSS..TTTTT..00...CCCC..K..K...|[]...|\n";
		cout << "	|..S......T...0..0..C.....K.K....|.123.|\n";
		cout << "	|..SSS....T...0..0..C.....KK.....|.456.|\n";
		cout << "	|....S....T...0..0..C.....K.K....|.789.|\n";
		cout << "	|..SSS....T....00...CCCC..K..K...|__0__|\n";
		cout << "	|______________________________________|\n";
	}

}

bool ColaMachine::gameLoop() {
	//Starts at false so the game begins
	bool isDone = false;

	while (isDone != true) {
		//Check if game has ended
		isDone = checkEnd();
		//print 15 new lines
		cout << string(15, '\n');
		//Prints the vending machine
		printMachine();
		//prints the amount of money you have
		printMoney();
		//Prints your inventory
		printInv();
		//asks you what drink you would like.
		chooseDrink();
	}
	return true;
}

void ColaMachine::printMachine() {
	//Print the machine
	cout << "	 ______________________________________\n";
	cout << "	/------------Vending Machine-----------\\" << endl;
	cout << "	|--1--------2-------3-------4-------5--|\n";
	cout << "	|.Coke...Sprite...Fanta...Water...Beer.|\n";
	cout << "	|..|" << _cola << "|.....|" << _sprite << "|.....|" << _fanta << "|.....|" << _water << "|....|" << _beer << "|..|\n";
	cout << "	|..$50....$100.....$50.....$20....$180.|\n";
	cout << "	|................................._____|\n";
	cout << "	|................................|[]...|\n";
	cout << "	|................................|.123.|\n";
	cout << "	|................................|.456.|\n";
	cout << "	|................................|.789.|\n";
	cout << "	|................................|__0__|\n";
	cout << "	|______________________________________|\n";
}
bool ColaMachine::checkEnd() {
	//If Everything is empty return true!
	if ((_cola <= 0) && (_sprite <= 0) && (_fanta <= 0) && (_water <= 0) && (_beer <= 0)) {
		return true;
	}

	return false;
}

void ColaMachine::addMoney(int money) {

	//This part doesnt seem to modify the actual value
	//Whenever It goes back to the main game loop it doesnt change.
	_money += money;


}


void ColaMachine::chooseDrink() {
	Bank bo;
	//Ask what drink you would like.
	int choice;
	cout << "What drink would you like?: ";
	cin >> choice;
	//Switch through the entire store and check if there is enough money and items to purchase.
	switch (choice) {
	case 1:
		if ((_cola != 0) && (_money >= 50)) {
			//remove one cola
			_cola--;
			//Take the money away
			_money -= 50;
			//Add cola to inventory
			addInv(1);
		}
		else if (_cola <= 0) {
			//If cola ran out.
			cout << "Out of Cola!" << endl;

			string a;
			cin >> a;
			break;
		}
		else {
			//If its here then the cola didnt run out! That means there is not enough money!
			cout << "Not enough money!" << endl;
			string a;
			cin >> a;
		}
		break;
	case 2:
		//Same as cola
		if ((_sprite != 0) && (_money >= 100)) {
			_sprite--;
			_money -= 100;
			addInv(2);
		}
		else if (_sprite <= 0) {
			cout << "Out of Sprite!" << endl;

			string a;
			cin >> a;
			break;
		}
		else {
			cout << "Not enough money!" << endl;
			bo.askLoan();
		}
		break;
	case 3:
		if ((_fanta != 0) && (_money >= 35)) {
			_fanta--;
			_money -= 50;
			addInv(3);
		}
		else if (_fanta <= 0) {
			cout << "Out of Fanta!" << endl;

			string a;
			cin >> a;
			break;
		}
		else {
			cout << "Not enough money!" << endl;
			bo.askLoan();
		}
		break;
	case 4:
		if ((_water != 0) && (_money >= 20)) {
			_water--;
			_money -= 20;
			addInv(4);
		}
		else if (_water == 0) {
			cout << "Out of water!" << endl;
			bo.askLoan();
			break;
		}
		else {
			cout << "Not enough money!" << endl;
			bo.askLoan();
		}
		break;
	case 5:
		if ((_beer != 0) && (_money >= 180)) {
			_beer--;
			_money -= 180;
			addInv(5);
		}
		else if (_beer <= 0) {
			cout << "Out of beer!" << endl;
			string a;
			cin >> a;
			break;
		}
		else {
			cout << "Not enough money!" << endl;
			bo.askLoan();
		}
		break;

	default:
		//If input was other than 1-5
		cout << "Bad input! Enter any key to continue: ";
		//Temporary pause
		string a;
		cin >> a;
	}	//Test if money is <20, if so prompt the user to take a loan.

	cout << '\n';


}
void ColaMachine::addInv(int drink) {
	/*Takes in a drink as a parameter.
	1-coca,
	2-sprite,
	3-fanta
	4-water
	5-beer
	*/
	switch (drink) {
	case 1:
		_pcola++;
		break;
	case 2:
		_psprite++;
		break;
	case 3:
		_pfanta++;
		break;
	case 4:
		_pwater++;
		break;
	case 5:
		_pbeer++;
		break;
	}

}

void ColaMachine::moneyMaker() {
	//Generate money between 100 and 2000
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> money(100, 2000);
	//Set user money equal to a random value.
	_money = money(randomEngine);

}


