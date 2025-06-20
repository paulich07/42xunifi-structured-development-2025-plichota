/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:58:33 by plichota          #+#    #+#             */
/*   Updated: 2025/06/20 12:11:42 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_book *create_entry(char *id, char *title, char *author)
{
    t_book *book;

    if (!id || !title || !author)
        return NULL;
    int book_id = ft_atoi(id);
    if (book_id <= 0)
        return NULL;

    book = malloc(sizeof(t_book));
    if (!book)
        return NULL;

    book->id = book_id;
    book->title = ft_strdup(title);
    book->author = ft_strdup(author);
    book->next = NULL;
    return book;
}

int add_to_catalog(t_catalog *catalog, t_book *book)
{
    if (!catalog || !book || catalog->count >= MAX_BOOKS)
        return 0;

    book->next = catalog->books;
    catalog->books = book;
    catalog->count++;
    return 1;
}

int load_catalog(const char *filename, t_catalog *catalog)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return 0;

    char *line;
    while ((line = get_next_line(fd)) && catalog->count < MAX_BOOKS)
    {
        char *trimmed = ft_trim(line);
        if (!trimmed || is_empty_line(trimmed))
        {
            free(line);
            continue;
        }

        char **tokens = ft_split(trimmed, ',');
        int count = 0;
        while (tokens && tokens[count])
            count++;

        if (count != 3)
        {
            ft_printf("Invalid line format: %s\n", trimmed);
            free_line_and_tokens(line, tokens);
            continue;
        }

        char *id = ft_trim(tokens[0]);
        char *title = ft_trim(tokens[1]);
        char *author = ft_trim(tokens[2]);
        t_book *book = create_entry(id, title, author);

        if (!book)
        {
            ft_printf("Invalid book entry: %s\n", trimmed);
            free_line_and_tokens(line, tokens);
            continue;
        }

        add_to_catalog(catalog, book);
        free_line_and_tokens(line, tokens);
    }
    close(fd);
    return 1;
}

void search_by_title(t_catalog *catalog, const char *query)
{
    t_book *curr = catalog->books;
    char *q_lower = ft_str_tolower(query);
    int found = 0;

    while (curr)
    {
      char *t_lower = ft_str_tolower(curr->title);
      if (ft_strnstr(t_lower, q_lower, ft_strlen(t_lower)))
      {
        print_book(curr);
        found = 1;
      }
      free(t_lower);
      curr = curr->next;
    }
    free(q_lower);

    if (!found)
      ft_printf("No matching books by title.\n");
}

void search_by_author(t_catalog *catalog, const char *query)
{
    t_book *curr = catalog->books;
    char *q_lower = ft_str_tolower(query);
    int found = 0;

    while (curr)
    {
        char *a_lower = ft_str_tolower(curr->author);
        if (ft_strnstr(a_lower, q_lower, ft_strlen(a_lower)))
        {
            print_book(curr);
            found = 1;
        }
        free(a_lower);
        curr = curr->next;
    }
    free(q_lower);

    if (!found)
        ft_printf("No matching books by author.\n");
}
