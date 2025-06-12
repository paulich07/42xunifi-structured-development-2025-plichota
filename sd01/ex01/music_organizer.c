#include "music_organizer.h"

// scanning music files, categorizing them, and updating a
// central music database

struct MusicLibrary *create_music_library()
{
    struct MusicLibrary *library = NULL;
    // malloc?

    if (!library)
        return (NULL);
    return (library);
}

const char **scan_directory(const char *directory_path)
{
    if (!directory_path)
        return (NULL);

    return 
}

struct MusicFile *process_music_file(const char *directory_path, const char *filename)
{
    if (!directory_path || !filename)
        return (NULL);

    // cerca canzone col filename nella 
}

void update_music_library(struct MusicLibrary *library, struct MusicFile *song)
{
    if (!library || !song)
        return ;

    // to do update
}

struct MusicLibrary *organize_music_library(const char *directory_path)
{
    struct MusicLibrary *library = create_music_library();

    return (library);
}
