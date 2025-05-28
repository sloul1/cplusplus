// Linux grep like tool 'mygrep' in C++

// Compile: 
// g++ -o mygrep mygrep_03.cpp

// Usage: ./mygrep <search_string> <file1> [file2 ...]
// or for interactive search 
// ./mygrep

// Five planned increments:

/*
1/5 increment: Basic Interactive String Search

The program asks the user for a "large" string 
from which to search for a smaller string. The latter can be found anywhere in the large string. If the string to be searched for is found in the large string, its occurrence is reported starting from position 0. In all cases, a message is printed that the string has been found.

2/5 increment: Command Line Functionality

The increment must also include the functionality of the previous increment, i.e. if the program is still started with just the program file (binary) name `./mygrep`.

If the program is started from the command line as described below, its usage will begin to resemble basic grep usage with command line arguments.

Example run:

./mygrep following man_grep_plain_ASCII.txt 
     The following options are available:
     The grep utility exits with one of the following values:

The program goes through the contents of the ASCII file given to it line by line and if the searched string "following" (2nd command line argument) is found somewhere within each line, the line in question is printed; otherwise, it is not. The operation is exactly the same as the operation of grep in its simplest use.

3/5 increment: simple statistical analysis

mygrep should be able to run so that:

- If desired, it prints the line numbers in a large file in front of the lines found

- If desired, at the end of the run, mygrep prints information about how many lines in the file contained the string you searched for.

Both of these features are controlled using command line arguments: if line numbering is desired, it is specified using a command line argument; the same applies to counting the number of lines.

Example run:

./mygrep -olo following man_grep_plain_ASCII.txt 
32:     The following options are available:
245:     The grep utility exits with one of the following values:

Occurrences of lines containing "following": 2

As you can see from the example run, these additional optional options are provided in the form -olo. You can interpret this to mean that "-o" tells that the desired options that affect the execution of the program are listed after it, and l = line numbering and o = occurrences. Now there are four command line arguments instead of three.

If the option specification is -ol, only the line numbers are printed, and if it is -oo, only the number of lines that have occurred is printed. The user can then specify these options in a selective manner.

Note that previous increments must also work!
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