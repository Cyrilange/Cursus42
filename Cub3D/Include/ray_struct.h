/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:06:41 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/29 14:09:04 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_STRUCT_H
# define RAY_STRUCT_H

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

//struct for the color RGB because of the norm
typedef struct s_rgb
{
	int	r; //red
	int	g; //green
	int	b; //blue
}	t_rgb;
// Structure storing raycasting-related
typedef struct s_ray
{
	double	camera_x;		// x-coordinate in camera space (-1 to 1)
	double	ray_dir_x;		// ray direction vector x
	double	ray_dir_y;		// ray direction vector y
	int		map_x;			// current x position in map grid
	int		map_y;			// current y position in map grid
	double	side_dist_x;	// distance to next x side
	double	side_dist_y;	// distance to next y side
	double	delta_dist_x;	// distance between two x intersections
	double	delta_dist_y;	// distance between two y intersections
	double	wall_x;			// exact hit position on wall (for texture)
	int		step_x;			// step direction on x axis (-1 or 1)
	int		step_y;			// step direction on y axis (-1 or 1)
	int		hit;			// flag: 1 if wall hit, 0 otherwise
	int		side;			// side of the wall hit (0=x, 1=y)
	double	perp_wall_dist;	// corrected perpendicular distance
	int		line_height;	// height of the wall slice on screen
	int		draw_start;		// start pixel for drawing the wall
	int		draw_end;		// end pixel for drawing the wall
	int		tx;				// texture x
	int		ty;				// texture y
	int		d;				// intermediate distance for texture calc
	int		idx;			// pixel index in texture buffer
}	t_ray;

#endif