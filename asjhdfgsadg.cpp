#include <iostream>
#include <string>
using namespace std;

int main() {
    string storedDate[100];
    string storedDestinationName[100];
    float storeFareTotal[100];
    string takeDate;
    char askDate;
    int countDate = 0;
    int menuChoice;

    do {
        cout << "\n1. Add info\n";
        cout << "2. Show info\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> menuChoice;

        if (menuChoice == 1) {
            // Ask user if they want to enter a new date
            do {
                cout << "New date (y/n): ";
                cin >> askDate;
                askDate = tolower(askDate);

                if (askDate == 'y') {
                    cout << "Enter date (yyyy/mm/dd): ";
                    cin >> takeDate;
                    storedDate[countDate] = takeDate;
                } else if (askDate == 'n') {
                    if (countDate > 0) {
                        storedDate[countDate] = storedDate[countDate - 1];
                    } else {
                        cout << "No previous date found. Please enter a new one.\n";
                        askDate = 'x'; // force repeat
                    }
                } else {
                    cout << "Invalid input. Type 'y' or 'n'.\n";
                }
            } while (askDate != 'y' && askDate != 'n');

            // Get destination and fare
            cout << "Enter destination name: ";
            cin >> storedDestinationName[countDate];
            cout << "Enter fare price: ";
            cin >> storeFareTotal[countDate];

            countDate++;
        }

        else if (menuChoice == 2) {
            // Display stored entries
            cout << "\nDate\t\tPlace\t\tPrice\n";
            for (int i = 0; i < countDate; i++) {
                cout << storedDate[i] << "\t" << storedDestinationName[i] << "\t\t" << storeFareTotal[i] << endl;
            }
        }

    } while (menuChoice != 3);

    return 0;
}
 