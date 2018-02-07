#include <iostream>
#include <string>
#include <fstream>
#include "ColaMachine.h"
#include <random>
#include "Bank.h"
#include <ctime>
using namespace std;


int main() {
	//Random num generator for the drinks!
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> beverage(1, 9);

	//ColaMachine Object
	ColaMachine cola;
	//Bank Object
	Bank bank;
	//Initialize colamachine
	cola.init(beverage(randomEngine), beverage(randomEngine), beverage(randomEngine), beverage(randomEngine), beverage(randomEngine));


	//MAIN GAME LOOP
	cola.gameLoop();

	//100 new lines
	cout << string(100, '\n');

	cout << "Thank you for playing!" << endl;
	cola.outOfStock(true);
	string a;
	cin >> a;

}