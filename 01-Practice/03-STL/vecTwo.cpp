#include<iostream>
#include<vector>
#include<string>
using namespace std;

template <class T>
void Display(vector<T> v)
{
    for(int i = 0; i<v.size(); i++)
    {
        cout<<"| "<<v[i]<<" |";
    }
    cout<<"\n\n";
}

int main()
{
    vector<string> vNames;
    vector<long> vGrade;
    int size = 0;
    int grade = 0;
    string name;
    cout<<"Enter the how many number of students: "<<endl;
    cin>>size;

    for(int i = 0;  i<size; i++)
    {
        cout<<"Enter name of student: "<<endl;
        cin>>name;
        vNames.push_back(name);

        cout<<"Enter grade of student: "<<endl;
        cin>>grade;
        vGrade.push_back(grade);
    }

    Display(vNames);
    Display(vGrade);
}