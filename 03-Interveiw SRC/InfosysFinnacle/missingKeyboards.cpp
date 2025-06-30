#include<iostream>
using namespace std;

// Find missing number in an array
bool findNumber(int arr[], int NUM, int size) {
    bool found = false;
    for(int i = 0; i < size; i++){
        if(arr[i] == NUM) {
            found = true; // Return the index of the missing number
        }
    }
    return found; // Return -1 if the number is not found
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] > max) {
            max = arr[i]; // Return the index of the missing number
        }
    }
    return max; // Return -1 if the number is not found
}

int main() {
    // int arr[] = {4, 4, 3, 2, 6, 9};
    int arr[] = {10, 13, 12, 8};
    int X = 8; // The number we are looking for
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int findMaxValue = size + X; // Find the maximum value in the array
    for(int i = X+1; i < findMaxValue; i++){
        bool isFound = findNumber(arr, i, size);
        if(isFound == false) {
            cout << "The keyboard " << i << " is Missing "<< endl;
            //break;
        }
    }
    return 0;
}
