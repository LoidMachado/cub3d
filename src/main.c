/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:54:35 by lmachado          #+#    #+#             */
/*   Updated: 2025/03/26 11:47:31 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static void show_map(t_game *game, int on)
{
	if (on)
	{
		if (on == 1 || on == 3)
		{
			for(int i = 0; game->map[i] != NULL; i++)
				printf("%s\n", game->map[i]);
		}
		if (on == 2 || on == 3)
		{
			printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\n", game->no_texture, game->so_texture, game->we_texture, game->ea_texture);
			printf("Floor: %s\n", game->floor_color);
			printf("Ceiling: %s\n", game->ceiling_color);
		}
	}
}

int main(int ac, char **av)
{
	t_game game;

	check_arguments(ac, av, &game);
	initialize_game(&game);
	game.lines = print_map(av[1]);
	parse_game(&game, game.lines);
	validate_all(&game);
	show_map(&game, 2);	
	free_all(&game);
	return (0);
}
