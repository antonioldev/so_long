/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:34:08 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/12 10:34:12 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_find_position(t_vars *v, int *x, int *y, char componets)
{
	int	i;
	int	j;

	i = 0;
	while (i < v -> height)
	{
		j = 0;
		while (v -> arr[i][j] != '\0')
		{
			if (v -> arr[i][j] == componets)
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}

static int	ft_is_safe(char **arr, int i, int j)
{
	int	lines;
	int	colums;

	lines = 0;
	colums = ft_strlen(arr[lines]);
	while (arr[lines])
		lines++;
	if (i > 0 && i < lines && j > 0 && j < colums)
		return (0);
	return (-1);
}

static int	ft_check_path(t_vars *v, char **visited, int i, int j)
{
	if (ft_is_safe(v->arr, i, j) == 0
		&& v->arr[i][j] != '1' && visited[i][j] != 'x')
	{
		if (visited[i][j] == 'C')
			v ->collectable--;
		if (visited[i][j] == 'E')
			v -> exit -= 1;
		visited[i][j] = 'x';
		if (ft_check_path(v, visited, i - 1, j) == 0)
			return (0);
		if (ft_check_path(v, visited, i, j - 1) == 0)
			return (0);
		if (ft_check_path(v, visited, i + 1, j) == 0)
			return (0);
		if (ft_check_path(v, visited, i, j + 1) == 0)
			return (0);
	}
	return (-1);
}

int	ft_check_valid_map(t_vars *v, char **visited)
{
	int	coll;

	ft_find_position(v, &v -> x_player, &v -> y_player, 'P');
	ft_find_position(v, &v -> x_exit, &v -> y_exit, 'E');
	coll = v -> collectable;
	while (v ->collectable > 0)
	{
		ft_check_path(v, visited, v -> x_player, v -> y_player);
		if (v->collectable > 0 || v -> exit != 0)
			return (-1);
	}
	v->collectable = coll;
	v->exit = 1;
	return (0);
}
