/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:36:14 by mpascual          #+#    #+#             */
/*   Updated: 2020/12/12 18:38:27 by mpascual         ###   ########.fr       */
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
    char                **map;
    void                *background;
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
void    read_cub(char *file_path, t_vars *vars);
void    init_vars(t_vars *vars);
void    draw_background(char *bkg_addr, t_vars *vars);
void    *setup(t_vars *vars);

#endif