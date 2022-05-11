SOURCE = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c\
		 ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		 ft_strlcpy.c ft_strlcat.c ft_memchr.c ft_memcmp.c ft_toupper.c\
		 ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c\
		 ft_strdup.c ft_calloc.c ft_atoi.c ft_substr.c ft_strjoin.c\
		 ft_strtrim.c ft_split.c ft_itoa.c

OBJS = ${SOURCE:.c=.o}
NAME = libft.a
INCLUDES = includes
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: ${NAME}

${NAME}: ${OBJS}
	ar -rc ${NAME} ${OBJS}
clean:
	rm ${OBJS}
fclean:	clean
	rm -f ${NAME}
try:
	./libft.a

re: fclean all

.PHONY: all clean fclean try re
