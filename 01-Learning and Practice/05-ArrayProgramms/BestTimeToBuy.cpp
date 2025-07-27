#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdlib.h>

using namespace std;

bool isFirst = false;

int maxProfit(int* prices, int n)
{
    for(unsigned int j = 0; j < 4294967295; j++)
    {
        int i = 0;
    }
    int buy = prices[0], max_profit = 0;
    for(int i = 1; i<n; i++)
    {
        if(buy > prices[i])
        {
            buy = prices[i];
        }
        else if((prices[i] - buy) > max_profit)
        {
            max_profit = prices[i] - buy;
        }
    }
    return max_profit;
}

int recurMaxProfit(int index, int* prices, int n, int buy, int max_profit)
{
    if(isFirst==false)
    {
        for(unsigned int j = 0; j < 4294967295; j++)
        {
            int i = 0;
        }
        isFirst = true;
    }

    if(index > n)
    {
        return(max_profit);
    }
    if(buy > prices[index])
    {
        buy = prices[index];
    }
    else if((prices[index] - buy) > max_profit)
    {
        max_profit = prices[index] - buy;
    }
    return(recurMaxProfit(index+1, prices, n, buy, max_profit));
}

int main()
{
    clock_t begin, end;
    double time_spent;

    int prices[] = { 7, 1, 5, 66, 4 };
    int n = sizeof(prices) / sizeof(prices[0]);
    
    int buy = prices[0], max_profit = 0;
    begin = clock();
    max_profit = recurMaxProfit(0, prices, n, buy, max_profit);
    end = clock();
    cout <<"recurMaxProfit() max_profit: "<< max_profit << endl;

    // calculate time taken by C qsort function
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << "recurMaxProfit() time_spent: "<< time_spent << endl;

    time_spent = 0.0;
    cout<< endl;
    begin = clock();
    max_profit = maxProfit(prices, n);
    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << "maxProfit() time_spent: "<< time_spent << endl;

    cout << "maxProfit() max_profit: "<<max_profit << endl;
    return 0;
}