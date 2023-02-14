NAME = libft.a

SRCS = ft_bzero.c \
	   ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	   ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c \
	   ft_calloc.c \
	   ft_substr.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	   get_next_line.c get_next_line_utils.c

#BONUS =

#OBJS_BONUS = $(BONUS:.c=.o)

OBJS = $(SRCS:.c=.o)

CC = gcc -Wall -Werror -Wextra

LIBC = ar rcs

RM = rm -f

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS)
	$(LIBC) $@ $^

#bonus:$(OBJS_BONUS)
#	$(LIBC) $(NAME) $^

clean:
	$(RM) $(OBJS) #$(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
