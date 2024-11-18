/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:55:28 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/04/06 18:18:54 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "so_long.h"

int is_ber_file(const char *filename) {
    size_t len = strlen(filename);
    if (len < 5) // El nombre del archivo es demasiado corto para ser ".ber"
        return 0;
    return strcmp(filename + len - 4, ".ber") == 0;
}

void check_file_error(const char *filename) {
    if (!is_ber_file(filename)) {
        ft_printf("\nError: El archivo no tiene la extensión .ber\n");
        exit(EXIT_FAILURE);
    }
    // Aquí puedes agregar más verificaciones si es necesario
}

 static int	horizontalwall(t_complete *game)
 {
     int	i;
     int	j;

     i = game->widthmap;
     j = 0;
     while (j < i)
     {
         if (game->map[0][i] == '1' && game->map[game->heightmap - 1][j] == '1')
             return (0);
         j++;
     }
     return (1);
 }

 static int	verticalwall(t_complete *game)
 {
     int	height;
     int	width;

     height = 0;
     width = game->widthmap;
     while (height < game->heightmap)
     {
         if (!(game->map[height][0] == '1' && game->map[height][width - 1] == '1'))
             return (0);
         height++;
     }
     return (1);
 }

 static void	if_walls(t_complete *game)
 {
     int	verticalwalls;
     int	horizontalwalls;

     verticalwalls = verticalwall(game);
     horizontalwalls = horizontalwall(game);
     if (!verticalwalls || !horizontalwalls)
     {
         ft_printf("\nThis map is missing the walls\n");
         exit_point(game);
     }
 }

 static void	count_checker(t_complete *game, int height, int width)
 {
     if (game->map[height][width] != '1' &&
         game->map[height][width] != '0' &&
         game->map[height][width] != 'P' &&
         game->map[height][width] != 'E' &&
         game->map[height][width] != 'C' &&
         game->map[height][width] != 'B' &&
         game->map[height][width] != '\n')
     {
         ft_printf("\nError Here!%c\n", game->map[height][width]);
         exit_point(game);
     }
     if (game->map[height][width] == 'C')
         game->columncount++;
     if (game->map[height][width] == 'P')
         game->playercount++;
     if (game->map[height][width] == 'B')
         game->enemycount++;
     if (game->map[height][width] == 'E')
         game->exitcount++;
 }

 void	character_valid(t_complete *game)
 {
     int	height;
     int	width;

     height = 0;
     while (height < game->heightmap - 1)
     {
         width = 0;
         while (width <= game->widthmap)
         {
             count_checker(game, height, width);
             width++;
         }
         height++;
     }
     if (!(game->playercount == 1 && game->columncount > 1
         && game->exitcount == 1))
     {
         ft_printf("\nError\nSomething is wrong!\n");
         ft_printf("either player, exit or collectable issue\n");
         exit_point(game);
     }
 }


// Función para verificar si hay una ruta desde la posición inicial hasta un coleccionable
int can_reach_collectable(t_complete *game, t_Position start) {
    // Matriz de visitados para evitar bucles infinitos
    int visited[game->heightmap][game->widthmap];
    memset(visited, 0, sizeof(visited));

    // Cola para el algoritmo de búsqueda en anchura (BFS)
    t_Position queue[game->heightmap * game->widthmap];
    int front = 0, rear = 0;

    // Agregar la posición inicial a la cola y marcarla como visitada
    queue[rear++] = start;
    visited[start.row][start.col] = 1;

    while (front < rear) {
        t_Position current = queue[front++];

        // Verificar si la posición actual contiene un coleccionable
        if (game->map[current.row][current.col] == 'C') {
            return 1; // Se encontró un coleccionable accesible
        }

        // Direcciones posibles: arriba, abajo, izquierda, derecha
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

		int i = 0;
while (i < 4) {
    int new_row = current.row + dr[i];
    int new_col = current.col + dc[i];

    // Verificar si la nueva posición está dentro de los límites del mapa
    if (new_row >= 0 && new_row < game->heightmap &&
        new_col >= 0 && new_col < game->widthmap &&
        !visited[new_row][new_col] &&
        game->map[new_row][new_col] != '1') {
        // Agregar la nueva posición a la cola y marcarla como visitada
        queue[rear++] = (t_Position){new_row, new_col};
        visited[new_row][new_col] = 1;
    }
    i++;
	}
    }

    return 0; // No se encontró ningún coleccionable accesible
}


void check_errors(t_complete *game) {
    if_walls(game);
    character_valid(game);

    // Verificar si el jugador puede llegar a algún coleccionable
    t_Position player_position;
    int i = 0;
    int j;
    while (i < game->heightmap) {
        j = 0;
        while (j < game->widthmap) {
            if (game->map[i][j] == 'P') {
                player_position.row = i;
                player_position.col = j;
                break;
            }
            j++;
        }
        if (j < game->widthmap) // Si encontramos al jugador, salimos del bucle exterior
            break;
        i++;
    }

    if (!can_reach_collectable(game, player_position)) {
        ft_printf("\nError: No hay una ruta accesible a los coleccionables\n");
        exit_point(game);
    }
}

