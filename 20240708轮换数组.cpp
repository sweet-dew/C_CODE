#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


void takeTurns1(int nums[], int n, int k);
void takeTurns2(int nums[], int n, int k);
void takeTurns3(int nums[], int n, int k);
void takeTurns4(int nums[], int n, int k);

void main()
{
	int nums[7] = { 1,2,3,4,5,6,7 };
	int n=7,k=3;
	takeTurns4(nums, n, k);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", nums[i]);
	}	
}


void takeTurns1(int nums[], int n, int k)
{
	k = k % n;
	int last = 0;
	while (k--)
	{
		last = nums[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			nums[i] = nums[i - 1];
		}
		nums[0] = last;
	}
}


void takeTurns2(int nums[], int n,int k)
{
	k = k % n;
	k = n - k;
	int first = 0;
	while (k--)
	{
		first = nums[0];
		for (int i = 0; i < n - 1; i++)
		{
			nums[i] = nums[i + 1];
		}
		nums[n - 1] = first;
	}	
}


void takeTurns3(int nums[], int n, int k)
{
	k = k % n;
	int temps[105] = { 0 };
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (i < k) {
			temps[i] = nums[n - k + i];
		}
		else {
			temps[i] = nums[i - k];
		}
	}
	for (i = 0; i < n; i++)
	{
		nums[i] = temps[i];
	}
}


void swap(int a[],int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		int temp = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = temp;
	}	
}
void takeTurns4(int nums[], int n, int k)
{
	k = k % n;
	swap(nums, n);
	swap(nums, k);
	swap(&nums[k], n - k);
}