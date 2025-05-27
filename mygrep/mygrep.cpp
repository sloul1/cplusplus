// Linux grep like tool 'mygrep'in C++

// Five planned increments:
// 1st increment: Create 

// Compile: 
// $ g++ -o mygrep mygrep.cpp

// Run:
// $ ./mygrep

#include <iostream>
//#include <string>

using namespace std;

int main ()
{
    
    string userInput = ""; // user input
    string searchString = ""; // search string

    cout << "Give a string from which to search for: ";
    getline(cin, userInput);

    cout << "Give search string: ";
    getline(cin, searchString);

    // Check if the contents of search string `searchString` is found in the user input string `userInput`.
    size_t pos = userInput.find(searchString);
    
    if (pos != string::npos) {
        cout << "The string \"" << searchString 
                  << "\" was found at position " << pos << ".\n";
    } else {
        cout << "The string \"" << searchString 
                  << "\" was NOT found in \"" << userInput << "\"\n";
    }

   return 0;
}

