.PHONY: all clean fclean re bonus
# Name of file
NAME		=	philo

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs
PATH_LOG	=	philo/logs

# List of sources
SRCS_DISP	=	error_message.c print0.c what_message.c
SRCS_MANA_T	= 	actions.c routines.c
SRCS_PARS	=	parsing0.c
SRCS_TOOLS	=	ft_atoi.c ft_exit.c ft_gettime.c ft_isdigit.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_strlen.c ft_usleep.c
SRCS		=	$(addprefix $(PATH_SRC)/display/, $(SRCS_DISP)) \
				$(addprefix $(PATH_SRC)mana_thread/, $(SRCS_MANA_T)) \
				$(addprefix $(PATH_SRC)/parsing/, $(SRCS_PARS)) \
				$(addprefix $(PATH_SRC)/tools/, $(SRCS_TOOLS)) \
				$(addprefix $(PATH_SRC)/, )  main.c #add files à la racine

OBJS		=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
INCS		=	$(PATH_INC)/philo.h

# Commands of compilation
COMP		=	clang
COMP_FLAG	=	-Wall -Wextra -Werror
COMP_ADD	=	-I$(PATH_INC) -I$(LIBFT_DIR)/$(PATH_INC)

# Others Command
RM			=	/bin/rm

# Color Code and template code
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:	init $(NAME)
	@ echo "$(_SUCCESS) Compilation done"

init:
	 $(shell mkdir -p $(PATH_OBJ))

bonus :	all

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -pthread -lpthread

$(PATH_OBJ)/%.o : $(PATH_SRC)/*/%.c  $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@ -pthread
	@ echo "$(_INFO) Compilation of $*"

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.c  $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@ -pthread
	@ echo "$(_INFO) Compilation of $*"

clean:
	@ $(RM) -rf $(PATH_OBJ)
	echo "$(_INFO) Deleted files and directory"

fclean: clean
	@ $(RM) -rf $(NAME)

re: fclean all
