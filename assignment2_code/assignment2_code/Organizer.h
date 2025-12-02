#pragma once
#include <string>
#include "LinkedBagDS/LinkedBag.h"
#include "Event.h"
#include <vector>

class Organizer
{
private: // Basic information about the organizer
    std::string username;
    std::string email;
    std::string password;
    std::string bio;
    std::string profilePicture;

    LinkedBag<Event *> events; // A LinkedBag that stores all events (both Virtual and Venue)

public:
    // Default constructor: creates an empty Organizer
    Organizer();

    // Constructor with parameters: creates Organizer with given details
    Organizer(const std::string &u, const std::string &e, const std::string &p,
              const std::string &b, const std::string &pic);

    const std::string &getUsername() const; // Get the username of this organizer
    void setPassword(const std::string &p); // Change the password
    void displayProfile() const;            // Show organizer profile
    void addEventAtKFromEnd(Event *e, int k); // Add an event at position k from the end of the list

    bool operator==(const Organizer &otherOrganizer) const;

    void addEvent(Event *e); // Add a new event
    void displayAllEvents() const;
    void displayEventK(int k) const; // Display the event at index k
    void modifyEvent(int k, const std::string &newName, const std::string &newDesc);
    void sellTicket(int k); // Sell a ticket for event at index k
    void deleteEvent(int k); // Delete the event at index k
};

