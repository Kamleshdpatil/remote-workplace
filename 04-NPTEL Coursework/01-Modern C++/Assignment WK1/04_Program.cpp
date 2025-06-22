#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    vector<int> cVec(3,-1);

    for(int i = 0; i < 3; i++){
        cVec[i] = (i + 1) * 10;
    }

    cVec.resize(3);
    cVec.resize(3, 110);

    cout<<endl;
    for(int i = 0; i < 3; i++){
        cVec.push_back((i + 1) * 20);
    }

    for(int i = 0; i < cVec.size(); i++){
        cout<<cVec[i] <<" ";
    }
    
    return(0);
}
