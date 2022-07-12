 #include "payment.h"
#include <iostream>
#include <string>
using namespace std;

payment::payment(string number, string type): card_no(number), payment_type(type) {}

payment::payment(const payment& other)
{
	payment_type = other.payment_type;
	card_no = other.card_no;
}

//setters
void payment::set_cardNumber(string n) { card_no = n; }
void payment::set_paymentType(string t) { payment_type = t; }

//getters
string payment::get_cardNumber() { return card_no; }
string payment::get_paymentype() { return payment_type; }

void payment::print()
{
	cout << card_no << ", ";
	cout << payment_type << endl;
}

