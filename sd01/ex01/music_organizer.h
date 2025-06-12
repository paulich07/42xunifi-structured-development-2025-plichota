#ifndef MUSIC_ORGANIZER_H
# define MUSIC_ORGANIZER_H

#include <unistd.h>
#include <stdlib.h>

typedef struct music_entry
{
    char *filename;
    char *directory_path;
} MusicEntry;


struct MusicLibrary *create_music_library();
const char **scan_directory(const char *directory_path);
struct MusicFile *process_music_file(const char *directory_path, const char *filename);
void update_music_library(struct MusicLibrary *library, struct MusicFile *song);

struct MusicLibrary *organize_music_library(const char *directory_path);

#endif