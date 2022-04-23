SOURCE = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c\
		ft_strlen.c ft_memset.c ft_bzero.c
OBJS = ${SOURCE:.c=.o}
TARGET = libft.a
INCLUDES = includes
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: ${TARGET}

${TARGET}: ${OBJS}
	ar -rc ${TARGET} ${OBJS}
clean:
	rm ${OBJS}
fclean:	clean
	rm ${TARGET}
try:
	./libft.a

re: fclean all

.PHONY: all clean fclean try re
