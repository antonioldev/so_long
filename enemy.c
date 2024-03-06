/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 08:23:41 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/20 08:23:43 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_create_enemy(t_vars *v)
{
	if (v->arr[v->x_exit][v->y_exit - 1] == '0')
	{
		v->x_enemy = v->x_exit;
		v->y_enemy = v->y_exit - 1;
	}
	else if (v->arr[v->x_exit][v->y_exit + 1] == '0')
	{
		v->x_enemy = v->x_exit;
		v->y_enemy = v->y_exit + 1;
	}
	else if (v->arr[v->x_exit - 1][v->y_exit] == '0')
	{
		v->x_enemy = v->x_exit - 1;
		v->y_enemy = v->y_exit;
	}
	else if (v->arr[v->x_exit][v->y_exit] == '0')
	{
		v->x_enemy = v->x_exit + 1;
		v->y_enemy = v->y_exit;
	}
	else
		return ;
	v -> enemy = 1;
	put_image_to_map('L', v->y_enemy * v->s, v->x_enemy * v->s, &v);
}

int	ft_is_safe_enemy(t_vars *v, int i, int j)
{
	if (v->arr[i][j] != '1' && v->arr[i][j] != 'C'
		&& v->arr[i][j] != 'O' && v->arr[i][j] != 'E')
		return (0);
	return (-1);
}
