NAME = so_long
CC = cc
DEPS = so_long.h
FLAGS = -Wall -Wextra -Werror -g -I$(DEPS)
SRC = 	main.c error_check.c error_check_2.c \
		render.c move_player.c free.c print.c \
		animation.c enemy.c move_enemy.c \
		utils.c split.c itoa.c
OBJ = $(SRC:.c=.o)
RM = rm -f
MLX = -lmlx_Linux 
MLXFLAG = -lXext -lX11
MLXPATH = -Lminilibx-linux

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ) $(MLX)
	$(CC) $(FLAGS) $(MLXPATH) $(OBJ) $(MLX) $(MLXFLAG) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

$(MLX):
	$(MAKE) --no-print-directory -C ./minilibx-linux	

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all
