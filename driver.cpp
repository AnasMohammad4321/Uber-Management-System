#include "driver.h"
#include "user.h"
#include <iostream>
#include "trip.h";
using namespace std;

driver::driver(string name, date dob, string email, string phone, string liscense, string vehicle) : user(name, dob, email, phone)
{
    license_num = liscense;
    vehicle_num = vehicle; 
}

void driver::pickARide(trip* ptr)
{
    if (ptr != nullptr)
    {
        if (ptr->get_status() != "completed" && ptr->get_status() == "Looking for driver")
        {
            current_ride = ptr;
            current_ride->set_driver(this);
            current_ride->set_status("ongoing");
            rides[count++] = current_ride;
        }
        else if (ptr->get_status() != "Looking for driver")
            cout << "Passenger not looking for driver." << endl;
        else if (ptr->get_status() == "completed")
            cout << "The trip is already completed." << endl;
    }
}

void driver::endARide()
{
    if (current_ride != nullptr)
    {
        current_ride->set_status("completed");
        current_ride->set_passenger_curride(nullptr);
        current_ride = nullptr;
    }
}

float driver::getAvgRating()
{
    int deno = 0;
    for (int i = 0;i < count;i++)
    {
        if (rides[i] != nullptr && rides[i]->get_status() != "cancelled")
        {
            rating += rides[i]->driver_rating;
            deno++;
        }
    }
    rating = rating / deno;
    return rating;
}

void driver::ratePassanger(trip* ptr, int a)
{
    if (ptr != nullptr && ptr->get_status() == "completed")
    {
        if (a > 0 && a < 6)
            ptr->passanger_rating = a;
        else
            cout << "Rating between 1 to 5" << endl;
    }
    else
        cout << "Error in Rating." << endl;
}

ostream& operator<<(ostream& osObject, driver& other)
{
    other.user::print();
    osObject << other.license_num << endl;
    osObject << other.vehicle_num << endl;
    osObject << "Total trips = " << other.count << endl;
    if (other.current_ride != nullptr)
        osObject << "Status : " << other.current_ride->get_status() << endl;
    else
        osObject << "Currently not driving." << endl;
    return osObject;
}
    