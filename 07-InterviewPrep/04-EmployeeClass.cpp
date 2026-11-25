#include<iostream>
#include<unordered_map>

using namespace std;

class Employee{
    int id;
    string name;
    string designation;

    public:
    Employee() = default;

    Employee(int iId, string sName, string sDesig) : id(iId), name(sName), designation(sDesig){}

    int getId() const { return id;}

    string getName() const {return name;}

    string getDesignation() const {return designation;}

    void showDetails() const
    {
        cout<<"ID: "<<id<<"\n";
        cout<<"Name: "<<name<<"\n";
        cout<<"Designation: "<<designation<<"\n";
    }

    virtual ~Employee(){}
};

int main()
{
    Employee emp1 = Employee(1101, "Kamlesh Dugade", "Software Engineer");
    Employee emp2 = Employee(1102, "Gouri Dugade", "Software Engineer");
    Employee emp3= Employee(1103, "Shivani Dugade", "MIS Executive");

    unordered_map<int, Employee> empDatabase;

    empDatabase.emplace(1101, emp1);
    empDatabase.emplace(1102, emp2);
    empDatabase.emplace(1103, emp3);

    int searchById = 0;
    cout<<"Enter employee ID for search: ";
    cin>>searchById;

    auto it = empDatabase.find(searchById);
    cout<<endl;
    if(it != empDatabase.end())
    {
        it->second.showDetails();
    }else
        cout<<"Employee not found !!";

    return(0);
}
