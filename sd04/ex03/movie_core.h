#ifndef MOVIE_CORE_H
# define MOVIE_CORE_H

# include "movie_types.h"

int         load_movies(const char *filename, t_watchlist *list);
t_movie     *create_movie(int id, char *title, char *genre, int watched, int rating, char *date);
int         add_to_list(t_watchlist *list, t_movie *movie);
void        free_line_and_tokens(char *line, char **tokens);

void        menu_loop(t_watchlist *list, const char *filename);
void        list_movies(t_watchlist *list);
void        search_by_title(t_watchlist *list, const char *query);
void        search_by_genre(t_watchlist *list, const char *query);
void        filter_by_watch_status(t_watchlist *list, int watched);
void        add_movie(t_watchlist *list);
void        mark_as_watched(t_watchlist *list);
void        update_movie(t_watchlist *list);
void        delete_movie(t_watchlist *list);
t_movie     *find_movie_by_id(t_watchlist *list, int id);

int         save_movies(const char *filename, t_watchlist *list);

#endif
