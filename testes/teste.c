/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:26:51 by lmachado          #+#    #+#             */
/*   Updated: 2025/02/26 12:26:54 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define WIDTH 6
#define HEIGHT 5

#include <stdio.h>

#define WIDTH 6
#define HEIGHT 5

char map[HEIGHT][WIDTH] = {
    "111111",
    "100001",
    "10P001",
    "100001",
    "111111"
};

// Função de Flood Fill para verificar se o mapa está fechado corretamente
int flood_fill(int x, int y) {
    if (x < 0 || x >= HEIGHT || y < 0 || y >= WIDTH) {
        return 0; // Saiu do mapa, significa que há um buraco
    }
    if (map[x][y] == '1' || map[x][y] == 'F') return 1; // Parede ou já visitado

    map[x][y] = 'F'; // Marca como visitado

    // Recursão para checar todos os lados
    if (!flood_fill(x + 1, y)) return 0;
    if (!flood_fill(x - 1, y)) return 0;
    if (!flood_fill(x, y + 1)) return 0;
    if (!flood_fill(x, y - 1)) return 0;

    return 1;
}

int main() {
    // Substituir 'P' por '0' para a verificação funcionar corretamente
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (map[i][j] == 'P') {
                map[i][j] = '0';
            }
        }
    }

    // Inicia o Flood Fill a partir de um espaço vazio (evite iniciar em '1')
    int is_closed = 1;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (map[i][j] == '0') {
                is_closed = flood_fill(i, j);
                break;
            }
        }
        if (!is_closed) break;
    }

    if (is_closed) {
        printf("✅ Mapa está fechado corretamente!\n");
    } else {
        printf("❌ Mapa não está fechado corretamente!\n");
    }

    return 0;
}


