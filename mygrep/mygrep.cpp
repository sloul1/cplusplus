// Linux grep like tool 'mygrep' in C++

// Five planned increments:
// 1st increment: Create 

// Compile: 
// $ g++ -o mygrep mygrep.cpp

// Run:
// $ ./mygrep

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to search for a string in a given file
void processFile(const string& filename, const string& searchString, bool lineNumbers, int& totalMatches) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    int lineno = 1;
    
    while (getline(file, line)) {
        size_t pos = line.find(searchString);
        if (pos != string::npos) {
            if (lineNumbers) {
                cout << lineno << ": " << line << endl;
            } else {
                cout << line << endl;
            }
            totalMatches++;
        }
        lineno++;
    }
    file.close();
}

// Function to process command-line arguments
void processArguments(int argc, char* argv[]) {
    bool lineNumbers = false;
    bool countOccurrences = false;

    int argIndex = 1;
    while (argIndex < argc && argv[argIndex][0] == '-') {
        string option = argv[argIndex];
        for (char c : option.substr(1)) {
            switch(c) {
                case 'l':
                    lineNumbers = true;
                    break;
                case 'o':
                    countOccurrences = true;
                    break;
                default:
                    cerr << "Unknown option: -" << c << endl;
                    return;
            }
        }
        argIndex++;
    }

    if (argIndex >= argc) {
        cerr << "Usage: program [-l] [-o] <search_string> <file1> ... <filen>" << endl;
        return;
    }

    string searchString = argv[argIndex++];
    vector<string> files;
    while (argIndex < argc) {
        files.push_back(argv[argIndex++]);
    }

    int totalMatches = 0;
    for (const string& file : files) {
        processFile(file, searchString, lineNumbers, totalMatches);
    }

    if (countOccurrences) {
        cout << "Occurrences of lines containing \"" << searchString << "\": " << totalMatches << endl;
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