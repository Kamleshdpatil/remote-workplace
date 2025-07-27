#include<stdbool.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include <cctype>
#include<vector>
#include<map>

using namespace std;

void printArray(const char *arr, int size)
{
    printf("\n");
    for(int i = 0; i < size; i++)
    {
        printf("Arr[%d]= %c\n", i, arr[i]);
    }
    printf("\n");
}

int main(void)
{
    void DisplayAlphabetCount(char[], int, char[], int);
    char paragraph[1024] = "BBBBB YYZZ WWKKJJHLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\0";
    char alphabet[28] = "abcdefghijklmnopqrstuvwxyz\0";

    map<char, int> mapObj;
    vector<char> vecPara;
    vector<char> vecAlpha;
    map<char, int> map;

    for(int itr = 0; itr<strlen(paragraph); itr++)
    {
        vecPara.push_back(paragraph[itr]);
    }
    
    for(int itr = 0; itr<strlen(alphabet); itr++)
    {
        vecAlpha.push_back(alphabet[itr]);
    }

    // for(int i = 0; i< 26; i++)
    // {
    //     map.insert({'A'+i, i+1});
    // }

    for(auto itr = 0; itr < vecPara.size(); itr++)
    {
        if(tolower((vecPara[itr]) >= 'a') || tolower((vecPara[itr]) <= 'z'))
        {
            map.insert({tolower(vecPara[itr]), 0});
        }
    }

    
    for(auto itr = 0; itr < vecPara.size(); itr++)
    {
        mapObj.insert(map.find(vecPara[itr]), 0);
    }
    


    //DisplayAlphabetCount(paragraph, paraSize, alphabet, alphaSize);

    return(0);
}



void DisplayAlphabetCount(char* const paragraph, int paraSize, char* const alphabet, int alphaSize)
{
    int iA = 0;
    int iB = 0;
    int iC = 0;
    int iD = 0;
    int iE = 0;
    int iF = 0;
    int iG = 0;
    int iH = 0;
    int iI = 0;
    int iJ = 0;
    int iK = 0;
    int iL = 0;
    int iM = 0;
    int iN = 0;
    int iO = 0;
    int iP = 0;
    int iQ = 0;
    int iR = 0;
    int iS = 0;
    int iT = 0;
    int iU = 0;
    int iV = 0;
    int iW = 0;
    int iX = 0;
    int iY = 0;
    int iZ = 0;
    
    for(int i = 0; i<paraSize; i++)
    {
        switch (tolower(paragraph[i]))
        {
        case 'a':
            iA++;
            break;
        case 'b':
            iB++;
            break;
        case 'c':
            iC++;
            break;
        case 'd':
            iD++;
            break;
        case 'e':
            iE++;
            break;
        case 'f':
            iF++;
            break;
        case 'g':
            iG++;
            break;
        case 'h':
            iH++;
            break;
        case 'i':
            iI++;
            break;
        case 'j':
            iJ++;
            break;
        case 'k':
            iK++;
            break;
        case 'l':
            iL++;
            break;
        case 'm':
            iM++;
            break;
        case 'n':
            iN++;
            break;
        case 'o':
            iO++;
            break;
        case 'p':
            iP++;
            break;
        case 'q':
            iQ++;
            break;
        case 'r':
            iR++;
            break;
        case 's':
            iS++;
            break;
        case 't':
            iT++;
            break;
        case 'u':
            iU++;
            break;
        case 'v':
            iV++;
            break;
        case 'w':
            iW++;
            break;
        case 'x':
            iX++;
            break;
        case 'y':
            iY++;
            break;
        case 'z':
            iZ++;
            break;
        default:
            break;
        }
    }

    cout<<"iA = "<<iA<<endl;
    cout<<"iB = "<<iB<<endl;
    cout<<"iC = "<<iC<<endl;
    cout<<"iD = "<<iD<<endl;
    cout<<"iE = "<<iE<<endl;
    cout<<"iF = "<<iF<<endl;
    cout<<"iG = "<<iG<<endl;
    cout<<"iH = "<<iH<<endl;
    cout<<"iI = "<<iI<<endl;
    cout<<"iJ = "<<iJ<<endl;
    cout<<"iK = "<<iK<<endl;
    cout<<"iL = "<<iL<<endl;
    cout<<"iM = "<<iM<<endl;
    cout<<"iN = "<<iN<<endl;
    cout<<"iO = "<<iO<<endl;
    cout<<"iP = "<<iP<<endl;
    cout<<"iQ = "<<iQ<<endl;
    cout<<"iR = "<<iR<<endl;
    cout<<"iS = "<<iS<<endl;
    cout<<"iT = "<<iT<<endl;
    cout<<"iU = "<<iU<<endl;
    cout<<"iV = "<<iV<<endl;
    cout<<"iW = "<<iW<<endl;
    cout<<"iX = "<<iX<<endl;
    cout<<"iY = "<<iY<<endl;
    cout<<"iZ = "<<iZ<<endl;

}