#include <iostream>
#include <string>
using namespace std;

// Forward declarations for state functions
void State0(const string &w, int i);
void State1(const string &w, int i);
void State2(const string &w, int i);
void State3(const string &w, int i);
void State4(const string &w, int i); // Trap state

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

// Main function
int main() {
    string w;
    cout << "Enter a binary string: ";
    cin >> w;
    State0(w, 0); // Start with State0
    return 0;
}
