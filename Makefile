NAME=libftprintf.a

CC=gcc

CFLAGS = -Wall -Wextra -Werror -I.

SRCS = ft_printf.c

UTILS_SRCS = utils/ft_putchar.c utils/ft_putstr.c utils/ft_putnbr.c \
			 utils/ft_puthex.c

OBJS = $(SRCS:.c=.o)

UTILS_OBJS = $(UTILS_SRCS:.c=.o)

RM = rm -f

all:	$(NAME)

$(NAME):	$(UTILS_OBJS) $(OBJS)
		ar rcs $(NAME) $(UTILS_OBJS) $(OBJS)

clean:
		$(RM) $(UTILS_OBJS) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re
