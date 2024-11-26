#include <iostream>
#include <string>
using namespace std;

// Forward declarations for state functions
void State0(const string &w, int i);
void State1(const string &w, int i);
void State2(const string &w, int i);
void State3(const string &w, int i);
void State4(const string &w, int i); // Trap state

bool isAccepted = false; // Tracks if the string is accepted

// State 0: Start state
void State0(const string &w, int i) {
    cout << "State 0" << endl;
    if (i == w.size()) {
        cout << "String is rejected." << endl;
        return;
    }
    if (w[i] == '1')
        State1(w, i + 1);
    else
        State0(w, i + 1);
}

// State 1: One '1' encountered
void State1(const string &w, int i) {
    cout << "State 1" << endl;
    if (i == w.size()) {
        cout << "String is rejected." << endl;
        return;
    }
    if (w[i] == '1')
        State2(w, i + 1);
    else
        State1(w, i + 1);
}

// State 2: Two '1's encountered (final state for two '1's)
void State2(const string &w, int i) {
    cout << "State 2" << endl;
    if (i == w.size()) {
        isAccepted = true;
        cout << "String is accepted. (Exactly two '1's)" << endl;
        return;
    }
    if (w[i] == '1')
        State3(w, i + 1);
    else
        State2(w, i + 1);
}

// State 3: Three '1's encountered (final state for three '1's)
void State3(const string &w, int i) {
    cout << "State 3" << endl;
    if (i == w.size()) {
        isAccepted = true;
        cout << "String is accepted. (Exactly three '1's)" << endl;
        return;
    }
    if (w[i] == '1')
        State4(w, i + 1);
    else
        State3(w, i + 1);
}

// State 4: More than three '1's encountered (trap state)
void State4(const string &w, int i) {
    cout << "State 4 (Trap State)" << endl;
    if (i == w.size()) {
        cout << "String is rejected." << endl;
        return;
    }
    State4(w, i + 1); // Stay in trap state for any input
}

// Menu function
void menu() {
    int choice;
    string w;

    do {
        cout << "\nFinite Automata Simulation Menu\n";
        cout << "1. Check a binary string\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                isAccepted = false; // Reset acceptance flag for each new string
                cout << "Enter a binary string: ";
                cin >> w;

                // Check if the string is valid (contains only '0' and '1')
                for (char c : w) {
                    if (c != '0' && c != '1') {
                        cout << "Invalid input. Please enter a binary string (containing only '0' and '1')." << endl;
                        isAccepted = false;
                        break;
                    }
                }
                if (!isAccepted) {
                    State0(w, 0); // Start with State0
                }
                break;

            case 2:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please enter 1 or 2." << endl;
        }
    } while (choice != 2);
}

// Main function
int main() {
    menu();
    return 0;
}

