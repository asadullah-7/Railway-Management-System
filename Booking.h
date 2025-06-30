#pragma once
#include <string>
using namespace std;

class Booking {
private:
    string passengerName;
    string cnic;
    string destination;
    string seatClass;
    int trainNumber;  // Added train number reference
    Booking* next;

public:
    Booking(const string& name, const string& id, const string& dest,
        const string& seat, int trainNum)
        : passengerName(name), cnic(id), destination(dest),
        seatClass(seat), trainNumber(trainNum), next(nullptr) {
    }

    // Getters
    string getPassengerName() const { return passengerName; }
    string getCNIC() const { return cnic; }
    string getDestination() const { return destination; }
    string getSeatClass() const { return seatClass; }
    int getTrainNumber() const { return trainNumber; }  // New getter

    Booking* getNext() const { return next; }
    void setNext(Booking* n) { next = n; }

    void display() const {
        cout << "- " << passengerName << " | CNIC: " << cnic
            << " | Train #: " << trainNumber  // Display train number
            << " | Destination: " << destination
            << " | Class: " << seatClass << endl;
    }
};