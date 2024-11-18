/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:55:53 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/04/05 11:25:29 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "so_long.h"

 int	exit_point(t_complete *game)
 {
     int	line;

     line = 0;
     if (game->winpointer)
         mlx_destroy_window(game->mlxpointer, game->winpointer);
     free(game->mlxpointer);
     while (line < game->heightmap)
         free(game->map[line++]);
     free(game->map);
     exit(0);
 }

int main(int argc, char **argv) {
    if (argc != 2 || !is_ber_file(argv[1])) {
        ft_printf("\nError: Debes proporcionar un archivo .ber como argumento\n");
        return (0);
    }
    
    t_complete game;
    ft_memset(&game, 0, sizeof(t_complete));
    
    map_reading(&game, argv);
    check_errors(&game);
    
    game.mlxpointer = mlx_init();
    game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 40),
                                     (game.heightmap * 40), "solong");
    
    place_images_in_game(&game);
	game.player.render = game.player.right;
    game.movement_counter = -1;
    adding_in_graphics(&game);
    
    mlx_key_hook(game.winpointer, controls_working, &game);
    mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
    
    mlx_loop(game.mlxpointer);

    return (0);
}

