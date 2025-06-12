#include "music_organizer.h"

int get_number_of_files(const char **filenames)
{
    int  i = 0;
    if (!filenames)
        return (0);
    while (filenames[i] != NULL)
        i++;
    return (i);
}

// free library and its contents
void free_library(struct MusicLibrary *library)
{
    free(library);
}

struct MusicLibrary *organize_music_library(const char *directory_path)
{
    if (!directory_path)
        return (NULL);

    struct MusicLibrary *library = create_music_library();
    
    const char **filenames = scan_directory(directory_path);

    if (!filenames)
    {
        free_library(library);
    }

    int n = get_number_of_files(filenames);

    for (int i = 0; i < n; i++)
    {
        struct MusicFile *musicFile = process_music_file(directory_path, filenames[i]);
        if (musicFile != NULL)
            update_music_library(library, musicFile);
    }

    return (library);
}
