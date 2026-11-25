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

class EmployeeManager {
    private:
    unordered_map<int, Employee> empDatabase;

    public:

    void addEmployee(const Employee& emp)
    {
        empDatabase.emplace(emp.getId(), emp);
    }

    const Employee* findEmployee(int searchById)
    {
        auto it = empDatabase.find(searchById);
        cout<<endl;
        if(it != empDatabase.end())
        {
            return &(it->second);
        }else
            return nullptr;
    }

};

int main()
{
    Employee emp1 = Employee(1101, "Kamlesh Dugade", "Software Engineer");
    Employee emp2 = Employee(1102, "Gouri Dugade", "Software Engineer");
    Employee emp3= Employee(1103, "Shivani Dugade", "MIS Executive");

    EmployeeManager mgr;
    mgr.addEmployee(emp1);
    mgr.addEmployee(emp2);
    mgr.addEmployee(emp3);

    int searchById = 0;
    cout<<"Enter employee ID for search: ";
    cin>>searchById;

    const Employee* ePtr = mgr.findEmployee(searchById);
    if(ePtr)
        ePtr->showDetails();
    else
        cout<<"Employee not found !!"<<endl;

    return(0);
}
