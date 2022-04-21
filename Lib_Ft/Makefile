SOURCE = rush.c struct.c
OBJS = ${SOURCE:.c=.o}
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
$NAME: ${OBJS} 	
	${GCC} -o rush-02 ${OBJS}
clean:
	rm ${OBJS}
fclean:	clean
	rm rush-02
try:
	./rush-02
