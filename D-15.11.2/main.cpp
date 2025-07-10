#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file";
        return 1;
    }

    unordered_map<string, int> word_counts;
    string word;

    while (infile >> word) {
        ++word_counts[word];
    }

    infile.close();

    cout << "Number of times each word occurs in the file: ";
    for (const auto& pair : word_counts) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
