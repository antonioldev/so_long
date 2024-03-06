/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:01:57 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/11 17:02:00 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_error(int argc, char **argv)
{
	int	fd;

	errno = 22;
	if (argc < 2)
		perror("Error\n: Map not provided ");
	else if (argc > 2)
	{
		errno = 7;
		perror("Error\n");
	}
	if (argc != 2)
		exit (1);
	else
		fd = ft_open_path_map(argv[1]);
	if (fd == -1)
	{
		errno = 2;
		perror("Error\n");
		exit (1);
	}
	return (fd);
}

static int	ft_check_lenght(t_vars *v)
{
	int	i;

	i = 0;
	v->width = ft_strlen(v->arr[i++]);
	while (v->arr[i])
	{
		if ((long unsigned int)v->width != ft_strlen(v->arr[i]))
			return (-1);
		i++;
	}
	v->height = i;
	v->win_h = (v->height * v->s) + 50;
	v->win_w = (v->width * v->s);
	return (i);
}

static int	ft_check_border(char **arr, int lines)
{
	int	i;
	int	j;
	int	lenght;

	i = 0;
	j = 0;
	lenght = (int)ft_strlen(arr[i]);
	while (j < lenght)
		if (arr[i][j++] != '1')
			return (-1);
	while (j > 0)
		if (arr[lines - 1][--j] != '1')
			return (-1);
	while (i < lines)
	{
		if (arr[i][0] != '1' || arr[i][lenght - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

static int	ft_check_components(t_vars *v, int i, int j)
{
	while (++i < v->height)
	{
		j = 0;
		while (v->arr[i][j] != '\0')
		{
			if (v->arr[i][j] == 'C')
				v->collectable++;
			else if (v->arr[i][j] == 'E')
				v->exit++;
			else if (v->arr[i][j] == 'P')
				v->player++;
			else if ((v->arr[i][j] != '0') && (v->arr[i][j] != '1'))
				return (-1);
			j++;
		}
	}
	if (v->exit != 1 || v->player != 1 || v->collectable < 1)
		return (-1);
	return (0);
}

int	ft_check_map(t_vars *v)
{
	errno = 22;
	if (ft_check_lenght(v) == -1)
	{
		perror("Error\nMap is not rectangular");
		return (-1);
	}
	if (ft_check_border(v->arr, v->height) == -1)
	{
		perror("Error\nMap is not surrounded by walls");
		return (-1);
	}
	if (ft_check_components(v, -1, 0) == -1)
	{
		perror("Error\nMap doesn't contain the right compontents");
		return (-1);
	}
	if (ft_check_valid_map(v, v->visited) == -1)
	{
		perror("Error\nMap doesn't have a valid path");
		return (-1);
	}
	return (0);
}
