/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:58:11 by mpascual          #+#    #+#             */
/*   Updated: 2020/12/03 02:44:36 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int         create_trgb(int t, int r, int g, int b)
{
    return(t << 24 | r << 16 | g << 8 | b);
}

int         get_t(int trgb)
{
    return(trgb & (0xFF << 24));
}

void        init_vars(t_vars *vars)
{
    char    *map_init;

    map_init = "0";
    vars->width = 1920;
    vars->height = 1080;
    vars->north = "../textures/north.xpm";
    vars->south = "../textures/south.xpm";
    vars->west = "../textures/west.xpm";
    vars->east = "../textures/east.xpm";
    vars->sprite = "./test_image.xpm";
    vars->floor_color = create_trgb(0, 220, 100, 0);
    vars->ceiling_color = create_trgb(0, 255, 30, 0);
    vars->map = &map_init;
}
