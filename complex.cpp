/*Implement a class Complex which represents the Complex Number data type. Implement the following
1. Constructor (including a default constructor which creates the complex number 0+0i).                  
2. Overload operator+ to add two complex numbers.                                                                
3. Overload operator* to multiply two complex numbers.            
4. Overload operators << and >> to print and read Complex Numbers.*/	

#include <iostream>
using namespace std;

class Complex
{
    double real, img;
    public:
        Complex ();
        friend istream &operator >>(istream&, Complex&);
        friend ostream &operator <<(ostream&, Complex&);
        Complex operator +(Complex);
        Complex operator *(Complex);
};

Complex::Complex()
{
    real=0;
    img=0;
}

istream &operator >>(istream&, Complex&i)
{
    cin>>i.real>>i.img;
    return cin;
}

ostream &operator <<(ostream&, Complex&d)
{
    cout<<d.real<<"+"<<d.img<<"i"<<endl;
    return cout;
}

Complex Complex::operator +(Complex c1)
{
    Complex temp;
    temp.real=real+c1.real;
    temp.img=img+c1.img;
    return temp;
}

Complex Complex::operator *(Complex c2)
{
    Complex temp1;
    temp1.real=real*c2.real-img*c2.img;
    temp1.img=real*c2.img+img*c2.real;
    return temp1;
}

int main()
{
    Complex c1, c2, c3, c4;
    int flag=1;
    char b;
    while (flag==1)
    {
        cout<<"Enter real and imaginary part for first number: ";
        cin>>c1;
        cout<<"Enter real and imaginary part for second number: ";
        cin>>c2;
        int f=1;
        while (f==1)
        {
            cout<<"Complex number 1: "<<c1<<endl;
            cout<<"Complex number 2: "<<c2<<endl;
            cout<<"****Menu****"<<endl;
            cout<<"1. Add Complex Numbers."<<endl;
            cout<<"2. Multiply Complex Numbers."<<endl;
            cout<<"3. Exit."<<endl;
            int a;
            cout<<"Choose: ";
            cin>>a;
            if (a==1)
            {
                c3=c1+c2;
                cout<<"Addition: "<<c3<<endl;
                cout<<"More operations?(y/n): ";
                cin>>b;
                if (b=='y' || b=='Y')
                {
                    f=1;
                }
                else
                {
                    cout<<"Thanks!"<<endl;
                    f=0;
                    flag=0;
                }
            }
            
            if (a==2)
            {
                c4=c1*c2;
                cout<<"Multiplication: "<<c4<<endl;
                cout<<"More operations?(y/n): ";
                cin>>b;
                if (b=='y' || b=='Y')
                {
                    f=1;
                }
                else
                {
                    cout<<"Thanks!"<<endl;
                    f=0;
                    flag=0;
                }
            }
            
            if (a==3)
            {
                cout<<"Thanks!"<<endl;
                f=0;
                flag=0;
            }
        }
    }
    return 0;
}
