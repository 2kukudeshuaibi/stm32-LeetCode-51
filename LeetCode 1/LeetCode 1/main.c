#include <stdio.h>
#include <string.h>



//�ҵ�һ��������ֻ����һ�ε���
int singleNumber(int* nums, int numsize)
{
	/*��һ�ַ���
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < numsize; i++)
	{
		for (j = 0; j < numsize; j++)
		{
			if (nums[i] == nums[j])
			{
				count++;
			}
		}
		if (count == 1)
		{
			break;
		}
	}
	return nums[i];*/



	int i = 0;
	int tmp = *nums;
	for (i = 1; i < numsize; i++)
	{
		tmp = tmp ^ nums[i];
	}
	return tmp;
}

int main()
{
	int arr[9] = { 4,1,2,1,2 ,5,6,6,5 };
	printf("%d", singleNumber(arr, 9));
	return 0;
}