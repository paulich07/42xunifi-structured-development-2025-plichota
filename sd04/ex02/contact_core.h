#ifndef CONTACT_CORE_H
# define CONTACT_CORE_H

# include "contact_types.h"

int         load_contacts(const char *filename, t_contact_list *list);
t_contact   *create_contact(int id, char *name, char *phone, char *email, char *city, char *address);
int         add_to_list(t_contact_list *list, t_contact *contact);
int         is_valid_contact(char **fields, t_contact_list *list);
void        free_line_and_tokens(char *line, char **tokens);

void        menu_loop(t_contact_list *list, const char *filename);
void        list_contacts(t_contact_list *list);
void        search_by_name(t_contact_list *list, const char *query);
void        search_by_city(t_contact_list *list, const char *query);
void        add_contact(t_contact_list *list);
void        update_contact(t_contact_list *list);
void        delete_contact(t_contact_list *list);
t_contact   *find_contact_by_id(t_contact_list *list, int id);

int         save_contacts(const char *filename, t_contact_list *list);

#endif
