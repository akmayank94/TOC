#include <iostream>
#include <string>
using namespace std;

// Function to check if the input is a valid binary number
bool isValidBinary(const string& tape) {
    for (char ch : tape) {
        if (ch != '0' && ch != '1') {
            return false; // Invalid character found
        }
    }
    return true;
}

// Function to simulate the Turing Machine for binary increment
string turingMachineIncrement(string tape) {
    int n = tape.length();
    int i = n - 1; // Start from the rightmost bit

    cout << "Initial Tape: " << tape << endl;
    cout << "Simulating Turing Machine transitions:" << endl;

    // Traverse the tape to increment the binary number
    while (i >= 0) {
        if (tape[i] == '0') {
            tape[i] = '1'; // Flip 0 to 1 (no carry)
            cout << "Flip '0' to '1'. Tape: " << tape << endl;
            return tape;   // No carry, return the result
        } else if (tape[i] == '1') {
            tape[i] = '0'; // Flip 1 to 0 and propagate the carry
            cout << "Flip '1' to '0'. Tape: " << tape << endl;
            i--;           // Move left
        }
    }

    // If carry propagates beyond the leftmost bit (e.g., 111 + 1 = 1000)
    tape = "1" + tape;
    cout << "Carry propagated beyond the leftmost bit. New Tape: " << tape << endl;
    return tape;
}

int main() {
    string input;
    cout << "Enter a binary number: ";
    cin >> input;

    // Validate the input binary number
    if (!isValidBinary(input)) {
        cout << "Error: Invalid binary input!" << endl;
    } else {
        string result = turingMachineIncrement(input);
        cout << "Incremented binary number: " << result << endl;
    }

    return 0;
}

