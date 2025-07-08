#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// This function will be used to remove commas from the numbers in the txt file
string removeCommas(const string& str) {
    string result;
    for (char ch : str) {
        if (ch != ',') {
            result += ch;
        }
        return result;
    }
}

int main() {
    string filename;
    cout << "Enter the filename: "; // Enter directory of babynames2010s.txt
    getline(cin, filename);

    ifstream inputFile(filename);
    ofstream boyFile("boynames.txt");
    ofstream girlFile("girlnames.txt");

    if (!inputFile || !boyFile || !girlFile) {
        cerr << "Cannot open file" << endl;
        return 1;
    }
    string rankStr, boyName, boyCountStr, girlName, girlCountStr;
    while (inputFile >> rankStr >> boyName >> boyCountStr >> girlName >> girlCountStr) {
        int rank = stoi(rankStr); // Converting strings to integers
        int boyCount = stoi(removeCommas(boyCountStr));
        int girlCount = stoi(removeCommas(girlCountStr));

        boyFile << rank << " " << boyName << " " << boyCount << endl;
        girlFile << rank << " " << girlName << " " << girlCount << endl;
    }

    cout << "boynames.txt and girlnames.txt were created" << endl;

    inputFile.close();
    boyFile.close();
    girlFile.close();

    return 0;
}
