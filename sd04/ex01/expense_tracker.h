#ifndef EXPENSE_TRACKER_H
# define EXPENSE_TRACKER_H

# ifndef MAX_RECORDS
#  define MAX_RECORDS 1000
# endif

# ifndef MAX_LINE_LEN
#  define MAX_LINE_LEN 1024
# endif

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_record
{
  char    *date;
  float   amount;
  char    *category;
  char    *description;
  struct s_record *next;
} t_record;

typedef struct s_dataset
{
  t_record  *records;
  int       count;
} t_dataset;

typedef struct s_category_total
{
  char  *category;
  float total;
  float percentage;
} t_category_total;

// Core functions
int     load_records(const char *filename, t_dataset *dataset);
int     add_to_dataset(t_dataset *dataset, t_record *record);
t_record *create_entry(char *date, float amount, char *category, char *description);
void    filter_by_category(t_dataset *input, t_dataset *output, const char *query);
void    filter_by_date_range(t_dataset *input, t_dataset *output, const char *start, const char *end);
void    copy_dataset(t_dataset *src, t_dataset *dst);
void    compute_summary(t_dataset *data, float *total, float *average);
int     compute_category_breakdown(t_dataset *data, t_category_total **output);
void    print_summary(t_dataset *data);
void    print_category_breakdown(t_category_total *list, int count);

// Utilities
char    *ft_trim(char *str);
char    *ft_tolower(const char *str);
int     ft_strnstr_ci(const char *hay, const char *needle);
int     is_valid_input(const char *input);
int     is_valid_date(const char *str);
int     compare_dates(const char *d1, const char *d2);
int     is_empty_line(const char *str);
void    print_record(const t_record *rec);
void    free_dataset(t_dataset *data);
void    free_line_and_tokens(char *line, char **tokens);
void    safe_free(void **ptr);

#endif
