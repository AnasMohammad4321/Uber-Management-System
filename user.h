#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "date.h" //owning and unidirectional relation
class trip;		 //non-owning and bidirectional relation

class user{
	string user_name;
	date date_of_birth;
	string email_address;
	string phone_number;
public:
	virtual float getAvgRating() = 0;
	float rating;
	int size = 20;
	trip** rides = new trip*[size];
	int count = 0;
	trip* current_ride;
	//constructors
	user(string, date, string, string);

	//setters
	void set_name(string);
	void set_date_of_birth(date&);
	void set_phone_number(string);
	float get_average_rating();

	//getters
	string get_name();
	date get_date_of_birth();
	string get_email();
	string get_phone_number();
	
	void print();
	void printTrips();
	
};