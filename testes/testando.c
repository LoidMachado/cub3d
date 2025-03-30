/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testando.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:08:38 by lmachado          #+#    #+#             */
/*   Updated: 2025/02/27 16:08:41 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_line(char *line, char *key, char *value) {
    int i = 0;

    // Pular espaços iniciais, se houver
    while (line[i] == ' ') i++;

    // Copiar a chave (ex: "NO", "F", etc.)
    int j = 0;
    while (line[i] != ' ' && line[i] != '\0') {
        key[j++] = line[i++];
    }
    key[j] = '\0'; // Terminar string corretamente

    // Pular espaço entre chave e valor
    while (line[i] == ' ') i++;

    // Copiar o valor (resto da linha)
    strcpy(value, line + i);
}

int main() {
    char *lines[] = {
        "NO ./path_to_the_north_texture",
        "SO ./path_to_the_south_texture",
        "WE ./path_to_the_west_texture",
        "EA ./path_to_the_east_texture",
        "F 220,100,0",
        "C 225,30,1"
    };

    char key[10];   // Para armazenar a chave (ex: "NO", "F", etc.)
    char value[256]; // Para armazenar o valor

    for (int i = 0; i < 6; i++) {
        parse_line(lines[i], key, value);
        printf("Chave: %s | Valor: %s\n", key, value);
    }

    return 0;
}

