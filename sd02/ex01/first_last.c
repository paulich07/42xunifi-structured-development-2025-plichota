void first_last(int arr[], int size, int target, int *first, int *last)
{
    int i;
    int first_saved;

    if (!arr || size < 1 || !first || !last)
        return ;
    i = 0;
    first_saved = 0;
    *first = -1;
    *last = -1;
    while (i < size)
    {
        if (arr[i] == target && !first_saved)
        {
            *first = i;
            *last = i;
            first_saved++; 
        }
        else if (arr[i] == target && first_saved)
        {
            *last = i;
        }
        i++;
    }
}

// #include <stdio.h>
// int main(void)
// {
//     int arr[] = {1, 8, 3, 4, 1};
//     int first = -1;
//     int last = -1;
//     int target = 2;
//     int size = sizeof(arr) / sizeof(arr[0]);

//     first_last(arr, size, target, NULL, &last);
//     printf("first %d, last %d\n", first, last);
// }