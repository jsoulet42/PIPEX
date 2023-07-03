### EXECUTABLE ###
NAME		=	pipex
### FOLDERS ###
LIBFT		=	INCLUDES/libft/libft.a
LIB			= ./INCLUDES/libft

### SOURCES ###
SRCS	=	main.c \



OBJS	=	$(SRCS:.c=.o)
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
###-fsanitize=address
INC	=	-I $(LIB)
RM = rm -f


all:	$(NAME) $(LIBFT)
	@echo $(NOC)Le projet pipex de a ete compile avec succes${NOC}

$(LIBFT):
		@echo $(GREEN)Construction de la libft$(NOC)
		@make -s -C $(LIB) all

%.o: %.c
		@$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(LIBFT)
			@echo $(GREEN)Construction de pipex$(NOC)
			@$(CC) -o $(NAME) $(OBJS) -L ${LIB} -lft

clean:
		@echo $(RED)Destruction des .o$(NOC)
		@$(RM) $(OBJS)
		@make -C $(LIB) clean > /dev/null

fclean: clean
		@echo $(RED)Destruction des .a$(NOC)
		@$(RM) $(NAME)
		@make -C $(LIB) fclean > /dev/null

re:		fclean all

### COLORS ###

NOC			= "\033[0m"
BOLD		= "\033[1m"
UNDERLINE	= "\033[4m"
BLACK		= "\033[1;30m"
RED			= "\033[1;31m"
GREEN		= "\033[1;32m"
YELLOW		= "\033[1;33m"
BLUE		= "\033[1;34m"
VIOLET		= "\033[1;35m"
CYAN		= "\033[1;36m"
WHITE		= "\033[1;37m"
