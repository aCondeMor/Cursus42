SOURCE = main.c

OBJS = ${SOURCE:.c=.o}
NAME = pipex
INCLUDES = includes
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: ${NAME}

${NAME}: ${OBJS}
	$(GCC) ${OBJS} -o ${NAME}
clean:
	rm -f ${OBJS}
fclean:	clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean .c.o
