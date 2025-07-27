#include<iostream>
#include<vector>

using namespace std;

bool isCelebrety(int (*matrix)[4], int row, int column, int *celebrity)
{
    vector<int> pos;
    
    int posi = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(matrix[i][j]==1)
            {
                pos.push_back(j);
               
                static int const  num = pos[i];
                posi = num;
            }
        }
    }

    for(int i = 0; i < pos.size(); i++)
    {
        cout<<"Pos: "<<pos[i]<<" ";
        if(pos[i] != posi)
        {
            return false;
        }
    }
    
    *celebrity = posi;
    return true;
}

bool knows(int (*matrix)[4], int a, int b) { return matrix[a][b]; }

int isCelebretyEx(int (*matrix)[4], int row, int column)
{
    int indegree[4] = { 0 }, outdegree[4] = { 0 };
 
    // query for all edges
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int x = knows(matrix, i, j);
 
            // set the degrees
            outdegree[i] += x;
            indegree[j] += x;
        }
    }
 
    // find a person with indegree n-1
    // and out degree 0
    for (int i = 0; i < 4; i++)
        if (indegree[i] == 4 - 1 && outdegree[i] == 0)
            
            return i;
 
    return -1;
}

int main(void)
{
    int MATRIX[4][4] = { { 0, 0, 1, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 1, 0 },
                      { 0, 0, 1, 0 } };
    //int MATRIX[4][4] = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 1, 0} };
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<<MATRIX[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    bool bret = false;
    int celebrity = 0;
    int id = isCelebretyEx(MATRIX, 4, 4);
    // if(bret)
    //     cout<<"\nFound Celebrety at "<<celebrity<<endl;
    // else
    //     cout<<"\nNot found!!"<<endl;

    
    id == -1 ? cout << "No celebrity"
             : cout << "Celebrity ID " << id;
    
    return(0);
}