/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:55:46 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/04/03 06:29:48 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "so_long.h"

 static int	width_of_map(char *string)
 {
     int	width;

     width = 0;
     while (string[width] != '\0')
         width++;
     if (string[width - 1] == '\n')
         width--;
     return (width);
 }

static int add_line(t_complete *game, char *line)
{
    char **temporary;
    int i;

    if (!line)
        return (0);

    i = 0;
    game->heightmap++;
    temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
    if (!temporary)
        return (0); // Manejo de error si malloc falla

    // Copia las líneas existentes al nuevo arreglo temporal
    while (i < game->heightmap - 1)
    {
        temporary[i] = game->map[i];
        i++;
    }
    temporary[i] = line;

    // Libera la memoria asignada previamente a game->map
    free(game->map);

    // Actualiza game->map al nuevo arreglo temporal
    game->map = temporary;
    return (1);
}

int	map_reading(t_complete *game, char **argv)
 {
     char	*readmap;

     game->fd = open(argv[1], O_RDONLY);
     if (game->fd < 0)
         return (0);
     while (1)
     {
         readmap = get_next_line(game->fd);
         if (!add_line(game, readmap))
             break ;
     }
     close (game->fd);
     game->widthmap = width_of_map(game->map[0]);
     return (1);
 }
