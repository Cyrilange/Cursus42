/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:14:03 by csalamit          #+#    #+#             */
/*   Updated: 2025/11/06 20:02:02 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_textures(t_texture *tex)
{
	tex->no = NULL;
	tex->so = NULL;
	tex->ea = NULL;
	tex->we = NULL;
	tex->no_path = NULL;
	tex->so_path = NULL;
	tex->ea_path = NULL;
	tex->we_path = NULL;
	tex->ceilling = 0;
	tex->floor = 0;
}
