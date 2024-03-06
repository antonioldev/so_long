/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:24:05 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/19 10:24:23 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	put_animation_enemy(int i, int h, int w, t_vars **v)
{
	int	mod;

	mod = i % 4;
	if (mod == 0)
		put_image(&v, h, w, "./textures/enemy/e1.xpm");
	else if (mod == 1)
		put_image(&v, h, w, "./textures/enemy/e2.xpm");
	else if (mod == 2)
		put_image(&v, h, w, "./textures/enemy/e3.xpm");
	else if (mod == 3)
		put_image(&v, h, w, "./textures/enemy/e4.xpm");
}

void	put_animation_right(int i, int h, int w, t_vars **v)
{
	int	mod;

	mod = i % 6;
	(*v)->sleep = 0;
	while ((*v)->sleep < 10000000)
		(*v)->sleep++;
	if (mod == 0)
		put_image(&v, h, w, "./textures/player/pl_r1.xpm");
	else if (mod == 1)
		put_image(&v, h, w, "./textures/player/pl_r2.xpm");
	else if (mod == 2)
		put_image(&v, h, w, "./textures/player/pl_r3.xpm");
	else if (mod == 3)
		put_image(&v, h, w, "./textures/player/pl_r4.xpm");
	else if (mod == 4)
		put_image(&v, h, w, "./textures/player/pl_r5.xpm");
	else if (mod == 5)
		put_image(&v, h, w, "./textures/player/pl_r6.xpm");
}

void	put_animation_left(int i, int h, int w, t_vars **v)
{
	int	mod;

	mod = i % 6;
	(*v)->sleep = 0;
	while ((*v)->sleep < 10000000)
		(*v)->sleep++;
	if (mod == 0)
		put_image(&v, h, w, "./textures/player/pl_l1.xpm");
	else if (mod == 1)
		put_image(&v, h, w, "./textures/player/pl_l2.xpm");
	else if (mod == 2)
		put_image(&v, h, w, "./textures/player/pl_l3.xpm");
	else if (mod == 3)
		put_image(&v, h, w, "./textures/player/pl_l4.xpm");
	else if (mod == 4)
		put_image(&v, h, w, "./textures/player/pl_l5.xpm");
	else if (mod == 5)
		put_image(&v, h, w, "./textures/player/pl_l6.xpm");
}

void	put_animation_up(int h, int w, t_vars **v)
{
	int	mod;

	mod = (*v)->x_player % 4;
	if (mod == 0)
		put_image(&v, h, w, "./textures/player/pl_b1.xpm");
	else if (mod == 1)
		put_image(&v, h, w, "./textures/player/pl_b2.xpm");
	else if (mod == 2)
		put_image(&v, h, w, "./textures/player/pl_b3.xpm");
	else if (mod == 3)
		put_image(&v, h, w, "./textures/player/pl_b4.xpm");
}
