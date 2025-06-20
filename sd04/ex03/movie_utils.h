#ifndef MOVIE_UTILS_H
# define MOVIE_UTILS_H

# include "movie_types.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

char    *ft_trim(char *str);
char    *ft_tolower(const char *str);
int     ft_strnstr_ci(const char *hay, const char *needle);
int     is_valid_id(const char *str, t_watchlist *list);
int     is_valid_rating(const char *str);
int     is_valid_date(const char *date);
int     is_valid_input(const char *input);
int     is_empty_line(const char *str);
int     is_valid_flag(const char *str);
int     parse_watched_flag(const char *str);
int     parse_rating(const char *str);
char    *read_input(const char *prompt);
void    safe_free(void **ptr);
void    free_watchlist(t_watchlist *list);

// === Stats
void    print_stats(t_watchlist *list);

#endif
