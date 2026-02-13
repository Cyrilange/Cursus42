/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:13:40 by csalamit          #+#    #+#             */
/*   Updated: 2025/11/06 20:14:02 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
//struc from struct.h
# include "struct.h"
//define for all the define parts
# include "define.h"
//minilbx
# include "MLX42/include/MLX42/MLX42.h"
//libft
# include "libft/libft.h"
//Math
# include "math.h"
//initialisation
void			init_player(t_player *player, double start_x, double start_y,
					char start);
//void			init_game(t_game *game);
void			init_game_struct(t_game *game);
void			init_map(t_map *map);
void			init_textures(t_texture *textures);
void			init_window(t_game *game);
void			init_ray(t_ray *ray, t_game *game, int x);
void			init_ray_step(t_ray *ray, t_game *game);
//tools
void			*check_malloc(size_t size);
void			error_function(const char *message);
void			g_error_function(t_game *game, const char *message);
void			free_game(t_game *game);
void			handle_line_or_exit(t_game *game, char *line, t_line **lines);
//parsing
void			parse_map_file(const char *filename, t_game *game);
unsigned int	parse_color(char *s);
void			load_textures(t_game *game);
void			find_player(t_game *game, double *start_x, double *start_y,
					char *start_dir);
int				handle_line(t_game *game, char *line, t_line **lines);
//3d
void			draw_ray_column(t_game *game, int x, t_ray *ray);
void			raycasting(t_game *game);
void			ft_put_pixel(t_game *game, int x, int y, uint32_t color);
//control
void			try_move(t_game *game, double dx, double dy);
void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			rotate_left(t_player *player);
void			rotate_right(t_player *player);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			game_loop(void *param);
//check
void			check_name(char *file);
int				check_wall(t_game *game);
//modif of GNL
void			free_gnl_static(void);
void			handle_line_error(t_game *game, const char *message);
void			close_game(void *param);
void			helper_free_game(t_game *game);
//valgrind --suppressions=suppressions.supp ./cub3D maps/supergiant.cub
#endif
