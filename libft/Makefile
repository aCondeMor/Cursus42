SOURCE = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c\
		 ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		 ft_strlcpy.c ft_strlcat.c ft_memchr.c ft_memcmp.c ft_toupper.c\
		 ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c\
		 ft_strdup.c ft_calloc.c ft_atoi.c ft_substr.c ft_strjoin.c\
		 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BSOURCE = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		  ft_lstmap.c

OBJS = ${SOURCE:.c=.o}
BOBJS = ${BSOURCE:.c=.o}
NAME = libft.a
INCLUDES = includes
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: ${NAME}
so:
	$(GCC) -nostartfiles -fPIC $(CFLAGS) $(SOURCE) $(BSOURCE) 
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BOBJS)
${NAME}: ${OBJS}
	ar -rc ${NAME} ${OBJS}
bonus: $(OBJS) $(BOBJS)
	ar -rc $(NAME) $?
clean:
	rm ${OBJS} ${BOBJS}
fclean:	clean
	rm -f ${NAME}
try:
	./libft.a
re: fclean all

.PHONY: all clean fclean try re so bonus
