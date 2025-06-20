#ifndef PASSWORD_VALIDATOR_H
# define PASSWORD_VALIDATOR_H

typedef enum status {
    VALID,
    INVALID
} PwStatus;

int is_special_char(char c);
int is_digit(char c);
int is_lowercase(char c);
int is_uppercase(char c);

PwStatus validate_password(const char *new_pw, const char *curr_pw);

#endif
