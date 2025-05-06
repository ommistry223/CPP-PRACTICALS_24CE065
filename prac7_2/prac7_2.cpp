#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

struct Stats {
    size_t lines = 0, words = 0, chars = 0;
};

Stats analyze_file(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    Stats stats;
    string line;

    while (getline(file, line)) {
        stats.lines++;
        stats.chars += line.length() + 1; // +1 for newline
        
        bool in_word = false;
        for (char c : line) {
            if (isspace(c)) in_word = false;
            else if (!in_word) { in_word = true; stats.words++; }
        }
    }

    return stats;
}

int main() {
    const string filename = "demo.txt";

    Stats s = analyze_file(filename);
    cout << "Lines: " << s.lines << "\nWords: " << s.words 
         << "\nChars: " << s.chars << endl;

    return 0;
}