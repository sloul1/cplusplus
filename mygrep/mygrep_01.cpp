// Linux grep like tool 'mygrep' in C++

// Five planned increments.

/*
1st increment: The program asks the user for a "large" string 
from which to search for a smaller string. The latter can be found anywhere in the large string. If the string to be searched for is found in the large string, its occurrence is reported starting from position 0. In all cases, a message is printed that the string has been found.
*/

// Compile: 
// g++ -o mygrep mygrep_01.cpp

// Run:
// ./mygrep


#include <iostream>
#include <string>

using namespace std;

int main() {
    string userInput;
    string searchString;

    // Get user input for large and small strings
    cout << "Give a string from which to search for: ";
    getline(cin, userInput);

    cout << "Give search string: ";
    getline(cin, searchString);

    size_t position = 0;
    bool found = false;

    // Search for all occurrences of `searchString` in `userInput`
    while ((position = userInput.find(searchString, position)) != string::npos) {
        cout << "The string \"" << searchString 
             << "\" was found at position " << position << '\n';
        position++;  // Move to the next character after the current match
        found = true;
    }

    if (!found) {
        cout << "The string \"" << searchString 
             << "\" was NOT found in \"" << userInput << "\"\n";
    } else {
        cout << "All occurrences of the substring have been reported.\n";
    }

    return 0;
}