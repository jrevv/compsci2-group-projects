#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int master_account = 0;
    int project_accounts[10] = {0};
    int* users[100];

    for (int i = 0; i < 100; ++i) {
        users[i] = &master_account;
    }

    char choice;
    do {
        cout << "\nU)ser A)dministrator Q)uit: ";
        cin >> choice;
        choice = toupper(choice);

        if (choice == 'U') {
            int id, copies;
            cout << "Enter user ID (0-99): ";
            cin >> id;
            if (id < 0 || id >= 100) {
                cout << "The user ID you entered is invalid.\n";
                continue;
            }
            cout << "Enter number of copies: ";
            cin >> copies;
            *users[id] += copies;
            cout << "Copies added.\n";
        }
        else if (choice == 'A') {
            char admin_choice;
            cout << "\nB)alance M)aster P)roject: ";
            cin >> admin_choice;
            admin_choice = toupper(admin_choice);

            if (admin_choice == 'B') {
                cout << "\nMaster account balance: " << master_account << "\n";
                for (int i = 0; i < 10; ++i) {
                    cout << "Project " << i << " balance: " << project_accounts[i] << "\n";
                }
            }
            else if (admin_choice == 'M') {
                int id;
                cout << "Enter user ID to link to master account: ";
                cin >> id;
                if (id < 0 || id >= 100) {
                    cout << "The user ID you entered is invalid.\n";
                    continue;
                }
                users[id] = &master_account;
                cout << "User " << id << " linked to master account.\n";
            }
            else if (admin_choice == 'P') {
                int user_id, project_id;
                cout << "Enter user ID: ";
                cin >> user_id;
                cout << "Enter project ID (0-9): ";
                cin >> project_id;
                if (user_id < 0 || user_id >= 100 || project_id < 0 || project_id > 9) {
                    cout << "Invalid ID(s).\n";
                    continue;
                }
                users[user_id] = &project_accounts[project_id];
                cout << "User " << user_id << " linked to project account " << project_id << ".\n";
            }
            else {
                cout << "Invalid admin option.\n";
            }
        }
        else if (choice != 'Q') {
            cout << "Invalid menu option.\n";
        }
    }
    while (choice != 'Q');

    cout << "Program ended.\n";
    return 0;
}
