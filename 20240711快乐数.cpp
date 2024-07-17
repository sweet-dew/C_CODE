#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

bool isHappyNum(int num);
void main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d", isHappyNum(num));
}

bool isHappyNum(int num)
{
	int a = 0, b = 0, c = 0;
	int Num[230] = { 0 },n=0;
	while (1)
	{
		a = num / 100;
		b = (num / 10) % 10;
		c = num % 10;
		num = pow(a, 2) + pow(b, 2) + pow(c, 2);
		if (num == 1) {
			return true;
		}
		else 
		{
			for (int i = 0; i < n; i++)
			{
				if (num == Num[i]) {
					return false;
				}
			}
			Num[n++] = num;
		}		
	}
}