/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:43:50 by lmachado          #+#    #+#             */
/*   Updated: 2025/03/30 16:03:16 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int verify_space(t_game *game)
{
    int x;
    int y;

    y = 0;
    while(game->map[y] != NULL)
    {
        x = 0;
        while (game->map[y][x] != '\0')
        {
            if(game->map[y][x] == ' ')
            {
                if ((y > 0 && game->map[y - 1][x] == '0') ||
                    (game->map[y + 1] != NULL && game->map[y + 1][x] == '0') ||
                    (x > 0 && game->map[y][x - 1] == '0') ||
                    (game->map[y][x + 1] != '\0' && game->map[y][x + 1] == '0'))
                {
                    return (1);
                }
            }
            x++;
        }   
        y++;
    }
    return(0);
}


void add_space(t_game *game)
{
    int x, y;
    char *new_line;

	if (!game || !game->map)
        return;
    y = 0;
	new_line = NULL;
    while (game->map[y] != NULL)
    {
        x = strlen(game->map[y]);

        new_line = malloc((x + 2) * sizeof(char));
		if (!new_line) 
			return;
        strcpy(new_line, game->map[y]);

        new_line[x] = ' ';
        new_line[x + 1] = '\0';

        free(game->map[y]);
        game->map[y] = new_line;

        y++;
    }
}

void validate_all(t_game *game)
{
    if(verify_characters(game))
    {
        printf("Error: Mapa invalido\n");
        free_all(game);
    }
	add_space(game);
	if (verify_space(game))
    {
        printf("Error: Mapa invalido\n");
        free_all(game);
    }
    if (verify_extension(game->no_texture)
        || verify_extension(game->so_texture)
        || verify_extension(game->we_texture)
        || verify_extension(game->ea_texture))
    {
        printf("Error: Chave invalida\n");
        free_all(game);
    }
    if (is_valid_color(game->ceiling_color) || is_valid_color(game->floor_color))
    {
        printf("Error: cor invalida\n");
        free_all(game);
    }
    else
    {
        game->color_c = get_color(game->ceiling_color);
        game->color_f = get_color(game->floor_color);
    }
}