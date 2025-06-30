#pragma once
#include "Trains.h"
#include "data_Structure.h"
#include "TrainDepartureManager.h"
#include <iostream>
using namespace std;

class TrainArrivalManager {
private:
    Queue<Train*> arrivalQueue;

public:
    void addArrivalTrain(Train* train) {
        arrivalQueue.push(train);
        cout << "Arrival Train Added Successfully!\n";
    }

    void showArrivalTrains() const {
        if (arrivalQueue.isEmpty()) {
            cout << "No arrival trains available.\n";
            return;
        }

        cout << "\nArrival Trains:\n";
        for (int i = 0; i < arrivalQueue.size(); i++) {
            arrivalQueue.get(i)->displayInfo();
        }
    }

    void processNextArrival(TrainDepartureManager& departureManager) {
        if (arrivalQueue.isEmpty()) {
            cout << "No arriving train to process.\n";
            return;
        }

        Train* arrivedTrain = arrivalQueue.pop();
        cout << "Train \"" << arrivedTrain->getName() << "\" from "
            << arrivedTrain->getFrom() << " has arrived at "
            << arrivedTrain->getArrivalTime() << ".\n";

        // Get new departure details
        string newDestination, departureTime;
        cout << "\nEnter new departure details:\n";
        cout << "Destination: ";
        getline(cin, newDestination);
        cout << "Departure Time: ";
        getline(cin, departureTime);

        // Update train for departure
        arrivedTrain->setTo(newDestination);
        arrivedTrain->setDepartureTime(departureTime);
        arrivedTrain->setStatus("Ready for Departure");

        // Add to departure queue
        departureManager.addDepartureTrain(arrivedTrain);
    }

    void updateArrivalStatus(int number, const string& newStatus) {
        for (int i = 0; i < arrivalQueue.size(); i++) {
            Train* t = arrivalQueue.get(i);
            if (t->getNumber() == number) {
                t->setStatus(newStatus);
                cout << "Status Updated for Train #" << number << endl;
                return;
            }
        }
        cout << "Train #" << number << " not found in arrival list.\n";
    }
};