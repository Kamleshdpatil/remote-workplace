#include<iostream>

using namespace std;

int main(void)
{
    void SquarPattern(int);
    void RightTringlePattern(int);
    void RightTringleNumberPattern(int);
    void RightTringleNumberSamePattern(int);
    void ReverseRightTringlePattern(int);
    void ReverseRightTringleNumberPattern(int);
    void ReverseRightTringleNumberSamePattern(int);
    void EquilateralTringlePattern(int);
    void ReverseEquilateralTringlePattern(int);
    void TwoRightTringleReversAndStraightPattern(int);
    void RightTringleZeroOneZeroOnePattern(int);
    void MaharajaTaajPattern(int);
    void SquarTwoTaajPattern(int);
    void DamruPattern(int);

    int n = 0;
    std::cout<<"Enter number for pattern: ";
    cin>>n;

    //SquarPattern(n);
    //RightTringlePattern(n);
    //RightTringleNumberPattern(n);
    //RightTringleNumberSamePattern(n);
    //ReverseRightTringlePattern(n);
    //ReverseRightTringleNumberPattern(n);
    //ReverseRightTringleNumberSamePattern(n);
    //EquilateralTringlePattern(n);
    //ReverseEquilateralTringlePattern(n);
    //TwoRightTringleReversAndStraightPattern(n);
    //RightTringleZeroOneZeroOnePattern(n);
    //MaharajaTaajPattern(n);
    //SquarTwoTaajPattern(n);
    DamruPattern(n);

    return(0);
}

void DamruPattern(int num)
{
    int space = (2 * num) - 2;
    for(int i = 1; i <= (2 * num) - 1; i++)
    {

        int stars = i;
        if(i > num)
            stars = (2 * num) - i;
        // Stars
        for(int j = 1; j <= stars; j++)
        {
            std::cout<<"*";
        }

        // Space
        for(int j = 1; j<= space; j++)
        {
            std::cout<<" ";
        }

        // Stars
        for(int j = 1; j <= stars; j++)
        {
            std::cout<<"*";
        }

        std::cout<<endl;

        if(i < num)
            space = space - 2;
        else
            space = space + 2;

    }

}

void SquarTwoTaajPattern(int num)
{
    int space = 0;

    for(int i = 0; i < num; i++)
    {
        // Stars
        for(int j = 1; j <= num - i; j++)
        {
            std::cout<<"*";
        }

        // space
        for(int j = 0; j <= space; j++)
        {
            std::cout<<" ";
        }

        // Stars
       for(int j = 1; j <= num - i; j++)
        {
            std::cout<<"*";
        }
        space = space+2;
        std::cout<<endl;
    }
    space = (2 * num) -2;
    for(int i = 1; i <= num; i++)
    {
        // Stars
        for(int j = 1; j <= i; j++)
        {
            std::cout<<"*";
        }

        // space
        for(int j = 0; j <= space; j++)
        {
            std::cout<<" ";
        }

        // Stars
       for(int j = 1; j <= i; j++)
        {
            std::cout<<"*";
        }
        space = space-2;
        std::cout<<endl;
    }
}

void MaharajaTaajPattern(int num)
{
    int space = 2 * (num-1);
    for(int i = 1; i <= num; i++)
    {
        // Number
        for(int j = 1; j <= i; j++)
        {
            cout<<j;
        }
        // space
        for(int j = 1; j <= space; j++)
        {
            cout<<" ";
        }
        // Number
        for(int j = i; j >= 1; j--)
        {
            cout<<j;
        }
        cout<<endl;
        space = space-2;
    }
}

void RightTringleZeroOneZeroOnePattern(int num)
{
    int start = 1;
    for(int i = 0; i < num; i++)
    {
        if(i % 2 == 0)
            start = 1;
        else
            start = 0;

        for(int j = 0; j <= i; j++)
        {
            cout<<start<<" ";
            start = 1 - start;
        }
        
        cout<<endl;
    }
}

void TwoRightTringleReversAndStraightPattern(int num)
{
    for(int i = 1; i <= (num * 2) - 1; i++)
    {
        int stars = i;
        if(i > num)
            stars = (2 * num) - i;
        for(int j = 0; j < stars; j++)
        {
            cout<<"* ";
        }
        
        cout<<endl;
    }
}

void ReverseEquilateralTringlePattern(int num)
{
    for(int i = 0; i < num; i++)
    {
        //space
        for(int j = 0; j < i; j++)
        {
            cout<<" ";
        }

        // stars
        for(int j = 0; j <(2 * num - ((2*i) + 1)); j++)
        {
            cout<<"*";
        }

        //space
        for(int j = 0; j < i; j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }

    // for(int i = num; i > 0; i--)
    // {
    //     //space
    //     for(int j = num-i+1; j > 0; j--)
    //     {
    //         cout<<" ";
    //     }

    //     // stars
    //     for(int j = 2*i-1; j > 0; j--)
    //     {
    //         cout<<"*";
    //     }

    //     //space
    //     for(int j = num-i+1; j > 0; j--)
    //     {
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }
}

void EquilateralTringlePattern(int num)
{
    for(int i = 0; i < num; i++)
    {
        //space
        for(int j = 0; j<num-i-1; j++)
        {
            cout<<" ";
        }

        // stars
        for(int j = 0; j < (2*i+1); j++)
        {
            cout<<"*";
        }

        //space
        for(int j = 0; j<num-i-1; j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}

void ReverseRightTringleNumberSamePattern(int num)
{
    for(int i = 1; i <= num; i++)
    {
        for(int j = 1; j <= num-i+1; j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void ReverseRightTringleNumberPattern(int num)
{
    for(int i = 1; i <= num; i++)
    {
        for(int j = 1; j <= num-i+1; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void ReverseRightTringlePattern(int num)
{
    for(int i = num; i >= 1; i--)
    {
        for(int j = i; j >= 1; j--)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

void RightTringleNumberSamePattern(int num)
{
    for(int i = 1; i <= num; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void RightTringleNumberPattern(int num)
{
    for(int i = 1; i <= num; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void RightTringlePattern(int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

void SquarPattern(int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}