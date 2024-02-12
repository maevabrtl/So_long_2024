!bin/bash

find ./ -name "so_long" > .find
echo ".//so_long" > .check_comp
echo $? > .find
rm .check_comp

# check_exist:
# 	@./ .make_tools.sh
# 	if [ "diff .check_comp .find" == "0" ]; then \
# 		make --no-print-directory check_for_new && echo "yolo"; \
# 	else \
# 		echo "yolo esle"; \
# 	fi

# check_for_new:
# 	if [ "$$(find $(SRCS) -newer "$(NAME)" -print -quit)" ]; then \
# 		make --no-print-directory build; \
# 	else \
# 		echo "Everything is up to date !"; \
# 	fi
