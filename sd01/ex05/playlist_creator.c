#include "playlist_creator.h"

void free_all(
    struct MoodSettings *mood,
    struct FilterSettings *filters,
    struct SongData *song,
    struct Playlist *playlist
)
{
    if (mood)
        free_mood_settings(mood);
    if (filters)
        free_filter_settings(filters);
    if (song)
        free_song_data(song);
    if (playlist)
        free_playlist(playlist);
}

struct Playlist *create_playlist(void)
{
    struct MoodSettings *mood = NULL;
    struct FilterSettings *new_filters = NULL;
    struct FilterSettings *filters = NULL;
    struct SongData *song = NULL;
    struct Playlist *playlist = NULL;
    int var = 0;
    
    mood = analyze_user_mood();
    if (!mood)
    {
        free_all(mood, filters, song, playlist);
        return (NULL);
    }

    filters = default_filters();
    if (!filters)
    {
        free_all(mood, filters, song, playlist);
        return (NULL);
    }

    var = get_mood_variations(mood);
    if (var < 0)
    {
        free_all(mood, filters, song, playlist);
        return (NULL);
    }

    for (int i = 0; i < var; ++i) {
        new_filters = refine_filters(filters);

        if (!new_filters)
        {
            free_all(mood, filters, song, playlist);
            return (NULL);
        }

        if (new_filters != filters)
        {
            free_filter_settings(filters);
            filters = new_filters;
        }
    }

    if (filters_require_popular_song(filters))
        song = fetch_popular_song();
    else
        song = fetch_niche_song();

    if (!song)
    {
        free_all(mood, filters, song, playlist);
        return (NULL);
    }

    playlist = combine_with_mood_playlist(song, mood);
    if (!playlist)
    {
        free_all(mood, filters, song, playlist);
        return (NULL);
    }

    return (playlist);
}