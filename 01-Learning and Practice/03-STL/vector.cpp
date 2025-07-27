#include<iostream>
#include<vector>
using namespace std;

void Display(vector<int>& v)
{
    for(int i = 0; i<v.size(); i++)
    {
        cout<<"| "<<v[i]<<" |";
        //cout<<"| "<<v.at(i)<<" |";
    }
}

int main()
{
    vector<int> vec1; //vector<data_type> name;
    
    int element;
    int size = 0;
    cout<<"Enter size: "<<endl;
    cin>>size;

    for(int i = 0; i<size; i++)
    {
        cout<<"\nEnter Element to store into vector: "<<endl;
        cin>>element;
        vec1.push_back(element);
    }
    // vec1.pop_back();

    vector<int> :: iterator itr = vec1.begin();

    //vec1.insert(itr, 5, 77);
    vec1.insert(itr+2, 60);
    Display(vec1);
    return 0;
}
