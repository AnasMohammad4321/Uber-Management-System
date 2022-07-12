 #include "trip.h"
#include "passanger.h"
#include "driver.h"
#include "date.h"
#include <iostream>
#include <string>
using namespace std;

trip::trip():status("leisure"),pick_up(""),drop_off(""),pass(0),driv(0)
{

}

//copy constructor
trip::trip(const trip& t) 
{
	status = t.status;
	driv = t.driv;
	pass = t.pass;
	d = t.d;
	pick_up = t.pick_up;
	drop_off = t.drop_off;
	driver_rating = t.driver_rating;
	passanger_rating = t.passanger_rating;
}
//overloaded assignmnet operator
trip trip::operator=(const trip& t)
{
	status = t.status;
	driv = t.driv;
	pass = t.pass;
	d = t.d;
	pick_up = t.pick_up;
	drop_off = t.drop_off;
	driver_rating = t.driver_rating;
	passanger_rating = t.passanger_rating;
	return t;
}

void trip::set_status(string a) { status = a; }
void trip::rate_driver(int d)
{ if(d<=5 && d>=1)
	driver_rating = d;
}
void trip::rate_passanger(int p)
{ if(p <= 5 && p>=1)
	passanger_rating = p;
}
void trip::set_pickUp(string p)
{ pick_up = p; }
void trip::set_dropOff(string d) { drop_off = d; }
void trip::set_driver(driver* d) { driv = d; }
void trip::set_passanger(passanger* p) { pass = p; }

void trip::set_passenger_curride(trip* ptr)
{
	pass->current_ride = ptr;
}

string trip::get_status() { return status; }
string trip::get_pickUp() { return pick_up; }
string trip::get_dropOff() { return drop_off; }
passanger& trip::get_passanger() { return *pass; }

ostream& operator<<(ostream& osObject, trip& other)
{
	osObject << "Status: " << other.get_status() << endl;
	osObject << "Date: " << *other.d << endl;
	osObject << "Pick up location: " << other.get_pickUp() << endl;
	osObject << "Drop off location: " << other.get_dropOff() << endl;
	if (other.driv != nullptr)
	{
		osObject << "Driver Name: " << other.driv->get_name() << endl;
		osObject << "Driver's Rating: " << other.driver_rating << endl;
		
	}
	if (other.pass != nullptr)
	{
		osObject << "Passenger name: " << other.pass->get_name() << endl;
		osObject << "Passenger's Rating: " << other.passanger_rating << endl;
	}
	return osObject;
}
