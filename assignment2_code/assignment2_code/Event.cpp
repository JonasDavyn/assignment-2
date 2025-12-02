
// TO DO: #include all the standard libraries and your own libraries here

// TO DO: function implementations

// ------------------------------------------------------------------------------
// Operator overloading implementation

#include "Event.h"
using namespace std;
// Constructor: create a new Event with given name, description, and rating
Event::Event(const string &n, const string &d, double r)
	: name(n), description(d), rating(r), ticketsSold(0) {}

Event::~Event() {} // Destructor: nothing special to clean up

string Event::getName() const { return name; } // Getter: return the name of the event
void Event::setName(const string &n) { name = n; } // Setter: change the name of the event
void Event::setDescription(const string &d) { description = d; } // Setter: change the description of the event

void Event::display() const // Display event details (print info to the screen)
{
	cout << "\nEvent: " << name
		 << "\nDescription: " << description
		 << "\nRating: " << rating
		 << "\nTickets Sold: " << ticketsSold << endl;
}

void Event::sellTicket() // Sell one ticket: increase count and show total
{
	ticketsSold++;
	cout << "Ticket sold! Total: " << ticketsSold << endl;
}

bool Event::operator==(const Event& otherEvent) const {
	return Event::name == otherEvent.name;
}




