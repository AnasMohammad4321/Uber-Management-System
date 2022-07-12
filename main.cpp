#include <iostream>
#include <memory>
#include <fstream>
#include "payment.h"
#include "driver.h"
#include "date.h"
#include "passanger.h"
#include "trip.h"
using namespace std;

const int SIZE = 20;
user** users = new user * [SIZE];
int counter = 0;

//an array of trips to keep pointers of all the trips of uber application
//This array will keep data of all the trips ever created. 
trip** uberTrips = new trip * [SIZE];
int n = 0;
void addToUsers(user* u)// function to add users
{
	if (counter < SIZE - 1 && u != nullptr)
	{
		users[counter++] = u;
	}
}
void printUsers() //function to print users
{
	for (int i = 0; i < counter; i++)
		users[i]->print();
}

void addToUberTrips(trip* t)// function to add new trips to uberTrips
{
	if (n < SIZE - 1 && t != nullptr)
	{
		uberTrips[n++] = t;
	}
}
void printUberTrips() //function to print uberTrips
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << *uberTrips[i] << endl;
	}
}
void readfromfile(string filename)
{
	ifstream infile;
	infile.open(filename);
	char* store = new char[50];
	string name, em, ph;
	int d, m, y;
	char usertype;
	while (!infile.eof())//till the file reaches the end
	{
		infile.getline(store, 50, ',');
		usertype = store[0];
		infile.getline(store, 50, ',');
		name = store;
		infile.getline(store, 50, '-');
		d = stoi(store); 
		infile.getline(store, 50, '-');
		m = stoi(store);
		infile.getline(store, 50, ',');
		y = stoi(store);
		infile.getline(store, 50, ',');
		em = store;
		infile.getline(store, 50, '\n');
		ph = store;
		if (usertype == 'p')
		{
			passanger* p = new passanger(name, date(d,m,y), em, ph, payment("", ""));
			addToUsers(p);
		}
		else if (usertype == 'd')
		{
			date Date(d,m,y);
			driver* d = new driver(name, Date, em, ph, "", "");
			addToUsers(d);
		}
	}
	infile.close();
}
user* HighestRatedUser()
{
	int large = 0;
	int index = 0;
	for (int i = 0; i < counter; i++)
	{
		if (users[i]->getAvgRating() > large)
		{
			large = users[i]->getAvgRating();
			index = i;
		}
	}
	return users[index];
}

user* HighestRatedDriver()
{
	float large = 0;
	int index = 0;
	driver* ptr;
	for (int i = 0; i < counter; i++)
	{
		ptr = dynamic_cast<driver*> (users[i]);
		if (ptr != nullptr)
		{
			if (users[i]->getAvgRating() > large)
			{
				large = users[i]->getAvgRating();
				index = i;
			}
		}
	}
	return users[index];
}

