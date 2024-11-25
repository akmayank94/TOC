#include <iostream>
#include <string>
#include <set>
using namespace std;

// Simulating FAs for L1 and L2
bool simulateL1(const string &w) {
    // FA for L1: Strings with an even number of 'a's
    int countA = 0;
    for (char c : w) {
        if (c == 'a') countA++;
    }
    return countA % 2 == 0;
}

bool simulateL2(const string &w) {
    // FA for L2: Strings with an odd number of 'b's
    int countB = 0;
    for (char c : w) {
        if (c == 'b') countB++;
    }
    return countB % 2 != 0;
}

// Simulate Union (L1 U L2)
bool simulateUnion(const string &w) {
    return simulateL1(w) || simulateL2(w);
}

// Simulate Intersection (L1 ∩ L2)
bool simulateIntersection(const string &w) {
    return simulateL1(w) && simulateL2(w);
}

// Simulate Concatenation (L1 L2)
bool simulateConcatenation(const string &w) {
    for (size_t i = 0; i <= w.size(); i++) {
        string part1 = w.substr(0, i);
        string part2 = w.substr(i);
        if (simulateL1(part1) && simulateL2(part2)) {
            return true;
        }
    }
    return false;
}

// Main function
int main() {
    string w;
    cout << "Enter a string over {a, b}: ";
    cin >> w;

    cout << "Simulating L1 (even number of 'a's): " 
         << (simulateL1(w) ? "Accepted" : "Rejected") << endl;

    cout << "Simulating L2 (odd number of 'b's): " 
         << (simulateL2(w) ? "Accepted" : "Rejected") << endl;

    cout << "Union (L1 U L2): " 
         << (simulateUnion(w) ? "Accepted" : "Rejected") << endl;

    cout << "Intersection (L1 ∩ L2): " 
         << (simulateIntersection(w) ? "Accepted" : "Rejected") << endl;

    cout << "Concatenation (L1 L2): " 
         << (simulateConcatenation(w) ? "Accepted" : "Rejected") << endl;

    return 0;
}
