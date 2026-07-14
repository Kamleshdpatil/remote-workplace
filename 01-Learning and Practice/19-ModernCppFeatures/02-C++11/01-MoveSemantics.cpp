#include<iostream>
#include<vector>

using namespace std;

void print(vector<int>& nums)
{
    for(int num : nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(void)
{
    vector<int> source = {10, 20, 30, 40};
    cout<<"Address source: "<<&source<<endl;
    // cout<<"Printing source array: ";
    
    vector<int> target = move(source);
    cout<<"After move Address source: "<<&source<<endl;
   
    cout<<"target capacity: "<<target.capacity()<<endl;

    cout<<"Address target: "<<&target<<endl;

    // cout<<"Printing target array: ";
    // print(target);

    return(0);
}
