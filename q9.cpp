#include <iostream>
#include <string>
using namespace std;

// Function to simulate the Turing Machine
bool turingMachine(string tape) {
    int n = tape.length();
    int i = 0;

    // Step 1: Ensure the input only contains a, b, c
    for (char ch : tape) {
        if (ch != 'a' && ch != 'b' && ch != 'c') {
            return false; // Invalid character
        }
    }

    while (true) {
        // Mark an 'a' with 'X'
        while (i < n && tape[i] != 'a') i++;
        if (i == n) break; // No more 'a' left to process
        tape[i] = 'X'; // Mark the 'a'
        i++;

        // Match with a 'b' and mark it as 'Y'
        while (i < n && tape[i] != 'b') i++;
        if (i == n || tape[i] != 'b') return false; // 'b' not found
        tape[i] = 'Y'; // Mark the 'b'
        i++;

        // Match with a 'c' and mark it as 'Z'
        while (i < n && tape[i] != 'c') i++;
        if (i == n || tape[i] != 'c') return false; // 'c' not found
        tape[i] = 'Z'; // Mark the 'c'
        i = 0; // Reset to start for the next iteration
    }

    // Check if all characters are marked
    for (char ch : tape) {
        if (ch != 'X' && ch != 'Y' && ch != 'Z') {
            return false; // Unprocessed symbols remain
        }
    }

    return true; // Successfully processed the tape
}

int main() {
    string input;
    cout << "Enter the string (a^n b^n c^n): ";
    cin >> input;

    if (turingMachine(input)) {
        cout << "Accepted: The string is in the language a^n b^n c^n\n";
    } else {
        cout << "Rejected: The string is not in the language a^n b^n c^n\n";
    }

    return 0;
}
