#ifndef MOVIE_TYPES_H
# define MOVIE_TYPES_H

typedef struct s_movie
{
    int     id;
    char    *title;
    char    *genre;
    int     watched;
    int     rating;
    char    *date;
    struct s_movie *next;
}   t_movie;

typedef struct s_watchlist
{
    t_movie *head;
    int     count;
    int     max_id;
}   t_watchlist;

typedef struct s_genre_stats
{
    char    *genre;
    int     count;
    int     total_rating;
    float   average;
}   t_genre_stats;

#endif
