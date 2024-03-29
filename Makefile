.PHONY: all clean fclean re os libs me a sandwich tests FORCE

include Includes/Libft/text_mod.mk

#******************************************************************************#
#                                  VARIABLES                                   #
#******************************************************************************#

#******************************************************************************#
#                             Compilation & Flags                              #
#******************************************************************************#

NAME := so_long
CC := cc
MANDATORY_FLAGS := -Wall -Wextra -Werror -g3
DEPS_FLAGS := -MMD -MP
MLX_LINUX_FLAGS := -L ./minilibx-linux -lmlx -lXext -lX11
MLX_A := minilibx-linux/libmlx.a

#******************************************************************************#
#                                OS Checking                                   #
#******************************************************************************#

OS = $(shell uname)
ifeq ($(OS), Linux)
	ALL_FLAGS := $(MANDATORY_FLAGS) $(DEPS_FLAGS)
	OS_MLX := $(MLX_LINUX_FLAGS)
	MLX_DIR := minilibx-linux
endif


#******************************************************************************#
#                                   Paths                                      #
#******************************************************************************#

PATH_INC = ./Includes/
PATH_SRCS = ./Srcs/
PATH_OBJS = ./.Objs/
PATH_PARSING = $(addprefix $(PATH_SRCS), Parsing/)
PATH_PARSING_OBJS = $(addprefix $(PATH_OBJS), Parsing/)
PATH_GAME = $(addprefix $(PATH_SRCS), Game/)
PATH_GAME_OBJS = $(addprefix $(PATH_OBJS), Game/)
PATH_EXIT_CLEAN = $(addprefix $(PATH_SRCS), Exit_clean/)
PATH_EXIT_CLEAN_OBJS = $(addprefix $(PATH_OBJS), Exit_clean/)

#******************************************************************************#
#                                  Includes                                    #
#******************************************************************************#

FILES_INC = so_long.h
INCS = $(addprefix $(PATH_INC), $(FILES_INC))
PATH_LIBFT = $(addprefix $(PATH_INC), Libft/)
LIBFT = $(addprefix $(PATH_LIBFT), libft.a)

#******************************************************************************#
#                                    Main                                      #
#******************************************************************************#

FILE_MAIN = main
MAIN_SRC = $(addprefix $(PATH_SRCS), $(addsuffix .c , $(FILE_MAIN)))
MAIN_OBJ = $(addprefix $(PATH_OBJS), $(addsuffix .o , $(FILE_MAIN)))

#******************************************************************************#
#                                   Parsing                                    #
#******************************************************************************#

FILES_PARSING = is_valid_map is_winnable_map parse_map
PARSING_SRCS = $(addprefix $(PATH_PARSING), $(addsuffix .c , $(FILES_PARSING)))
PARSING_OBJS = $(addprefix $(PATH_PARSING_OBJS), $(addsuffix .o , $(FILES_PARSING)))

#******************************************************************************#
#                                     Game                                     #
#******************************************************************************#

FILES_GAME = graphics handler init_tools
GAME_SRCS = $(addprefix $(PATH_GAME), $(addsuffix .c , $(FILES_GAME)))
GAME_OBJS = $(addprefix $(PATH_GAME_OBJS), $(addsuffix .o , $(FILES_GAME)))

#******************************************************************************#
#                                  Exit_clean                                  #
#******************************************************************************#

FILES_EXIT_CLEAN = clean_and_exit free_tools_sl
EXIT_CLEAN_SRCS = $(addprefix $(PATH_EXIT_CLEAN), $(addsuffix .c , $(FILES_EXIT_CLEAN)))
EXIT_CLEAN_OBJS = $(addprefix $(PATH_EXIT_CLEAN_OBJS), $(addsuffix .o , $(FILES_EXIT_CLEAN)))

#******************************************************************************#
#                              Sources + Objects                               #
#******************************************************************************#

ALL_OBJS_PATH = $(PATH_OBJS) $(PATH_PARSING_OBJS) $(PATH_GAME_OBJS) $(PATH_EXIT_CLEAN_OBJS)
OBJS = $(MAIN_OBJ) $(PARSING_OBJS) $(GAME_OBJS) $(EXIT_CLEAN_OBJS)
ALL_SRCS_PATH = $(PATH_SRCS) $(PATH_PARSING) $(PATH_GAME) $(PATH_EXIT_CLEAN)
SRCS = $(MAIN_SRC) $(PARSING_SRCS) $(GAME_SRCS) $(EXIT_CLEAN_SRCS)

