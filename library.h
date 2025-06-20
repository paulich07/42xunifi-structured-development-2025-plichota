#ifndef LIBRARY_H
#define LIBRARY_H

# ifndef MAX_BOOKS
#  define MAX_BOOKS 1000
# endif

# ifndef MAX_LINE_LEN
#  define MAX_LINE_LEN 1024
# endif

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_book
{
  int     id;
  char    *title;
  char    *author;
  struct s_book   *next;
} t_book;

typedef struct s_catalog
{
  t_book  *books;
  int     count;
} t_catalog;


int     load_catalog(const char *filename, t_catalog *catalog);
int     add_to_catalog(t_catalog *catalog, t_book *book);
t_book  *create_entry(char *id, char *title, char *author);
void    search_by_title(t_catalog *catalog, const char *query);
void    search_by_author(t_catalog *catalog, const char *query);


// Utilities
char    *ft_trim(char *str);
char    *ft_tolower(const char *str);
int     ft_strnstr_ci(const char *hay, const char *needle);
int     is_valid_input(const char *input);
int     is_empty_line(const char *str);
void    print_book(const t_book *book);
void    free_catalog(t_catalog *catalog);
void    free_line_and_tokens(line, tokens);

#endif
