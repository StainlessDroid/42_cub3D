/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:36:14 by mpascual          #+#    #+#             */
/*   Updated: 2020/11/17 21:42:18 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include "mlx_linux/mlx.h"
# include "libft_printf/header.h"

int         create_trgb(int t, int r, int g, int b);
int         get_t(int trgb);
int         get_r(int trgb);
int         get_g(int trgb);
int         get_b(int trgb);
int         add_shade(double distance, int color);

#endif