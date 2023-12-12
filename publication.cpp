/*
Imagine a publishing company which does marketing for book and audiocassette versions.
Create a class publication that stores the title (a string)
and price (type float) of a
 publication.From this class derive two classes: book, which
adds a page count(type int),
 and tape, which adds a playing time in minutes(type float).
 Write a program that instantiates the book and tape classes,
allows user to enter data and
 displays the data members.If an exception is caught, replace
all the data member values
 with zero values.
*/

#include <iostream>
using namespace std;

class publication
{
    string title;
    float price;
    public:
    void add()
    {
        cout<<"Enter information of Publication"<<endl;
        cout<<"\nPublication Title: ";
        cin.ignore();
        getline(cin, title);
        cout<<"\nPublication Price: ";
        cin>>price;
    }
    void display()
    {
        cout<<"\n----------------------------";
        cout<<"\nTitle of Publication: "<<title;
        cout<<"\nPrice of Publication: "<<price;
    }
};

class book:public publication
{
    int pg_cnt;
    public:
    void add_book()
    {
        try
        {
            add();
            cout<<"\nEnter number of pages: ";
            cin>>pg_cnt;
            
            if (pg_cnt<=0)
            {
                throw pg_cnt;
            }
        }
        catch(...)
        {
            cout<<"\nInvalid page count!";
            pg_cnt=0;
        }
    }
    void display_book()
    {
        display();
        cout<<"\nPage Count: "<<pg_cnt;
        cout<<"\n----------------------------";
    }
};

class tape:public publication
{
    float play_time;
    public:
    void add_tape()
    {
        try
        {
            add();
            cout<<"\nEnter playing time(in minutes): ";
            cin>>play_time;
            if (play_time<=0)
            {
                throw play_time;
            }
        }
        catch(...)
        {
            cout<<"\nInvalid playing time!";
            play_time=0;
        }
    }
    void display_tape()
    {
        display();
        cout<<"\nPlaying Time (in minutes):"<<play_time;
        cout<<"\n----------------------------";
    }
};

int main()
{
    book b[10];
    tape t[10];
    int a, b_count, t_count;
    int flag=1;
    
    while (flag==1)
    {
        cout<<"\n****PUBLICATION DATABASE SYSTEM****"<<endl;
        cout<<"\n1. Add information to books.";
        cout<<"\n2. Add information to tape.";
        cout<<"\n3. Display information of books.";
        cout<<"\n4. Display information of tapes.";
        cout<<"\n5. Exit.";
        cout<<"\nEnter your choice: ";
        cin>>a;
        switch(a)
        {
            case 1:
            b[b_count].add_book();
            b_count++;
            break;
            
            case 2:
            t[t_count].add_tape();
            t_count++;
            break;
            
            case 3:
            cout<<"****BOOK PUBLICATION DATABASE SYSTEM****"<<endl;
            for (int j=0; j<b_count; j++)
            {
                b[j].display_book();
            }
            break;
            
            case 4:
            cout<<"****TAPE PUBLICATION DATABASE SYSTEM****"<<endl;
            for (int i=0; i<t_count; i++)
            {
                t[i].display_tape();
            }
            break;
            
            case 5:
            cout<<"\nThank You!";
            flag=0;
        }
    }
    return 0;
}
