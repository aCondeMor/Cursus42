SOURCE = main.c libft/ft_split.c libft/ft_strjoin.c libft/ft_strlen.c\
	libft/ft_strncmp.c libft/ft_strdup.c libft/ft_substr.c libft/ft_putendl_fd.c\
	libft/ft_memcpy.c auxfunctions.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c\

OBJS = ${SOURCE:.c=.o}
NAME = pipex
INCLUDES = includes
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: ${NAME}

${NAME}: ${OBJS}
	${GCC} ${CFLAGS} ${OBJS} -o ${NAME} 

clean:
	rm -f ${OBJS}
fclean:	clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean .c.o
