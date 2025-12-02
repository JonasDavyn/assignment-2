#include <iostream>
#include <string>
#include <fstream>
// TO DO: #include any other libraries you need
#include "EventTicket340.h"
#include "VirtualEvent.h"
#include "VenueEvent.h"

using namespace std;

using namespace std;

/**
 *
 * Displays the application's main menu
 * pre create a new object of type Organizer
 * @param organizer object to interact with
 *
 * */
// This function shows the menu for the organizer
// The organizer can choose what action to do
void displayOrganizerMenu(Organizer &organizer)   
{
	int organizerChoice = 0;
	do
	{
		cout << "\n Hi " << organizer.getUsername() << ", Are you ready!\n what would you like to do:\n"
			 << "1. Display Profile\n"
			 << "2. Modify Password\n"
			 << "3. Create Event\n"
			 << "4. Display All Events\n"
			 << "5. Display Kth Event\n"
			 << "6. Modify Event\n"
			 << "7. Sell Tickets\n"
			 << "8. Delete Event\n"
			 << "0. Logout\n"
			 << "Choice: ";
		cin >> organizerChoice;

		switch (organizerChoice)
		{
		case 1: 
		{
			// TO DO: display organizer's profile information
			//      : e.g. organizer.displayProfile();
			organizer.displayProfile(); // Show organizer profile
			break;
		}
		case 2:
		{
			// TO DO: ask for new password and update organizer's password
			string np;
			cout << "New password: "; // Change organizer password
			getline(cin, np);
			organizer.setPassword(np);
			cout << "Password updated.\n";
			break;
		}
		case 3:
		{
			// TO DO: ask organizer to choose event type, then ask them to input event details.
			// Create the event and add it to the organizer's events
			cout << "Event type? (1 = Virtual, 2 = Venue): "; // Create a new event (virtual or venue)
			int t;
			cin >> t;
			cin.ignore();

			string name, desc;
			double rating = 0.0;

			cout << "Name: ";
			getline(cin, name);
			cout << "Description: ";
			getline(cin, desc);
			cout << "Rating (0-5): ";
			cin >> rating;
			cin.ignore();

			Event *newEv = nullptr; // <-- tek yerde tut

			if (t == 1) // VirtualEvent
			{
				string link, audience;
				cout << "Stream link: ";
				getline(cin, link);
				cout << "Audience: ";
				getline(cin, audience);
				newEv = new VirtualEvent(name, desc, rating, link, audience);
			}
			else // VenueEvent
			{
				string venue, dt;
				int capacity = 0;
				cout << "Venue: ";
				getline(cin, venue);
				cout << "Date/Time: ";
				getline(cin, dt);
				cout << "Capacity: ";
				cin >> capacity;
				cin.ignore();
				newEv = new VenueEvent(name, desc, rating, venue, dt, capacity);
			}


			cout << "Optional: enter k (position from end) or -1 to skip: ";
			int k;
			cin >> k;
			cin.ignore();

			organizer.addEventAtKFromEnd(newEv, k); 

			break;
        
		}
		case 4:
		{
			// TO DO: display all organizer's events
			//        You may re-use code from class demo
			organizer.displayAllEvents(); // Show all events
			break;
		}
		case 5:
		{
			// TO DO: ask the organizer for a value k
			// Find the Kth event, if k > LinkedBag size,
			//    return an error message that includes the size of the LinkedBag
			int k;
			cout << "Index k (0-based): ";
			cin >> k;
			cin.ignore();
			organizer.displayEventK(k);
			break;
		}
		case 6:
		{
			// TO DO: ask the organizer for the index of the event they want to modify.
			// Find the event, then prompt them for the new name and description.
			// Modify the event accordingly.
			// If index > LinkedBag size,
			//    return an error message that includes the size of the LinkedBag
			int idx;
			cout << "Index to modify (0-based): "; // Modify an event
			cin >> idx;
			cin.ignore();
			string newName, newDesc;
			cout << "New name: ";
			getline(cin, newName);
			cout << "New description: ";
			getline(cin, newDesc);
			organizer.modifyEvent(idx, newName, newDesc);
			break;
		}
		case 7:
		{
			// TO DO: ask the organizer for the index of the event
			// Find the event, then sell the tickets.
			// If index > LinkedBag size,
			//    return an error message that includes the size of the LinkedBag
			int idx; // Sell a ticket for an event
			cout << "Index to sell ticket (0-based): ";
			cin >> idx;
			cin.ignore();
			organizer.sellTicket(idx);
			break;
			break;
		}
		case 8:
		{
			// TO DO: ask the organizer for the index of the event they want to delete
			// Find the event, then remove it from the list.
			// If index > LinkedBag size,
			//    return an error message that includes the size of the LinkedBag
			int idx;
			cout << "Index to delete (0-based): "; // Delete an event
			cin >> idx; 
			cin.ignore();
			organizer.deleteEvent(idx);
			 break;
		}
		case 0: // Exit program
		{
			cout << "Logging you out." << endl;
			break;
		}
		default:
			cout << "Invalid choice. Please try again." << endl;
		}

	} while (organizerChoice != 0);
}

int main(int argc, char** argv)
{
	// If an output filename is provided as the first argument, redirect cout to that file.
	std::ofstream outFile;
	std::streambuf* coutBuf = nullptr;
	if (argc > 1)
	{
		outFile.open(argv[1]);
		if (outFile.is_open())
		{
			coutBuf = std::cout.rdbuf();           // save old buf
			std::cout.rdbuf(outFile.rdbuf());     // redirect cout to file
		}
		else
		{
			std::cerr << "Warning: could not open output file '" << argv[1] << "' - continuing with console output." << std::endl;
		}
	}

	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one organizer
	EventTicket340 eventTicket340; // Create the EventTicket340 system

	cout << "\n Welcome to EventTicket340:" << endl;
	// TO DO: Ask the organizer to enter their information
	//        Instantiate a new Organizer object

	// Ask organizer for profile information
	string u, e, p, b, pic;
	cout << "Username: ";
	getline(cin, u);
	cout << "Email: ";
	getline(cin, e);
	cout << "Password: ";
	getline(cin, p);
	cout << "Short bio: ";
	getline(cin, b);
	cout << "Profile picture path: ";
	getline(cin, pic);

	// call eventTicket340 createOrganizer function
	// replace /*...*/ with the right parameters
	eventTicket340.createOrganizer(u, e, p, b, pic /*...*/);

	// Retrieve the organizer
	Organizer currentOrganizer = eventTicket340.getOrganizer();

	// Display the main menu
	displayOrganizerMenu(currentOrganizer);
	// If we redirected cout to a file, restore the buffer and close file
	if (coutBuf)
	{
		std::cout.rdbuf(coutBuf);
		outFile.close();
	}

	return 0;
}