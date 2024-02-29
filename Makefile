# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 18:02:42 by kpourcel          #+#    #+#              #
#    Updated: 2024/02/19 17:54:43 by kpourcel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

# Universal compilation 

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif
 
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit -o $(NAME)
endif
 
# Include libraries
LIBRARIES_DIR = ./libraries
LIBRARIES_MAKEFILE = $(LIBRARIES_DIR)/Makefile

# [...]
 
all: $(MLX_LIB) $(NAME) libraries

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(LIBRARIES_MAKEFILE):
	@make -C $(LIBRARIES_DIR)

libraries: $(LIBRARIES_MAKEFILE)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	@make clean -C $(LIBRARIES_DIR)
	@make clean -C $(MLX_DIR)
	rm -rf $(OBJS)

fclean: clean
	@make fclean -C $(LIBRARIES_DIR)
	rm -f $(NAME)

re: fclean all
