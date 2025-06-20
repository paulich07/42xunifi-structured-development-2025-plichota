# Contact Manager

## Load file
- Check if the file exists and can be opened
- If not, print error and exit
- For each line:
  - Read the line: get_next_line()
  - Trim whitespace: ft_trim()
  - Split by comma: ft_split()
    - If n_tokens != 6: skip line and print warning
    - Validate fields:
        - ID must be a positive int and unique
        - Name and city must be non-empty
        - Phone must contain at least one digit, digits/symbols only
        - Email must contain one '@', non-empty local and domain, and at least one dot in domain
        - Address can be empty
  - If valid:
    - Create a new contact: create_contact()
    - Add to contact list: add_to_list()
    - Track max ID
  - Free line and tokens: free_line_and_tokens()

## Main Menu (loop)
while (true)
  - Show menu options:
      1 - List all contacts
      2 - Search by name
      3 - Search by city
      4 - Add new contact
      5 - Update contact by ID
      6 - Delete contact by ID
      7 - Save & Exit
  - Read user input
  - Validate option
  - Execute the selected operation
  - Return to menu unless option 7

## Operations

### List all contacts
- Loop through list and print formatted data

### Search by name or city
- Read input string
- Convert input and contact field to lowercase
- Compare using ft_strnstr_ci()
- Print matches or "No results"

### Add new contact
- Prompt for each field
- Validate each input
- Assign unique ID (max_id + 1)
- Append to list

### Update contact
- Prompt for contact ID
- If not found, show error
- Otherwise prompt field-by-field (skip with empty input)
- Re-validate fields

### Delete contact
- Prompt for contact ID
- If found, remove from list and free memory

### Save & Exit
- Open temp file
- Write all contacts (CSV format)
- Replace original file with temp file (rename)
- Free memory and exit

## Exit and clean
- Free all contacts: free_contacts()
- Close any file handles if open
- Exit program
