#ifndef PASSWORD_VALIDATOR_H
# define PASSWORD_VALIDATOR_H

typedef struct history
{
    char *new;
    char *old;
    char *older;
} PasswordHistory;

typedef enum status
{
    VALID,
    INVALID_WEAK,
    INVALID_SIMILAR
} PwStatus;

int is_special_char(char c);
int is_digit(char c);
int is_lowercase(char c);
int is_uppercase(char c);

PwStatus validate_password(const char *new_pw, const char *curr_pw);

#endif
