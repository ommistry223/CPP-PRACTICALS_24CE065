#include <iostream>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;

// Function to normalize word by converting to lowercase and removing punctuation
string normalize_word(const string& word) {
    string normalized;
    for (char ch : word) {
        if (isalpha(ch)) {
            normalized += tolower(ch);
        }
    }
    return normalized;
}

int main() {
    cout << "Enter a sentence: ";
    string input;
    getline(cin, input);

    map<string, int> word_frequency;
    istringstream iss(input);
    string word;

    while (iss >> word) {
        string normalized = normalize_word(word);
        if (!normalized.empty()) {
            word_frequency[normalized]++;
        }
    }

    cout << "\nWord Frequency:\n";
    cout << "--------------\n";
    for (const auto& entry : word_frequency) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}