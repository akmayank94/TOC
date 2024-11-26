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

    // Transition for pushing 'a' onto the stack
    while (i < input.length() && input[i] == 'a') {
        pdaStack.push('a');
        cout << "Reading 'a', pushing to stack. Stack size: " << pdaStack.size() << endl;
        i++;
    }

    // Transition for popping 'a' from the stack for each 'b'
    while (i < input.length() && input[i] == 'b') {
        if (pdaStack.empty()) {
            cout << "Reading 'b', but stack is empty. String rejected." << endl;
            return false; // More 'b's than 'a's
        }
        pdaStack.pop();
        cout << "Reading 'b', popping from stack. Stack size: " << pdaStack.size() << endl;
        i++;
    }

    // Final check: Input fully processed and stack empty
    if (i == input.length() && pdaStack.empty()) {
        cout << "Input processed completely. Stack is empty. String is accepted by the PDA." << endl;
        return true;
    } else {
        cout << "Input not fully processed or stack is not empty. String rejected." << endl;
        return false;
    }
}

// Main function
int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    // Validate and process input
    if (simulatePDA(input)) {
        cout << "Result: String is accepted by the PDA." << endl;
    } else {
        cout << "Result: String is rejected by the PDA." << endl;
    }

    return 0;
}

