/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:55:08 by mpascual          #+#    #+#             */
/*   Updated: 2020/12/14 18:09:42 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     read_config_file(t_vars *vars)
{
    int     fd;

    fd = open(vars->cub_path, O_RDONLY, O_CREAT);
    /*
    if (read_config(vars, fd) != 0)
        error(4);
    */
    if (read_map(vars, fd) != 0)
        error(2);
    close(fd);
    return (EXIT_SUCCESS);
}
/*
int     read_config(t_vars *vars, const int fd)
{
    return (EXIT_SUCCESS);
}
*/
int     read_map(t_vars *vars, const int fd)
{
    char            **map;
    unsigned int    rows;
    unsigned int    columns;
    unsigned int    i;

    rows = 0;
    columns = 0;
    i = 0;
    while (get_next_line(fd, map) != -1)          //Read from fd line by line
        rows++;
    ft_printf("rows=%u\n", rows);
    while (map[i] && i <= rows)                            //get the map_width value
    {
        if (ft_strlen(map[i]) > columns)
            columns = ft_strlen(map[i]);
        i++;
    }
    ft_printf("solved\n");
    store_map(map, rows, columns, vars);
    return (EXIT_SUCCESS);                  //return result from map_validation
}

void    store_map(char **map, unsigned int columns, unsigned int rows,
                 t_vars *vars)
{
    unsigned int    i;
    unsigned int    j;
    unsigned int    count;

    i = 0;
    j = 0;
    count = 0;
    if (!(vars->map = malloc(sizeof(int) * rows * columns)))
        error(1);
    while (map[i][j] && (i <= columns && j <= rows))
    {
        if (ft_isdigit(map[i][j]))
            vars->map[count++] = map[i][j] - 48;
        else if (map[i][j] == ' ' || map[i][j])
            vars->map[count++] = 9;             //9 represents blank spaces in the map
        i++;
        if (++i == columns)
        {
            i = 0;
            j++;
        }
    }
}
/*
int     map_validation(int *map)
{
    return (EXIT_SUCCESS);
}
*/