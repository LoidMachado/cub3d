/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:29:41 by lmachado          #+#    #+#             */
/*   Updated: 2025/03/30 16:12:16 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void check_arguments(int ac, char **av, t_game *game)
{
	if(ac != 2)
	{
		write(2,"Error!\n Incorrect arguments \n",30);
		exit(1);
	}	
	if(strlen(av[1]) < 4 || !strchr(av[1], '.') || strcmp(".cub", av[1]+strlen(av[1]) - 4) != 0)
	{
		write(2,"Error!\n Incorrect extension \n",30);
		exit(1);
	}
	game->fd = open(av[1], O_RDONLY);
	if(game->fd < 0)
	{
		write(2,"Error!\n",1);
		write(2,strerror(errno),strlen(strerror(errno)));
		exit(1);
	}	
}

static int return_values(char *str, int *i)
{
    int k;
    
    k = 0;
    while (str[k] != '\0')
    {
        if (str[k] && (str[k] == '1' && str[k + 1] == '1'
            && str[k + 2] == '1' && str[k + 3] == '1')) 
            break;
        k++;
    }
    *i = 0;
    while (str[*i] != '\0')
        (*i)++;
    while (*i > 0)
    {
        if(str[*i] == '1')
            break;
        (*i)--;
    }
    return(k);
}

void verifybreakline(char *str)
{
    int i;
    int k;
    
    k = return_values(str, &i);
    while(k < i)
    {
        if (str[k] == '\n' && str[k + 1] != '\0')
        {
            if (str[k + 1] == '\n')
            {
                printf("Mapa invalido\n");
                free(str);
                exit(1);
            }
            
        }
        k++;
    } 
}

int verify_characters(t_game *game)
{
    char c;
    int x;
    int y;
    int count = 0;
    
    y = 0;
    while(game->map[y] != NULL)
    {
        x = 0;
        while(game->map[y][x] != '\0')
        {
            c = game->map[y][x];
            if(c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != ' ' && c != '\n')
                return (1);
            if (c == 'W' || c == 'N' || c == 'S' || c == 'E')
            {
                count++;
            }
            x++;
        }
        y++;
    }
    if(count != 1)
        return (1);        
    return (0);
}