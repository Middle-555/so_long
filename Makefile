# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 18:19:59 by kpourcel          #+#    #+#              #
#    Updated: 2024/03/05 18:51:03 by kpourcel         ###   ########.fr        #
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

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx$(UNAME).a
ifeq ($(shell uname), Linux)
    MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
    MLX_FLAGS = -framework OpenGL -framework AppKit
endif

# Include libraries
LIBRARIES_DIR = ./libraries
LIBRARIES_MAKEFILE = $(LIBRARIES_DIR)/Makefile

# Source files
SRCS := src/main.c \
        src/so_long.c \
        src/check_error.c \
        src/map_error.c \
        src/so_long_utils.c \
        src/move.c \
        src/input.c \
        src/sprites_initialisation.c

# Object files
OBJS := $(SRCS:.c=.o)

all:  $(MLX_LIB) $(NAME) libraries

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) -o $(OBJS)  $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(LIBRARIES_MAKEFILE):
	make -C $(LIBRARIES_DIR)

libraries: $(LIBRARIES_MAKEFILE)

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	make clean -C $(LIBRARIES_DIR)
	make clean -C $(MLX_DIR)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBRARIES_DIR)
	rm -f $(NAME)

re: fclean all
