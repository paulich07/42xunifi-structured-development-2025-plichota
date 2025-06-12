#include "password_validator.h"

int is_special_char(char c)
{
    char *special = "@#$%%ˆ&*";
    while (*special != '\0')
    {
        if (*special == c)
            return (1);
        special++;
    }
    return (0);
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_lowercase(char c)
{
    return (c >= 'a' && c <= 'z');
}

int is_uppercase(char c)
{
    return (c >= 'A' && c <= 'Z');
}

PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
    int i = 0;
    int special_chars = 0;
    int digits = 0;
    int lowercase = 0;
    int uppercase = 0;
    int isSame = 1;
    
    if (!new_pw || !curr_pw)
        return (INVALID);
    while(new_pw[i] != '\0')
    {
        if (is_special_char(new_pw[i]))
            special_chars++;
        if (is_digit(new_pw[i]))
            digits++;
        if (is_lowercase(new_pw[i]))
            lowercase++;
        if (is_uppercase(new_pw[i]))
            uppercase++;
        if (curr_pw[i] && new_pw[i] != curr_pw[i])
            isSame = 0;
        i++;
    }
    if (special_chars > 0
        && digits > 0
        && lowercase > 0
        && uppercase > 0
        && !isSame
        && i >= 8)
        return (VALID);
    return (INVALID);
}

// int main(void)
// {
//     char *new = "Ravio%%20";
//     char *old = "RavioloMaledetto23";
//     printf("Status %d\n", validate_password(new, old));
// }