#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>

using namespace std;

#define ASCII_SIZE 256

template<class T>
void CountCharFrequencyUsingMap(T* arr, int size)
{
    map<T, int> mp;

    for(int i = 0; i < size; i++)
    {
        char ch = arr[i];
        ch = toupper(ch);
        if(ch != ' ')
            if(ch != '\0')
                mp[ch]++;
    }
    // Traverse through map and print frequencies
    for (auto x : mp)
        cout << x.first << ": " << x.second << endl;
}


void CountIntegerFrequencyUsingMap(int* arr, int size)
{
    unordered_map<int, int> mp;

    for(int i = 0; i < size; i++)
    {
        mp[arr[i]]++;
    }
    // Traverse through map and print frequencies
    for (auto x : mp)
        cout << x.first << ": " << x.second << endl;
}

void CountFrequencyOfEachElement(int* arr, int size)
{
    int count = 1;
    // Mark all array elements as not visited
    vector<bool> visited(size, false);

    for(int i = 0; i < size; i++)
    {
        if(visited[i]==true)
            continue;

        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                visited[j]=true;
            }
        }
        cout<<"Count of: "<<arr[i]<<" is: "<<count<<endl;
        count = 1;
    }
}

void getMaxOccurringChar(char* str)
{
    int count[ASCII_SIZE] = {0};

    int iSize = strlen(str);
    int max = 0;
    char maxChar;

    for(int i = 0; i < iSize; i++)
    {
        count[(int)str[i]]++;
        printf(" %c is %d times\n", str[i], count[(int)str[i]]);
    }
}

void ReverseString(char* str)
{
    int n = strlen(str);
    int l = 0, r =  n- 1;
    cout<<"Before loop: "<<str<<endl;
    for(int i = 0; i<= n/2; i++)
    {
        swap(str[l], str[r]);
        r--;
        l++;
    }
    
}

int main(void)
{
    char str[] = {"KamleshDugade"};
    int arr[] = {10, 20, 20, 10, 10, 20, 5, 20};

    int size = sizeof(arr)/sizeof(arr[0]);
    int n = sizeof(str)/sizeof(str[0]);
    //CountFrequencyOfEachElement(arr, size);
    //CountIntegerFrequencyUsingMap(arr, size);
    //CountCharFrequencyUsingMap(str, n);
    //getMaxOccurringChar(str);
    ReverseString(str);
    cout<<"After loop: "<<str<<endl;
    return(0);
}