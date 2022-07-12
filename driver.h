#pragma once
#include <iostream>
#include "user.h"
class trip;
using namespace std;

class driver: public user{
    string license_num;
	string vehicle_num;
public:
	driver(string, date, string, string, string, string);
    void pickARide(trip*);
	void endARide();
	float getAvgRating();
	void ratePassanger(trip*,int);
	friend ostream& operator <<(ostream&, driver&);
	friend class trip;
};