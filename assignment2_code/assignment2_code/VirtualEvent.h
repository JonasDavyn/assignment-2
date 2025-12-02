#pragma once
#include "Event.h"

// VirtualEvent is a type of Event that happens online
// It has extra fields: stream link and audience
class VirtualEvent : public Event
{
private:
    std::string streamLink; // Link for streaming
    std::string audience;   // Who is watching

public: // Constructor: set name, description, rating, link, and audience
    VirtualEvent(const std::string &n, const std::string &d, double r,
                 const std::string &link, const std::string &aud);

    void display() const override; // Show event info (adds stream link + audience)
    void sellTicket() override;    // Sell ticket for a virtual event (gives access code)
};
