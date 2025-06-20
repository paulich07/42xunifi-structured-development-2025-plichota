# Expense Tracker

## Load file
- Check the existence of file
- Return error and exit program if not valid

## Parse file
while i < 1000
  - Read a line from file: get_next_line()
  - Trim extra spaces: ft_trim()
  - Split line in tokens by comma: ft_split()
    - If n_tokens != 4: skip line and print error: ft_printf()
    - If amount is invalid or <= 0, or contains 'zero' / 'invalid_amount': skip
    - If date format is invalid: skip
  - Allocate entry with token values [date, amount, category, description]: create_entry()
  - Free line and tokens: free_line_and_tokens()
  - Add to dataset: add_to_dataset()

## Prompt
while (empty_line < 2 || is_valid_input)
  - print "How do you want to filter?": ft_printf()
      1 - Filter by Category
      2 - Filter by Date Range
      3 - Show All
  - read input: read()
  - If input is not 1/2/3 repeat prompt until valid input is received
  - If input is empty the first time repeat prompt and increment empty_line
  - If double enter is pressed without any prompt exit program

## Apply filter
- If category filter selected:
  - Ask for substring input: read_input()
  - Trim and convert to lowercase: ft_trim(), ft_tolower()
  - Filter by case-insensitive match on category
- If date range selected:
  - Prompt for start and end date (YYYY-MM-DD)
  - Validate format and order: is_valid_date(), compare_dates()
  - Filter by range
- If show all: copy dataset

## Display summary
- Compute total number of records
- Compute total amount spent
- Compute average
- Compute breakdown by category (case-insensitive grouping)
- Print each category:
    - Total amount
    - Percentage of total
- If no results:
    - Print "No matching records found."

## Exit and clean
- Free stored dataset: free_dataset()
- Close file handle: close()
- Print exit message: ft_printf()
