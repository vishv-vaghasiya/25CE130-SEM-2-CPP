#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("input.txt"); // Change file name if needed

    // Error handling
    if (!file) {
        cout << "Error: Unable to open file!" << endl;
        return 1;
    }

    string line;
    int lineCount = 0, wordCount = 0, charCount = 0;

    while (getline(file, line)) {
        lineCount++;  // Count lines

        bool inWord = false;

        for (int i = 0; i < static_cast<int>(line.length()); i++) {
            charCount++; // Count characters

            // Check if character is part of a word
            if (line[i] != ' ' && line[i] != '\t') {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }

        // Count newline character
        charCount++;
    }

    file.close();

    cout << "Total Lines: " << lineCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Characters: " << charCount << endl;

    return 0;
}
