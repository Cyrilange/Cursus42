/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:10:01 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/29 21:44:10 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "ray_struct.h"
# include "define.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <limits.h>
# include <memory.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//struct because of find player(fn cannot have more than 4 args)
typedef struct s_player_ctx
{
	double	*s_x; //start x
	double	*s_y; //start y 
	char	*start_dir; //start direction
	int		found; // player found counter
}	t_player_ctx;
//hand
typedef struct s_hud
{
	mlx_texture_t	*hand_texture;
	mlx_image_t		*hand_image;
	int				x; //x and y to make sure the value was kept for main
	int				y;
}	t_hud;
// Linked list node to temporarily store lines while parsing the map
typedef struct s_line
{
	char			*content;	// The content of the line
	struct s_line	*next;		// Pointer to the next line
}					t_line;
// Wrapper for MLX image data (used as render buffer)
typedef struct s_img
{
	mlx_image_t		*img;			// MLX image pointer
	int				img_width;		// Image width
	int				img_height;		// Image height
}					t_img;
// Holds all texture resources and their RGB data
typedef struct s_texture
{
	mlx_texture_t	*no;			// North wall texture
	char			*no_path;		// Path to north texture file
	mlx_texture_t	*so;			// South wall texture
	char			*so_path;		// Path to south texture file
	mlx_texture_t	*ea;			// East wall texture
	char			*ea_path;		// Path to east texture file
	mlx_texture_t	*we;			// West wall texture
	char			*we_path;		// Path to west texture file
	unsigned int	ceilling;		// Ceiling color (RGB encoded)
	unsigned int	floor;			// Floor color (RGB encoded)
}					t_texture;
// Player info and precomputed rays for each screen column
typedef struct s_player
{
	double			pos_x;			// Player position X
	double			pos_y;			// Player position Y
	double			dir_x;			// Direction vector X
	double			dir_y;			// Direction vector Y
	double			plan_x;			// Camera plane X (for FOV)
	double			plan_y;			// Camera plane Y (for FOV)
	double			move_speed;		// Movement speed
	double			rot_speed;		// Rotation speed
	char			start_dir;		// Initial orientation (N, S, E, W)
	t_ray			ray[WIN_WIDTH];	// Ray data for each screen column
}					t_player;
// Map information and dimensions
typedef struct s_map
{
	char			**map;			// 2D array of map characters
	int				map_width;		// Map width (max line length)
	int				map_height;		// Map height (line count)
}					t_map;
// Main game structure containing everything
typedef struct s_game
{
	mlx_t			*mlx;			// MLX context pointer
	void			*win;			// window handle
	t_player		player;			// Player and ray info
	t_texture		texture;		// Texture data and colors
	t_map			map;			// Map data
	t_img			img;			// Main rendering image buffer
	t_hud			hud;			// HUD elements
	bool			show_minimap;	// Minimap toggle
	bool			m_key_pressed;	// M key state for minimap toggle
}					t_game;
//struct for the norm for checking the wall if they are close or not
typedef struct s_wall_ctx
{
	t_game	*game;
	int		y;
	int		x;
	int		line_len;
}	t_wall_ctx;

#endif
