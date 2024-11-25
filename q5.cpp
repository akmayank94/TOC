#include <iostream>
#include <string>
using namespace std;

// Function prototypes for states
void State00(const string &w, int i);
void State01(const string &w, int i);
void State10(const string &w, int i);
void State11(const string &w, int i);

// State 00: Even 'a's and even 'b's (Accepting state)
void State00(const string &w, int i) {
    cout << "State 00 (Even 'a', Even 'b')" << endl;
    if (i == w.size()) {
        cout << "String is accepted." << endl;
        return;
    }
    if (w[i] == 'a') State10(w, i + 1);
    else if (w[i] == 'b') State01(w, i + 1);
    else cout << "Invalid input. String rejected." << endl;
}

// State 01: Even 'a's and odd 'b's
void State01(const string &w, int i) {
    cout << "State 01 (Even 'a', Odd 'b')" << endl;
    if (i == w.size()) {
        cout << "String is rejected." << endl;
        return;
    }
    if (w[i] == 'a') State11(w, i + 1);
    else if (w[i] == 'b') State00(w, i + 1);
    else cout << "Invalid input. String rejected." << endl;
}

// State 10: Odd 'a's and even 'b's
void State10(const string &w, int i) {
    cout << "State 10 (Odd 'a', Even 'b')" << endl;
    if (i == w.size()) {
        cout << "String is rejected." << endl;
        return;
    }
    if (w[i] == 'a') State00(w, i + 1);
    else if (w[i] == 'b') State11(w, i + 1);
    else cout << "Invalid input. String rejected." << endl;
}

// State 11: Odd 'a's and odd 'b's
void State11(const string &w, int i) {
    cout << "State 11 (Odd 'a', Odd 'b')" << endl;
    if (i == w.size()) {
        cout << "String is rejected." << endl;
        return;
    }
    if (w[i] == 'a') State01(w, i + 1);
    else if (w[i] == 'b') State10(w, i + 1);
    else cout << "Invalid input. String rejected." << endl;
}

// Main function
int main() {
    string w;
    cout << "Enter a string over {a, b}: ";
    cin >> w;
    State00(w, 0); // Start at State 00
    return 0;
}
