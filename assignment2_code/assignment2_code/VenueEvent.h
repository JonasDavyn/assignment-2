#pragma once
#include "Event.h"

// VenueEvent is a child class of Event
// It represents an event that happens in a physical venue
class VenueEvent : public Event
{
private:
    std::string venue;
    std::string dateTime;
    int capacity;

public: // Constructor: create a VenueEvent with extra details
    VenueEvent(const std::string &n, const std::string &d, double r,
               const std::string &v, const std::string &dt, int cap);

    void display() const override; // Show event info, including venue details

    void sellTicket() override;
};
