.PHONY: all clean fclean re libft me a sandwich

include Includes/Libft/text_mod.mk

NAME := so_long
CC := cc
MANDATORY_FLAGS := -Wall -Wextra -Werror
DEPS_FLAGS := -MMD -MP
MLX_MACOS_FLAGS := -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext -framework OpenGL -framework AppKit
CC_FLAGS := -fsanitize=address -g3
ALL_FLAGS = $(MANDATORY_FLAGS) $(CC_FLAGS) $(DEPS_FLAGS) $(MLX_MACOS_FLAGS)
PRINT := echo
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
FILES_SRCS = main.c


#******************************************************************************#
#                                    OBJS                                      #
#******************************************************************************#

PATH_OBJS = ./Objs/
FILES_OBJS = main.o

#******************************************************************************#
#                                    ALL                                       #
#******************************************************************************#


#*****************************************************************************#
#                                   RULES                                     #
#*****************************************************************************#

all: # $(NAME) libft
	@$(PRINT) "\n$(TEXT_MOD_1)Executable$(RESET) $(TEXT_MOD_2)\
	so_long$(RESET) $(TEXT_MOD_1)successfully created !$(RESET)\n"

libft:
	@make -C $(LIBFT)

clean:
	@make clean -C $(LIBFT)
	@rm -rf $(PATH_OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all

#*****************************************************************************#
#                                Compilation                                  #
#*****************************************************************************#

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c $(INCS) $(LIBFT)
	@printf %b "  $(TEXT_MOD_3)Compiling$(RESET) $(TEXT_MOD_4)$<...$(RESET)"
	@$(CC) $(ALL_FLAGS) -I $(PATH_INC) -o $@ -c $<
	@printf "\r"
	@printf "                                                                                     \r"

$(NAME): $(PATH_OBJS) $(OBJS)
	@$(CC) $(ALL_FLAGS) $(OBJS) -o $@

$(PATH_OBJS):
	@mkdir -p $@

#*****************************************************************************#
#                                Funny part                                   #
#*****************************************************************************#

TEXT_MOD_1 = $(ADD_TEXT_MOD)$(BOLD)$(FONT)$(CYAN)$(END_MOD)
TEXT_MOD_2 = $(ADD_TEXT_MOD)$(BOLD)$(ITALIC)$(FONT)$(GREEN)$(END_MOD)
TEXT_MOD_3 = $(ADD_TEXT_MOD)$(FONT)$(CYAN)$(END_MOD)
TEXT_MOD_4 = $(ADD_TEXT_MOD)$(BOLD)$(FADE)$(ITALIC)$(FONT)$(BLUE)$(END_MOD)

# <The thing you want to make>: <the stuff you need to make it>
#     <The steps to make it>
me:
	@true
a:
	@true
sandwich:
	@if [ `id -u` != 0 ]; then echo "What? Make it yourself."; else echo "Ok..."; fi
