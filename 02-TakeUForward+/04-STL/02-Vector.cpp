#include<iostream>
#include<vector>

using namespace std;


int main()
{
    /// PAIR 
    // pair<int, string> student;

    // student.first = 10;
    // student.second = "Kamlesh";

    // cout<<"Student name: "<<student.second<<" & Roll No.: "<<student.first<<endl;
    
    // pair<pair<int, string>, int> studentInfo;

    // studentInfo.first.first = 10;
    // studentInfo.first.second = "Kamlesh";
    // studentInfo.second = 8;

    // cout<<"Student name: "<<studentInfo.first.second<<" & Roll No.: "<<studentInfo.first.first<<" Class: "<<studentInfo.second<<endl;
    
    //// VECTOR
    // vector<int> vecInt = {10, 20, 30, 40, 50};
    // for(auto num : vecInt)
    // {
    //     cout<<num<<" ";
    // }

    vector<int> vecInt2;
    vector<int> vecInt3(10,10);
    for(int i=0; i < 10; i++)
    {
        vecInt2.push_back(i+1);
    }
    // cout<<"Fornt: "<<vecInt2.front()<<endl;
    // cout<<"Back: "<<vecInt2.back()<<endl;

    // Iterator
    cout<<"Iterator Printing vecInt2:- ";
    for(vector<int>::iterator it = vecInt2.begin(); it != vecInt2.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    // // Erase
    // vecInt2.erase(vecInt2.begin());

    // // Insert
    // vecInt2.insert(vecInt2.begin(), 1000);
    // cout<<"Fornt: "<<vecInt2.front()<<endl;
    // cout<<"Back: "<<vecInt2.back()<<endl;
    // vecInt2.insert(vecInt2.begin()+1, 20);
    // vecInt2.insert(vecInt2.end(), 5777);
    swap(vecInt3, vecInt2);
    vecInt3.clear();

    // // Printing
    cout<<"After Printing vecInt2:- ";
    for(auto num : vecInt2)
    {
        cout<<num<<" ";
    }
    cout<<endl;

    // // Printing
    cout<<"After Printing vecInt3:- ";
    for(auto num : vecInt3)
    {
        cout<<num<<" ";
    }
        
    
    cout<<endl;
    return (0); 
}
