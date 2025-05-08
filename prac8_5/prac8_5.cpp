#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class DirectoryManager {
private:
    map<string, vector<string>> directory;

    bool folder_exists(const string& folder_name) const {
        return directory.find(folder_name) != directory.end();
    }

    bool file_exists(const string& folder_name, const string& file_name) const {
        const auto& files = directory.at(folder_name);
        return find(files.begin(), files.end(), file_name) != files.end();
    }

public:
    void create_folder(const string& folder_name) {
        if (folder_exists(folder_name)) {
            cout << "Error: Folder '" << folder_name << "' already exists.\n";
            return;
        }
        directory[folder_name];
        cout << "Folder '" << folder_name << "' created successfully.\n";
    }

    void add_file(const string& folder_name, const string& file_name) {
        if (!folder_exists(folder_name)) {
            cout << "Error: Folder '" << folder_name << "' doesn't exist.\n";
            return;
        }
        if (file_exists(folder_name, file_name)) {
            cout << "Error: File '" << file_name << "' already exists in folder '" 
                 << folder_name << "'.\n";
            return;
        }
        directory[folder_name].push_back(file_name);
        cout << "File '" << file_name << "' added to folder '" 
             << folder_name << "' successfully.\n";
    }

    void list_directory() const {
        if (directory.empty()) {
            cout << "Directory is empty.\n";
            return;
        }

        cout << "\nDirectory Structure:\n";
        cout << setfill('-') << setw(40) << "" << setfill(' ') << "\n";

        // C++11 compatible loop without structured bindings
        for (const auto& folder_entry : directory) {
            cout << "[" << folder_entry.first << "]\n";
            
            if (folder_entry.second.empty()) {
                cout << "  (empty)\n";
            } else {
                for (const auto& file : folder_entry.second) {
                    cout << "  - " << file << "\n";
                }
            }
            cout << "\n";
        }
        cout << setfill('-') << setw(40) << "" << setfill(' ') << "\n";
    }
};

int main() {
    DirectoryManager manager;
    string command;

    cout << "Directory Management System\n";
    cout << "Commands: mkdir <name>, add <folder> <file>, ls, exit\n\n";

    while (true) {
        cout << "> ";
        cin >> command;

        if (command == "mkdir") {
            string folder_name;
            cin >> folder_name;
            manager.create_folder(folder_name);
        } 
        else if (command == "add") {
            string folder_name, file_name;
            cin >> folder_name >> file_name;
            manager.add_file(folder_name, file_name);
        } 
        else if (command == "ls") {
            manager.list_directory();
        } 
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Invalid command. Try: mkdir, add, ls, or exit\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Exiting directory manager. Goodbye!\n";
    return 0;
}