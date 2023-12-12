#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class person
{
    string name, dob, phone;

public:
    int id;

    person() : id(0), name(""), dob(""), phone("") {}

    void accept()
    {
        cout << "\nEnter ID: ";
        cin >> id;
        cout << "\nEnter Name: ";
        cin >> name;
        cout << "\nEnter DOB: ";
        cin >> dob;
        cout << "\nEnter Phone: ";
        cin >> phone;
    }

    void display()
    {
        cout << "ID:" << id << "  |  Name:" << name << "  |  DOB:" << dob << "  |  Phone:" << phone << endl;
    }

    bool operator<(const person &other) const
    {
        return id < other.id;
    }
};

int main()
{
    vector<person> v;
    int f=0, key;

    while (1)
    {
        person p;
        int a;

        cout << "\n1. New Record.";
        cout << "\n2. Display Records.";
        cout << "\n3. Search Record.";
        cout << "\n4. Sort Records.";
        cout << "\n5. Exit.";
        cout << "\nChoose: ";
        cin >> a;

        switch (a)
        {
        case 1:
            p.accept();
            v.push_back(p);
            break;

        case 2:
            for (int i = 0; i < v.size(); i++)
            {
                v[i].display();
            }
            break;

        case 3:
            cout << "\nEnter ID to search: ";
            cin >> key;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i].id == key)
                {
                    f = 1;
                    v[i].display();
                }
            }
            if (f == 0)
            {
                cout << "\nID Not Found!";
            }
            break;

        case 4:
            cout << "\nSorting Records by ID:";

            sort(v.begin(), v.end());
            
            for (int i = 0; i < v.size(); i++)
            {
                v[i].display();
            }
            break;

        case 5:
            cout << "Thank You!";
            return 0;
            break;

        default:
            cout << "\nInvalid Choice!";
            break;
        }
    }
    return 0;
}
