 #pragma once
#include <iostream>
#include <string>
#include "payment.h"
#include "user.h"
class trip;
using namespace std;

class passanger : public user
{
	payment payment_method[3];// card, cash
	int index = 0;
public:
	friend class trip;
	passanger(string, date, string, string, payment);
	void add_payment(payment&);
	void delete_payment(payment&);
	trip* bookRide(string, string);
	void cancelRide();
	void rateDriver(trip*, int);
	float getAvgRating();
	friend ostream& operator<<(ostream&, passanger&);
};
