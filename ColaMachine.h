#pragma once
#include <list>
#include <iostream>
#include <string>
#include <random>
#include "Bank.h"
using namespace std;

class ColaMachine
{
public:
	//Add money to _money
	void addMoney(int money);
	ColaMachine();
	//Print Vending machine function
	void printMachine();
	
	//Main game loop
	bool gameLoop();

	//Ask the user what drink they want
	void chooseDrink();

	//generate money
	void moneyMaker();

	//Vending machine with a cool //OUT OF STOCK// text
	void outOfStock(bool test);

	//Print user inventory
	void printInv();

	//Print the amount of money user has!
	void printMoney() { cout << "Your money: " << '$' << _money << '\n' << endl; }

	//Add to inventory
	void addInv(int drink);

	//Initialize the machine
	void init(int cola, int water, int sprite, int fanta, int beer);

	//Check if game has ended
	bool checkEnd();
	//Destructor
	~ColaMachine();
protected:
	int _money;
private:
	//Private values for machine
	bool _end;
	int _cola;
	int _water;
	int _sprite;
	int _fanta;
	int _beer;
	//Private player values. _p in front
	int _pcola;
	int _pwater;
	int _psprite;
	int _pfanta;
	int _pbeer;
};

