SRCS	=	$(wildcard *.c)

OBJS	=	$(SRCS:.c=.o)



GCC	=	gcc -Werror -Wall -Wextra

RM = rm -f

NAME	=	libft.a

all:	$(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re bonus
