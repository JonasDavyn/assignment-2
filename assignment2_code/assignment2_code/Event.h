// Base class: Event
#pragma once
#include <string>
#include <iostream>

// This is a function that allows you to compare two events based on their name. 
// You may directly include it in your class definition. 
// Operator overloading function prototype will be inside the class.

class Event
{
protected:
    // Basic event details
    std::string name;
    std::string description;
    double rating;
    int ticketsSold;

public:
    Event(const std::string &n, const std::string &d, double r);
    virtual ~Event();
    std::string getName() const;

    // Setters for event details
    void setName(const std::string &n);
    void setDescription(const std::string &d);

    virtual void display() const; // show event details
    virtual void sellTicket();    // sell one ticket

    bool operator==(const Event &otherEvent) const;
};

