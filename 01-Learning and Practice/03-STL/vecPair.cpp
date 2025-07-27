#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

template <class T, class T1>
void Display(vector<T> v, vector<T1> v1)
{
    if(v.size() == 0 || v1.size() == 0)
    {
        cout<<"Empty vector list"<<endl; 
        return;
    }
    for(int i = 0; i<v.size(); i++)
    {
        cout<<"| "<<v[i]<<" |";
        cout<<"| "<<v1[i]<<" |";
    }
    cout<<"\n\n";
}

template<class T>
void Display(vector<T> v)
{
    if(v.size() == 0)
    {
        cout<<"Empty vector list"<<endl; 
        return;
    }
    for(int i = 0; i<v.size(); i++)
    {
        cout<<"| "<<v[i].first<<", "<<v[i].second<<" |";
    }
    cout<<"\n\n";
}


int main(void)
{
    vector< pair <string, int>> vec;
    vec.push_back(make_pair("Kamlesh", 7));
    Display(vec);
    return(0);
}