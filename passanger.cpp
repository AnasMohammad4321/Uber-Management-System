#include "passanger.h"
#include "trip.h";
#include <iostream>
#include <string>
using namespace std;

passanger::passanger(string name, date dob, string mail, string number, payment p) :user(name, dob, mail, number)
{
	payment_method[0] = p;
}

//ostream& operator<<(ostream& osObject, passanger& p)}

ostream& operator<<(ostream& osObject, passanger& other)
{
	other.user::print();
	other.payment_method[0].print();
	cout << "Total trips = " << other.count << endl;
	if (other.current_ride != nullptr)
		osObject << other.current_ride->get_status() << endl;
	else
		osObject << "Currently not riding." << endl;
	return osObject;
}

void passanger::add_payment(payment& p)
{
	if (index == 3)
		cout << "Payment methods are full." << endl;
	else if (index < 3)
		payment_method[index++] = p;
}

void passanger::delete_payment(payment& p)
{
	for (int i = 0;i < 3;i++)
	{
		if (&p == &payment_method[i])
		{
			payment_method[i] = payment("","");
		}
	}
}

trip* passanger::bookRide(string x, string y)
{
	if (current_ride == nullptr)
	{
		current_ride = new trip; //okay
		current_ride->d = new date; // okay
		current_ride->set_status("Looking for driver"); // okay
		current_ride->set_pickUp(x); // okay
		current_ride->set_dropOff(y); // okay
		current_ride->set_passanger(this); //okay
		rides[count++] = current_ride;
		
		return current_ride;
	}
	cout << "Passenger cannot have two rides at once." << endl;
	return current_ride;
}

void passanger::cancelRide()
{
	if (current_ride != nullptr)
	{
		current_ride->set_status("cancelled");
		current_ride = nullptr;
	}
	else if (current_ride == nullptr)
		cout << "No current ride." << endl;
}

void passanger::rateDriver(trip* ptr, int a)
{
	if (ptr != nullptr && ptr->get_status() == "completed")
	{
		if (a > 0 && a < 6)
			ptr->driver_rating = a;
		else
			cout << "Rating between 1 to 5" << endl;
	}
	else
		cout << "Error in Rating." << endl;
}

float passanger::getAvgRating()
{
	int deno = 0;
	for (int i = 0;i < count;i++)
	{
		if (rides[i] != nullptr && rides[i]->get_status() != "cancelled")
		{
			rating += rides[i]->passanger_rating;
			deno++;
		}
	}
	rating = rating / deno;
	return rating;
}
