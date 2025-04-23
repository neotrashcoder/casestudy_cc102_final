#include <iostream> // eto nung magulo yung loop experiment lang
#include <cstdlib>

using namespace std;

void menu()
{
    cout<<endl;
    cout<<"Bus Ticket Management System"<<endl;
    cout<<"1. New Transaction"<<endl;
    cout<<"2. Log"<<endl;
    cout<<"3. Available Seats"<<endl;
    cout<<"4. Summary of sales"<<endl;
    cout<<"5. Exit"<<endl;
}

void destinationList()
{
    cout<<endl;
    cout<<"Destination"<<endl;
    cout<<"1. SM"<<endl;
    cout<<"2. Pacific"<<endl;
    cout<<"3. Sumacab Campus"<<endl;
    cout<<"4. Sta Rosa"<<endl;
    cout<<"5. Zaragoza"<<endl;
    cout<<"6. La Paz"<<endl;
    cout<<"7. Tarlac City"<<endl;
}

int main()
{
    int menuChoice, newTrCh, destination;
    char newDate;
    string date;

    while(menuChoice != 5)
    {
        menu();

        cout<<"enter choice: ";
        cin>>menuChoice;

        if(menuChoice == 1)
        {
            cout<<"new date? (y/n): ";
            cin>>newDate;

            if(newDate == 'y')
            {
                cout<<"Enter date: ";
                cin>>date;

                cout<<endl;
                cout<<"new transaction"<<endl;
                cout<<"1. destination"<<endl;
                cout<<"2. back"<<endl;
                
                cout<<"enter choice: ";
                cin>>newTrCh;

                if(newTrCh == 1)
                {
                    destinationList();

                    cout<<"enter destination: ";
                    cin>>destination;

                    switch(destination)
                    {
                        case 1:
                            /* code */
                            break;
                        case 2:
                            /* code */
                            break;
                        case 3:
                            /* code */
                            break;
                        case 4:
                            /* code */
                            break;
                        case 5:
                            /* code */
                            break;
                        case 6:
                            /* code */
                            break;
                        case 7:
                            /* code */
                            break;
                        default:
                            break;
                    }
                }
            }// end of if newdate is yes
            else if(newDate == 'n')
            {
                cout<<endl;
                cout<<"new transaction"<<endl;
                cout<<"1. destination"<<endl;
                cout<<"2. back"<<endl;

                cout<<"enter choice: ";
                cin>>newTrCh;

                if(newTrCh == 1)
                {
                    destinationList();

                    cout<<"enter destination: ";
                    cin>>destination;

                    switch(destination)
                    {
                        case 1:
                            /* code */
                            break;
                        case 2:
                            /* code */
                            break;
                        case 3:
                            /* code */
                            break;
                        case 4:
                            /* code */
                            break;
                        case 5:
                            /* code */
                            break;
                        case 6:
                            /* code */
                            break;
                        case 7:
                            /* code */
                            break;
                        default:
                            break;
                    }// end of destination switch case
                }// end of if newtransaction
            }// end of if newdate is no
        }// end of menu choice if
    }// end of menu choice while loop

    return EXIT_SUCCESS;
}// end of main