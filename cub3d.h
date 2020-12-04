/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:36:14 by mpascual          #+#    #+#             */
/*   Updated: 2020/12/03 02:49:40 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <mlx.h>
# include "libft_printf/header.h"

typedef struct  s_vars
{
    void        *mlx;
    void        *win;
    char        *cub_path;
    int         width;
    int         height;
    char        *north;
    char        *south;
    char        *west;
    char        *east;
    char        *sprite;
    int         floor_color;
    int         ceiling_color;
    char        **map;
}               t_vars;

void    error(int error_type);
void    read_cub(char *file_path, t_vars *vars);
void    init_vars(t_vars *vars);

#endif