.PHONY: all clean fclean re libft

NAME = so_long
CC = cc
CC_FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
PATH_OBJ = ./Objs/
PATH_SRC = ./Srcs/
PATH_INC = ./Includes/

#******************************************************************************#
#                                  Includes                                    #
#******************************************************************************#

LIBFT = $(addprefix $(PATH_INC)Libft)

FILES_INC = so_long
INCS = $(addprefix $(PATH_INC)$(FILES_INC), $(addsuffix .h , $(FILES_INC)))


#******************************************************************************#
#                                   MOVES                                      #
#******************************************************************************#

MOVES_FOLDER = moves/
FILES_MOVES = push reverse_rotate rotate swap
SRCS_MOVES = $(addprefix $(PATH_SRC)$(MOVES_FOLDER), $(addsuffix .c , $(FILES_MOVES)))
OBJS_MOVES = $(addprefix $(PATH_OBJ)$(MOVES_FOLDER), $(addsuffix .o , $(FILES_MOVES)))

#******************************************************************************#
#                                    UTILS                                     #
#******************************************************************************#

UTILS_FOLDER = utils/
FILES_UTILS = conversion_utils formating_utils list_utils string_utils
SRCS_UTILS = $(addprefix $(PATH_SRC)$(UTILS_FOLDER), $(addsuffix .c , $(FILES_UTILS)))
OBJS_UTILS = $(addprefix $(PATH_OBJ)$(UTILS_FOLDER), $(addsuffix .o , $(FILES_UTILS)))

#******************************************************************************#
#                                    ALL                                       #
#******************************************************************************#

OBJS = $(OBJS_ALGO) $(OBJS_MOVES) $(OBJS_UTILS)
SRCS = $(SRCS_ALGO) $(SRCS_MOVES) $(SRCS_UTILS)
PATH_OBJS = $(addprefix $(PATH_OBJ), $(ALGO_FOLDER) $(MOVES_FOLDER) $(UTILS_FOLDER))

#*****************************************************************************#
#                                   RULES                                     #
#*****************************************************************************#

all: $(NAME)

clean:
	@rm -rf $(PATH_OBJ)

fclean: clean
	@rm -f $(NAME)
	echo

re: fclean all

#*****************************************************************************#
#                                Compilation                                  #
#*****************************************************************************#

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(INC)
	@$(CC) $(CC_FLAGS) -I $(PATH_INC) -c $< -o $@

$(NAME): $(PATH_OBJS) $(OBJS)
	@$(CC) $(CC_FLAGS) $(OBJS) -o $@

$(PATH_OBJS):
	@mkdir -p $@
