#include<iostream>

using namespace std;

void ReverString(char* str, int n)
{
    int left = 0;
    int right = n-1;
    while (right > left)
    {
        swap(str[left], str[right]);
        left++;
        right--;
    }
    
}

int main(void)
{
    char str[] = {"Kamlesh Dugade"};

    cout<<"Before: "<<str<<endl;

    ReverString(str, strlen(str));

    cout<<"After: "<<str<<endl;

    return(0);
}
