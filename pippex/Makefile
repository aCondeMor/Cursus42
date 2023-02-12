SOURCE = main.c

OBJS = ${SOURCE:.c=.o}
NAME = pippex
INCLUDES = includes
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: ${NAME}
so:
	$(GCC) -nostartfiles -fPIC $(CFLAGS) $(SOURCE)
	gcc -nostartfiles -shared -o pippex.so $(OBJS)
${NAME}: ${OBJS}
	$(GCC) ${OBJS} -o ${NAME}
clean:
	rm -f ${OBJS}
fclean:	clean
	rm -f ${NAME}
try:
	./pippex.a
re: fclean all

.PHONY: all clean fclean try re so .c.o
