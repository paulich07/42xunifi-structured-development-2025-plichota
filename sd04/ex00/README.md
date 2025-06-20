# Library

## Load file
- Check the existence of file
- Return error and exit program if not valid

## Parse file
while i < 1000
  - Read a line from file: get_next_line()
  - Trim extra spaces: ft_trim()
  - Split line in tokens by comma: ft_split()
    - If n_tokens != 3: skip line and print error: ft_printf()
  - Allocate entry with token values [id, title, author]: create_entry()
  - Free line and tokens: free_line_and_tokens();
  - Add to catalog: add_to_catalog()

## Prompt
while (empty_line < 2 || is_valid_input)
  -  print "How do you want to search?": ft_printf()
      1 - Search by Title
      2 - Search by Author
  - read input: read()
  - If input is not 1 or 2 repeat prompt until valid input is received
  - If input is empty the first time repeat prompt and increment empty_line
  - If double enter is pressed without any prompt exit program

## Search and display results
while (empty_line < 2)
  - Get input for search: read();
  - If input is empty the first time repeat prompt and increment empty_line
  . If double enter is pressed without any prompt exit program
  - Trim whitespaces: ft_trim()
  - Transform in lowercase: ft_tolower();
  - Search for substring (based on the previous choice): ft_strnstr()
  - If match found:
      print [display ID, Title, Author]: print_book()
  - If match not found
      print: "No matching books found.": ft_printf()

## Exit and clean
- Clear stored catalog: free_catalog()
- Close file handle: close()
- Print exit message: ft_printf()
