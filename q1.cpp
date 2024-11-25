#include <iostream>
#include <string>
using namespace std;

// Forward declaration of states
void State0(const string &w, int i);
void State1(const string &w, int i);
void State2(const string &w, int i);
void State3(const string &w, int i);

// State 0: Start state
void State0(const string &w, int i) {
    cout << "State 0" << endl;
    if (i == w.size()) { // Use .size() to check the length of the string
        cout << "String is rejected." << endl; // Didn't reach final state
        return;
    }
    if (w[i] == '1')
        State1(w, i + 1);
    else
        State0(w, i + 1); // Stay in q0 for input 0
}

// State 1: One consecutive '1' encountered
void State1(const string &w, int i) {
    cout << "State 1" << endl;
    if (i == w.size()) { // Use .size() to check the length of the string
        cout << "String is rejected." << endl; // Didn't reach final state
        return;
    }
    if (w[i] == '1')
        State2(w, i + 1);
    else
        State0(w, i + 1); // Reset to q0 on input 0
}

// State 2: Two consecutive '1's encountered
void State2(const string &w, int i) {
    cout << "State 2" << endl;
    if (i == w.size()) { // Use .size() to check the length of the string
        cout << "String is rejected." << endl; // Didn't reach final state
        return;
    }
    if (w[i] == '1')
        State3(w, i + 1);
    else
        State0(w, i + 1); // Reset to q0 on input 0
}

// State 3: Final state, three consecutive '1's
void State3(const string &w, int i) {
    cout << "State 3" << endl;
    if (i == w.size()) { // Use .size() to check the length of the string
        cout << "String is accepted." << endl; // Reached final state
        return;
    }
    State3(w, i + 1); // Stay in final state for any input
}

// Main function
int main() {
    string w;
    cout << "Enter a binary string: ";
    cin >> w;
    State0(w, 0); // Start with State0
    return 0;
}
