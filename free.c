/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:28:36 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/18 13:28:38 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_free_malloc_and_close(t_vars *v, int fd)
{
	int	i;

	i = 0;
	while (v->visited[i])
	{
		free(v -> visited[i]);
		free(v -> arr[i]);
		i++;
	}
	free(v -> visited);
	free(v -> arr);
	close(fd);
}

void	ft_destroy_mlx(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_display(v->mlx);
	free (v->mlx);
}
