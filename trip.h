#pragma once
#include<iostream>
using namespace std;
class driver;
class passanger;
class date;

class trip {
private:
	string status;
	string pick_up;
	string drop_off;
	passanger* pass;
	driver* driv;
public:
	date* d;
	int driver_rating;
	int passanger_rating;
	trip();
	trip(const trip&);
	trip operator=(const trip&);
	void set_status(string);
	void rate_driver(int);
	void rate_passanger(int);
	void set_pickUp(string);
	void set_dropOff(string);
	void set_driver(driver*);
	void set_passanger(passanger*);
	void set_passenger_curride(trip*);
	string get_status();
	string get_pickUp();
	string get_dropOff();
	passanger& get_passanger();
	friend ostream& operator << (ostream& osObject, trip& other);
 };
