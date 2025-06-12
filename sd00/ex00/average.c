#include "average.h"

int     is_between_0_and_100(int n)
{
	return (n >= 0 && n <= 100);
}

float   average(const int *arr, int size)
{
	int i;
	int sum;
	int n;

	i = 0;
	sum = 0;
	n = 0;
	if (size <= 0 || !arr)
		return ((float) 0);
	while (i < size)
	{
		if (is_between_0_and_100(arr[i]))
		{
			sum += arr[i];
			n++;
		}
		i++;
	}
	return (((float) sum) / n);
}

// #include <stdio.h>
// int main(void)
// {
//     int arr[] = {1, 2, -1, 10};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     printf("final sum = %f\n", average(arr, 0));
// }