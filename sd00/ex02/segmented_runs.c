#include "segmented_runs.h"

// controllo che il segmento
// - contenga almeno 3 numeri
// - il precedente sia strettamente minore
// - il successivo sia strettamente maggiore
int contains_strictly_increasing_sequence(const int *arr, int start_index, int l)
{
    int i;

    if (!arr || l < 3 || start_index < 0)
        return (0);
    i = start_index + 1;
    while (i < start_index + l - 1)
    {
        if (arr[i - 1] == (arr[i] - 1)
        && arr[i + 1] == (arr[i] + 1))
        {
            // printf("contiene sequenza: %d %d %d\n", arr[i - 1], arr[i], arr[i + 1]);
            return (1);
        }
        i++;
    }
    return (0);
}

int count_segments(const int *arr, int size)
{
    int count;
    int i;
    int start;

    start = 0;
    count = 0;
    i = 0;
    if (!arr || size <= 0)
        return (-1);
    while (i < size)
    {
        if (arr[i] == -1 || i == size - 1)
        {
            if (i == size - 1)
                count += contains_strictly_increasing_sequence(arr, start, i - start + 1);
            else
                count += contains_strictly_increasing_sequence(arr, start, i - start);
            start = i + 1;
        }
        i++;
    }
    return (count);
}

// #include <stdio.h>
// int main(void)
// {
//     int arr[] = {1, 2, 3, -1, 10, 11, 13, 1, -1, 20, -1, 0, 1, -1, 1, 4, 5, 6};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     printf("count = %d\n", count_segments(arr, size));
// }