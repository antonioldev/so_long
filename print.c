/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:15:42 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/18 14:15:44 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_print_moves(t_vars **v)
{
	char	*move;

	mlx_string_put((*v)->mlx, (*v)->win, 5,
		(*v)->win_h - 40, 0xffffff, "Moves :");
	move = ft_itoa((*v)->move);
	mlx_string_put((*v)->mlx, (*v)->win, 50, (*v)->win_h - 40,
		0x000000, move);
	free (move);
	(*v)->move++;
	move = ft_itoa((*v)->move);
	mlx_string_put((*v)->mlx, (*v)->win, 50, (*v)->win_h - 40,
		0xffffff, move);
	free (move);
}

void	put_image(t_vars ***v, int h, int w, char *img)
{
	int	img_w;
	int	img_h;

	(**v)-> img = mlx_xpm_file_to_image((**v)-> mlx, img, &img_w, &img_h);
	mlx_put_image_to_window((**v)-> mlx, (**v)-> win, (**v)-> img, h, w);
	mlx_destroy_image((**v)-> mlx, (**v)-> img);
}

int	ft_print_end(t_vars **v)
{
	if ((*v)->lose == 2)
		put_image(&v, 0, 0, "./textures/lost.xpm");
	else
		put_image(&v, 0, 0, "./textures/won.xpm");
	mlx_string_put((*v)->mlx, (*v)->win, 5,
		512 + 50, 0xffffff, "PRESS ESC TO EXIT");
	return (0);
}
