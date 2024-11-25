#include <iostream>
#include <string>
using namespace std;

// Forward declarations for state functions
void State0(const string &w, int i, char first, char second);
void State1(const string &w, int i, char first, char second);
void State2(const string &w, int i, char first, char second);
void State3(const string &w, int i, char first, char second);
void State4(const string &w, int i, char first, char second);
void StateReject(const string &w);

// State 0: Start state
void State0(const string &w, int i, char first, char second) {
    cout << "State 0" << endl;
    if (i >= w.size()) {
        cout << "String is rejected." << endl;
        return;
    }
    if (w[i] == 'a' || w[i] == 'b')
        State1(w, i + 1, w[i], '\0');
    else
        StateReject(w);
}

// State 1: Read the second character
void State1(const string &w, int i, char first, char second) {
    cout << "State 1" << endl;
    if (i >= w.size()) {
        cout << "String is rejected." << endl;
        return;
    }
    if (w[i] == 'a' || w[i] == 'b')
        State2(w, i + 1, first, w[i]);
    else
        StateReject(w);
}

// State 2: Process intermediate characters
void State2(const string &w, int i, char first, char second) {
    cout << "State 2" << endl;
    if (i >= w.size() - 2) { // Only last two characters are left
        State3(w, i, first, second);
        return;
    }
    if (w[i] == 'a' || w[i] == 'b')
        State2(w, i + 1, first, second);
    else
        StateReject(w);
}

// State 3: Read the third-to-last character
void State3(const string &w, int i, char first, char second) {
    cout << "State 3" << endl;
    if (i >= w.size()) {
        cout << "String is rejected." << endl;
        return;
    }
    if (w[i] == first)
        State4(w, i + 1, first, second);
    else
        StateReject(w);
}

// State 4: Read the fourth-to-last character and verify
void State4(const string &w, int i, char first, char second) {
    cout << "State 4" << endl;
    if (i >= w.size()) {
        cout << "String is rejected." << endl;
        return;
    }
    if (w[i] == second) {
        cout << "String is accepted." << endl;
        return;
    }
    StateReject(w);
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
    if (w.size() < 4) {
        cout << "String is rejected. (Too short)" << endl;
    } else {
        State0(w, 0, '\0', '\0'); // Start at State 0
    }
    return 0;
}
