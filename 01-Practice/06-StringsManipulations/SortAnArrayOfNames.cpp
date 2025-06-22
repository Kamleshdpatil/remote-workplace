// #include<stdio.h>
// #include<iostream>
// #include<stdlib.h>

// using namespace std;
// void sort(const char** brr, int size)
// {
    
// }


// int main()
// {
 
//     // Get the array of names to be sorted
//     const char* arr[]
//         = { "geeksforgeeks", "geeksquiz", "clanguage" };
 
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int i;
 
//     // Print the given names
//     printf("Given array is\n");
//     for (i = 0; i < n; i++)
//         printf("%d: %s \n", i, arr[i]);
 
//     // Sort the given names
//     sort(arr, n);
 
//     // Print the sorted names
//     printf("\nSorted array is\n");
//     for (i = 0; i < n; i++)
//         printf("%d: %s \n", i, arr[i]);
 
//     return 0;
// }

#include<stdio.h>
#include<iostream>
#include<algorithm>

 using namespace std;
 
int main() 
{
  int n=5;
  char arr[] = "sandwich"; 
  //string arr[]={"sandwich","apple","banana","zombie","pear"}; 
  sort(arr, arr + strlen(arr), less<char>()); 
  for(int i=0;i<sizeof(arr)/sizeof(char);i++)
 { cout<<arr[i]<<" "; 
 } 
}