#include<iostream>
#include<stdbool.h>
#include<vector>

using namespace std;

void findSubArrayOfSumZero(int [] , int , vector<vector<int>>&);
void DisplayVector(vector<vector<int>>&);
int main(void)
{
    int arr[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<vector<int>> V;
    findSubArrayOfSumZero(arr, size, V);
    DisplayVector(V);
    return(0);
}

void findSubArrayOfSumZero(int a[] , int n, vector<vector<int>> &V)
{
    int i = 0, j = 0;
    int sum=0;
    for(i; i<n-1; i++) // i = 4
    {
        vector<int> temp;
        sum += a[i];
        for(j=i+1; j<n; j++) // j = -2
        {
            sum += a[j]; //0
            if(sum == 0)
            {
                for(int k=i; k<j+1; k++)
                {
                    temp.push_back(a[k]);
                }
                V.push_back(temp);
                temp.clear();
            }
        }
        sum =0;
    }
}


void DisplayVector(vector<vector<int>> &V)
{
    for(int i=0; i < V.size(); i++)
    {
        for(int j=0; j<V[i].size(); j++)
        {
            if(j == V[i].size()-1)
            {
                cout<<V[i][j]<<endl;
            }
            else
            {
                cout<<V[i][j]<<", ";
            }
        }
    }
}

