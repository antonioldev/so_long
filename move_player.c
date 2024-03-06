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

	x = v -> x_player;
	y = v -> y_player;
	if (v -> arr[x - 1][y] != '1' && v -> arr[x - 1][y] != 'E')
	{
		v -> arr[x][y] = '0';
		put_image_to_map(v->arr[x][y], y * s, x * s, &v);
		put_image_to_map(v->arr[x][y], y * s, (x - 1) * s, &v);
		v -> x_player -= 1;
		if (v -> arr[x - 1][y] == 'C')
			v -> collectable--;
		else if (v->collectable == 0 && v -> arr[x - 1][y] == 'O')
		{
			v->lose = 1;
			mlx_loop_end (v->mlx);
		}
		x--;
		v -> arr[x][y] = 'P';
		ft_print_moves(&v);
		put_animation_up(y * s, x * s, &v);
	}
}

static void	ft_move_down(t_vars *v, int s, int i)
{
	int	x;
	int	y;

	x = v -> x_player;
	y = v -> y_player;
	if (v -> arr[x + 1][y] != '1' && v -> arr[x + 1][y] != 'E')
	{
		v -> arr[x][y] = '0';
		put_image_to_map(v->arr[x][y], y * s, x * s, &v);
		put_image_to_map(v->arr[x][y], y * s, (x + 1) * s, &v);
		v -> x_player += 1;
		if (v -> arr[x + 1][y] == 'C')
			v -> collectable--;
		else if (v->collectable == 0 && v -> arr[x + 1][y] == 'O')
		{
			v->lose = 1;
			mlx_loop_end (v->mlx);
		}
		x++;
		v -> arr[x][y] = 'P';
		ft_print_moves(&v);
		while (i-- >= 0)
			put_animation_right(i, y * s, x * s - i, &v);
	}
}

static void	ft_move_left(t_vars *v, int s, int i)
{
	int	x;
	int	y;

	x = v -> x_player;
	y = v -> y_player;
	if (v -> arr[x][y - 1] != '1' && v -> arr[x][y - 1] != 'E')
	{
		v -> arr[x][y] = '0';
		put_image_to_map(v->arr[x][y], y * s, x * s, &v);
		put_image_to_map(v->arr[x][y], (y - 1) * s, x * s, &v);
		v -> y_player -= 1;
		if (v -> arr[x][y - 1] == 'C')
			v -> collectable--;
		else if (v->collectable == 0 && v -> arr[x][y - 1] == 'O')
		{
			v->lose = 1;
			mlx_loop_end (v->mlx);
		}
		y--;
		v -> arr[x][y] = 'P';
		ft_print_moves(&v);
		while (i-- >= 0)
			put_animation_left(i, y * s + i, x * s, &v);
	}
}

static void	ft_move_right(t_vars *v, int s, int i)
{
	int	x;
	int	y;

	x = v -> x_player;
	y = v -> y_player;
	if (v -> arr[x][y + 1] != '1' && v -> arr[x][y + 1] != 'E')
	{
		v -> arr[x][y] = '0';
		put_image_to_map(v->arr[x][y], y * s, x * s, &v);
		put_image_to_map(v->arr[x][y], (y + 1) * s, x * s, &v);
		v -> y_player += 1;
		if (v -> arr[x][y + 1] == 'C')
			v -> collectable--;
		else if (v->is_open == 1 && v -> arr[x][y + 1] == 'O')
		{
			v->lose = 1;
			mlx_loop_end (v->mlx);
		}
		y++;
		v -> arr[x][y] = 'P';
		ft_print_moves(&v);
		while (i-- >= 0)
			put_animation_right(i, y * s - i, x * s, &v);
	}
}

/*Managing when a button is pressed*/
int	handle_input(int ks, t_vars *v)
{
	if (ks == XK_Escape)
		return (mlx_loop_end (v->mlx));
	else if (ks == XK_Down && v -> lose == 0)
		ft_move_down(v, v->s, v->s);
	else if (ks == XK_Up && v -> lose == 0)
		ft_move_up(v, v->s);
	else if (ks == XK_Left && v -> lose == 0)
		ft_move_left(v, v->s, v->s);
	else if (ks == XK_Right && v -> lose == 0)
		ft_move_right(v, v->s, v->s);
	else if (ks == XK_End && v -> lose == 0 && v->enemy != 1)
		ft_create_enemy(v);
	if (v->x_player == v->x_enemy && v->y_player == v->y_enemy)
	{
		v->lose = 2;
		mlx_loop_end(v->mlx);
	}
	if (v -> collectable == 0 && v -> lose == 0)
	{
		v -> is_open = 1;
		v -> arr[v->x_exit][v->y_exit] = 'O';
		put_image_to_map('O', v->y_exit * v->s, v->x_exit * v->s, &v);
	}
	return (0);
}
