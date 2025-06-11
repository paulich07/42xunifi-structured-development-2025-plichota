#ifndef CRITICAL_WINDOWS_H
# define CRITICAL_WINDOWS_H

# ifndef RANGE
#  define RANGE 5
# endif

int is_critical(const int *readings, int start_index);
int count_critical_windows(const int *readings, int size);

#endif
