/* Given two sorted arrays, the task is to merge them in a sorted manner.

    Input: arr1[] = { 1, 3, 4, 5}, arr2[] = {2, 4, 6, 8} 
    Output: arr3[] = {1, 2, 3, 4, 4, 5, 6, 8}

    Input: arr1[] = { 5, 8, 9}, arr2[] = {4, 7, 8} 
    Output: arr3[] = {4, 5, 7, 8, 8, 9} 
*/
#include<iostream>
#include<cstdlib>
using namespace std;

int mergeTwoSortedArrays(int arr1[], int n1, int arr2[], int n2, int* mergeArray)
{
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            mergeArray[k++] = arr1[i++];
        }
        else {
            mergeArray[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1 (if any)
    while(i < n1){
        mergeArray[k++] = arr1[i++];
    }

    // Copy remaining elements from arr2 (if any)
    while(j < n2){
        mergeArray[k++] = arr2[j++];
    }

    return k; // Total size of merged array
}

int main()
{
    int arr1[] = {5, 8, 9}, arr2[] = {4, 7, 8};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    int* mergeArray = (int*)malloc((n1 + n2) * sizeof(int));

    int finalSize = mergeTwoSortedArrays(arr1, n1, arr2, n2, mergeArray);
    
    for(int i = 0; i < finalSize; i++){
        cout << mergeArray[i] << " ";
    }

    cout << endl;
    free(mergeArray);
    return 0;
}
