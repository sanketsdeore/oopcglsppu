#include <iostream>
#include <string.h>
#include <exception>
using namespace std;
class Student
{
        private:
        string name;
        int roll_no;
        string class_name;
        char division;
        string dob;
        string blood_group;
        string contact_address;
        string phone_no;
        string driving_license;
    public:
    Student()
    {
        this->name = "";
        this->roll_no = 0;
        this->class_name = "";
        this->division = 'A';
        this->dob = "";
        this->blood_group = "";
        this->contact_address = "";
        this->phone_no = "";
        this->driving_license = "";
    }
    Student(Student &other)
    {
        this->name = other.name;
        this->roll_no = other.roll_no;
        this->class_name = other.class_name;
        this->division = 'A';
        this->dob = other.dob;
        this->blood_group = other.blood_group;
        this->contact_address = other.contact_address;
        this->phone_no = other.phone_no;
        this->driving_license = other.driving_license;
    }
    
    inline void display()
    {
        cout << "\n\nStudent Details: \n";
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll_no << endl;
        cout << "Class Name :" << class_name << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << blood_group << endl;
        cout << "Contact Address: " << contact_address << endl;
        cout << "Telephone Number: " << phone_no << endl;
        cout << "Driving license Number: " << driving_license << endl;
    }
    
    ~Student()
    {
        cout << "Memory Deallocated!!!"<<endl;
    }
    
    
    friend class Data;
};
class Data
{
    public:
    void getData(Student &student)
    {
        cout << "\nEnter student Name: ";
        cin >> student.name;
        cout << "\nEnter student Roll No: ";
        cin >> student.roll_no;
        cout << "\nEnter student class name: ";
        cin >> student.class_name;
        cout << "\nEnter student date of birth: ";
        cin >> student.dob;
        cout << "\nEnter student blood group: ";
        cin >> student.blood_group;
        cout << "\nEnter student contact address: ";
        cin.ignore();
        getline(cin, student.contact_address);
        cout << "\nEnter student phone number: ";
        cin >> student.phone_no;
        cout << "\nEnter student driving license number: ";
        cin >> student.driving_license;
        cout << "\n";
    }
};

int main()
{
    try
    {
        Student *student1 = new Student();
        Data data1;
        data1.getData(*student1);
        student1->display();
        Student student2 = *student1;
        student2.display();
    }
    
    catch (exception &e)
    {
        cerr << e.what() << '\n';
    }
}
