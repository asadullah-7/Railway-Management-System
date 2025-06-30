#pragma once
#include <string>
#include <iostream>
using namespace std;

class Train 
{
private:
    int number;
    string name;
    string from;
    string to;
    string arrivalTime;
    string departureTime;
    int totalSeats;
    int bookedSeats;
    string status = "On Time";

public:
    Train() : number(0), name(""), from(""), to(""),
        arrivalTime(""), departureTime(""),
        totalSeats(0), bookedSeats(0) {}

    Train(int num, const string& n, const string& f, const string& t,
        const string& arr, const string& dep, int seats)
        : number(num), name(n), from(f), to(t),
        arrivalTime(arr), departureTime(dep),
        totalSeats(seats), bookedSeats(0) {}

    // Getters
    int getNumber() const { return number; }
    string getName() const { return name; }
    string getFrom() const { return from; }
    string getTo() const { return to; }
    string getArrivalTime() const { return arrivalTime; }
    string getDepartureTime() const { return departureTime; }
    int getTotalSeats() const { return totalSeats; }
    int getBookedSeats() const { return bookedSeats; }
    int getAvailableSeats() const { return totalSeats - bookedSeats; }
    string getStatus() const { return status; }

    // Setters
    void setTo(const string& newTo) { to = newTo; }
    void setDepartureTime(const string& time) { departureTime = time; }
    void setStatus(const string& s) { status = s; }

    bool bookSeat() {
        if (bookedSeats < totalSeats) {
            bookedSeats++;
            return true;
        }
        return false;
    }

    bool cancelSeat() {
        if (bookedSeats > 0) {
            bookedSeats--;
            return true;
        }
        return false;
    }

    void displayInfo() const {
        cout << "\nTrain #" << number << " - " << name << endl;
        cout << "From: " << from << "   To: " << to << endl;
        cout << "Arrival: " << arrivalTime << "   Departure: " << departureTime << endl;
        cout << "Status: " << status << endl;
        cout << "Seats Available: " << getAvailableSeats() << " / " << totalSeats << endl;
        cout << "-------------------------------------------" << endl;
    }
};