/*
121. Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/
#include<stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int minprice = prices[0];
    int profit = 0;
    for( int i = 0; i < pricesSize; i++ ){
		if( prices[i] < minprice ){
			minprice = prices[i];
		}else if( prices[i] - minprice > profit ){
			profit = prices[i] - minprice;
		}
    }
    return profit;
    
}

int main()
{
	int prices[4] = {2,7,1,4};
	int pricesSize = 4;
	int res = maxProfit(prices,pricesSize);
	printf("%d\n",res);
}


















