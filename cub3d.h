/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:36:14 by mpascual          #+#    #+#             */
/*   Updated: 2020/12/14 18:08:13 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <mlx.h>
# include "libft_printf/header.h"

typedef struct  s_vars
{
    void                *mlx;
    void                *win;
    char                *cub_path;
    int                 width;
    int                 height;
    char                *north;
    char                *south;
    char                *west;
    char                *east;
    char                *sprite;
    int                 *map;
    void                *img;
    int                 bpp;
    int                 size_line;
    int                 endian;
    short unsigned int  ceiling_r;
    short unsigned int  ceiling_g;
    short unsigned int  ceiling_b;
    short unsigned int  floor_r;
    short unsigned int  floor_g;
    short unsigned int  floor_b;
}               t_vars;

void    error(int error_type);
int     read_config_file(t_vars *vars);
void    init_vars(t_vars *vars);
void    draw_background(char *bkg_addr, t_vars *vars);
int     setup(t_vars *vars);
int     read_map(t_vars *vars, int fd);
//int     map_validation(int *map);
void    store_map(char **map, unsigned int rows, unsigned int columns,
                 t_vars *vars);
//int     read_config(t_vars *vars, int fd);

#endif