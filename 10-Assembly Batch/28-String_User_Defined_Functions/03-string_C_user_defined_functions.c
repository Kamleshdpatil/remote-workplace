#include<stdio.h>
#include<stdlib.h>

int mystrlen(const char *pszStr);                           // Done
char* mystrcat(char *pszDest, const char *pszSrc);          // Done
char* mystrncat(char *pszDest, const char *pszSrc, int n);  // Done
char* mystrcpy(char *pszDest, const char *pszSrc);          // Done
char* mystrset(char *pszStr, char chChar);                  // Done
char* mystrupr(char *pszStr);                               // Done                          
char* mystrrev(char *pszStr);                               // Done

int mystrcmp(const char *pszStr1, const char *pszStr2);     // Done

char* mystrchr(const char *pszStr, char chKey);             // Done
char* mystrrchr(const char *pszStr, char chKey);            // Done
char* mystrstr(const char *pszStr, const char *pSubStr);    // Done

void printStr(const char *pszStr)
{
    int len = 0;
    while(pszStr[len] != '\0'){
        printf("%c", pszStr[len++]);
    }
    printf("\n");
}

int main()
{
    char* fName = malloc(10 * sizeof(char));
    mystrcpy(fName, "Kamlesh");
    
    char lName[] = "Dugade";

    // mystrcat(fName, lName);
    // mystrncat(fName, lName, 3);
    // mystrset(fName, '*');
    // mystrupr(fName);
    // mystrrev(fName);

    // char fName2[] = "Kamlesh";
    // if(mystrcmp(fName, fName2))
    // {
    //     printf("Looks Same !!\n");
    // }else{
    //     printf("Looks Diff !!\n");
    // }

    // char* res = mystrchr(fName, 'm');
    // if(res != NULL)
    // {
    //     printStr(res);
    // }

    // char* res = mystrrchr(fName, 'a');
    // if(res != NULL)
    // {
    //     printStr(res);
    // }

    char* res = mystrstr(fName, "l");
    if(res != NULL)
    {
        printStr(res);
    }
}

int mystrlen(const char *pszStr)
{
    int len = 0;
    while(pszStr[len] != '\0'){len++;}

    return len;
}

char* mystrcat(char *pszDest, const char *pszSrc)
{
    int srcLen = mystrlen(pszSrc);
    int destLen = mystrlen(pszDest);
    int totalSize = (destLen + srcLen)+1;

    char* temp = realloc(pszDest, totalSize);
    if(temp == NULL)
    {
        printf("\nllocation failed !");
        return NULL;
    }
    pszDest = temp;
    int destIndex = destLen;

    for(int i = 0; i < srcLen; i++)
    {
        pszDest[destIndex++] = pszSrc[i];
    }
    pszDest[destIndex] = '\0';

    return pszDest;
}

char* mystrncat(char *pszDest, const char *pszSrc, int n)
{
    int srcLen = mystrlen(pszSrc);
    int destLen = mystrlen(pszDest);

    int totalSize = (destLen + n)+1;

    char* temp = realloc(pszDest, totalSize);
    if(temp == NULL)
    {
        printf("\nllocation failed !");
        return NULL;
    }
    pszDest = temp;
    int destIndex = destLen;

    for(int i = 0; i < n; i++)
    {
        pszDest[destIndex++] = pszSrc[i];
    }
    pszDest[destIndex] = '\0';

    return pszDest;
}

char* mystrcpy(char *pszDest, const char *pszSrc)
{
    int srcLen = mystrlen(pszSrc);
    int destLen = mystrlen(pszDest);

    if(srcLen > destLen)
    {
        char* temp = realloc(pszDest, srcLen);
        if(temp == NULL)
        {
            printf("\nllocation failed !");
            return NULL;
        }
        pszDest = temp;
    }

    for(int i = 0; i < srcLen; i++)
    {
        pszDest[i] = pszSrc[i];
    }
    pszDest[srcLen] = '\0';

    return pszDest;
}

char* mystrset(char *pszStr, char chChar)
{
    int len = mystrlen(pszStr);
    for(int i = 0; i < len; i++)
    {
        pszStr[i] = chChar;
    }

    return pszStr;
}

char* mystrupr(char *pszStr)
{
    int len = mystrlen(pszStr);
    for(int i = 0; i < len; i++)
    {
        if(pszStr[i] >= 'a' && pszStr[i] <= 'z')
        {
            pszStr[i] = pszStr[i] - 32;
        }
    }

    return pszStr;
}

char* mystrrev(char *pszStr)
{
    int end = mystrlen(pszStr)-1;
    int start = 0;
    while (start < end)
    {
        char ch = pszStr[start];
        pszStr[start] = pszStr[end];
        pszStr[end] = ch;

        end--;
        start++;
    }
    return pszStr;
}

int mystrcmp(const char *pszStr1, const char *pszStr2)
{
    int len = mystrlen(pszStr1)-1;
    int len2 = mystrlen(pszStr2)-1;
    if(len != len2) return 0;

    int start = 0;
    while (start < len)
    {
        if(pszStr1[start] != pszStr2[start])
        {return 0;}
        start++;
    }
    return 1;
}

char* mystrchr(const char *pszStr, char chKey)
{
    if (pszStr[0] == chKey) {
        return (char*)pszStr;
    }

    int start = 0;
    while (pszStr[start] != '\0')
    {
        if(pszStr[start] == chKey)
        {
            return (char*)&pszStr[start];
        }
        start++;
    }
    return NULL;
}

char* mystrrchr(const char *pszStr, char chKey)
{
    int end = mystrlen(pszStr);
    while (end >= 0)
    {
        if(pszStr[end] == chKey)
        {
            return (char*)&pszStr[end];
        }
        end--;
    }
    return NULL;
}

char* mystrstr(const char *pszStr, const char *pSubStr)
{
    if (pSubStr[0] == '\0') {
        return (char*)pszStr;
    }

    int start = 0;
    while (pszStr[start] != '\0')
    {
        int j = 0;
        while (pszStr[start + j] == pSubStr[j] && pSubStr[j] != '\0')
        {
            j++;
        }

        if(pSubStr[j] == '\0')
            return (char*)&pszStr[start];
        start++;
    }
    return NULL;
}
