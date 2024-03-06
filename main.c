/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   main.c	 :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: alimotta <marvin@42.fr>	+#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2024/01/10 10:43:37 by alimotta	  #+#	#+#	 */
/*   Updated: 2024/01/11 17:01:42 by alimotta	 ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "solong.h"

int	ft_end_game(t_vars *v)
{
	v->mlx = mlx_init();
	if (v->mlx == NULL)
		return (-1);
	v->win = mlx_new_window(v->mlx, 512, 592, "THE END");
	if (v->win == NULL)
		return (free(v->mlx), -1);
	ft_print_end(&v);
	mlx_hook(v->win, 2, 1L << 0, handle_input, v);
	mlx_hook(v->win, 17, 1L << 0, x_pressed, v);
	mlx_loop(v->mlx);
	ft_destroy_mlx(v);
	return (0);
}

int	ft_open_path_map(char *file_name)
{
	int		fd;
	char	path[100];

	ft_strlcpy(path, "maps/", 6);
	ft_strlcat(path, file_name, 100);
	fd = open(path, O_RDONLY);
	return (fd);
}

static char	*ft_read_from_file(int fd, char *s)
{
	size_t	bytes_read;
	char	temp[1];
	char	*s2;

	while (s == 0 || bytes_read > 0)
	{
		bytes_read = read(fd, temp, 1);
		if (s == 0 && bytes_read > 0)
		{
			s = (char *)malloc(bytes_read + 1);
			ft_strlcpy(s, temp, bytes_read + 1);
		}
		else if (bytes_read > 0)
		{
			s2 = (char *)malloc(ft_strlen(s) + bytes_read + 1);
			ft_strlcpy(s2, s, ft_strlen(s) + 1);
			ft_strlcat(s2, temp, ft_strlen(s) + bytes_read + 1);
			free (s);
			s = (char *)malloc(ft_strlen(s2) + 1);
			ft_strlcpy(s, s2, ft_strlen(s2) + 1);
			free (s2);
		}
	}
	return (s);
}

static void	ft_initiate_vars(t_vars *v, int fd)
{
	char	*str;

	str = ft_read_from_file(fd, 0);
	v -> collectable = 0;
	v -> player = 0;
	v -> exit = 0;
	v -> move = 0;
	v -> arr = ft_split(str, '\n');
	v -> visited = ft_split(str, '\n');
	v -> is_open = 0;
	v -> enemy = 0;
	v -> sleep = -1;
	v -> lose = 0;
	v -> s = 34;
	v -> x_enemy = 0;
	v -> y_enemy = 0;
	v -> frame = 0;
	free (str);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_vars	v;

	fd = ft_error(argc, argv);
	ft_initiate_vars(&v, fd);
	if (ft_check_map(&v) == 0)
	{
		v.mlx = mlx_init();
		if (v.mlx == NULL)
			return (-1);
		v.win = mlx_new_window(v.mlx, v.win_w, v.win_h, "MY GAME");
		if (v.win == NULL)
			return (free(v.mlx), -1);
		render_map(&v);
		mlx_hook(v.win, 17, 1L << 0, x_pressed, &v);
		mlx_hook(v.win, 3, 1L << 1, handle_input, &v);
		mlx_loop_hook(v.mlx, ft_move_enemy, &v);
		mlx_loop(v.mlx);
		ft_destroy_mlx(&v);
		if (v.lose > 0)
			ft_end_game(&v);
	}
	ft_free_malloc_and_close(&v, fd);
	return (0);
}
