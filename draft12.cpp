#include <iostream>
#include <cstdlib>

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

void showMenu()
{
    cout<<"Bus Ticket Management System"<<endl;
    cout<<"1. New Transaction"<<endl;
    cout<<"2. Log"<<endl;
    cout<<"3. Available Seats"<<endl;
    cout<<"4. Exit"<<endl;
}

void showDestinationList()
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

void showDiscountTypeList()
{
    cout<<endl;
    cout<<"Discount Type"<<endl;
    cout<<"1. Senior"<<endl;
    cout<<"2. PWD"<<endl;
    cout<<"3. Student"<<endl;
    cout<<"4. None"<<endl;
}

double convertToDestinationDistance(char destinationTypeDistance)
{
    switch(destinationTypeDistance)
    {
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

string convertToDestinationName(char destinationTypeName)
{
    string desName;

    if(destinationTypeName == '1')
    {
        desName = "SM      ";

        return desName;
    }
    else if(destinationTypeName == '2')
    {
        desName = "PACIFIC ";

        return desName;
    }
    else if(destinationTypeName == '3')
    {
        desName = "SUMACAB ";

        return desName;
    }
    else if(destinationTypeName == '4')
    {
        desName = "STAROSA ";

        return desName;
    }
    else if(destinationTypeName == '5')
    {
        desName = "ZARAGOZA";

        return desName;
    }
    else if(destinationTypeName == '6')
    {
        desName = "LAPAZ   ";

        return desName;
    }
    else if(destinationTypeName == '7')
    {
        desName = "TARLAC  ";

        return desName;
    }

    return desName;
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
    string storeDate[256];
    string takeDate; // var related to dates

    char destinationType;
    double destination; // destination becomes SM, etc
    string destinationName;
    string storeDestinationName[256];
    int countDestination = 0; // var related to destination

    int typeOfDiscount;
    double fareTotal;
    double storeFareTotal[256];
    int countFare = 0; // var for related to fare

    int countLimit = 0;
    int i; // used for loop iteration

    int r, c;
    string assignedSeat;
    bool seatsArray[4][5];
    char rowLetter;
    bool seatAssigned;
    int columnNumber; // var related to seats

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
        storeDate[i] = "No date yet";
        storeDestinationName[i] = "No place yet";
    }

    while(menuChoice != 4)
    {
        showMenu();

        cout<<"Choice: ";
        cin>>menuChoice;

        if(menuChoice == 1)
        {
            while(askDate != 'y' || askDate != 'n')
            {
                cout<<"New date? (y/n): ";
                cin>>askDate;

                askDate = tolower(askDate);

                if(askDate == 'y')
                {
                    cout<<"Enter date (YYYY.MM.DD): ";
                    cin>>takeDate; // store the date in the array storeDate
                    break;
                }
                else if(askDate == 'n')
                {
                    cout<<"Using the previous date."<<endl;
                    break;
                }
                else
                {
                    cout<<"Invalid answer try again"<<endl<<endl;
                }
            }

            do
            {
                showDestinationList();

                cout<<"Enter destination: ";
                cin>>destinationType;

                destination = convertToDestinationDistance(destinationType);

                if(destinationType >= '1' && destinationType <= '7')
                {
                    showDiscountTypeList();

                    storeDate[countDate] = takeDate; // store the date in the array storeDate

                    cout<<"Choice: ";
                    cin>>typeOfDiscount;

                    assignedSeat = ""; // available seats start
                    seatAssigned = false;
                    for(r = 0; r < 4; r++)
                    {
                        if(seatAssigned)
                        {
                            break; // stop if already assigned
                        }

                        for(c = 0; c < 5; c++)
                        {
                            if(seatsArray[r][c])
                            {
                                seatsArray[r][c] = false;
                                rowLetter = 'A' + r;
                                columnNumber = '1' + c;

                                assignedSeat += rowLetter;
                                assignedSeat += columnNumber;

                                cout<<endl;
                                cout<<"Seat "<<assignedSeat<<" automatically assigned."<<endl;

                                seatAssigned = true;

                                break; //to exit inner loop after assignment
                            }
                        }
                    } // available seats end

                    fareTotal = calculateTotalFare(destination, typeOfDiscount);

                    cout<<"================================="<<endl;
                    cout<<"|    --> Total fare is P"<<fareTotal<<" \t|"<<endl;
                    cout<<"================================="<<endl;

                    destinationName = convertToDestinationName(destinationType);

                    storeDestinationName[countDestination] = destinationName;

                    countDate++;
                    countDestination++;
                    storeFareTotal[countFare] += fareTotal;
                    countFare++;
                    countLimit++;
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
            cout<<endl;
            cout<<"Date\t\t\tPlace\t\t\tPrice"<<endl;
            cout<<"======================================================="<<endl;
            for(i = 0; i <= countLimit; i++)
            {
                cout<<storeDate[i]<<"   "<<"\t|\t"<<storeDestinationName[i]<<"   "<<"\t|\t"<<storeFareTotal[i]<<endl;
            }

            cout<<endl;
        }
        else if(menuChoice == 3)
        {
            cout<<endl;
            cout<<"Seat Availability (A = Available, O = Occupied):"<<endl<<endl;
            for(r = 0; r < 4; r++)
            {
                for(c = 0; c < 5; c++)
                {
                    rowLetter = 'A' + r;
                    columnNumber = 1 + c;

                    cout<<rowLetter<<columnNumber<<": ";
                    if(seatsArray[r][c])
                    {
                        cout<<"A  |  ";
                    }
                    else
                    {
                        cout<<"O  |  ";
                    }
                }

                cout<<endl<<endl;
            }

            cout<<endl;
        }
        else if(menuChoice == 4)
        {
            cout<<"Thank you!"<<endl<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"Invalid input. Try again."<<endl;

        }
    } // end of while loop menu choice

    return EXIT_SUCCESS;
} // end of main