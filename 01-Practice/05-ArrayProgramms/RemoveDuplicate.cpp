#include<vector>
#include<iostream>
#include<set>
using namespace std;


void removeDuplicates(vector<int> &arr, int n) {
	// // Write your code here.
	// set<int> st;
	// int count = 0;
	// for(int i = 0; i < n; i++)
	// {
	// 	st.insert(arr[i]);
	// }
	// return(st.size());

	int i = 0;
	vector<int> newVec;
	for(i = 0; i < arr.size()-1; i++)
	{
		cout<<"i+1 : "<<i+1<<endl;
		if(arr[i] != arr[i+1])
		{
			newVec.push_back(arr[i]);
		}
	}
	//i++;
	if(i >= arr.size())
	{
		cout<<"\narr.size(): "<<arr.size()<<" exceeded!! "<<" i is: "<<i<<endl;
	}
	newVec.push_back(arr[arr.size()-1]);
	cout<<"\nAfter: "<<endl;
    for(int i = 0; i <newVec.size(); i++)
    {
        cout<<newVec[i]<<" ";
    }
	//return i+1;
}

int main(void)
{
    vector<int> vrr = {1, 1, 2, 2, 2, 2, 2, 3, 3, 4, 5, 6, 7, 7, 8, 9};
	cout<<"Before: "<<endl;
    for(int i = 0; i <vrr.size(); i++)
    {
        cout<<vrr[i]<<" ";
    }
	cout<<endl;
	removeDuplicates(vrr, vrr.size());
	// cout<<"\nAfter: "<<endl;
	// for(int i = 0; i <vrr.size(); i++)
    // {
    //     cout<<vrr[i]<<" ";
    // }
    return(0);
}