#include <iostream>// wait kumakain ako
#include <cstdlib> // eto yung ginawa nung last meeting walang akong binago

#define MAXSEAT 28
#define SENIOR 0.30
#define PWD 0.25
#define STUDENT 0.20
#define SM 2.2

const double baseFare = 12.0;
const double baseDistance = 4.0;
const double additionalRate = 1.5;

using namespace std;
// void 1
void menu()
{
  cout<<"Bus Ticket Management System"<<endl;
  cout<<"1. New Transaction"<<endl;
  cout<<"2. Log"<<endl;
  cout<<"3. Available Seats"<<endl;
  cout<<"4. Summary of sales"<<endl;
  cout<<"5. Exit"<<endl;
}
// void 2
void destination()
{
  cout<<"Destination"<<endl;
  cout<<"1. SM"<<endl;
  cout<<"2. Pacific"<<endl;
  cout<<"3. Sumacab Campus"<<endl;
  cout<<"4. Sta Rosa"<<endl;
  cout<<"5. Zaragoza"<<endl;
  cout<<"6. La Paz"<<endl;
  cout<<"7. Tarlac City"<<endl;
}
// function 1
double discount(int dType, double subFare)
{
  switch(dType)
  {
  case 1:
    subFare = subFare - (subFare * SENIOR);

    return subFare;
    break;
  case 2:
    subFare = subFare - (subFare * PWD);
    
    return subFare;
    break;
  case 3:
    subFare = subFare - (subFare * STUDENT);
    
    return subFare;
    break;
  }
}

