/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:51:28 by lmachado          #+#    #+#             */
/*   Updated: 2025/03/30 16:03:27 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

# define MAX_LINE_LENGTH 1024

typedef struct s_game
{
	char    *no_texture;
	char    *so_texture;
	char    *we_texture;
	char    *ea_texture;
	char *floor_color;
	char *ceiling_color;
	char    **map;
	int width;
    int height;
    char    **lines;
	int rows;
	int cols;
	int fd;
	int			y;
	int			x;
	int			x_p;
	int			y_p;
	int color_f;
	int color_c;
}   t_game;

typedef struct s_bytes
{
	int	total_bytess;
}   t_bytes;

void	fill_matriz(char **matriz, char *s);
void    Validate_characters(t_game *game);
void	free_split(char **matriz);
void	free_all(t_game *game);
void	initialize_game(t_game *game);
void check_arguments(int ac, char **av, t_game *game);
void    parse_line(t_game *game, char *line);
void	validate_all(t_game *game);

char	*get_nextline(char *str, t_bytes *bit);
char	*ft_strtrim(char const *s1, char const *set);
char    **parse_map(char **lines, int start_index);
char	*alocate_space(char *content, char *buffer);
char	**alocate_matriz(int word);
char	**ft_split(char *s);
char	**print_map(char *str);
char	*ft_strdup(char *str);
char	*ft_strcat(char *dest, char *str);
char	*alocate_word(char *start, int len);
void parse_game(t_game *game, char **lines);
int	delimeter(char c);
int	count_words(char *str);
int	ft_strlen(char *str);
int verify_characters(t_game *game);
void verifybreakline(char *str);
char *validate_wall(t_game *game);
int strlen_map(t_game *game);
void validate_walls(t_game *game);
char *validate_zero(t_game *game);
void validate_zeros(t_game *game);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_atoi(const char *nptr);
char	**ft_split_1(char const *s, char c);
int verify_extension(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int is_valid_color(char *line);
int get_color(char *line);
# endif
