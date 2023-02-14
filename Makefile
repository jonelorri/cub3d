NAME = Cub3d

SRC =  raycaster.c\
	

OBJ = raycaster.o\

CFLAGS =  #-Wall -Wextra -Werror -fsanitize=address -g3

CC = gcc -O3

$(NAME): $(OBJ)
		@date
		@${MAKE} -C mlx 2>.null
		@$(CC) $(CFLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)
		@echo "\n-------CORRECTLY COMPILED------"
	
all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $^ -o $@	

clean:
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf .null
	@${MAKE} -C mlx clean
	@echo "---------CLEAN  DONE----------"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "---------FCLEAN  DONE---------"

re: fclean all

.PHONY: all clean fclean re

