/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 07:58:54 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/13 07:58:56 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*Exit the loop when pressing X button*/
int	x_pressed(t_vars *v)
{
	v->lose = -1;
	mlx_loop_end (v->mlx);
	return (0);
}

void	put_image_to_map(char p, int h, int w, t_vars **v)
{
	if (p == '1')
		put_image(&v, h, w, "./textures/wall.xpm");
	else if (p == 'C')
		put_image(&v, h, w, "./textures/gold.xpm");
	else if (p == 'O')
		put_image(&v, h, w, "./textures/open.xpm");
	else if (p == 'E')
		put_image(&v, h, w, "./textures/exit.xpm");
	else if (p == 'P')
		put_image(&v, h, w, "./textures/player.xpm");
	else if (p == '0')
		put_image(&v, h, w, "./textures/floor.xpm");
	else if (p == 'L')
		put_image(&v, h, w, "./textures/enemy.xpm");
}

void	render_map(t_vars *v)
{
	int	w_map;
	int	h_map;
	int	w;
	int	h;

	h = 0;
	h_map = 0;
	while (v -> height > 0)
	{
		w = 0;
		w_map = 0;
		while (w_map < v -> width)
		{
			put_image_to_map(v -> arr[h_map][w_map], w, h, &v);
			w_map++;
			w += v->s;
		}
		h_map++;
		h += v->s;
		v -> height--;
	}
}