user* HighestRatedPassenger()
{
	float large = 0;
	int index = 0;
	passanger* ptr;
	for (int i = 0; i < counter; i++)
	{
		ptr = dynamic_cast<passanger*> (users[i]);
		if (ptr != nullptr)
		{
			if (users[i]->getAvgRating() > large)
			{
				large = users[i]->getAvgRating();
				index = i;
			}
		}
	}
	return users[index];
}
int main()
{

	passanger* p1 = new passanger("P1", date(10, 10, 1990), "ali@yahoo.com", "0334564334", payment("111-222-333-333", "card"));
	driver* d1 = new driver("D1", date(16, 1, 1990), "ayesha@yahoo.com", "0357757585", "Lin1197717", "VIN9817917");

	//////Test Case 1, user books, driver picks, driver ends (rating can be given only in this case)
	cout << *p1 << endl;
	cout << *d1 << endl;

	addToUberTrips(p1->bookRide("A", "B"));// will create a new trip and add it to uberTrips array
	cout << *uberTrips[n - 1];// will print this trip
	
	addToUberTrips(p1->bookRide("C", "D"));//prints error as p1 has already booked a ride
	d1->pickARide(uberTrips[n - 1]); //will assign  d1 to uberTrip[0], the status of this ride will also change to InProgress
	//system("pause");
	d1->ratePassanger(uberTrips[n - 1], 5); //error as the trip is not complete
	p1->rateDriver(uberTrips[n - 1], 4); //error as the trip is not complete

	cout << *p1 << endl;
	cout << *d1 << endl;

	d1->endARide(); //will change the status of uberTrip[0] to Complete

	d1->ratePassanger(uberTrips[n - 1], 5); //error as the trip is not complete
	p1->rateDriver(uberTrips[n - 1], 4); //error as the trip is not complete
	cout << *uberTrips[n - 1] << endl;
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->pickARide(uberTrips[n - 1]);//prints error as the ride is completed
	cout << "-------------------------------------" << endl;

	//////Test case 2: User books, driver picks, user cancels, ratings are not applicable to cancelled ride
	addToUberTrips(p1->bookRide("C", "D"));
	d1->pickARide(uberTrips[n - 1]);
	cout << *p1 << endl;
	cout << *d1 << endl;
	p1->cancelRide();
	p1->cancelRide();//error as there is no current ride
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->ratePassanger(uberTrips[n - 1], 5); //error as the ride was not complete
	p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete
	cout << "-------------------------------------" << endl;

	////Test Case 3: User Books, user Cancels, driver cannot pick this ride now, ratings are not applicable to this ride
	addToUberTrips(p1->bookRide("D", "E"));
	p1->cancelRide();
	d1->pickARide(uberTrips[n - 1]); //error as this ride is not looking for driver
	d1->ratePassanger(uberTrips[n - 1], 5); //error as the ride was not complete
	p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete
	cout << "-------------------------------------" << endl;

	////Test Case 4: getting avg ratings adn print trip funnction
	//Adding some more test data
	addToUberTrips(p1->bookRide("X", "Y"));
	d1->pickARide(uberTrips[n - 1]);
	d1->endARide();
	d1->ratePassanger(uberTrips[n - 1], 3);
	p1->rateDriver(uberTrips[n - 1], 5);

	addToUberTrips(p1->bookRide("X", "Y"));
	d1->pickARide(uberTrips[n - 1]);
	d1->endARide();
	d1->ratePassanger(uberTrips[n - 1], 6);//error as the rating is not between 1 and 5
	d1->ratePassanger(uberTrips[n - 1], 4);
	d1->ratePassanger(uberTrips[n - 1], 3);// will upate the passanging rating from 4 to 3
	p1->rateDriver(uberTrips[n - 1], 1);

	p1->printTrips();
	d1->printTrips();
	

	cout << p1->getAvgRating() << endl;
	cout << d1->getAvgRating() << endl;
	//system("pause");
	delete p1;
	p1 = nullptr;
	delete d1;
	d1 = nullptr;
	//module 3

	readfromfile("Data.txt");
	printUsers();
	trip* t = nullptr;
	passanger* p = dynamic_cast<passanger*>(users[0]);
	if (p != nullptr)
		addToUberTrips(t = p->bookRide("a", "b"));
	driver* d = dynamic_cast<driver*>(users[1]);
	if (d != nullptr)
	{
		d->pickARide(t);
		d->endARide();
		d->ratePassanger(t, 4);
	}
	p->rateDriver(t, 5);
	passanger* p0 = dynamic_cast<passanger*>(users[2]);
	if (p0 != nullptr)
		addToUberTrips(p0->bookRide("a", "b"));
	d->pickARide(t);
	d->endARide();
	d->ratePassanger(t, 3);
	p0->rateDriver(t, 4);
	passanger* p2 = dynamic_cast<passanger*>(users[5]);
	if (p2 != nullptr)
		addToUberTrips(p2->bookRide("a", "b"));
	d->pickARide(t);
	d->endARide();
	d->ratePassanger(t, 4);
	p2->rateDriver(t, 5);

	cout << "highest rating user" << endl;

	HighestRatedUser()->print();
	cout << "highest rating driver" << endl;

	HighestRatedDriver()->print();
	cout << "highest rating passanger" << endl;

	HighestRatedPassenger()->print();



	system("PAUSE");
}
