/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:53:00 by plichota          #+#    #+#             */
/*   Updated: 2025/06/20 12:04:41 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char *ft_trim(char *str)
{
  if (!str)
    return NULL;
  while (*str && ft_isspace(*str))
    str++;
  size_t len = ft_strlen(str);
  while (len > 0 && ft_isspace(str[len - 1]))
    len--;
  return ft_substr(str, 0, len);
}

char *ft_str_tolower(const char *str)
{
  if (!str)
    return NULL;
  char *res = ft_strdup(str);
  if (!res)
    return NULL;
  for (int i = 0; res[i]; i++)
    res[i] = ft_tolower(res[i]);
  return res;
}

int is_valid_input(const char *input)
{
  if (!input)
    return 0;
  while (*input)
  {
    if (!ft_isspace(*input))
      return 1;
    input++;
  }
  return 0;
}

int is_empty_line(const char *str)
{
  if (!str)
    return 1;
  while (*str)
  {
    if (!ft_isspace(*str))
      return 0;
    str++;
  }
  return 1;
}

void print_book(const t_book *book)
{
  if (!book)
    return;
  ft_printf("ID: %d\nTitle: %s\nAuthor: %s\n\n", book->id, book->title, book->author);
}

void free_catalog(t_catalog *catalog)
{
  t_book *tmp;

  while (catalog->books)
  {
      tmp = catalog->books;
      catalog->books = catalog->books->next;
      free(tmp->title);
      free(tmp->author);
      free(tmp);
  }
  catalog->count = 0;
}

void free_line_and_tokens(char *line, char **tokens)
{
  int i = 0;

  if (line)
      free(line);
  if (tokens)
  {
      while (tokens[i])
          free(tokens[i++]);
      free(tokens);
  }
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}
