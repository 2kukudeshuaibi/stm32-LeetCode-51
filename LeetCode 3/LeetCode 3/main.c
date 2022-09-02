#include <stdio.h>
#include <string.h>



//求一个数组中 最大的子数组
int maxSubArray(int* nums, int numsize)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int max = 0;
	int sum = 0;
	for (i = 0; i < numsize; i++)//    0<--->9
	{
		for (j = i; j < numsize; j++)//  i<---->9
		{
			for (k = i; k <= j; k++)//   i<---->j
			{
				sum += nums[k];
			}
			if (sum > max)
			{
				max = sum;
			}
			sum = 0;
		}
	}
	return max;
}


int main()
{
	int arr[9] = { -2,1,-3,4,-1,2,1,-5,4 };
	int a = maxSubArray(arr, 9);
	printf("%d ", a);
	return 0;
}