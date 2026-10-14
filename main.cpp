#include <iostream>
#include <stack>
#include <limits>
using namespace std;
/*
    Anthony Diaz / adiaz6040@sdsu.edu
    CS 210 / Scovil
    Assignment 4 - De-Recursion
*/

// Asks whether to run another calculation. Accepts Y/y/N/n and re-prompts otherwise.
bool askToContinue() {
    char userInput;
    while (true) {
        cout << "Want to calculate another factorial? (Y/N)" << endl;
        cin >> userInput;
        if (cin.fail() == true) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again." << endl;
        } else if (userInput == 'Y' || userInput == 'y') {
            return true;
        } else if (userInput == 'N' || userInput == 'n') {
            return false;
        }
        else {
            cout << "Invalid input. Try again." << endl;

        }
    }
}
// Prompts until the user enters an integer from 0 to 20.
// Clears the error flag and discards bad input so a non-numeric entry
// (like "abc") doesn't cause an infinite loop
int userInput() {
    int userNum;
    bool validInput = false;
    do {
        cout << "Please enter an integer (0-20): ";
        cin >> userNum;
        if (cin.fail()) {
            cin.clear(); // reset the error flag so cin can be used again
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the bad input
            validInput = false;
            cout << "Invalid input. Try again." << endl;
        }
        else if (userNum < 0 || userNum > 20) {
            cout << "Invalid input. Try again." << endl;
            validInput = false;
        } else {
            validInput = true;
        }
    }   while (!validInput);
    return userNum;
}
void printName() {
    cout << "Anthony Diaz" << endl;
    cout << "ID : 134646574" << endl;
    cout << "CS210 - Assignment 4" << endl;
}
// Using unsigned long long because 20!
// (about 2.4 x 10^18) overflows a 32-bit int.
// 20 is the largest input whose factorial
// still fits in an unsigned long long.
class Factorial {
public:
    unsigned long long calculate(int num) {
        stack<int> s;
        for (int i = 1; i <= num; i++) {
            s.push(i);
        }
        unsigned long long accumulator = 1;
        while (!s.empty()) {
            int currentValue = s.top();
            s.pop();
            accumulator *= currentValue;
        }
        return accumulator;
    }
};
int main() {
    printName();
    Factorial f;
    // Main loop: get a number,
    // compute its factorial, then ask whether to repeat
    while (true) {
        int userSelection = userInput();
        unsigned long long result = f.calculate(userSelection);
        cout << "The factorial of " << userSelection
             << " is " << result << "." << endl;
        if (!askToContinue()) {
            break;
        }
    }
    return 0;
}