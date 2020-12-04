/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:55:08 by mpascual          #+#    #+#             */
/*   Updated: 2020/11/30 01:17:17 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
int     is_valid(char *line)
{
    if (*line == '\0' || line[1] == '\0')
        return (0);
    else if (line[0] == 'R')
        return (1);
    else if (line[0] == 'F')
        return (2);
    else if (line[0] == 'C')
        return (3);
    else if (line[0] == 'N' && line[1] == 'O')
        return (4);
    else if (line[0] == 'W' && line[1] == 'E')
        return (6);
    else if (line[0] == 'E' && line[1] == 'A')
        return (7);
    else if (line[0] == 'S')
    {
        if (line[1] == 'O')
            return (5);
        else
            return (8);
    }
    else
        return (0);
}
*/

int     get_identifier(int fd, t_map_var *map_var)
{
    char    *line;

    line += 2;
    map_var->width = ft_atoi(line);
    line += ft_nbrlen(map_var->width, 10);
    map_var->height = ft_atoi(line);
    free(line);
    return (0);
}

void     read_cub(char *file_path, t_map_var *map_var)
{
    int     fd;

    fd = open(file_path, O_RDONLY, O_CREAT);
    if (get_identifier(fd, map_var))
        error(2);
    close(fd);
}