int main()
{
  int menuChoice, newTrCh, desCh, discType;
  int seat[14][2] = {{1, 2}, {3, 4}};
  char dateCh;
  double fare, distance, discountedFare;

  do
  {
    menu();
    
    cout<<"Enter choice: ";
    cin>>menuChoice;
  
    if(menuChoice == 1)
    {
      while(newTrCh != 2)
      {
        
        cout<<endl;
        cout<<"New Transaction"<<endl;
        cout<<"1. Destination"<<endl;
        cout<<"2. Back"<<endl;

        cout<<"Enter choice: ";
        cin>>newTrCh;

        cout<<endl;

        if(newTrCh == 1)
        {
          destination();

          cout<<"Enter destination: ";
          cin>>desCh;
          
          switch(desCh)
          {
            case 1:
              if(2.2 <= baseDistance) 
              {
                  fare = baseFare;
              }else{
                  fare = baseFare + (2.2 - baseDistance) * additionalRate;
              }
              
              cout<<"========================"<<endl;
              cout<<"Discount Type"<<endl;
              cout<<"1. Senior"<<endl;
              cout<<"2. PWD"<<endl;
              cout<<"3. Student"<<endl;
              cout<<"4. None"<<endl;
              
              cout<<"Enter: ";
              cin>>discType;

              if(discType == 1)
              {
                discountedFare = discount(discType, fare);

                cout<<"Your total fare is: ₱"<<discountedFare<<endl;
              }
              else if(discType == 2)
              {
                discountedFare = discount(discType, fare);

                cout<<"Your total fare is: ₱"<<discountedFare<<endl;
              }
              else if(discType == 3)
              {
                discountedFare = discount(discType, fare);

                cout<<"Your total fare is: ₱"<<discountedFare<<endl;
              }
              else if(discType == 4)
              {
                cout<<"Your total fare is: ₱"<<fare<<endl;
              }                                  
              break;
            case 2:
              if(3.1 <= baseDistance) 
              {
                  fare = baseFare;
              }else{
                  fare = baseFare + (3.1 - baseDistance) * additionalRate;
              }
              
              cout<<"========================"<<endl;
              cout<<"Discount Type"<<endl;
              cout<<"1. Senior"<<endl;
              cout<<"2. PWD"<<endl;
              cout<<"3. Student"<<endl;
              cout<<"4. None"<<endl;

              cout<<"Enter: ";
              cin>>discType;

              if(discType == 1)
              {
                fare = fare - (fare * SENIOR);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 2)
              {
                fare = fare - (fare * PWD);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 3)
              {
                fare = fare - (fare * STUDENT);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 4)
              {
                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              break;
            case 3:
              if(5.0 <= baseDistance) 
              {
                  fare = baseFare;
              }else{
                  fare = baseFare + (5.0 - baseDistance) * additionalRate;
              }
              
              cout<<"========================"<<endl;
              cout<<"Discount Type"<<endl;
              cout<<"1. Senior"<<endl;
              cout<<"2. PWD"<<endl;
              cout<<"3. Student"<<endl;
              cout<<"4. None"<<endl;

              cout<<"Enter: ";
              cin>>discType;

              if(discType == 1)
              {
                fare = fare - (fare * SENIOR);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 2)
              {
                fare = fare - (fare * PWD);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 3)
              {
                fare = fare - (fare * STUDENT);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 4)
              {
                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              break;
            case 4:
              if(7.1 <= baseDistance) 
              {
                  fare = baseFare;
              }else{
                  fare = baseFare + (7.1 - baseDistance) * additionalRate;
              }
              
              cout<<"========================"<<endl;
              cout<<"Discount Type"<<endl;
              cout<<"1. Senior"<<endl;
              cout<<"2. PWD"<<endl;
              cout<<"3. Student"<<endl;
              cout<<"4. None"<<endl;

              cout<<"Enter: ";
              cin>>discType;

              if(discType == 1)
              {
                fare = fare - (fare * SENIOR);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 2)
              {
                fare = fare - (fare * PWD);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 3)
              {
                fare = fare - (fare * STUDENT);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 4)
              {
                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              break;
            case 5:
              if(24 <= baseDistance) 
              {
                  fare = baseFare;
              }else{
                  fare = baseFare + (24 - baseDistance) * additionalRate;
              }
              
              cout<<"========================"<<endl;
              cout<<"Discount Type"<<endl;
              cout<<"1. Senior"<<endl;
              cout<<"2. PWD"<<endl;
              cout<<"3. Student"<<endl;
              cout<<"4. None"<<endl;

              cout<<"Enter: ";
              cin>>discType;

              if(discType == 1)
              {
                fare = fare - (fare * SENIOR);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 2)
              {
                fare = fare - (fare * PWD);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 3)
              {
                fare = fare - (fare * STUDENT);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 4)
              {
                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              break;
            case 6:
              if(32 <= baseDistance) 
              {
                  fare = baseFare;
              }else{
                  fare = baseFare + (32 - baseDistance) * additionalRate;
              }
              
              cout<<"========================"<<endl;
              cout<<"Discount Type"<<endl;
              cout<<"1. Senior"<<endl;
              cout<<"2. PWD"<<endl;
              cout<<"3. Student"<<endl;
              cout<<"4. None"<<endl;

              cout<<"Enter: ";
              cin>>discType;

              if(discType == 1)
              {
                fare = fare - (fare * SENIOR);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 2)
              {
                fare = fare - (fare * PWD);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 3)
              {
                fare = fare - (fare * STUDENT);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 4)
              {
                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              break;
            case 7:
              if(49 <= baseDistance) 
              {
                  fare = baseFare;
              }else{
                  fare = baseFare + (49 - baseDistance) * additionalRate;
              }
              
              cout<<"========================"<<endl;
              cout<<"Discount Type"<<endl;
              cout<<"1. Senior"<<endl;
              cout<<"2. PWD"<<endl;
              cout<<"3. Student"<<endl;
              cout<<"4. None"<<endl;

              cout<<"Enter: ";
              cin>>discType;

              if(discType == 1)
              {
                fare = fare - (fare * SENIOR);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 2)
              {
                fare = fare - (fare * PWD);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 3)
              {
                fare = fare - (fare * STUDENT);

                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              else if(discType == 4)
              {
                cout<<"Your total fare is: ₱"<<fare<<endl;
              }
              break;
            default:
              cout<<"Invalid Destination"<<endl<<endl;
              break;
          }
        }
      }   
    }
    else if(menuChoice == 2)
    {
      cout<<""<<endl;
    }
    else if(menuChoice == 3)
    {
      
    }
    else if(menuChoice == 4)
    {
      
    }
    else if(menuChoice == 5)
    {
      cout<<"Thanks"<<endl<<endl;
    }else{
      cout<<"Invalid"<<endl<<endl;
      }
  }while(menuChoice != 5);
  
  return EXIT_SUCCESS;
}