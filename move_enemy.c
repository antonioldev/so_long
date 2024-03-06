/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:02:48 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/18 11:02:52 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_move_up(t_vars *v, int s)
{
	int	x;
	int	y;
	int	i;

	x = v -> x_enemy;
	y = v -> y_enemy;
	if (v -> arr[x - 1][y] != '1' && v -> arr[x - 1][y] != 'E')
	{
		v -> arr[x][y] = '0';
		put_image_to_map(v->arr[x][y], y * s, x * s, &v);
		put_image_to_map(v->arr[x][y], y * s, (x - 1) * s, &v);
		x--;
		v -> arr[x][y] = 'L';
		i = s;
		while (i >= 0)
		{
			i -= 1;
			put_animation_enemy(i, y * s, x * s + i, &v);
		}
		v -> x_enemy -= 1;
	}
}

static void	ft_move_down(t_vars *v, int s)
{
	int	x;
	int	y;
	int	i;

	x = v -> x_enemy;
	y = v -> y_enemy;
	if (v -> arr[x + 1][y] != '1' && v -> arr[x + 1][y] != 'E')
	{
		v -> arr[x][y] = '0';
		put_image_to_map(v->arr[x][y], y * s, x * s, &v);
		put_image_to_map(v->arr[x][y], y * s, (x + 1) * s, &v);
		x++;
		v -> arr[x][y] = 'L';
		i = s;
		while (i >= 0)
		{
			i -= 1;
			put_animation_enemy(i, y * s, x * s - i, &v);
		}
		v -> x_enemy += 1;
	}
}

static void	ft_move_left(t_vars *v, int s)
{
	int	x;
	int	y;
	int	i;

	x = v -> x_enemy;
	y = v -> y_enemy;
	if (v -> arr[x][y - 1] != '1' && v -> arr[x][y - 1] != 'E')
	{
		v -> arr[x][y] = '0';
		put_image_to_map(v->arr[x][y], y * s, x * s, &v);
		put_image_to_map(v->arr[x][y], (y - 1) * s, x * s, &v);
		y--;
		v -> arr[x][y] = 'L';
		i = s;
		while (i >= 0)
		{
			i -= 1;
			put_animation_enemy(i, y * s + i, x * s, &v);
		}
		v -> y_enemy -= 1;
	}
}

static void	ft_move_right(t_vars *v, int s)
{
	int	x;
	int	y;
	int	i;

	x = v -> x_enemy;
	y = v -> y_enemy;
	if (v -> arr[x][y + 1] != '1' && v -> arr[x][y + 1] != 'E')
	{
		v -> arr[x][y] = '0';
		put_image_to_map(v->arr[x][y], y * s, x * s, &v);
		put_image_to_map(v->arr[x][y], (y + 1) * s, x * s, &v);
		y++;
		v -> arr[x][y] = 'L';
		i = s;
		while (i >= 0)
		{
			i -= 1;
			put_animation_enemy(i, y * s - i, x * s, &v);
		}
		v -> y_enemy += 1;
	}
}

int	ft_move_enemy(t_vars *v)
{
	int	m;

	v->frame++;
	v->framerate = v->frame % 100000;
	if (v->enemy == 1 && v->framerate == 0)
	{
		m = (v->x_player + v->y_player + v->x_exit + v->x_enemy) % 4;
		if (ft_is_safe_enemy(v, v->x_enemy + 1, v->y_enemy) == 0 && m == 0)
			ft_move_down(v, v->s);
		else if (ft_is_safe_enemy(v, v->x_enemy, v->y_enemy - 1) == 0 && m == 1)
			ft_move_left(v, v->s);
		else if (ft_is_safe_enemy(v, v->x_enemy - 1, v->y_enemy) == 0 && m == 2)
			ft_move_up(v, v->s);
		else if (ft_is_safe_enemy(v, v->x_enemy, v->y_enemy + 1) == 0 && m == 3)
			ft_move_right(v, v->s);
		else if (ft_is_safe_enemy(v, v->x_enemy + 1, v->y_enemy) == 0)
			ft_move_down(v, v->s);
		if (v->x_player == v->x_enemy && v->y_player == v->y_enemy)
		{
			v->lose = 2;
			mlx_loop_end(v->mlx);
		}
	}
	return (0);
}
