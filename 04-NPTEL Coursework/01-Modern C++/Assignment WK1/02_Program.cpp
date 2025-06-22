#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
    char data[] = {'a', 'b', 'c', 'd', 'e'};
    char key = 'd';
    if(binary_search(data, data+5, key)){
        cout<<"found";
    }else{
        cout<<"not found";
    }
    
    return(0);
}
