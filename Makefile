.PHONY: all clean fclean re libft me a sandwich

NAME := so_long
CC := cc
MANDATORY_FLAGS := -Wall -Wextra -Werror
DEPS_FLAGS := -MMD -MP
MLX_MACOS_FLAGS := -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext -framework OpenGL -framework AppKit
CC_FLAGS := -fsanitize=address -g3
ALL_FLAGS = $(MANDATORY_FLAGS) $(CC_FLAGS) $(DEPS_FLAGS) $(MLX_MACOS_FLAGS)
#to modify later to make something that works both on my mac and at school pc's

#******************************************************************************#
#                                  Includes                                    #
#******************************************************************************#

PATH_INC = ./Includes/
LIBFT = $(addprefix $(PATH_INC), Libft)
FILES_INC = so_long.h
INCS = $(addprefix $(PATH_INC), $(FILES_INC))

#******************************************************************************#
#                                    SRCS                                      #
#******************************************************************************#

PATH_SRCS = ./Srcs/
FILES_SRCS =
SRCS =

#******************************************************************************#
#                                    OBJS                                      #
#******************************************************************************#

PATH_OBJS = ./Objs/
FILES_OBJS =
OBJS =

#******************************************************************************#
#                                    ALL                                       #
#******************************************************************************#


#*****************************************************************************#
#                                   RULES                                     #
#*****************************************************************************#

# <The thing you want to make>: <the stuff you need to make it>
#     <The steps to make it>
me:
	@true
a:
	@true
sandwich:
	@if [ `id -u` != 0 ]; then echo "What? Make it yourself."; else echo "Ok..."; fi

all: $(NAME) libft

libft:
	@make -C $(LIBFT)

clean:
	@make clean -C $(LIBFT)
	@rm -rf $(PATH_OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all

# test: all

# bonus:

#*****************************************************************************#
#                                Compilation                                  #
#*****************************************************************************#

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c $(INCS) $(LIBFT)
	@$(CC) $(MANDATORY_FLAGS) $(CC_FLAGS) $(DEPS_FLAGS) $(MLX_MACOS_FLAGS) -I $(PATH_INC) -c $< -o $@

$(NAME): $(PATH_OBJS) $(OBJS)
	@$(CC) $(CC_FLAGS) $(OBJS) -o $@

$(PATH_OBJS):
	@mkdir -p $@