#******************************************************************************#
#                              Text modification                               #
#******************************************************************************#

TEXT_MOD_1 = $(ADD_TEXT_MOD)$(BOLD)$(FONT)$(CYAN)$(END_MOD)
TEXT_MOD_2 = $(ADD_TEXT_MOD)$(BOLD)$(ITALIC)$(FONT)$(GREEN)$(END_MOD)
TEXT_MOD_3 = $(ADD_TEXT_MOD)$(FONT)$(CYAN)$(END_MOD)
TEXT_MOD_4 = $(ADD_TEXT_MOD)$(BOLD)$(FADE)$(ITALIC)$(FONT)$(BLUE)$(END_MOD)
TEXT_MOD_5 = $(ADD_TEXT_MOD)$(FONT)$(CYAN)$(END_MOD)
TEXT_MOD_6 = $(ADD_TEXT_MOD)$(ITALIC)$(FONT)$(GREEN)$(END_MOD)

#******************************************************************************#
#                                   RULES                                      #
#******************************************************************************#

#******************************************************************************#
#                               Building rules                                 #
#******************************************************************************#

all: os libs begin_compil $(NAME) end_compil

re: re_mess fclean all

#*****************************************************************************#
#                              Librairies rules                               #
#*****************************************************************************#

libs:
	@echo "> $(TEXT_MOD_5)Making libs$(RESET)"
	@echo ""
	@make --no-print-directory -C $(PATH_LIBFT)
	@echo "\033[A\033[K"
	@echo ""
	@make -s --no-print-directory -C $(MLX_DIR)
	@echo "\033[A\033[K"
	@echo "$(TEXT_MOD_1)Libraries ready for use ! 🚀 $(RESET)\n"


#*****************************************************************************#
#                               Cleaning rules                                #
#*****************************************************************************#

clean:
	@make --no-print-directory clean -C $(PATH_LIBFT)
	@rm -rf $(PATH_OBJS)
	@echo "> $(TEXT_MOD_5)Objects files deleted.$(RESET)"

fclean: clean
	@make --no-print-directory fclean -C $(PATH_LIBFT)
	@make -s --no-print-directory clean -C $(MLX_DIR)
	@rm -f $(NAME)
	@echo "> $(TEXT_MOD_5)Executable$(RESET) $(TEXT_MOD_6)so_long\
	$(RESET) $(TEXT_MOD_5)deleted.$(RESET)"

#*****************************************************************************#
#                               Checking rules                                #
#*****************************************************************************#

os:
	@echo "\n$(TEXT_MOD_1)LET'S BUILD !$(RESET)"
	@echo "\n> $(TEXT_MOD_5)Checking the OS...$(RESET)"
	@echo "> $(TEXT_MOD_5)OS is $(OS) !$(RESET)"

#*****************************************************************************#
#                               Messages rules                                #
#*****************************************************************************#

re_mess:
	@echo "\n$(TEXT_MOD_1)Rebuilding program... $(RESET)\n"

begin_compil:
	@echo "> $(TEXT_MOD_5)Starting compilation... $(RESET)"

end_compil:
	@echo "\n$(TEXT_MOD_1)Executable$(RESET) $(TEXT_MOD_2)\
	so_long$(RESET) $(TEXT_MOD_1)successfully created !$(RESET)\n"

#*****************************************************************************#
#                             Compilation rules                               #
#*****************************************************************************#

$(NAME): $(ALL_OBJS_PATH) $(OBJS) $(INCS) $(LIBFT) Makefile
	@$(CC) $(OBJS) $(LIBFT) $(MLX_LINUX_FLAGS) -o $@
	@echo "> $(TEXT_MOD_5)Compilation succeeded !$(RESET)"

$(ALL_OBJS_PATH):
	@mkdir $@

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c $(INCS) $(LIBFT) Makefile
	@printf %b "  $(TEXT_MOD_3)Compiling$(RESET) $(TEXT_MOD_4)$<...$(RESET)"
	@$(CC) -c $(MANDATORY_FLAGS) $< -o $@
	@printf "\r"
	@printf "                                                                                     \r"

-include $(OBJS:.o=.d)

#*****************************************************************************#
#                                Funny part                                   #
#*****************************************************************************#

# <The thing you want to make>: <the stuff you need to make it>
# 	<The steps to make it>

me:
	@true
a:
	@true
sandwich:
	@if [ `id -u` != 0 ]; then echo "What? Make it yourself."; else echo "Ok..."; fi
