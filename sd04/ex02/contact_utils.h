#ifndef CONTACT_UTILS_H
# define CONTACT_UTILS_H

# include "contact_types.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

char    *ft_trim(char *str);
char    *ft_tolower(const char *str);
int     ft_strnstr_ci(const char *hay, const char *needle);

int     is_valid_id(const char *str, t_contact_list *list);
int     is_valid_phone(const char *str);
int     is_valid_email(const char *str);
int     is_valid_input(const char *input);
int     is_empty_line(const char *str);

char    *read_input(const char *prompt);

void    safe_free(void **ptr);
void    free_contacts(t_contact_list *list);

#endif
