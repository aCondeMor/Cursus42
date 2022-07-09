SOURCE = main.c ft_printf.c ft_printf_utils.c libft/ft_putchar_fd.c\
	libft/ft_putstr_fd.c libft/ft_strlen.c ft_printf_utils_v2.c 

OBJS = ${SOURCE:.c=.o}
NAME = libftprintf.a
INCLUDES = includes
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: ${NAME}
so:
	$(GCC) -nostartfiles -fPIC $(CFLAGS) $(SOURCE)
	gcc -nostartfiles -shared -o libftftprintf.so $(OBJS)
${NAME}: ${OBJS}
	ar -rc ${NAME} ${OBJS}
clean:
	rm -f ${OBJS}
fclean:	clean
	rm -f ${NAME}
try:
	./libftprintf.a
re: fclean all

.PHONY: all clean fclean try re so .c.o
