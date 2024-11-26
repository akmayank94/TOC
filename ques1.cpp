#include <iostream>
#include <string>
using namespace std;

// Function to simulate the FA
bool simulateFA(const string &w) {
    int state = 0; // Start state is 0
    for (char c : w) {
        if (state == 0) {
            if (c == '1') state = 1; // Transition to State 1
        } else if (state == 1) {
            if (c == '1') state = 2; // Transition to State 2
            else state = 0;          // Reset to State 0
        } else if (state == 2) {
            if (c == '1') state = 3; // Transition to State 3
            else state = 0;          // Reset to State 0
        } else if (state == 3) {
            // Remain in State 3 for any input
            break;
        }
    }
    return state == 3; // Return true if final state is reached
}

// Function to validate binary strings
bool isBinary(const string &w) {
    for (char c : w) {
        if (c != '0' && c != '1') return false; // Invalid character found
    }
    return true;
}

// Main function with menu
int main() {
    int choice;
    do {
        cout << "\n===== Finite Automaton Simulation =====\n";
        cout << "1. Check a binary string\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string w;
            cout << "Enter a binary string: ";
            cin >> w;

            // Validate the input
            if (!isBinary(w)) {
                cout << "Invalid input! Please enter a binary string (only 0s and 1s)." << endl;
                break;
            }

            // Simulate the FA
            if (simulateFA(w)) {
                cout << "String is accepted." << endl;
            } else {
                cout << "String is rejected." << endl;
            }
            break;
        }
        case 2:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 2);

    return 0;
}

