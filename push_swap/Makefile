SOURCE_AUX = libft/ft_split.c libft/ft_isdigit.c libft/ft_putendl_fd.c\
	libft/ft_strncmp.c  libft/ft_putchar_fd.c\
	libft/ft_putstr_fd.c swaps.c pushes.c rotates.c rev_rotates.c\
	print_stacks.c sorting_small.c sorting_big.c stack.c libft/ft_strdup.c\
	libft/ft_memcpy.c aux_functions.c

SOURCE = $(SOURCE_AUX) main.c libft/ft_substr.c libft/ft_strlen.c libft/ft_strjoin.c 

BSOURCE = $(SOURCE_AUX) aux_functions_bonus.c main_bonus.c\
	get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c 

OBJS = ${SOURCE:.c=.o}
BOBJS = ${BSOURCE:.c=.o}
NAME = push_swap
BONUS = checker
INCLUDES = includes
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: ${NAME}

${NAME}: ${OBJS}
	${GCC} ${CFLAGS} ${OBJS} -o ${NAME} 

bonus: $(BOBJS)
	${GCC} ${CFLAGS} $(BOBJS) -o ${BONUS}
clean:
	rm -f ${OBJS} $(BOBJS)
fclean:	clean
	rm -f ${NAME} ${BONUS}

re: fclean all

.PHONY: all clean fclean .c.o
