/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:58:11 by mpascual          #+#    #+#             */
/*   Updated: 2020/12/14 00:43:30 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void        init_vars(t_vars *vars)
{
    vars->width = 1920 / 2;
    vars->height = 1080 / 2;
    vars->north = "../textures/north.xpm";
    vars->south = "../textures/south.xpm";
    vars->west = "../textures/west.xpm";
    vars->east = "../textures/east.xpm";
    vars->sprite = "./test_image.xpm";
    vars->ceiling_r = 11;
    vars->ceiling_g = 221;
    vars->ceiling_b = 221;
    vars->floor_r = 42;
    vars->floor_g = 42;
    vars->floor_b = 42;
}