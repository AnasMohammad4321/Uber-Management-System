#pragma once
#include <iostream>
using namespace std;

class date{
	int day;
	int month;
	int year;
public:
	//constructors
	date();
	date(int d, int m, int y);
	date(const date& Date);
	
	//getters
	int get_day();
	int get_month();
	int get_year();

	//setters
	void set_day(int d);
	void set_month(int m);
	void set_year(int y);

	friend ostream& operator <<(ostream& osObject, date date);
	void operator=(const date);

	
};