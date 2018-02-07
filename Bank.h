#pragma once
#include <iostream>
#include "ColaMachine.h"
#include <random>
#include <ctime>
#include <string>



using namespace std;

class Bank 
{
public:
	Bank();
	//Print out the bank
	void printBank();
	//ask for a loan
	void askLoan();
	//generate random money for bank
	int makeMoney();
	
	~Bank();
private:
	//value of loan and the amount the bank has
	int _loanValue;
	int _bankMoney;
};

