#pragma once
#include <iostream>
#include <string>
using namespace std;

class payment{
	string payment_type;
	string card_no;
public:
	//parameterized constructor
	payment(string n = "", string m = "");
	payment(const payment&);

	//setters
	void set_paymentType(string);
	void set_cardNumber(string);
	
	//getters
	string get_paymentype();
	string get_cardNumber();

	void print();
};