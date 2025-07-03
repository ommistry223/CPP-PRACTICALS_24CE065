#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits> // for input validation

using namespace std;

int main() {
    // Input validation for number of entries
    int num_entries;
    cout << "Enter number of participants: ";
    while (!(cin >> num_entries) || num_entries <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<pair<int, string>> participants;
    
    // Collect participant data
    cout << "Enter name and score for each participant:\n";
    for (int i = 0; i < num_entries; ++i) {
        string name;
        int score;
        
        cout << "Participant " << i+1 << ":\n";
        cout << "Name: ";
        cin >> name;
        
        cout << "Score: ";
        while (!(cin >> score)) {
            cout << "Invalid score. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        participants.emplace_back(score, name);
    }

    // Sort in descending order by score
    sort(participants.rbegin(), participants.rend());

    // Display results
    cout << "\nLeaderboard:\n";
    cout << "-----------------------------------------------\n";
    cout << "Rank\tName\t\tScore\n";
    cout << "-----------------------------------------------\n";
    
    for (size_t i = 0; i < participants.size(); ++i) {
        cout << i+1 << ".\t" << participants[i].second 
             << "\t\t" << participants[i].first << endl;
    }
    cout << "-----------------------------------------------\n";

    return 0;
}