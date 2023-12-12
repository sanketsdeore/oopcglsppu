#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    typedef map<string, int> mapType;
    mapType populationMap;
    
    populationMap.insert(pair<string, int>("Maharashtra", 7024562));
    populationMap.insert(pair<string, int>("Karnataka", 6230593));
    populationMap.insert(pair<string, int>("Punjab", 6029925));
    populationMap.insert(pair<string, int>("Kerala", 5984284));
    
    mapType::iterator iter;
    cout<<"Population of States"<<endl;
    cout<<"Size of Map: "<<populationMap.size();
    string state_name;
    cout<<"\nEnter Name of State: ";
    cin>>state_name;
    iter=populationMap.find(state_name);
    if (iter!=populationMap.end())
    {
        cout<<state_name<<"'s population "<<iter->second;
    }
    else
    {
        cout<<"\nState not found!";
        populationMap.clear();
    }
}
