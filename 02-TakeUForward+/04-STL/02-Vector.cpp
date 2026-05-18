#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> iVec;
    
    for(int i = 0; i < 20; i++)
    {
        iVec.push_back((i+1) * 10);
        cout<<"Element: "<<iVec[i]<<" Round: "<<(i+1)<<" Size: "<<iVec.size()<<" Capacity: "<<iVec.capacity()<<endl;
    }

    return(0);
}

