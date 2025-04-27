#include <iostream>
#include <cstdlib>// ni revise ko yung code para di masyado mahaba
#include <string>
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
    cout<<endl;
    cout<<"Bus Ticket Management System"<<endl;
    cout<<"1. New Transaction"<<endl;
    cout<<"2. Log"<<endl;
    cout<<"3. Available Seats"<<endl;
    cout<<"4. Exit"<<endl;
}

void destinationList()
{
    cout<<endl;
    cout<<"Destination"<<endl;
    cout<<"1. SM"<<endl;
    cout<<"2. Pacific"<<endl;
    cout<<"3. Sumacab"<<endl;
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
    string storedDate[256] = {"No date yet"};
    string takeDate; // var for dates

    char destinationType;
    double destination; // destination becomes SM, etc

    string assignedSeat;
    bool seatsArray[4][5];// pwede maging void
    bool seatAssigned;
    int r, c;
    char rowLetter;
    char columnNumber;

    
    int typeOfDiscount;
    double fareTotal;
    
    string destinationName;
    string storedDestinationName[256];
    int countDestination = 0;
    string convertedDestinationName;
    
    double storeFareTotal[20];
    int x = 0;
    int i; // used for iteration for loops
    
    for(r = 0; r < 4; r++) 
    {
        for(c = 0; c < 5; c++) 
        {
            seatsArray[r][c] = true;
        }
    }
    
    for(i = 0; i < 256; i++) 
    {
        storeFareTotal[i] = 0.00;
    } 
    
    for(i = 0; i < 256; i++) 
    {
        storedDate[i] = "No date yet";
        storedDestinationName[i] = "No place yet";
    } 
    
    while(menuChoice != 4)
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
                    cin>>takeDate;// store the date in the array storedDate 
                    break;
                }
                else if(askDate == 'n')
                {
                    storedDate[countDate] = takeDate;

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

                    if(askDate == 'y')
                    {
                        storedDate[countDate] = takeDate; // store the date in the array storedDate 
                        countDate++;
                    }

                    cout<<"Choice: ";
                    cin>>typeOfDiscount;
                    
                    //automatic seat assignment
                    assignedSeat = "";
                    seatAssigned = false;
                    for(r = 0; r < 4; r++) 
                    {
                        if(seatAssigned)

                        break; // stop if already assigned
                        
                        for(c = 0; c < 5; c++) 
                        {
                            if(seatsArray[r][c]) 
                            {
                                seatsArray[r][c] = false;
                                rowLetter = 'A' + r;
                                columnNumber = '1' + c;
                                
                                assignedSeat += rowLetter;
                                assignedSeat += columnNumber;
                                
                                cout<<"Seat "<<assignedSeat<<" automatically assigned."<<endl;
                                seatAssigned = true;
                                
                                break; //to exit inner loop after assignment
                            }
                        }
                    }
                    
                    fareTotal = calculateTotalFare(destination, typeOfDiscount);

                    cout<<endl<<"Total fare is P"<<fareTotal<<endl;

                    if(destinationType == '1') 
                    {
                        storedDestinationName[countDestination] = "SM      ";
                    } 
                    else if(destinationType == '2') 
                    {
                        storedDestinationName[countDestination] = "PACIFIC ";
                    } 
                    else if(destinationType == '3') 
                    {
                        storedDestinationName[countDestination] = "SUMACAB ";
                    } 
                    else if(destinationType == '4') 
                    {
                        storedDestinationName[countDestination] = "STAROSA ";
                    } 
                    else if(destinationType == '5') 
                    {
                        storedDestinationName[countDestination] = "ZARAGOZA";
                    } 
                    else if(destinationType == '6') 
                    {
                        storedDestinationName[countDestination] = "LAPAZ   ";
                    } 
                    else if(destinationType == '7') 
                    {
                        storedDestinationName[countDestination] = "TARLAC  ";
                    } 

                    countDestination++;

                    storeFareTotal[x] += fareTotal;
                    x++;
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
            cout<<"Date\t\t\tPlace\t\t\tPrice"<<endl;
            for(i = 0; i <= 10; i++)
            {
                cout<<storedDate[i]<<"   "<<"\t|\t"<<storedDestinationName[i]<<"   "<<"\t|\t"<<storeFareTotal[i]<<endl;
            }
        } 
        else if(menuChoice == 3)
        {
            cout<<"Seat Availability:"<<endl;
            
            for(r = 0; r < 4; r++) 
            {
                for(c = 0; c < 5; c++) 
                {
                    rowLetter = 'A' + r;
                    columnNumber = c + 1;

                    cout<<rowLetter<<columnNumber<<": ";

                    if(seatsArray[r][c]) 
                    {
                        cout<<"Available"; // yun lang try monga hanapin send ko sayo to
                    } 
                    else 
                    {
                        cout<<"Not Available"; // eto yung ako nag lipat
                    }
                    cout<<endl;
                } 
                cout<<endl;
            }
        }
        else
        {
            cout<<"Thank you!"<<endl;
            break;
        }
    } // end of while loop menu choice

    return EXIT_SUCCESS;
} // end of main