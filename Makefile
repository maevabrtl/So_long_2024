.PHONY: all clean fclean re libft mlx

NAME = so_long
CC = cc
CC_MANDATORY_FLAGS = -Wall -Wextra -Werror
CC_FLAGS = -fsanitize=address -g3

#******************************************************************************#
#                                  Includes                                    #
#******************************************************************************#

PATH_INC = ./Includes/
LIBFT = $(addprefix $(PATH_INC)Libft)
MLX = $(addprefix $(PATH_INC)mlx)
FILES_INC = so_long
INCS = $(addprefix $(PATH_INC)$(FILES_INC), $(addsuffix .h , $(FILES_INC)))

#******************************************************************************#
#                                    SRCS                                      #
#******************************************************************************#

PATH_SRCS = ./Srcs/

#******************************************************************************#
#                                    OBJS                                      #
#******************************************************************************#

PATH_OBJS = ./Objs/

#******************************************************************************#
#                                    ALL                                       #
#******************************************************************************#


#*****************************************************************************#
#                                   RULES                                     #
#*****************************************************************************#

all: $(NAME) libft mlx

libft:
	@make -C $(LIBFT)

mlx:
	@make -C $(MLX)

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
	@rm -rf $(PATH_OBJ)

fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(MLX)
	@rm -f $(NAME)

re: fclean all

# test: all

# bonus:

#*****************************************************************************#
#                                Compilation                                  #
#*****************************************************************************#

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c $(INCS) $(MLX) $(LIBFT)
	@$(CC) $(CC_MANDATORY_FLAGS) $(CC_FLAGS) -I $(PATH_INC) -c $< -o $@

$(NAME): $(PATH_OBJS) $(OBJS)
	@$(CC) $(CC_FLAGS) $(OBJS) -o $@

$(PATH_OBJS):
	@mkdir -p $@
