#include <iostream>
using namespace std;

int main() {
    const int MAX_MEMBERS = 100;
    string members[MAX_MEMBERS];
    int totalMembers, totalCommittees;
    int startMonth;

    cout << "=== Welcome to the Committee Lucky Draw System ===\n\n";

    // Step 1: Enter committee members
    cout << "Enter the total number of committee members: ";
    cin >> totalMembers;

    if (totalMembers > MAX_MEMBERS) {
        cout << "Error: Maximum allowed members are " << MAX_MEMBERS << ". Exiting program.\n";
        return 1;
    }

    cin.ignore(); // Clear input buffer
    for (int i = 0; i < totalMembers; i++) {
        cout << "Enter name of member #" << (i + 1) << ": ";
        getline(cin, members[i]);
    }

    // Step 2: Ask for number of committees
    cout << "\nEnter the total number of committees: ";
    cin >> totalCommittees;

    // Step 3: Ask for starting month
    cout << "Enter the starting month number (1 for Jan, 12 for Dec): ";
    cin >> startMonth;

    if (startMonth < 1 || startMonth > 12) {
        cout << "Invalid month. Please restart and enter a value between 1 and 12.\n";
        return 1;
    }

    int endMonth = startMonth + totalCommittees - 1;
    cout << "\nCommittees will run from month " << startMonth 
         << " to month " << (endMonth > 12 ? (endMonth % 12) : endMonth) << ".\n";

    // Step 4: Ask user to choose draw method
    cout << "\nChoose draw method:\n";
    cout << "1. All lucky draws at once\n";
    cout << "2. One draw per month\n";
    int choice;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    cout << "\n=== Lucky Draw Results ===\n";
    if (choice == 1) {
        for (int i = 0; i < totalCommittees; i++) {
            int luckyIndex = i % totalMembers;
            cout << "Committee #" << (i + 1) << ": " << members[luckyIndex] << " wins!\n";
        }
    } else if (choice == 2) {
        for (int i = 0; i < totalCommittees; i++) {
            int currentMonth = (startMonth + i - 1) % 12 + 1;
            int luckyIndex = i % totalMembers;
            cout << "Month " << currentMonth << " - Committee #" << (i + 1)
                 << ": " << members[luckyIndex] << " wins!\n";
        }
    } else {
        cout << "Invalid choice. Please restart the program.\n";
    }

    cout << "\nThank you for using the Lucky Draw System!\n";
    return 0;
}
