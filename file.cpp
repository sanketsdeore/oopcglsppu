#include <iostream>
#include <fstream>
using namespace std;

class Employee
{
    int id;
    string name;
    double salary;
    public:
    void accept()
    {
        cout<<"\nName: ";
        cin.ignore();
        getline(cin, name);
        cout<<"\nID: ";
        cin>>id;
        cout<<"\nSalary: ";
        cin>>salary;
    }
    void display()
    {
        cout<<"\nName: "<<name;
        cout<<"\nID: "<<id;
        cout<<"\nSalary: "<<salary;
    }
};

int main()
{
    Employee o[5];
    int i, n;
    fstream f;
    
    f.open("demo.txt", ios::out);
    
    cout<<"\nEnter no. of Employees: ";
    cin>>n;
    
    for (i=0; i<n; i++)
    {
        cout<<"\nEnter data of Employee"<<i+1;
        o[i].accept();
        f.write((char*)&o[i], sizeof o[i]);
    }
    
    f.close();
    
    f.open("demo.txt", ios::in);
    cout<<"Information of Employees"<<endl;
    
    for (i=0; i<n; i++)
    {
        cout<<"\nEmployee"<<i+1;
        f.read((char*)&o[i], sizeof o[i]);
        o[i].display();
    }
    f.close();
    return 0;
}
