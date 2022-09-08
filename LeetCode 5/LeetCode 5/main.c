#include <stdio.h>
#include <stdlib.h>

//7,1,5,3,6,4

int maxProfit1(int* prices, int pricessize)
{
	if (pricessize <= 1)
		return 0;
	int max = 0;
	int profit = 0;
	profit = maxProfit(prices, pricessize - 1);
	if (profit > max)
		max = profit;

	for (int i = 1; i <= pricessize - 1; i++)
	{
		profit = maxProfit(prices, i) + prices[pricessize - 1] - prices[i - 1];
		if (profit > max)
			max = profit;
	}
	return max;
}





int main()
{
	int arr[] = { 7,1,5,3,6,4 };
	int max = maxProfit1(arr, 6);
	printf("%d", max);
	return 0;
}