#include <iostream>
#include <cstdlib>// ni revise ko yung code para di masyado mahaba

/* 
    2 void ✅
    1 function return ❎ 2 pa
    1 for loop ✅
    1 do while loop ✅
    1 while loop ✅
    1 one dimentional ✅
    1 switch ✅ pero may sobrang isa ❎
    1 nested ✅?
    1 bi dimentional ❎ 
*/

#define SENIOR 0.30
#define PWD 0.25
#define STUDENT 0.20
// FOR DISCOUNTS
#define SM 4.0
#define PACIFIC 4.0
#define SUMACAB 5.4
#define STAROSA 7.1
#define ZARAGOZA 24
#define LAPAZ 32
#define TARLAC 49
#define INVALID_DESTINATION 0.0
// FOR DESTINATIONS DISTANCE IN KM
#define baseFare 15.0
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
    cout<<"8. Back"<<endl; 
}

void discountTypeList()
{
    cout<<endl;
    cout<<"Discount Type"<<endl;
    cout<<"1. Senior"<<endl;
    cout<<"2. PWD"<<endl;
    cout<<"3. Student"<<endl;
    cout<<"4. None"<<endl;
}

double convertToDestination(char destinationType) 
{
    switch(destinationType) {
        case '1':
            return SM;

            break;
        case '2':
            return PACIFIC;

            break;
        case '3':
            return SUMACAB;

            break;
        case '4':
            return STAROSA;

            break;
        case '5':
            return ZARAGOZA;

            break;
        case '6':
            return LAPAZ;

            break;
        case '7':
            return TARLAC;

            break;
        default:
            return INVALID_DESTINATION;

            break;
    }
}

double calculateTotalFare(double placeDest, int typeDisc)
{
    double fare;

    if(placeDest >= baseDistance) 
    {
        fare = baseFare + (placeDest - baseDistance) * additionalRate;
    }
    else if(placeDest == INVALID_DESTINATION) 
    {
        return 0;
    }
    else
    {
        fare = baseFare;
    }
    
    switch(typeDisc)
    {
        case 1:
            fare = fare - (fare * SENIOR);
        
            break;
        case 2:
            fare = fare - (fare * PWD);
        
            break;
        case 3:
            fare = fare - (fare * STUDENT);
        
            break;
        default:
            // default discount type none if tinayp na discount is greater than or equal to 4
            break;
    }

    return fare;
}

int main()
{
    int menuChoice, countDate = 0;
    char askDate;
    string storedDate[256];
    string takeDate; // var for dates

    char destinationType;
    double destination; // destination becomes SM, etc

    int typeOfDiscount;
    double fareTotal;

    while(menuChoice != 5)
    {
        menu();

        cout<<"Choice: ";
        cin>>menuChoice;

        if(menuChoice == 1)
        {
            while(askDate != 'y' || askDate != 'n')
            {
                cout<<"New date (y/n): ";
                cin>>askDate;

                askDate = tolower(askDate);

                if(askDate == 'y')
                {
                    cout<<"Enter date: ";
                    cin>>takeDate;

                    storedDate[countDate] += takeDate; // store the date in the array storedDate 
                    
                    countDate++;
                    break;
                }
                else if(askDate == 'n')
                {
                    storedDate[countDate] += takeDate;

                    countDate++;
                    break;
                }
                else
                {
                    cout<<"Invalid answer try again"<<endl<<endl;
                }
            }
            
            do
            {
                destinationList();

                cout<<"Enter destination: ";
                cin>>destinationType;
                
                destination = convertToDestination(destinationType);

                if(destinationType >= '1' && destinationType <= '7')
                {
                    discountTypeList();

                    cout<<"Choice: ";
                    cin>>typeOfDiscount;

                    fareTotal = calculateTotalFare(destination, typeOfDiscount);

                    cout<<"Total fare is P"<<fareTotal<<endl;
                } 
                else if(destinationType == '8')
                {
                    cout<<endl;
                }
                else
                {
                    cout<<"Invalid try again"<<endl;
                }
            }while(destinationType != '8'); // end of loop for choosing destination
        }
        else if(menuChoice == 2)
        {
            cout<<"Date"<<endl;
            for(int i = 0; i <= countDate; i++)
            {
                cout<<storedDate[i]<<endl;
            }
        } 
        else
        {
            break;
        }
    } // end of while loop menu choice

    return EXIT_SUCCESS;
} // end of main