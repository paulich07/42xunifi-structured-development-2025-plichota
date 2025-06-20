# Movie Watchlist

## Load file
- Check the existence of the file and open it
- Return error and exit program if not valid
- For each line in the CSV:
  - Read with get_next_line()
  - Trim all fields: ft_trim()
  - Split line by commas: ft_split()
    - Must contain exactly 6 fields
    - Validate:
        - ID: unique, positive integer
        - Title & Genre: non-empty
        - Watched flag: must be 0 or 1
        - If watched:
            - Rating: 1–10
            - Date: valid YYYY-MM-DD
        - If not watched:
            - Rating/date can be ignored (warn but accept)
  - If valid: create_movie(), add_to_list()
  - Free line and tokens

## Menu Loop
while (true)
  - Show menu:
      1 - List all movies
      2 - Search by title
      3 - Search by genre
      4 - Filter watched/unwatched
      5 - Add new movie
      6 - Mark movie as watched
      7 - Update title/genre
      8 - Delete a movie
      9 - Show statistics
      0 - Save and exit
  - Read option: read_input()
  - Validate and execute
  - Retur
