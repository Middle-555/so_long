# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 18:01:15 by kpourcel          #+#    #+#              #
#    Updated: 2024/03/12 16:14:48 by kpourcel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Name of the program
NAME    =    so_short

# Flags
CC		=	gcc
CFLAGS		=	-Wall -Werror -Wextra
LM		=	-lm
MFLAGS		=	-L/usr/X11R6/lib -lX11 -lXext

# Directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIB_DIR		=	libraries/
MLX_DIR		=	minilibx-linux/

# .c and .o files
SRC		=	$(wildcard $(SRC_DIR)*.c)
OBJ		=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

# .a files
LIBFT		=	$(LIB_DIR)libraries.a
MLX		=	$(MLX_DIR)libmlx.a

# The main rule
all                :	$(NAME)

# The name rule
$(NAME)            :    $(OBJ) $(LIBFT) $(MLX)
	@echo "\033[0;33mCompiling the whole project -> ⏳\033[0m"
	@$(CC) $(OBJ) $(LIBFT) $(MLX) $(MFLAGS) -o $@ -I include/
	@echo "\033[0;32mProject successfuly compiled -> ✅\033[0m\n"

# The libft rule
$(LIBFT)        :    $(LIB_DIR)
	@echo "\033[0;33mCompiling my libft -> ⏳\033[0m"
	@make all -sC $<
	@echo "\033[0;32mLibft successfuly compiled -> ✅\033[0m\n"

# The mlx rule
$(MLX)            :    $(MLX_DIR)
	@echo "\033[0;33mCompiling minilibx -> ⏳\033[0m"
	@make all -sC $< > /dev/null 2>&1
	@echo "\033[0;32mMinilibx successfuly compiled -> ✅\033[0m\n"

# Compile .c to .o files
$(OBJ_DIR)%.o    :    $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "\033[0;33mCompiling project src -> ⏳\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;32mSrc's project successfuly compiled -> ✅\033[0m\n"

# Create the obj directory
$(OBJ_DIR)        :
	@mkdir -p $@

# Clean, fclean and re rules
clean            :
	@echo "\033[0;31mCleaning obj files -> 🗑️\033[0m"
	@rm -rf $(OBJ_DIR)
	@make clean -sC $(LIB_DIR)
	@make clean -sC $(MLX_DIR) > /dev/null 2>&1
	@echo "\033[0;32mDone -> ✅\033[0m\n"

fclean            :    clean
	@echo "\033[0;31mCleaning program -> 🗑️\033[0m"
	@rm -rf $(NAME)
	@make fclean -sC $(LIB_DIR)
	@echo "\033[0;32mDone -> ✅\033[0m\n"
re                :    fclean all