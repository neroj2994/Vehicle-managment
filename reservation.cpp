//
//  main.cpp
//  Reservation
//
//  Created by Niroj Kapri on 2019/7/27.
//  Copyright © 2019 Niroj Kapri. All rights reserved.
//


//                   HEADER FILE USED IN PROJECT

#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;        // using standard library

static int p = 0;

//                   CLASS USED IN PROJECT

class Reservation

{
    
    char bus_no[5];     //variable for bus number in array format
    char driver[10];    //variable for driver name in array format
    char arrival[5];    //variable for arrival time in array format
    char depart[5];     //variable for departure in array format
    char from[10];      //variable for departure place in array format
    char to[10];        //variable for arrival place in array format
    char seat[8][4][10];//variable for bus number in array format
    
public:
    
    void add_bus();      //function for adding bus service
    void customer_resv();//function for customer seat reservation
    void empty();        // function for insert string empty to unreserved seat seats
    void show();         //function for showing seat reservation status for specific bus
    void avail();       // function for showing available vehicle list
    void position(int i);  // function for checking to seat in the specific vechicle
} //class ends here

bus[10];

void v_line(char ch)            //function for making divider
{
    for (int i=80;i>0;i--)       // initialization of for loop
        cout<<ch;
}
void Reservation::add_bus()     //function for adding bus service
{
    cout<<"Enter Vehicle no: ";
    cin>>bus[p].bus_no;
    cout<<"\nEnter Vehicle Driver's name: ";
    cin>>bus[p].driver;
    cout<<"\nVehicle Arrival time: ";
    cin>>bus[p].arrival;
    cout<<"\nVehicle Departure: ";
    cin>>bus[p].depart;
    cout<<"\nFrom: \t\t\t";
    cin>>bus[p].from;
    cout<<"\nTo: \t\t\t";
    cin>>bus[p].to;
    bus[p].empty();             // calling the empty function
    p++;
}

void Reservation::customer_resv()           //function for customer seat reservation
{
    int seat;
    char number[5];
top:                                        // declearisation of position
    cout<<"Vehicle no: ";
    cin>>number;
    int n;
    for(n=0;n<=p;n++)                       //initialization of for loop for checking vehicle number from array
    {
        if(strcmp(bus[n].bus_no, number)==0)        // checking the vechicle number
            break;
    }
    while(n<=p)                                 // if available
    {
        cout<<"\nSeat Number: ";
        cin>>seat;                              // Inserting of seat number
        if(seat>32)                             // checking if seat number greater then 32 the cannot insert
        {
            cout<<"\nThere are only 32 seats available in this vehicle.";
        }
        else
        {
            if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0) // checking the seat reserve or not if yes can add name
            {
                cout<<"Enter passanger's name: ";
                cin>>bus[n].seat[seat/4][(seat%4)-1];
                break;
            }
            else
                cout<<"The seat no. is already reserved.\n";
        }
    }
    if(n>p)
    {
        cout<<"Enter correct Vehicle no.\n";
        goto top;       // goto above declear position top
    }
}


void Reservation::empty()           // function for check empty seats
{
    for(int i=0; i<8;i++)           // 2D array declearation
    {
        for(int j=0;j<4;j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");     // function to string copy Empty in respect seat
        }
    }
}

void Reservation::show()            //function for showing seat reservation status for specific bus
{
    int n;
    char number[5];
    cout<<"Enter vehicle no: ";     // insert of vehicle number
    cin>>number;
    for(n=0;n<=p;n++)               // for loop for searching the vehicle
    {
        if(strcmp(bus[n].bus_no, number)==0)        //searching for vehicle using ctring compare function
            break;
    }
    
    while(n<=p)                     // initialization of while loop
    {
        v_line('*');
        cout<<"Vehicle no: \t"<<bus[n].bus_no
        <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
        <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
        <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
        bus[n].to<<"\n";                        // display tabular heading
        v_line('*');
        bus[0].position(n);                     // calling function position for displaying seat status for specific vehicle
        int a=1;
        for (int i=0; i<8; i++)                 //initialization of 2D for loop
        {
            for(int j=0;j<4;j++)
            {
                a++;
                if(strcmp(bus[n].seat[i][j],"Empty")!=0)
                cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
            }
        }
        break;
    }
    if(n>p)
        cout<<"Enter correct vehicle no: ";
}

void Reservation::position(int l)       // function for checking to seat in the specific vechicle
{
    int s=0;p=0;
    for (int i =0; i<8;i++)         //initialization of 2D for loop
    {
        cout<<"\n";
        for (int j = 0;j<4; j++)
        {
            s++;                // number for seat calculation
            if(strcmp(bus[l].seat[i][j], "Empty")==0)       //if condition with comparing string for empty seat
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[l].seat[i][j];    //printing infromation
                p++;            // caluclating total number of empty seat
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[l].seat[i][j]; //Printing information
            }
        }
    }
        cout<<"\n\nThere are "<<p<<" seats empty in Vehicle No: "<<bus[l].bus_no;
}

void Reservation::avail()       // function for showing available vehicle list
{
    for(int n=0;n<p;n++)
    {
        v_line('*');        // calling function for sepration between vehicle
        cout<<"Vehicle no: \t"<<bus[n].bus_no<<"\nDriver: \t"<<bus[n].driver
        <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"
        <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
        <<bus[n].to<<"\n";          // display the all available vehicle information
        v_line('*');        // calling function for sepration between vehicle
        v_line('_');        // calling function for sepration between vehicle
    }
}

// CALLING OF MAIN FUNCTION

int main()
{
    system("cls");      // clear screen function
    int ch;
    while(1)            // initialization of while loop for infinite looping
    {
        cout<<"\n\n\n\n\n";
        cout<<"\t\t\t1.Add Bus\n\t\t\t"
        <<"2.Reservation\n\t\t\t"
        <<"3.Show\n\t\t\t"
        <<"4.Vehicles Available. \n\t\t\t"
        <<"5.Exit";
        cout<<"\n\t\t\tEnter your choice:-> ";
        cin>>ch;
        switch(ch)               // initialization of switch case
        {
            case 1:  bus[p].add_bus();
                break;
            case 2:  bus[p].customer_resv();
                break;
            case 3:  bus[0].show();
                break;
            case 4:  bus[0].avail();
                break;
            case 5:  exit(0);
        }
    }
    return 0;
}

//END OF PROGRAM
