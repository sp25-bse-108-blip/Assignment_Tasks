#include <iostream>
#include <string>
using namespace std;
struct Seat {
    int seatNumber;
    bool isReserved;
    string passengerName;
};
void displayMenu() {
    cout << "\n==== Train Seat Reservation System ====" << endl;
    cout << "1. View Available Seats" << endl;
    cout << "2. Reserve a Seat" << endl;
    cout << "3. Cancel Reservation" << endl;
    cout << "4. Exit" << endl;
    cout << "=====================================" << endl;
    cout << "Enter your choice: ";
}
void displaySeats(Seat *seats, int totalSeats) {
    cout << "\nAvailable Seats:" << endl;
    for (int i = 0; i < totalSeats; i++) {
        if (!seats[i].isReserved) {
            cout << "Seat " << seats[i].seatNumber << " is available." << endl;
        }
    }
}
void reserveSeat(Seat *seats, int totalSeats) {
    int seatNum;
    cout << "\nEnter the seat number to reserve: ";
    cin >> seatNum;

    for (int i = 0; i < totalSeats; i++) {
        if (seats[i].seatNumber == seatNum) {
            if (!seats[i].isReserved) {
                cout << "Enter passenger's name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, seats[i].passengerName);
                seats[i].isReserved = true;
                cout << "Seat " << seatNum << " has been reserved for " << seats[i].passengerName << "." << endl;
                return;
            } else {
                cout << "Sorry, Seat " << seatNum << " is already reserved." << endl;
                return;
            }
        }
    }
    cout << "Invalid seat number." << endl;
}
void cancelReservation(Seat *seats, int totalSeats) {
    int seatNum;
    cout << "\nEnter the seat number to cancel reservation: ";
    cin >> seatNum;

    for (int i = 0; i < totalSeats; i++) {
        if (seats[i].seatNumber == seatNum) {
            if (seats[i].isReserved) {
                seats[i].isReserved = false;
                cout << "Reservation for seat " << seatNum << " (Passenger: " << seats[i].passengerName << ") has been canceled." << endl;
                seats[i].passengerName = ""; // Clear the passenger name
                return;
            } else {
                cout << "Seat " << seatNum << " is not reserved." << endl;
                return;
            }
        }
    }
    cout << "Invalid seat number." << endl;
}
int main() {
    const int totalSeats = 5;
    Seat seats[totalSeats];
    
    for (int i = 0; i < totalSeats; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].isReserved = false;
        seats[i].passengerName = "";
    }
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeats(seats, totalSeats);
                break;
            case 2:
                reserveSeat(seats, totalSeats);
                break;
            case 3:
                cancelReservation(seats, totalSeats);
                break;
            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
