/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 02:21:00 by mpascual          #+#    #+#             */
/*   Updated: 2020/12/12 18:50:53 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    *setup(t_vars *vars)
{
    char    *bkg_addr;

    vars->background = mlx_new_image(vars->mlx, vars->width, vars->height);
    bkg_addr = mlx_get_data_addr(vars->background, &vars->bpp, 
        &vars->size_line, &vars->endian);
    draw_background(bkg_addr, vars);
    return (vars->background);
}

int     draw_pixel(int r, int g, int b, char *img_addr)
{
    img_addr[0] = b;
    img_addr[1] = g;
    img_addr[2] = r;
    return (4);
}

void    draw_background(char *bkg_addr, t_vars *vars)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    while (y < vars->height / 2)
    {
        bkg_addr += draw_pixel(vars->ceiling_r, vars->ceiling_g,
         vars->ceiling_b, bkg_addr);
        x++;
        if (x == vars->width)
        {
            x = 0;
            y++;
        }
    }
    x = 0;
    while (y >= vars->height / 2 && y < vars->height)
    {
        bkg_addr += draw_pixel(vars->floor_r, vars->floor_g,
         vars->floor_b, bkg_addr);
        x++;
        if (x == vars->width)
        {
            x = 0;
            y++;
        }
    }
}