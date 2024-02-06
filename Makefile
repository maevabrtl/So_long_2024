.PHONY: all clean fclean re os message_begin_compil libft me a sandwich

include Includes/Libft/text_mod.mk

NAME := so_long

#******************************************************************************#
#                             Compilation & Flags                              #
#******************************************************************************#

CC := cc
MANDATORY_FLAGS := -Wall -Wextra -Werror
DEPS_FLAGS := -MMD -MP
CC_FLAGS := -fsanitize=address -g3
MLX_MACOS_FLAGS := -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext -framework OpenGL -framework AppKit
MLX_LINUX_FLAGS := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz mlx_linux/libmlx_Linux.a mlx_linux/libmlx.a

#******************************************************************************#
#                                OS Checking                                   #
#******************************************************************************#

OS = $(shell uname)
ifeq ($(OS), Linux)
	ALL_FLAGS := $(MANDATORY_FLAGS) $(DEPS_FLAGS)
	OS_MLX := $(MLX_LINUX_FLAGS)
	MLX_DIR := ./mlx_linux/
else
	ALL_FLAGS := $(MANDATORY_FLAGS) $(DEPS_FLAGS) $(CC_FLAGS)
	OS_MLX := $(MLX_MACOS_FLAGS)
endif

#******************************************************************************#
#                                  Includes                                    #
#******************************************************************************#

PATH_INC = ./Includes/
FILES_INC = so_long.h
LIBFT = $(addprefix $(PATH_INC), Libft)
INCS = $(addprefix $(PATH_INC), $(FILES_INC))

#******************************************************************************#
#                                    SRCS                                      #
#******************************************************************************#

PATH_SRCS = ./Srcs/
FILES_SRCS = main
SRCS := $(addprefix $(PATH_SRCS), $(addsuffix .c , $(FILES_SRCS)))


#******************************************************************************#
#                                    OBJS                                      #
#******************************************************************************#

PATH_OBJS = ./Objs/
OBJS = $(addprefix $(PATH_OBJS), $(addsuffix .o , $(FILES_SRCS)))

#******************************************************************************#
#                                    ALL                                       #
#******************************************************************************#


#*****************************************************************************#
#                                   RULES                                     #
#*****************************************************************************#

all: os libft message_begin_compil $(NAME) print_end_compil
#	@echo "\n$(TEXT_MOD_1)Executable$(RESET) $(TEXT_MOD_2)\
	so_long$(RESET) $(TEXT_MOD_1)successfully created !$(RESET)\n"

# check_all: log_exist
# ifdef .make_log
# 	@ls -la > .make_log_new
# endif

# log_exist:
# ifndef .make_log
# 	@ls -la > .make_log
# endif
# 	echo "yolo"

print_end_compil:
	@echo "\n$(TEXT_MOD_1)Executable$(RESET) $(TEXT_MOD_2)\
	so_long$(RESET) $(TEXT_MOD_1)successfully created !$(RESET)\n"

os:
#	@echo "\n$(TEXT_MOD_1)LET'S BUILD !$(RESET)"
#	@echo "\n> $(TEXT_MOD_5)Checking the OS...$(RESET)"
#	@echo "> $(TEXT_MOD_5)OS is $(OS) !$(RESET)"

libft:
#	@echo "> $(TEXT_MOD_5)Making libs$(RESET)"
	@make --no-print-directory -C $(LIBFT)
ifdef MLX_DIR
	@make -s --no-print-directory -C $(MLX_DIR)
endif
#	@echo "$(TEXT_MOD_1)Libraries ready for use ! 🚀 $(RESET)\n"

message_begin_compil:
#	@echo "> $(TEXT_MOD_5)Starting compilation... $(RESET)"

clean:
	@make --no-print-directory clean -C $(LIBFT)
	@rm -rf $(PATH_OBJS)
#	@echo "> $(TEXT_MOD_5)Objects files deleted.$(RESET)"

fclean: clean
	@make --no-print-directory fclean -C $(LIBFT)
	@rm -f $(NAME)
#	@echo "> $(TEXT_MOD_5)Executable$(RESET) $(TEXT_MOD_6)so_long\
	$(RESET) $(TEXT_MOD_5)deleted.$(RESET)"

re_message:
#	@echo "\n$(TEXT_MOD_1)Rebuilding program... $(RESET)\n"

re: re_message fclean all

#*****************************************************************************#
#                                Compilation                                  #
#*****************************************************************************#

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c $(INCS) $(LIBFT)
	@printf %b "  $(TEXT_MOD_3)Compiling$(RESET) $(TEXT_MOD_4)$<...$(RESET)"
	@$(CC) -c  $(ALL_FLAGS) $< -I$(PATH_INC) -o $@
	@printf "\r"
	@printf "                                                                                     \r"

$(NAME): $(PATH_OBJS) $(OBJS)
	@$(CC) $(OBJS) $(ALL_FLAGS) $(OS_MLX) -o $@
#	@echo "> $(TEXT_MOD_5)Compilation succeeded !$(RESET)"

$(PATH_OBJS):
	@mkdir -p $@

#*****************************************************************************#
#                                Funny part                                   #
#*****************************************************************************#

TEXT_MOD_1 = $(ADD_TEXT_MOD)$(BOLD)$(FONT)$(CYAN)$(END_MOD)
TEXT_MOD_2 = $(ADD_TEXT_MOD)$(BOLD)$(ITALIC)$(FONT)$(GREEN)$(END_MOD)
TEXT_MOD_3 = $(ADD_TEXT_MOD)$(FONT)$(CYAN)$(END_MOD)
TEXT_MOD_4 = $(ADD_TEXT_MOD)$(BOLD)$(FADE)$(ITALIC)$(FONT)$(BLUE)$(END_MOD)
TEXT_MOD_5 = $(ADD_TEXT_MOD)$(FONT)$(CYAN)$(END_MOD)
TEXT_MOD_6 = $(ADD_TEXT_MOD)$(ITALIC)$(FONT)$(GREEN)$(END_MOD)

# <The thing you want to make>: <the stuff you need to make it>
#     <The steps to make it>
me:
	@true
a:
	@true
sandwich:
	@if [ `id -u` != 0 ]; then echo "What? Make it yourself."; else echo "Ok..."; fi
