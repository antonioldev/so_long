/* ************************************************************************** */
/*	*/
/*	:::		 ::::::::   */
/*   solong.h		  :+:		 :+:	:+:   */
/*	+:+ +:+		+:+		*/
/*   By: alimotta <marvin@42.fr>	+#+  +:+		  +#+	*/
/*	+#+#+#+#+#+   +#+		  */
/*   Created: 2024/01/10 09:40:43 by alimotta		 #+#	#+#		*/
/*   Updated: 2024/01/10 16:39:58 by alimotta		###   ########.fr		  */
/*	*/
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <X11/keysym.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**arr;
	char	**visited;
	int		width;
	int		height;
	int		win_h;
	int		win_w;
	int		exit;
	int		collectable;
	int		player;
	int		x_player;
	int		y_player;
	int		sleep;
	int		x_exit;
	int		y_exit;
	int		is_open;
	int		move;
	int		enemy;
	int		x_enemy;
	int		y_enemy;
	int		lose;
	int		s;
	int		frame;
	int		framerate;
}			t_vars;

int		main(int argc, char **argv);
int		x_pressed(t_vars *v);
int		handle_input(int ks, t_vars *v);
int		ft_error(int argc, char **argv);
int		ft_check_map(t_vars *v);
int		ft_open_path_map(char *file_name);
int		ft_check_valid_map(t_vars *v, char **visited);
int		ft_move_enemy(t_vars *v);
int		ft_is_safe_enemy(t_vars *v, int i, int j);
int		ft_print_end(t_vars **v);
void	ft_create_enemy(t_vars *v);
void	render_map(t_vars *v);
void	ft_print_moves(t_vars **v);
void	ft_destroy_mlx(t_vars *v);
void	ft_free_malloc_and_close(t_vars *v, int fd);
void	put_image_to_map(char p, int h, int w, t_vars **v);
void	put_animation_right(int i, int h, int w, t_vars **v);
void	put_animation_left(int i, int h, int w, t_vars **v);
void	put_animation_up(int h, int w, t_vars **v);
void	put_animation_enemy(int i, int h, int w, t_vars **v);
void	put_image(t_vars ***v, int h, int w, char *img);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
#endif
