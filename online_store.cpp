#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

static int a=0;

class roomBooking
{
    char room[5], host[10], start[5], send[5], from[10],to[10],chair[8][4][10];

    public:

    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);

}r[10];

void vline(char ch)
{
    for(int i=80;i>0;i--)
    {
        cout<<ch;
    }
}


void roomBooking::install()
{

    cout<<"Enter Room No : ";
    cin>>r[a].room;
    cout<<endl;

    cout<<"Enter Host's Name : ";
    cin>>r[a].host;
    cout<<endl;

    cout<<"Start Time : ";
    cin>>r[a].start;
    cout<<endl;

    cout<<"Session Ends at : ";
    cin>>r[a].send;
    cout<<endl;

    cout<<"From : ";
    cin>>r[a].to;

    r[a].empty();

    a++;


}

void roomBooking::allotment()
{
    int chair;
    char number[5];
    top:

    cout<<"Room No : ";
    cin>>number;

    int n;

    for(n=0;n<=a;n++)
    {
        if(strcmp(r[n].room , number)==0)
        {
            break;
        }
    }

    while(n<=a)
    {
        cout<<"\nChair Number : ";
        cin>>chair;

        if(chair>32)
        {
            cout<<"\nThere are only 32 chairs available in Room.";
        }
        else
        {
            if(strcmp(r[n].chair[chair/4][(chair%4)-1],"Empty")==0)
            {
                cout<<"Enter customer's name :";
                cin>>r[n].chair[chair/4][(chair%4)-1];
                break;
            }

            else
            {
                cout<<"Chair Number is already reserved :";
            }
        }
    }

    if(n>a)
    {
        cout<<"Enter correct Room Number. "<<endl;
        goto top;
    }
}


void roomBooking::empty()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<4;j++)
        {
            strcpy(r[a].chair[i][j], "Empty");
        }
    }

}

void roomBooking::show()
{
    int n;
    char number[5];

    cout<<"Enter room No: ";

    cin>>number;
    for(n=0;n<=a;n++)
    {
        if(strcmp(r[n].room,number)==0)
        {
            break;
        }
    }

    while(n<=a)
    {
        vline('*');
        cout<<"Room no :\t"<<r[n].room
        <<"\nHost: \t"<<r[n].host<<"\t\tStart time :\t"
        <<r[n].start<<"\t Ende Time: "<<r[n].send<<"\nFrom :\t\t"<<r[n].from
        <<"\t\t To : \t\t"<<r[n].to<<"\n";

        vline('*');

        r[n].position(n);
        int b=1;

        for(int i=0;i<8;i++)
        {
            for(int j=0;j<4;j++)
            {
                b++;

                if(strcmp(r[n].chair[i][j],"Empty")!=0)
                {
                    cout<<"The chair no: "<<(b-1)<<" is reserved for "<<r[n].chair[i][j]<<".";
                }
            }
        }

        break;

    }

    if(n>a)
    {
        cout<<"Enter correct room no :";
    }
}

void roomBooking::position(int l)
{
    int s=0,p=0;

    for(int i=0;i<8;i++)
    {
        cout<<"\n";

        for(int j=0;j<4;j++)
        {
            s++;

            if(strcmp(r[l].chair[i][j], "Empty")==0)
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<r[l].chair[i][j];
                p++;
            }

            else
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<r[l].chair[i][j];

            }
        }
    }

    cout<<"\n\n There are "<<p<<" chairs empty in room No: "<<r[l].room<<". ";
}

void roomBooking::avail()
{
    for(int n=0;n<a;n++)
    {
        vline('*');
        cout<<"Room No: "<<r[n].room<<"\tHost: "<<r[n].host
        <<"\tstart time: "<<r[n].start<<"\tnd Time: "
        <<r[n].send<<"\tFrom: "<<r[n].from<<"\tTo: "
        <<r[n].to<<"\n";

        vline('*');
        vline('_');
    }
}

int main()
{
    system("cls");
    int w;

    while(1)
    {
        cout<<"\n\n\n\n\n";

        cout<<"\t\t\t1.Install\n\t\t\t"
        <<"2.Reservation\n\t\t\t"
        <<"3.show\n\t\t\t"
        <<"4.Rooms Available \n\t\t\t"
        <<"5.Exit ";

        cout<<"\n\t\t\tEnter your choice:-> ";
        cin>>w;

        switch(w)
        {
            case 1: r[a].install();
            break;

            case 2: r[a].allotment();
            break;

            case 3: r[a].show();
            break;

            case 4: r[a].avail();
            break;

            case 5: exit(0);
        }
    }

    return 0;
}