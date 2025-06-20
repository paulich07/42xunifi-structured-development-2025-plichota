/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:20:13 by plichota          #+#    #+#             */
/*   Updated: 2025/06/20 12:02:33 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

static char *get_trimmed_lower_input(void)
{
    char *input = get_next_line(STDIN_FILENO);
    if (!input || is_empty_line(input))
    {
        free(input);
        return NULL;
    }
    char *trimmed = ft_trim(input);
    char *lower = ft_str_tolower(trimmed);
    free(input);
    free(trimmed);
    return lower;
}

int main(int argc, char **argv)
{
    t_catalog catalog = {0};
    char *query;
    char *input;
    int mode = 0;
    int empty_count = 0;

    if (argc != 2)
    {
        ft_printf("Usage: %s <catalog_file>\n", argv[0]);
        return (1);
    }

    if (!load_catalog(argv[1], &catalog))
    {
        ft_printf("Error: Could not load file '%s'.\n", argv[1]);
        return (1);
    }

    ft_printf("Catalog loaded successfully.\n\n");

    while (empty_count < 2)
    {
        ft_printf("Search by:\n  1. Title\n  2. Author\n> ");
        input = get_next_line(STDIN_FILENO);

        if (is_empty_line(input))
        {
            free(input);
            empty_count++;
            continue;
        }

        empty_count = 0;
        if (ft_strncmp(input, "1", 1) == 0)
        {
            mode = 1;
            free(input);
            break;
        }
        else if (ft_strncmp(input, "2", 1) == 0)
        {
            mode = 2;
            free(input);
            break;
        }
        else
        {
            ft_printf("Invalid input. Please enter 1 or 2.\n");
            free(input);
        }
    }

    if (empty_count >= 2)
    {
        ft_printf("Exited.\n");
        free_catalog(&catalog);
        return (0);
    }

    empty_count = 0;
    while (empty_count < 2)
    {
        ft_printf("\nEnter search string (or double ENTER to quit):\n> ");
        query = get_trimmed_lower_input();

        if (!query)
        {
            empty_count++;
            continue;
        }

        empty_count = 0;
        if (mode == 1)
            search_by_title(&catalog, query);
        else
            search_by_author(&catalog, query);

        free(query);
    }

    ft_printf("Goodbye!\n");
    free_catalog(&catalog);
    return (0);
}
