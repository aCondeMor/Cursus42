SOURCE = main.c libft/ft_split.c libft/ft_isdigit.c libft/ft_putendl_fd.c\
	libft/ft_strncmp.c libft/ft_strlen.c libft/ft_putchar_fd.c\
	libft/ft_putstr_fd.c swaps.c pushes.c rotates.c rev_rotates.c\
	print_stacks.c sorting.c stack.c libft/ft_substr.c libft/ft_strdup.c\
	libft/ft_memcpy.c libft/ft_strjoin.c

OBJS = ${SOURCE:.c=.o}
NAME = push_swap
INCLUDES = includes
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: ${NAME}
so:
	$(GCC) -nostartfiles -fPIC $(CFLAGS) $(SOURCE)
	gcc -nostartfiles -shared -o pushswap.so $(OBJS)
${NAME}: ${OBJS}
	$(GCC) ${OBJS} -o ${NAME}
clean:
	rm -f ${OBJS}
fclean:	clean
	rm -f ${NAME}
try:
	./pushswap.a
re: fclean all

.PHONY: all clean fclean try re so .c.o
