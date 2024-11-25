#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to simulate PDA
bool simulatePDA(const string &input) {
    stack<char> pdaStack;
    int i = 0;

    // Step 1: Push the first part of the string (w) onto the stack
    while (i < input.length() && input[i] != 'X') {
        if (input[i] == 'a' || input[i] == 'b') {
            pdaStack.push(input[i]);
        } else {
            return false; // Invalid character before X
        }
        i++;
    }

    // Step 2: Ensure the special symbol 'X' is present
    if (i >= input.length() || input[i] != 'X') {
        return false; // No 'X' found
    }
    i++; // Skip 'X'

    // Step 3: Pop from the stack and match the second part of the string (wr)
    while (i < input.length()) {
        if (pdaStack.empty()) {
            return false; // More characters in wr than in w
        }
        char top = pdaStack.top();
        pdaStack.pop();
        if (input[i] != top) {
            return false; // Mismatch between stack and wr
        }
        i++;
    }

    // Step 4: Ensure the stack is empty after processing
    return pdaStack.empty();
}

// Main function
int main() {
    string input;
    cout << "Enter a string over {a, b, X}: ";
    cin >> input;

    if (simulatePDA(input)) {
        cout << "String is accepted by the PDA." << endl;
    } else {
        cout << "String is rejected by the PDA." << endl;
    }

    return 0;
}

