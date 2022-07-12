#include "date.h"
#include <time.h>
#include <ctime>
#include <iostream>
using namespace std;

//default constructor
date::date()
{
	time_t present = time(0);
	tm* ptm = new tm();
	localtime_s(ptm, &present);
	day = ptm->tm_mon;
	month = 1 + ptm->tm_mon;
	year = 1900 + ptm->tm_year;

}

//parameterized constructor
date::date(int d, int m, int y)
{
	if((d >= 1 && d <= 31) && (m >= 1 && m <= 12) && (y >= 1))
	{
		day = d;
		month = m;
		year = y;
	}
	else
		cout << "Invalid dates" << endl;
}
//copy constructor
date::date(const date& Date)
{
	if (this != &Date)
	{
		day = Date.day;
		month = Date.month;
		year = Date.year;
	}
}
//getter functions
int date::get_day() {return day;}
int date::get_month() {return month;}
int date::get_year() {return year;}

//setter functions
void date::set_day(int d) {day = d;}
void date::set_month(int m) {month = m;}
void date::set_year(int y) { year = y; }

void date::operator=(const date Date)
{
	if (this != &Date)
	{
		day = Date.day;
		month = Date.month;
		year = Date.year;
	}
	
}

ostream& operator << (ostream& osObject, date date)
{
	osObject << "Date: " << date.day << "-" << date.month << "-" << date.year; 
	return osObject;
}