#pragma once
#include "Trains.h"
#include "data_Structure.h"
#include <iostream>
using namespace std;

class TrainDepartureManager {
private:
    Queue<Train*> departureQueue;

    // Helper function to find train by number
    Train* findTrainByNumber(int number) {
        for (int i = 0; i < departureQueue.size(); i++) {
            Train* t = departureQueue.get(i);
            if (t->getNumber() == number) {
                return t;
            }
        }
        return nullptr;
    }

public:
    void addDepartureTrain(Train* train) {
        departureQueue.push(train);
        cout << "Departure Train Added Successfully!\n";
    }

    void showDepartureTrains() const {
        if (departureQueue.isEmpty()) {
            cout << "No departure trains available.\n";
            return;
        }

        cout << "\nDeparture Trains:\n";
        for (int i = 0; i < departureQueue.size(); i++) {
            departureQueue.get(i)->displayInfo();
        }
    }

    void departTrain() {
        if (departureQueue.isEmpty()) {
            cout << "No train to depart.\n";
            return;
        }

        Train* t = departureQueue.pop();
        cout << "Train \"" << t->getName() << "\" to " << t->getTo()
            << " has departed at " << t->getDepartureTime() << ".\n";
    }

    void updateDepartureStatus(int number, const string& newStatus) {
        Train* train = findTrainByNumber(number);
        if (train) {
            train->setStatus(newStatus);
            cout << "Status Updated for Train #" << number << " to \"" << newStatus << "\"\n";
        }
        else {
            cout << "Train #" << number << " not found in departure list.\n";
        }
    }

    Train* getTrainByDestination(const string& dest) {
        for (int i = 0; i < departureQueue.size(); i++) {
            Train* t = departureQueue.get(i);
            if (t->getTo() == dest && t->getAvailableSeats() > 0) {
                return t;
            }
        }
        return nullptr;
    }

    Train* getTrainByNumber(int number) {
        return findTrainByNumber(number);
    }
};