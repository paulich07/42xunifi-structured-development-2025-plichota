#include "grade_map.h"

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
    int i = 0;
    while (i < size)
    {
        mapped_grades[i] = mapper(scores[i]);
        i++;
    }
}

GradeReturn plusminus_mapper(int n)
{
    if (n >= 97)
        return ("A+");
    if (n >= 93)
        return ("A");
    if (n >= 90)
        return ("A-");
    if (n >= 87)
        return ("B+");
    if (n >= 83)
        return ("B");
    if (n >= 80)
        return ("B-");
    if (n >= 77)
        return ("C+");
    if (n >= 73)
        return ("C");
    if (n >= 70)
        return ("C-");
    if (n >= 67)
        return ("D+");
    if (n >= 63)
        return ("D");
    if (n >= 60)
        return ("D-");
    return ("F");
}

GradeReturn passfail_mapper(int n)
{
    if (n >= 60)
        return ("P");
    return ("F");
}

GradeReturn standard_mapper(int n)
{
    if (n >= 90)
        return ("A");
    if (n >= 80)
        return ("B");
    if (n >= 70)
        return ("A");
    if (n >= 60)
        return ("A");
    return ("F");
}

#include <stdio.h>

int main(void)
{
    int arr[] = {100, 90, 10, 2, 55, 78, 92};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    GradeReturn passfail_grades[size];
    GradeReturn standard_grades[size];
    GradeReturn plusminus_grades[size];

    map_scores(arr, size, passfail_mapper, passfail_grades);
    map_scores(arr, size, standard_mapper, standard_grades);
    map_scores(arr, size, plusminus_mapper, plusminus_grades);

    for (int i = 0; i < size; i++)
    {
        printf("score %3d   passfail %3s    standard %3s    plusminus %3s\n", 
            arr[i], passfail_grades[i], standard_grades[i], plusminus_grades[i]);
    }
}