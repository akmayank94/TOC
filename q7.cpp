#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to simulate PDA
bool simulatePDA(const string &input) {
    stack<char> pdaStack;
    int i = 0;

    // Transition for pushing 'a' onto the stack
    while (i < input.length() && input[i] == 'a') {
        pdaStack.push('a');
        i++;
    }

    // Transition for popping 'a' from the stack for each 'b'
    while (i < input.length() && input[i] == 'b') {
        if (pdaStack.empty()) {
            return false; // More 'b's than 'a's
        }
        pdaStack.pop();
        i++;
    }

    // Check if the input is fully processed and the stack is empty
    return i == input.length() && pdaStack.empty();
}

// Main function
int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    if (simulatePDA(input)) {
        cout << "String is accepted by the PDA." << endl;
    } else {
        cout << "String is rejected by the PDA." << endl;
    }

    return 0;
}
