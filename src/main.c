/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:10:24 by mpascual          #+#    #+#             */
/*   Updated: 2020/12/03 03:12:22 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    error(int error_type)
{
    if (error_type == 1)
        ft_printf("Memory error\n");
    else if (error_type == 2)
        ft_printf("Map file error\n");
    else if (error_type == 3)
        ft_printf("Argument error\n");
    exit(EXIT_FAILURE);
}

int     main()
{
    void        *sprite;
    t_vars   *vars;
    int         spt_w;
    int         spt_h;
    int         x;
    int         y;
    void        *clear;

    if (!(vars = malloc(sizeof(t_vars) + 1)))
        error(1);
    init_vars(vars);
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "cub3D");
    sprite = mlx_xpm_file_to_image(vars->mlx, vars->sprite, &spt_w, &spt_h);
    clear = mlx_new_image(vars->mlx, vars->width, vars->height);
    x = 0;
    y = 0;
    while (y >= 0 && y < vars->height - spt_h)
    {
        mlx_put_image_to_window(vars->mlx, vars->win, sprite, x, y);
        x++;
        if (x == vars->width - spt_w)
        {
            x = 0;
            y += spt_h;
        }
        mlx_put_image_to_window(vars->mlx, vars->win, clear, 0, 0);
    }
    mlx_loop(vars->mlx);
    free(vars);
    return (0);
}