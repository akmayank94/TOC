#include <iostream>
#include <string>
using namespace std;

// Forward declarations for state functions
void State0(const string &w, int i);
void State1(const string &w, int i);
void State2(const string &w, int i);
void StateReject(const string &w);

// State 0: Start state
void State0(const string &w, int i) {
    cout << "State 0" << endl;
    if (i >= w.size()) {
        cout << "String is rejected." << endl;
        return;
    }
    if (w[i] == 'a')
        State1(w, i + 1);
    else
        StateReject(w);
}

// State 1: After reading the first 'a'
void State1(const string &w, int i) {
    cout << "State 1" << endl;
    if (i >= w.size()) {
        cout << "String is rejected." << endl;
        return;
    }
    if (w[i] == 'b' && i == w.size() - 1) {
        // If 'b' is the last character, transition to State 2
        State2(w, i + 1);
    } else if (w[i] == 'a' || w[i] == 'b') {
        // Loop in State 1 for middle characters
        State1(w, i + 1);
    } else {
        StateReject(w);
    }
}

// State 2: Final state after reading 'b'
void State2(const string &w, int i) {
    cout << "State 2" << endl;
    if (i == w.size()) {
        cout << "String is accepted." << endl;
        return;
    }
    StateReject(w); // No valid transitions from this state
}

// Rejection state
void StateReject(const string &w) {
    cout << "Rejection State" << endl;
    cout << "String is rejected." << endl;
}

// Main function
int main() {
    string w;
    cout << "Enter a string over {a, b}: ";
    cin >> w;
    if (w.size() < 2) {
        cout << "String is rejected. (Too short)" << endl;
    } else {
        State0(w, 0); // Start at State 0
    }
    return 0;
}
