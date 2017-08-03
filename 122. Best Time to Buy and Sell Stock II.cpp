/*
122. Best Time to Buy and Sell Stock II
*/

#include<stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int minprice = prices[0];
    int profit = 0;
    for( int i = 0; i < pricesSize; i++ ){
		if( prices[i] > minprice ){
			profit += prices[i] - minprice;
		}
		minprice = prices[i];
    }
    return profit;
}
