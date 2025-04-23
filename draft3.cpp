#include <iostream>
#include <cstdlib>// medyo magulo kaya nag next ako sa draft 4

#define SENIOR 0.30
#define PWD 0.25
#define STUDENT 0.20
// FOR DISCOUNTS
#define SM 4.0
#define PACIFIC 4.0
#define SUMACAB 5.0
#define STAROSA 7.1
#define ZARAGOZA 24
#define LAPAZ 32
#define TARLAC 49
// FOR DESTINATIONS DISTANCE IN KM
#define baseFare 16.0
#define baseDistance 4.0
#define additionalRate 1.5
// FOR FARE

using namespace std;

void menu()
{
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

double discount(int dType, double subFare)
{
    switch(dType)
    {
        case 1:
            subFare = subFare - (subFare * SENIOR);

            cout<<"Total fare is ₱"<<subFare<<endl;
            break;
        case 2:
            subFare = subFare - (subFare * PWD);

            cout<<"Total fare is ₱"<<subFare<<endl;
            break;
        case 3:
            subFare = subFare - (subFare * STUDENT);

            cout<<"Total fare is ₱"<<subFare<<endl;
            break;
        case 4:
            cout<<"Total fare is ₱"<<subFare<<endl;
            break;
        default:
            cout<<"Inavid discount choice"<<endl;
            break;
    }

    return subFare;
}

int main()
{
    int menuChoice, newTrCh, destination, discType, dateCounter;
    char newDate;
    string takeDate;
    string storeDate[32];
    double fare, discountedFare;

    menuChoice = 0;
    while(menuChoice != 5)
    {
        menu();

        cout<<"Enter choice: ";
        cin>>menuChoice;
        
        if(menuChoice == 1)
        {
            cout<<"New date? (y/n): ";
            cin>>newDate;

            newDate = tolower(newDate);

            if(newDate == 'y')
            {
                dateCounter++;
                
                cout<<"Enter date (YYYY/MM/DD): ";
                cin>>takeDate;

                storeDate[dateCounter] = takeDate;

                newTrCh = 0;
                do
                {
                    cout<<endl;
                    cout<<"New transaction"<<endl;
                    cout<<"1. Destination"<<endl;
                    cout<<"2. Back"<<endl;
                    
                    cout<<"Enter choice: ";
                    cin>>newTrCh;

                    if(newTrCh == 1)
                    {
                        destinationList();

                        cout<<"Enter destination: ";
                        cin>>destination;

                        switch(destination)
                        {
                            case 1:
                                if(SM <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (SM - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            case 2:
                                if(PACIFIC <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (PACIFIC - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            case 3:
                                if(SUMACAB <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (SUMACAB - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            case 4:
                                if(STAROSA <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (STAROSA - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            case 5:
                                if(ZARAGOZA <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (ZARAGOZA - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            case 6:
                                if(LAPAZ <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (LAPAZ - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            case 7:
                                if(TARLAC <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (TARLAC - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            default:
                                break;
                        }
                    }// end of if else for calculating discount
                }while(newTrCh != 2);// while loop for new transaction
            }// end of if newdate is yes
            else if(newDate == 'n')
            {
                newTrCh = 0;
                do
                {
                    cout<<endl;
                    cout<<"New transaction"<<endl;
                    cout<<"1. Destination"<<endl;
                    cout<<"2. Back"<<endl;
                    
                    cout<<"Enter choice: ";
                    cin>>newTrCh;

                    if(newTrCh == 1)
                    {
                        destinationList();

                        cout<<"Enter destination: ";
                        cin>>destination;

                        switch(destination)
                        {
                            case 1:
                                if(SM <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (SM - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            case 2:
                                if(PACIFIC <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (PACIFIC - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            case 3:
                                if(SUMACAB <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (SUMACAB - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            case 4:
                                if(STAROSA <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (STAROSA - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            case 5:
                                if(ZARAGOZA <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (ZARAGOZA - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            case 6:
                                if(LAPAZ <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (LAPAZ - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            case 7:
                                if(TARLAC <= baseDistance) 
                                {
                                    fare = baseFare;
                                }else{
                                    fare = baseFare + (TARLAC - baseDistance) * additionalRate;
                                }
                                
                                cout<<endl;
                                cout<<"Discount Type"<<endl;
                                cout<<"1. Senior"<<endl;
                                cout<<"2. PWD"<<endl;
                                cout<<"3. Student"<<endl;
                                cout<<"4. None"<<endl;
                                
                                cout<<"Enter: ";
                                cin>>discType;

                                discountedFare = discount(discType, fare);
                
                                break;
                            default:
                                cout<<"Error. Please try again"<<endl<<endl;
                                break;
                        }
                    }// end of if else for calculating discount
                }while(newTrCh != 2);// while loop for new transaction
            }// end of if newdate is no
        }// end of menu choice if
    }// end of menu choice while loop
    if(menuChoice == 5)
    {
        for(int i = 0; i < 10; i++)
        {
            cout<<storeDate[i]<<endl;
        }
    }
    
    
    return EXIT_SUCCESS;
}// end of main