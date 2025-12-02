#include "VenueEvent.h"
#include <iostream>
using namespace std;

// Constructor: create a VenueEvent with extra details
// besides normal Event info, it also has venue, date/time, and capacity
VenueEvent::VenueEvent(const string &n, const string &d, double r,
                       const string &v, const string &dt, int cap)
    : Event(n, d, r), venue(v), dateTime(dt), capacity(cap) {}

void VenueEvent::display() const
{
    Event::display();      // Call base Event display first
    cout << "Venue: " << venue
         << "\nDate/Time: " << dateTime
         << "\nCapacity left: " << capacity << endl;
}

// Sell one ticket for the venue event
// If capacity is available, reduce capacity and increase ticketsSold
// If capacity is 0, show "sold out
void VenueEvent::sellTicket()
{
    if (capacity > 0)
    {
        capacity--;
        ticketsSold++;
        cout << "Venue ticket sold! Remaining: " << capacity << endl;
    }
    else
    {
        cout << "Event sold out!" << endl;
    }
}
