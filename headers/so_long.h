/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:59:34 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/04/06 18:14:20 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "../minilibx/mlx.h"

typedef struct s_position
{
	int	row;
	int	col;
}	t_Position;

typedef struct s_player
{
	void	**up;
	void	**down;
	void	**left;
	void	**right;
	void	**render;
}	t_player;

typedef struct s_start
{
	t_player	player;
	int			fd;
	int			heightmap;
	int			widthmap;
	int			playercount;
	int			columncount;
	int			enemycount;
	int			exitcount;
	int			x_axis;
	int			y_axis;
	int			counter;
	int			collectables;
	int			movement_counter;
	int			steps_taken; // Agregar el campo steps_taken
	char		**map;
	void		*floor;
	void		*barrier;
	void		*enemy;
	void		*exit;
	void		*collectable;
	void		*mlxpointer;
	void		*winpointer;
}	t_complete;

int		exit_point(t_complete *game);
int		map_reading(t_complete *game, char **argv);
int		controls_working(int command, t_complete *game);
int		is_ber_file(const char *filename);
void	adding_in_graphics(t_complete *game);
void	place_images_in_game(t_complete *game);
void	check_errors(t_complete *game);
void	display_game_over(t_complete *game);
void	close_game_after_delay(t_complete *game);
void	*ft_switch_img(void **img);

#endif
