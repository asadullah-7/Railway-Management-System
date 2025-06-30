#include <iostream>
#include "Trains.h"
#include "BookingManager.h"
#include "TrainArrivalManager.h"
#include "TrainDepartureManager.h"
using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(10000, '\n');
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif      
}

void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// Arrival Menu
void arrivalMenu(TrainArrivalManager& arrivalManager, TrainDepartureManager& departureManager) {
    int choice;
    do {
        clearScreen();
        cout << "\n=== Arrival Menu ===\n";
        cout << "1. Add Arrival Train\n";
        cout << "2. Show Arrival Trains\n";
        cout << "3. Process Arrival (Move to Departures)\n";
        cout << "4. Update Train Status\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        clearInput();


        switch (choice) {
        case 1: {
            int num, seats;
            string name, from, arrivalTime;
            cout << "Train Number: "; cin >> num; clearInput();
            cout << "Train Name: "; getline(cin, name);
            cout << "From: "; getline(cin, from);
            cout << "Arrival Time: "; getline(cin, arrivalTime);
            cout << "Total Seats: "; cin >> seats; clearInput();

            Train* t = new Train(num, name, from, "", arrivalTime, "", seats);
            arrivalManager.addArrivalTrain(t);
            break;
        }
        case 2:
            arrivalManager.showArrivalTrains();
            break;
        case 3:
            arrivalManager.processNextArrival(departureManager);
            break;
        case 4: {
            int num;
            string status;
            cout << "Train Number: "; cin >> num;
            cout << "New Status: "; cin >> status;
            arrivalManager.updateArrivalStatus(num, status);
            break;
        }
        }
        if (choice != 0) pause();
    } while (choice != 0);
}

// Departure Menu
void departureMenu(TrainDepartureManager& departureManager) {
    int choice;
    do {
        clearScreen();
        cout << "\n=== Departure Menu ===\n";
        cout << "1. Add Departure Train\n";
        cout << "2. Show Departure Trains\n";
        cout << "3. Depart Train\n";
        cout << "4. Update Train Status\n";
        cout << "0. Back\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input.\n";
            pause();
            continue;
        }
        clearInput();

        switch (choice) {
        case 1: {
            int num, seats;
            string name, to, departureTime;
            cout << "Train Number: "; cin >> num; clearInput();
            cout << "Train Name: "; getline(cin, name);
            cout << "To: "; getline(cin, to);
            cout << "Departure Time: "; getline(cin, departureTime);
            cout << "Total Seats: "; cin >> seats; clearInput();

            Train* t = new Train(num, name, "", to, "", departureTime, seats);
            departureManager.addDepartureTrain(t);
            break;
        }
        case 2:
            departureManager.showDepartureTrains();
            break;
        case 3:
            departureManager.departTrain();
            break;
        case 4: {
            int num;
            string status;
            cout << "Train Number: "; cin >> num;
            cout << "New Status: "; cin >> status;
            departureManager.updateDepartureStatus(num, status);
            break;
        }
        }
        if (choice != 0) pause();
    } while (choice != 0);
}

// Booking Menu
void bookingMenu(BookingManager& bookingMgr, TrainDepartureManager& depMgr) {
    int choice;
    do {
        clearScreen();
        cout << "\n=== Booking System ===\n";
        cout << "1. Book Ticket\n";
        cout << "2. View All Bookings\n";
        cout << "3. Search Booking\n";
        cout << "4. Cancel Booking\n";
        cout << "0. Back\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input.\n";
            pause();
            continue;
        }
        clearInput();

        switch (choice) {
        case 1: {
            string name, cnic, dest, seat;
            cout << "Passenger Name: "; getline(cin, name);
            cout << "CNIC: "; getline(cin, cnic);
            cout << "Destination: "; getline(cin, dest);
            cout << "Seat Class: "; getline(cin, seat);
            bookingMgr.bookTicket(name, cnic, dest, seat, depMgr);
            break;
        }
        case 2:
            bookingMgr.showAllBookings();
            break;
        case 3: {
            string cnic;
            cout << "Enter CNIC: "; getline(cin, cnic);
            bookingMgr.searchBooking(cnic);
            break;
        }
        case 4: {
            string cnic;
            cout << "Enter CNIC: "; getline(cin, cnic);
            bookingMgr.cancelBooking(cnic, depMgr);
            break;
        }
        }
        if (choice != 0) pause();
    } while (choice != 0);
}

int main() {
    TrainArrivalManager arrivalManager;
    TrainDepartureManager departureManager;
    BookingManager bookingManager;

    int choice;
    do {
        clearScreen();
        cout << "====================================\n";
        cout << "   RAILWAY MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Arrival Management\n";
        cout << "2. Departure Management\n";
        cout << "3. Booking System\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input.\n";
            pause();
            continue;
        }

        switch (choice) {
        case 1: arrivalMenu(arrivalManager, departureManager); break;
        case 2: departureMenu(departureManager); break;
        case 3: bookingMenu(bookingManager, departureManager); break;
        }
    } while (choice != 0);

    cout << "\nExiting system. Thank you!\n";
    return 0;
}