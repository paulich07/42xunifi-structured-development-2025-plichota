#ifndef CONTACT_TYPES_H
# define CONTACT_TYPES_H

typedef struct s_contact
{
    int     id;
    char    *name;
    char    *phone;
    char    *email;
    char    *city;
    char    *address;
    struct s_contact *next;
}   t_contact;

typedef struct s_contact_list
{
    t_contact   *head;
    int         count;
    int         max_id;
}   t_contact_list;

#endif
