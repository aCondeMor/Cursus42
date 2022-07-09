SOURCE = ft_printf.c ft_printf_utils.c ft_printf_utils_v2.c 

OBJS = ${SOURCE:.c=.o}
NAME = libftprintf.a
INCLUDES = includes
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB_DIR = libft
LIB = libft.a
.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: ${NAME}
so:
	$(GCC) -nostartfiles -fPIC $(CFLAGS) $(SOURCE)
	gcc -nostartfiles -shared -o libftftprintf.so $(OBJS)
${NAME}: ${OBJS}
	@make -C $(LIB_DIR)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	ar -rc ${NAME} ${OBJS}
clean:
	rm -f ${OBJS}
	@make clean -C $(LIB_DIR)
fclean:	clean
	rm -f ${NAME}
	@$(RM) -f $(LIB_DIR)/libft.a
try:
	./libftprintf.a
re: fclean all

.PHONY: all clean fclean try re so .c.o
