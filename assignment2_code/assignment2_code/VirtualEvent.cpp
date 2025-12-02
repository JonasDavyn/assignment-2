#include "VirtualEvent.h"
#include <iostream>
using namespace std;

// Constructor: create a VirtualEvent with extra details (link + audience)
VirtualEvent::VirtualEvent(const string &n, const string &d, double r,
                  const string &link, const string &aud)
    : Event(n, d, r), streamLink(link), audience(aud) {}

void VirtualEvent::display() const // Show event info, including stream link and audience
{
    Event::display();
    cout << "Stream Link: " << streamLink
         << "\nAudience: " << audience << endl;
}

void VirtualEvent::sellTicket() // Sell ticket for a virtual event
{
    ticketsSold++;
    cout << "Virtual ticket sold! Code: ACCESS" << ticketsSold << endl;
}
