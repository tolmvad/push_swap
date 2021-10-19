#SETUP
PUSH_SWAP	=	push_swap
CHECKER		=	checker
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
SRCS_FILES	=	push_swap.c push.c swap.c rotate.c error.c\
				checks.c positions.c creating.c markup_head.c\
				markup.c solve_a.c solve_b.c\
				align.c free.c d_rotate.c moves.c index.c need.c
SRCS_DIR	=	sources/
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJ			=	$(SRCS:.c=.o)

FUNC_FILES	=	ft_atoi.c ft_lstadd_back.c ft_lstadd_front.c\
				ft_lstake_first.c ft_lstake_last.c ft_lstnew.c\
				ft_lstlen.c ft_sort.c ft_strcmp.c
FUNC_DIR	=	functions/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_FILES))
OBJ_F		=	$(FUNC:.c=.o)

BONUS_FILES	=	checker.c checks.c creating.c error.c free.c\
				swap.c push.c rotate.c d_rotate.c
BONUS_DIR	=	sources/
BONUS		=	$(addprefix $(BONUS_DIR), $(BONUS_FILES))\
				gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ_B		=	$(BONUS:.c=.o)

HEADERS		=	includes/push_swap.h gnl/get_next_line.h

#COMMANDS
%.o: %.c $(HEADERS) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(PUSH_SWAP):	$(OBJ) $(OBJ_F)
				@$(CC) $(OBJ) $(OBJ_F) -o $(PUSH_SWAP)
				@echo -e "$(GREEN)$(PUSH_SWAP) created!$(DEFAULT)"

all:			$(PUSH_SWAP)

bonus:			all $(OBJ_B)
				@$(CC) $(OBJ_B) $(OBJ_F) -o $(CHECKER)
				@echo -e "$(GREEN)$(CHECKER) created!$(DEFAULT)"
clean:
				@$(RM) $(OBJ)
				@$(RM) $(OBJ_F)
				@$(RM) $(OBJ_B)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(PUSH_SWAP)
				@$(RM) $(CHECKER)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all bonus

.PHONY:		all bonus clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
