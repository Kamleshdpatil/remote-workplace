#include <cstdio>
using namespace std;

int main()
{
    FILE *infp, *outfp;

    if ((infp = fopen("myfile.txt", "r")) == NULL)
        return -1;
    if ((outfp = fopen("procfile.txt", "w")) == NULL)
        return 2;

    int c;
    while ((c = fgetc(infp)) != EOF)
    {
        if (c == ' ' || c == '\n')
            ;
        else
            fputc(c, outfp);
    }

    fclose(infp);
    fclose(outfp);

    return 0;
}
