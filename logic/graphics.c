/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:55:34 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/04/06 15:12:10 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    *ft_switch_img(void **img)
{
   static int    array_pos;
   static void   **copia_img;

   if (!copia_img || copia_img != img || !img[array_pos])
    {
        copia_img = img;
        array_pos = 0;
    }
    return (img[array_pos++]);
}
void   place_player(t_complete *game, int height, int width)
{
    mlx_put_image_to_window(game->mlxpointer,
                            game->winpointer, ft_switch_img(game->player.render), width * 40, height * 40);
    game->y_axis = height;
    game->x_axis = width;
    game->movement_counter++; // Incrementar el contador de movimiento
}

 void	place_collectable(t_complete *game, int height, int width)
 {
     mlx_put_image_to_window(game->mlxpointer,
                             game->winpointer, game->collectable, width * 40, height * 40);
     game->collectables++;
 }

void place_images_in_game(t_complete *game) {
    int i, j;

    game->floor = mlx_xpm_file_to_image(game->mlxpointer, "sprites/floor.xpm", &i, &j);
    game->barrier = mlx_xpm_file_to_image(game->mlxpointer, "sprites/wall.xpm", &i, &j);
    game->exit = mlx_xpm_file_to_image(game->mlxpointer, "sprites/exit.xpm", &i, &j);
    game->collectable = mlx_xpm_file_to_image(game->mlxpointer, "sprites/item.xpm", &i, &j);
    game->enemy = mlx_xpm_file_to_image(game->mlxpointer, "sprites/enemy.xpm", &i, &j);
	
	// Carga fox
	game->player.right = malloc(sizeof(void *) * 5);
    game->player.right[0] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox.xpm", &i, &j);
    game->player.right[1] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_2.xpm", &i, &j);
    game->player.right[2] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_3.xpm", &i, &j);
    game->player.right[3] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_4.xpm", &i, &j);
    game->player.right[4] = NULL;

	game->player.left = malloc(sizeof(void *) * 5);
	game->player.left[0] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_5.xpm", &i, &j);
	game->player.left[1] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_6.xpm", &i, &j);
	game->player.left[2] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_7.xpm", &i, &j);
	game->player.left[3] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_8.xpm", &i, &j);
	game->player.left[4] = NULL;

	game->player.up = malloc(sizeof(void *) * 5);
	game->player.up[0] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_9.xpm", &i, &j);
	game->player.up[1] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_10.xpm", &i, &j);
	game->player.up[2] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_11.xpm", &i, &j);
	game->player.up[3] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_12.xpm", &i, &j);
	game->player.up[4] = NULL;

	game->player.down = malloc(sizeof(void *) * 5);
	game->player.down[0] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_13.xpm", &i, &j);
	game->player.down[1] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_14.xpm", &i, &j);
	game->player.down[2] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_15.xpm", &i, &j);
	game->player.down[3] = mlx_xpm_file_to_image(game->mlxpointer, "sprites/fox_16.xpm", &i, &j);
	game->player.down[4] = NULL;



    // Cargar la imagen inicial del jugador usando ft_switch_img
    //game->player = ft_switch_img(game->mlxpointer);

    // Verificar si la imagen se cargó correctamente
//    if (!game->player) {
        // Manejar el error
//    }
}

void display_counters(t_complete *game)
 {
     // Mostrar el contador de recolectables en la pantalla
     char *collectables_str = ft_itoa(game->collectables);
     int collectables_x = 10; // Coordenada X para la esquina superior izquierda
     int collectables_y = 10; // Coordenada Y para la esquina superior izquierda
     mlx_string_put(game->mlxpointer, game->winpointer, collectables_x, collectables_y, 0xFFFFFF, "Collectables: ");
     mlx_string_put(game->mlxpointer, game->winpointer, collectables_x + 120, collectables_y, 0xFFFFFF, collectables_str); // Incrementa la posición X
     free(collectables_str); // Liberar la memoria asignada para la cadena

     // Mostrar el contador de movimiento del personaje en la pantalla
     char *movement_str = ft_itoa(game->movement_counter);
     int movement_x = 10; // Coordenada X para la esquina superior izquierda
     int movement_y = 30; // Coordenada Y para la esquina superior izquierda
     mlx_string_put(game->mlxpointer, game->winpointer, movement_x, movement_y, 0xFFFFFF, "Movement: ");
     mlx_string_put(game->mlxpointer, game->winpointer, movement_x + 120, movement_y, 0xFFFFFF, movement_str); // Incrementa la posición X
     free(movement_str); // Liberar la memoria asignada para la cadena
 }

void display_game_over(t_complete *game)                                         
{                                                                                
    int width, height; // Variables para almacenar el ancho y el alto de la imagen
    
    // Cargar la imagen game_over.xpm                                            
    void *game_over_image = mlx_xpm_file_to_image(game->mlxpointer, "sprites/game_over.xpm", &width, &height);
    
    // Mostrar la imagen en la ventana                                           
    mlx_put_image_to_window(game->mlxpointer, game->winpointer, game_over_image, 0, 0);
    
    // Actualizar la pantalla                                                    
    mlx_do_sync(game->mlxpointer);                                               
                                                                                 
    // Liberar la memoria asignada para la imagen                                
    mlx_destroy_image(game->mlxpointer, game_over_image);                        
}     

void close_game_after_delay(t_complete *game) {
     // Esperar 5 segundos
     sleep(5);
     // Cerrar el juego
     exit_point(game);
 }

void place_enemy(t_complete *game, int height, int width)
{
    // Utiliza mlx_put_image_to_window para mostrar la imagen del enemigo
    mlx_put_image_to_window(game->mlxpointer,
                            game->winpointer, game->enemy, width * 40, height * 40);

    // Actualiza otras propiedades del juego si es necesario
    // Por ejemplo, puedes contar la cantidad de enemigos colocados
    game->enemycount++;
}

void adding_in_graphics(t_complete *game)
{
    int height;
    int width;

    game->collectables = 0;
//	game->movement_counter = 0;
    height = 0;
    while (height < game->heightmap)
    {
        width = 0;
        while (game->map[height][width])
        {
            if (game->map[height][width] == '1')
                mlx_put_image_to_window(game->mlxpointer,
                                        game->winpointer, game->barrier, width * 40, height * 40);
            if (game->map[height][width] == 'C')
                place_collectable(game, height, width);
            if (game->map[height][width] == 'B')
                place_enemy(game, height, width);
            if (game->map[height][width] == 'P')
                place_player(game, height, width);
            if (game->map[height][width] == 'E')
                mlx_put_image_to_window(game->mlxpointer,
                                        game->winpointer, game->exit, width * 40, height * 40);
            if (game->map[height][width] == '0')
                mlx_put_image_to_window(game->mlxpointer,
                                        game->winpointer, game->floor, width * 40, height * 40);
            width++;
        }
        height++;
    }

    // Llamar a la función para mostrar los contadores en la pantalla
    display_counters(game);
}

