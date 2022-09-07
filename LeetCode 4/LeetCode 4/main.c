#include <stdio.h>
#include <string.h>


void moveZeroes(int* nums, int numsize)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < numsize; i++)
	{
		if (nums[i] == 0)
		{
			for (j = i; j < numsize-1; j++)
			{
				nums[j] = nums[j + 1];
			}
			nums[numsize-1] = 0;
		}
	}
}


int main()
{
	int arr[10] = { 0,1,0,3,12,6,0,9,0,3 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	moveZeroes(arr, 10);

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}