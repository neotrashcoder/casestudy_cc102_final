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
    minimum lang pala to
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
#define INVALID_DESTINATION 0.0f
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
    cout<<"4. Summary of sales"<<endl; // ano mas okay unahin yung flowchart or yung code?
    cout<<"5. Exit"<<endl; // an

    cout<<"Choice: "; // ganto rin balak ko sana gawin kaso di pa na d discuss yung global variable
    // cin>>menuChoice;

    // return menuChoice;
}

// int destinationType()
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

double convertToDestination(int destinationType) {
    switch(destinationType) {
        case 1:
            return SM;
        case 2:
            return PACIFIC;
        default:
            return INVALID_DESTINATION;
    }
}

void discountTypeChoices()
{
    cout<<endl;
    cout<<"Discount Type"<<endl;
    cout<<"1. Senior"<<endl;
    cout<<"2. PWD"<<endl;
    cout<<"3. Student"<<endl;
    cout<<"4. None"<<endl;
}

double calculateTotalFare(double placeDest, int typeDisc)
{
    double fare; // dito basta may malagay lang kami na di same sa parameters sa main function

    if(placeDest <= baseDistance) 
    {
        fare = baseFare;
    }
    else
    {
        fare = baseFare + (placeDest - baseDistance) * additionalRate;
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

    int destinationType;
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
            cout<<"New date (y/n): ";
            cin>>askDate;

            askDate = tolower(askDate);

            if(askDate == 'y')
            {
                cout<<"Enter date: ";
                cin>>takeDate;

                storedDate[countDate] += takeDate; // store the date in the array storedDate 
                
                countDate++;
            }
            else
            {
                storedDate[countDate] += takeDate;

                countDate++;
            }
            
            do
            {
                destinationList();

                cout<<"Enter destination: ";
                cin>>destinationType;

                switch(destinationType) // pano ba correct way?
                {                       // no, part talaga pagiisip ng var
                                        // It should be what it does, not what it is, or not why is it created
                                        // siguro pwede - destinationType ganun, destinationType kasi is parang, bakit mo sya ginawa pero di talaga kung ano un
                                        // siguro pwede mo syang i retain na ganyan, kasi destination padin naman sya eh
                                        // 
                    case 1:
                        discountTypeChoices(); // para i-display yung mga destination

                        cout<<"Choice: "; // eto pare parehas lang pwede pa baguhin to

                        /*
                        double convertToDestination(int destinationType) {
                            switch(destinationType) {
                                case 1:
                                    return SM;
                                case 2:
                                    return PACIFIC;
                                default:
                                    return INVALID_DESTINATION;
                            }
                        }

                        destinationList();

                        cout<<"Enter destination: ";
                        cin>>destinationType;

                        destination = convertToDestination(destinationType); // gamitin mo ung function na un

                        if(destination == INVALID_DESTINATION) {
                            cout<<endl;
                            break;
                        }

                        discountTypeChoices();

                        // tama ba ilan ba needed ng function return?
                        // nag dagdag lang akong isa eh

                        // kahit ilan daw pala basta minimu
                        // minimum ilan?
                        // kahit ilan basta daw minimun of 3 function that return...
                        // isipan ko pa ng isa, pero nagdagdag na ako ng isa pa ung convertToDestination
                        // di ba kasama ung main? haha

                        cout<<"Choice: ";
                        cin>>typeOfDiscount;

                        fareTotal = calculateTotalFare(destination, typeOfDiscount);

                        cout<<"Total fare is P"<<fareTotal<<endl;
                        
                        Pwedeng ganyan lang

                        I guess un lang for now
                        */
                        cin>>typeOfDiscount;

                        destination = SM;

                        fareTotal = calculateTotalFare(destination, typeOfDiscount);

                        cout<<"Total fare is P"<<fareTotal<<endl;
                        break;
                    case 2:
                        discountTypeChoices();

                        cout<<"Choice: ";
                        cin>>typeOfDiscount;

                        destination = PACIFIC;

                        fareTotal = calculateTotalFare(destination, typeOfDiscount);

                        cout<<"Total fare is P"<<fareTotal<<endl;
                        break;
                    case 3:
                        discountTypeChoices();

                        cout<<"Choice: ";
                        cin>>typeOfDiscount;

                        destination = SUMACAB;

                        fareTotal = calculateTotalFare(destination, typeOfDiscount);

                        cout<<"Total fare is P"<<fareTotal<<endl;
                        break;
                    case 4:
                        discountTypeChoices();

                        cout<<"Choice: ";
                        cin>>typeOfDiscount;

                        destination = STAROSA;

                        fareTotal = calculateTotalFare(destination, typeOfDiscount);

                        cout<<"Total fare is P"<<fareTotal<<endl;
                        break;
                    case 5:
                        discountTypeChoices();

                        cout<<"Choice: ";
                        cin>>typeOfDiscount;

                        destination = ZARAGOZA;

                        fareTotal = calculateTotalFare(destination, typeOfDiscount);

                        cout<<"Total fare is P"<<fareTotal<<endl;
                        break;
                    case 6:
                        discountTypeChoices();

                        cout<<"Choice: ";
                        cin>>typeOfDiscount;

                        destination = TARLAC;

                        fareTotal = calculateTotalFare(destination, typeOfDiscount);

                        cout<<"Total fare is P"<<fareTotal<<endl;
                        break;
                    case 7:
                        discountTypeChoices();

                        cout<<"Choice: ";
                        cin>>typeOfDiscount;

                        destination = SM;

                        fareTotal = calculateTotalFare(destination, typeOfDiscount);

                        cout<<"Total fare is P"<<fareTotal<<endl;
                        break;
                    default:
                        cout<<endl; // do nothing and exit the loop
                        break;
                }
            }while(destinationType != 8); // end of loop for choosing destination
        } // end of else if for choosing destination and asking for date on menu choice 1 new transaction
        else if(menuChoice == 2)
        {
            cout<<"Date"<<endl;
            for(int i = 0; i <= countDate; i++)
            {
                cout<<storedDate[i]<<endl; 
            }
        } // end of else if menuchoice 2 log
    } // end of while loop menu choice

    return EXIT_SUCCESS;
} // end of main