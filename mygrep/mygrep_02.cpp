// Linux grep like tool 'mygrep' in C++

// Compile: 
// g++ -o mygrep mygrep_02.cpp

// Usage: ./mygrep <search_string> <file1> [file2 ...]
// or for interactive search 
// ./mygrep

// Five planned increments:

/*
1/5 increment: The program asks the user for a "large" string 
from which to search for a smaller string. The latter can be found anywhere in the large string. If the string to be searched for is found in the large string, its occurrence is reported starting from position 0. In all cases, a message is printed that the string has been found.

2/5 increment:

The increment must also include the functionality of the previous increment, i.e. if the program is still started with just the program file (binary) name `./mygrep`.

If the program is started from the command line as described below, its usage will begin to resemble basic grep usage with command line arguments.

./mygrep following man_grep_plain_ASCII.txt 
     The following options are available:
     The grep utility exits with one of the following values:

The program goes through the contents of the ASCII file given to it line by line and if the searched string "following" (2nd command line argument) is found somewhere within each line, the line in question is printed; otherwise, it is not. The operation is exactly the same as the operation of grep in its simplest use.

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to search for a string in a given file
void searchInFile(const string& filePath, const string& searchString) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Could not open file: " << filePath << endl;
        return;
    }

    string line;
    
    while (getline(file, line)) {
        if (line.find(searchString) != string::npos) {
            cout << line << '\n';
        }
    }

    file.close();
}

// Function to process command-line arguments
void processArguments(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <search_string> <file1> [file2 ...]" << endl;
        return;
    }

    string searchString(argv[1]);

    for (int i = 2; i < argc; ++i) {
        searchInFile(argv[i], searchString);
    }
}

// Interactive function to search within a user input string
void interactiveSearch() {
    string userInput, searchString;

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
}

// Main function to choose between interactive or file-based search
int main(int argc, char* argv[]) {
    if (argc > 1) {
        processArguments(argc, argv);
    } else {
        cout << "No files provided. Starting interactive mode." << endl;
        interactiveSearch();
    }

    return 0;
}