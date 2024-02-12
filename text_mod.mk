# SET TEXT MODIFICATIONS IN MAKE

# Add 'include text_mod.mk' at the start of your Makefile to use this.
# Make sure it is in the same directory as your Makefile.

# This code signal the start of the modification
ADD_TEXT_MOD := \033[

# In case where you might want to write only a part of your text as under the effect
# you can undo it by adding this variable before the effect previously applied
EFFECT_UNDO := 2

# Those are the effects (blink seemingly doesn't work, at least on my computer)
NORMAL := 0;
BOLD := 1;
FADE := 2;
ITALIC := 3;
UNDERLINE := 4;
BLINK := 5;
INVERT := 7;
# After the effect you have to put a ';' so i integrated it to the variable

# You now have to specify wether you want to apply to the text or the text's background
BACKGROUND := 4
FONT := 3

# Those are the colors codes
BLACK := 0
RED := 1
GREEN := 2
YELLOW := 3
BLUE := 4
MAGENTA := 5
CYAN := 6
WHITE := 7

# the 'm' char is mandatory at the end of a text mod
END_MOD := m

# After that, you can write your text normally

# This rest the effects of your text to normal,
# it could be wrote as $(ADD_TEXT_MOD)$(NORMAL)$(ENDMOD)
# but it's clearer this way
RESET := \033[0m


# USE ILLUSTRATION :

#*****************************************************************************#
#																			  #
# TEXT_MOD = $(ADD_TEXT_MOD)$(BOLD)$(FONT)$(CYAN)$(END_MOD)					  #
#																			  #
# test:																		  #
# 	@echo "$(TEXT_MOD)Library ready to use !$(RESET)"						  #
#																			  #
#																			  #
#*****************************************************************************#

# Note : The example above is an equivalent to :

#		echo "\033[1;36mLibrary ready to use !\033[0m"


# Sources :	https://misc.flogisoft.com/bash/tip_colors_and_formatting
