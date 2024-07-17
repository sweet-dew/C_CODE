#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int find_peak(int nums[],int len);
int main()
{
	int nums1[] = { 1,2,3,1};
	int nums2[] = { 1,2,1,3,5,6,4 };

	printf("%d", find_peak(nums2,7));
	return 0;
}

int find_peak(int nums[],int len)
{
	int left = -1, right = len - 1;
	int mid = 0;
	while((left + 1) < right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] > nums[mid + 1]) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	return right;
}
