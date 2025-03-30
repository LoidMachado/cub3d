#include "../header/header.h"

int strlen_mtr(char **mtr)
{
    int i = 0;
    while (mtr[i])
    {
        i++;
    }
    return(i);
}

int is_number(char *str)
{
    int i;

    if(!str && *str != '\0')
       return (0);
    i =-1;
    while (str[++i])
    {
        if (str[i] < '0' || str[i] >'9')
            return (0);
    }
    return (1);
}
int get_color(char *line)
{
    int number[3];
    char **split;
    int i;

    split = ft_split_1(line + 2, ',');
    i = -1;
    while (split && split[++i])
        number [i] = ft_atoi(line);
    free_split(split);
    return (number[0] << 16 | number[1] << 8 | number[2]);
}

int num_comma(char *line)
{
    int i;
    int cont;

    cont = 0;
    i =-1;
    while(line[++i])
    {
        if(line[i] == ',')
            cont++;
    }
    return (cont);
}
int check_number(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (1);
    while (str[i] == ' ')
        i++;
    while (str[i])
    {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] == ','))
            i++;
        else
            return (1); 
    }
    return (0);
}

int is_valid_color(char *line)
{
    int number;
    char **split;
    int i;

    
    if (!line)
        return (1);
    i = -1;
    if (num_comma(line + 2) != 2)
        return (1);  
    split = ft_split_1(line + 2, ',');
    while (split && split[++i])
    {
        if (check_number(split[i]))
        {
                free_split(split);
                return (1);
        }
          
        number = ft_atoi(split[i]);
        if (number < 0 || number > 255)
        {
            free_split(split);
            return (1);
        }
    }
    if (i != 3)
    {
        free_split(split);
        return (1);
    }
    free_split(split);
    return (0);
}

int verify_extension(char *str)
{
    int c = 1;
    if (str == NULL)
        return (1);
    if (str[0] != '.' && str[1] != '/')
        return (1);
    while (str[c])
    {
        if (str[c] == '.')
        {
            c++;
            if (str[c] == 'x' && str[c + 1] == 'p' && str[c + 2] == 'm')
                return (0);
            else
                return (1);
        }
        c++;
    }
    return 1;
}

void parse_line(t_game *game, char *line)
{
    
    while (*line == ' ')
        line++;    
    if (strncmp(line, "NO ", 3) == 0)
        game->no_texture = strdup(line + 3); 
    else if (strncmp(line, "SO ", 3) == 0)
        game->so_texture = strdup(line + 3); 
    else if (strncmp(line, "WE ", 3) == 0)
        game->we_texture = strdup(line + 3); 
    else if (strncmp(line, "EA ", 3) == 0)
        game->ea_texture = strdup(line + 3); 
    else if (strncmp(line, "F ", 2) == 0 )
        game->floor_color = line;
    else if (strncmp(line, "C ", 2) == 0 )
        game->ceiling_color = line;
    else
    {
        printf("Erro: chave inválida%s\n", line);
        free_all(game);
    }
    return ;
}


static int is_map_line(char *line)
{
    while (*line && isspace((unsigned char)*line))
        line++;
    return (*line == '1' || *line == '0' || *line == ' ');
}

void parse_game(t_game *game, char **lines)
{
    int i = 0;
    int qtd_lines = 0;
    
    game->map = NULL;
    while (lines[i])
    {
        if (is_map_line(lines[i]))
        {
            game->map = realloc(game->map, sizeof(char *) * (qtd_lines + 2));
            game->map[qtd_lines++] = strdup(lines[i]);
            game->map[qtd_lines] = NULL;
        }
        else
            parse_line(game, lines[i]);
        i++;
    }
}
