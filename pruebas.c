/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 01:59:48 by mpascual          #+#    #+#             */
/*   Updated: 2020/11/18 01:15:05 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** ENCODING AND DECODING COLORS
** each byte contains 2^8 values (rgb values range from 0 to 255)
** We will fit a integer (4 bytes) using bitshifting to set the values
** programatically
*/

int     create_trgb(int t, int r, int g, int b)
{
    return(t << 24 | r << 16 | g << 8 | b);
}

/*
** Notice that because ints are stored from right to left, we need to bitshift
** each value the according amount backwards.
** This functions will retrieve int values from a encoded TRGB integer
*/

int     get_t(int trgb)
{
    return(trgb & (0xFF << 24));
}

int     get_r(int trgb)
{
    return(trgb & (0xFF << 16));
}

int     get_g(int trgb)
{
    return(trgb & (0xFF << 8));
}

int     get_b(int trgb)
{
    return(trgb & 0xFF);
}

int     add_shade(double distance, int color)
{
    int     transparency;
    int     new_color;

    transparency = get_t(color);

    if (distance > 0 && distance <= 1)
        transparency *= distance;
    else if (!distance)
        transparency = 0;
    new_color = create_trgb(transparency, get_r(color), get_g(color),
     get_b(color));
     return (new_color);
}
