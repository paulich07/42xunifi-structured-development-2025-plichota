#include "critical_windows.h"

static int is_critical(const int *readings, int start_index)
{
    int i;
    int count;
    int sum;

    i = 0;
    count = 0;
    sum = 0;
    while (i < RANGE)
    {
        if (readings[start_index + i] > 150)
            return (0);
        if (readings[start_index + i] >= 70)
            count++;
        sum += readings[start_index + i];
        i++;
    }
    if (count < 3)
        return (0);
    return (sum / RANGE >= 90);
}

int count_critical_windows(const int *readings, int size)
{
    int i;
    int count;
    
    if (!readings || size < 1)
        return (0);
    i = 0;
    count = 0;
    if (size < RANGE)
        return (0);
    while (i < size - RANGE + 1)
    {
        count += is_critical(readings, i);
        i++;
    }
    return (count);
}

// #include <stdio.h>
// int main(void)
// {
//     // int arr[] = {1, 60, 70, 30, 10, 141, 150, 1, -1, 23, -10, 140, 150, 130, 90, 3, 5, 6};
//     int arr[] = {100, 90, 151, 70, 90, 80, 100, 112, 120, 240};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     printf("count = %d\n", count_critical_windows(arr, size));
// }
