#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

// Helper function to remove leading and trailing non-alphabetic characters
string cleanWord(const string& word) {
    int start = 0;
    while (start < word.size() && !isalpha(word[start])) ++start;

    int end = word.size() - 1;
    while (end >= 0 && !isalpha(word[end])) --end;

    if (start > end) return "";
    return word.substr(start, end - start + 1);
}

int main() {
    string line;
    getline(cin, line);

    map<string, int> freq;
    stringstream ss(line);
    string rawWord;

    while (ss >> rawWord) {
        string word = cleanWord(rawWord);
        if (word.empty()) continue;

        // Convert to lowercase
        for (auto &c : word) c = tolower(static_cast<unsigned char>(c));

        freq[word]++;
    }

    for (const auto &p : freq)
        cout << p.first << ": " << p.second << endl;

    return 0;
}