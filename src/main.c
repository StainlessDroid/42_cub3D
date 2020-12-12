/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:10:24 by mpascual          #+#    #+#             */
/*   Updated: 2020/12/12 18:49:17 by mpascual         ###   ########.fr       */
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
    else if (error_type == 4)
        ft_printf("Setup error\n");
    exit(EXIT_FAILURE);
}

int     close_win(int keycode, t_vars *vars)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(EXIT_SUCCESS);
    }
    return(0);
}

int     main()
{
    t_vars      *vars;

    if (!(vars = malloc(sizeof(t_vars) + 1)))
        error(1);
    init_vars(vars);
    vars->mlx = mlx_init();
    setup(vars);
    vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "cub3D");
    mlx_put_image_to_window(vars->mlx, vars->win, vars->background, 0, 0);
    mlx_hook(vars->win, 2, 1L<<0, close_win, vars);
    mlx_loop(vars->mlx);
    free(vars);
    return (EXIT_SUCCESS);
}