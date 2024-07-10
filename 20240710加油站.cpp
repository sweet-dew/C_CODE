#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int gas_station(int gas[], int cost[],int n);
void main()
{
	int gas1[5] = { 1,2,3,4,5 }, cost1[5] = { 3, 4,5,1,2 };
	int gas2[3] = { 2,3,4 }, cost2[3] = { 3, 4,3};
	printf("%d",gas_station(gas1, cost1, 5));	
}

int gas_station(int gas[],int cost[],int n)
{
	int gas_remain = 0;
	bool flag = 0;
	for (int i = 0; i < n; i++)
	{
		flag = 1;
		gas_remain = gas[i];
		for (int j = 0; j < n; j++)
		{
			int k = i + j;
			int m = i + j + 1;
			if (k  >= n) {
				k -=n;
			}
			if (m >= n) {
				m -= n;
			}

			if (gas_remain - cost[k] >= 0){
				gas_remain += (gas[m] - cost[k]);
			}
			else {
				flag = 0;
				break;
			}
		}
		if (flag) {
			return i;
		}
	}
	return -1;
}