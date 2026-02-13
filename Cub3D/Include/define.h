/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:13:50 by csalamit          #+#    #+#             */
/*   Updated: 2025/11/01 22:54:52 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "MLX42/MLX42.h"
# define RESET "\033[0m"
# define RED "\033[1;31m"
# define ROSE "\033[38;5;200m"
# define PURPLE "\033[1;36m"
# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307

# define WIN_WIDTH 1280
# define WIN_HEIGHT 680

# define ERROR -1
# define COLLISION_MARGIN 0.2

# define FOV 0.90

# define MINIMAP_SCALE 6
# define MINIMAP_OFFSET_X 910
# define MINIMAP_OFFSET_Y 5
# define MINIMAP_MARGIN 10 
# define RED_PLAYER 0xFF0000FF
# define WHITE 0xFFFFFFFF
# define BLACK 0xFF000000

#endif