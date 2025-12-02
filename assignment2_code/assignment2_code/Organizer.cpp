
// TO DO: #include needed standard libraries and your own libraries here

// TO DO: function implementations

// Operator == overloading implementation
#include "Organizer.h"
#include "Event.h"
#include <iostream>
#include <vector>

Organizer::Organizer() // Default constructor: create an empty Organizer with blank fields
	: username(""), email(""), password(""),
	  bio(""), profilePicture("")
{
}

Organizer::Organizer( // Constructor with parameters: set all profile fields
	const std::string &u,
	const std::string &e,
	const std::string &p,
	const std::string &b,
	const std::string &pic)
	: username(u),
	  email(e),
	  password(p),
	  bio(b),
	  profilePicture(pic)
{
}

const std::string &Organizer::getUsername() const { return username; } // Return the username (read-only)

void Organizer::setPassword(const std::string &p) { password = p; } // Change the password

void Organizer::displayProfile() const // Print the organizer profile (password is hidden)
{
	std::cout << "\n--- Organizer Profile ---";
	std::cout << "Username: " << username << std::endl;
	std::cout << "Email   : " << email << std::endl;
	std::cout << "Bio     : " << bio << std::endl;
	std::cout << "Picture : " << profilePicture << std::endl;
	std::cout << "(Password hidden)";
}

bool Organizer::operator==(const Organizer &otherOrganizer) const
{
	return (Organizer::username == otherOrganizer.username) && (Organizer::email == otherOrganizer.email);
}

void Organizer::addEvent(Event *e) // Add an event to
{
	events.add(e);
	std::cout << "Event added: " << e->getName() << "\n"; 
}

void Organizer::displayAllEvents() const // Show all events by converting the bag to a vector and printing each
{
	std::vector<Event *> list = events.toVector();
	if (list.empty())
	{
		std::cout << "No events.\n";
		return;
	}
	for (Event *ev : list)
	{
		ev->display();
	}
}

// Display the k-th event (0-based) using findKthItem
// If k is invalid, print an error with the current size
void Organizer::displayEventK(int k) const
{
	Node<Event *> *node = events.findKthItem(k);
	if (!node)
	{
		std::cout << "No event at index " << k
				  << ". Total events: " << events.getCurrentSize() << "\n";
	}
	else
	{
		node->getItem()->display();
	}
}

void Organizer::modifyEvent(int k, const std::string &newName, const std::string &newDesc)
{
	Node<Event *> *node = events.findKthItem(k);
	if (!node)
	{
		std::cout << "Invalid index.\n";
	}
	else
	{
		node->getItem()->setName(newName);
		node->getItem()->setDescription(newDesc);
		std::cout << "Event modified.\n";
	}
}

void Organizer::sellTicket(int k) // Sell one ticket for the k-th event
{
	Node<Event *> *node = events.findKthItem(k);
	if (!node)
	{
		std::cout << "Invalid index.\n";
	}
	else
	{
		node->getItem()->sellTicket();
	}
}

void Organizer::deleteEvent(int k) // Delete (remove and free) the k-th event
{
	Node<Event *> *node = events.findKthItem(k);
	if (!node)
	{
		std::cout << "Invalid index.\n";
	}
	else
	{
		Event *e = node->getItem();
		events.remove(e); // remove pointer from the bag
		delete e;
		std::cout << "Event deleted.\n";
	}    
}

// Add an event at k-th position from the end using reverseAppendK
// If k < 0, just add to the front (default behavior)
void Organizer::addEventAtKFromEnd(Event *e, int k)
{
	if (k >= 0)
		events.reverseAppendK(e, k);
	else
		events.add(e);

	std::cout << "Event added: " << e->getName() << "\n";
}
