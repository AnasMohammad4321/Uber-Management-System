#include "user.h"
#include"trip.h"
#include <iostream>
using namespace std;

user::user( string name, date date, string email, string number): user_name(name), date_of_birth(date), email_address(email), phone_number(number) 
{
	//repair this function
	current_ride = nullptr;
	count = 0;
	rating = 0;
}

//setters
void user::set_name(string n) {user_name = n;}
void user::set_phone_number (string cell) {phone_number = cell;}
void user::set_date_of_birth(date& DOB) { date_of_birth = DOB;}

//getters
float user::get_average_rating() { return rating; }
string user::get_name() { return user_name; }
date user::get_date_of_birth(){ return date_of_birth; }
string user::get_email() { return email_address; }
string user::get_phone_number() { return phone_number; }

void user::print()
{
	cout << user_name << endl;
	cout << date_of_birth << endl;
	cout << email_address << endl;
	cout << phone_number << endl;
}

void user::printTrips()
{
	for (int i = 0;i < count;i++)
	{
		cout << *rides[i] << endl;
	}
}
