#pragma once
#include "LinkedBagDS/LinkedBag.h"
// TO DO include necessary libraries
#include <string>
#include "Organizer.h"

// This class only contains a single organizer
class EventTicket340
{
private:
    Organizer organizer; // The organizer who will create and manage events

public:
    EventTicket340();
    ~EventTicket340();

    // Create a new organizer profile
    void createOrganizer(const std::string &username, const std::string &email, const std::string &password, const std::string &bio, const std::string &profilePicture);

    // Retrieve the organizer object
    Organizer getOrganizer() const;
};
