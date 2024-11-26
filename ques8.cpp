#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to simulate PDA
bool simulatePDA(const string &input) {
    stack<char> pdaStack;
    int i = 0;

    cout << "Input: " << input << endl;
    cout << "Simulating PDA transitions:" << endl;

    // Step 1: Push the first part of the string (w) onto the stack
    cout << "Step 1: Pushing characters of w onto the stack." << endl;
    while (i < input.length() && input[i] != 'X') {
        if (input[i] == 'a' || input[i] == 'b') {
            pdaStack.push(input[i]);
            cout << "Pushed '" << input[i] << "' onto the stack. Stack size: " << pdaStack.size() << endl;
        } else {
            cout << "Invalid character '" << input[i] << "' encountered before 'X'. Rejecting string." << endl;
            return false; // Invalid character before X
        }
        i++;
    }

    // Step 2: Ensure the special symbol 'X' is present
    if (i >= input.length() || input[i] != 'X') {
        cout << "'X' not found in the input. Rejecting string." << endl;
        return false; // No 'X' found
    }
    cout << "'X' encountered. Moving to the second part of the string (wr)." << endl;
    i++; // Skip 'X'

    // Step 3: Pop from the stack and match the second part of the string (wr)
    cout << "Step 3: Matching characters in wr with stack contents." << endl;
    while (i < input.length()) {
        if (pdaStack.empty()) {
            cout << "Stack is empty, but more characters found in wr. Rejecting string." << endl;
            return false; // More characters in wr than in w
        }
        char top = pdaStack.top();
        pdaStack.pop();
        cout << "Popped '" << top << "' from the stack. Matching with '" << input[i] << "'." << endl;
        if (input[i] != top) {
            cout << "Mismatch found. Rejecting string." << endl;
            return false; // Mismatch between stack and wr
        }
        i++;
    }

    // Step 4: Ensure the stack is empty after processing
    if (pdaStack.empty()) {
        cout << "Input processed completely. Stack is empty. String is accepted by the PDA." << endl;
        return true;
    } else {
        cout << "Input processed completely, but stack is not empty. Rejecting string." << endl;
        return false;
    }
}

// Main function
int main() {
    string input;
    cout << "Enter a string over {a, b, X}: ";
    cin >> input;

    if (simulatePDA(input)) {
        cout << "Result: String is accepted by the PDA." << endl;
    } else {
        cout << "Result: String is rejected by the PDA." << endl;
    }

    return 0;
}

