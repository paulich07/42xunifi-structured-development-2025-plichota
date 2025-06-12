#include "movie_planner.h"

// usare flag -c nella compilazione per evitare undefined reference in fase di


// free content of Preferences
void free_preferences(struct Preferences *preferences)
{
    free(preferences);
}

// free content of Preferences
void free_movieList(struct MovieList *movieList)
{
    free(movieList);
}

void free_all(struct Preferences *preferences, struct MovieList *movieList)
{
    if (preferences)
        free_preferences(preferences);
    if (movieList)
        free_movieList(movieList);
}

struct Plan *create_movie_night_plan(void)
{
    struct MovieList *movieList = NULL;
    struct Preferences *preferences = NULL;

    preferences = get_user_preferences();
    if (!preferences)
        return (NULL);

    movieList = find_movies(preferences);
    if (!movieList)
    {
        free_all(preferences, movieList);
        return (NULL);
    }

    struct Plan *moviePlan = build_plan(movieList);
    if (!moviePlan)
    {
        free_all(preferences, movieList);
        return (NULL);
    }

    return (moviePlan);
}