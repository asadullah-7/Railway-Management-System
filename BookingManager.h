#pragma once
#include "Booking.h"
#include "TrainDepartureManager.h"
#include <iostream>
using namespace std;

class BookingManager {
private:
    Booking* head = nullptr;

public:
    bool cnicExists(const string& cnic) const {
        Booking* temp = head;
        while (temp) {
            if (temp->getCNIC() == cnic) return true;
            temp = temp->getNext();
        }
        return false;
    }

    void bookTicket(const string& name, const string& cnic,
        const string& dest, const string& seatClass,
        TrainDepartureManager& trainManager) {
        if (cnicExists(cnic)) {
            cout << "Booking already exists for CNIC " << cnic << ".\n";
            return;
        }

        Train* train = trainManager.getTrainByDestination(dest);
        if (!train || !train->bookSeat()) {
            cout << "Booking failed! No available trains/seats.\n";
            return;
        }

        Booking* newBooking = new Booking(
            name, cnic, dest, seatClass, train->getNumber()
        );

        if (!head) head = newBooking;
        else {
            Booking* temp = head;
            while (temp->getNext()) temp = temp->getNext();
            temp->setNext(newBooking);
        }

        cout << "Booking Confirmed for " << name << " to " << dest
            << " in " << seatClass << " class on Train #"
            << train->getNumber() << ".\n";
    }

    void showAllBookings() const {
        if (!head) {
            cout << "No bookings found.\n";
            return;
        }

        Booking* temp = head;
        cout << "\nAll Bookings:\n";
        while (temp) {
            temp->display();
            temp = temp->getNext();
        }
    }

    void searchBooking(const string& cnic) const {
        Booking* temp = head;
        while (temp) {
            if (temp->getCNIC() == cnic) {
                cout << "\nBooking Found:\n";
                temp->display();
                return;
            }
            temp = temp->getNext();
        }
        cout << "No booking found for CNIC: " << cnic << endl;
    }

    void cancelBooking(const string& cnic, TrainDepartureManager& trainManager) {
        if (!head) {
            cout << "No bookings to cancel.\n";
            return;
        }

        Booking* temp = head;
        Booking* prev = nullptr;

        while (temp && temp->getCNIC() != cnic) {
            prev = temp;
            temp = temp->getNext();
        }

        if (!temp) {
            cout << "Booking not found.\n";
            return;
        }

        // Cancel seat in train
        Train* train = trainManager.getTrainByNumber(temp->getTrainNumber());
        if (train) train->cancelSeat();

        if (prev) prev->setNext(temp->getNext());
        else head = temp->getNext();

        delete temp;
        cout << "Booking cancelled successfully.\n";
    }

    ~BookingManager() {
        while (head) {
            Booking* temp = head;
            head = head->getNext();
            delete temp;
        }
    }
};