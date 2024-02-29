# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 17:45:14 by kpourcel          #+#    #+#              #
#    Updated: 2024/02/19 17:45:17 by kpourcel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de ton exécutable
NAME = libraries.a

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Ajoute tous tes fichiers source de libft
SRC_LIBFT = libft/src/ft_atoi.c libft/src/ft_bzero.c libft/src/ft_calloc.c libft/src/ft_isalnum.c libft/src/ft_isalpha.c \
            libft/src/ft_isascii.c libft/src/ft_isprint.c libft/src/ft_itoa.c libft/src/ft_lstadd_back.c \
            libft/src/ft_lstadd_front.c libft/src/ft_lstclear.c libft/src/ft_lstdelone.c libft/src/ft_lstiter.c \
            libft/src/ft_lstlast.c libft/src/ft_lstmap.c libft/src/ft_lstnew.c libft/src/ft_lstsize.c libft/src/ft_memchr.c \
            libft/src/ft_memcmp.c libft/src/ft_memcpy.c libft/src/ft_memmove.c libft/src/ft_memset.c libft/src/ft_putchar_fd.c \
            libft/src/ft_putendl_fd.c libft/src/ft_putnbr_fd.c libft/src/ft_putstr_fd.c libft/src/ft_split.c libft/src/ft_strchr.c \
            libft/src/ft_strdup.c libft/src/ft_striteri.c libft/src/ft_strjoin.c libft/src/ft_strlcat.c libft/src/ft_strlcpy.c \
            libft/src/ft_strlen.c libft/src/ft_strmapi.c libft/src/ft_strncmp.c libft/src/ft_strnstr.c libft/src/ft_strrchr.c \
            libft/src/ft_strtrim.c libft/src/ft_substr.c libft/src/ft_tolower.c libft/src/ft_toupper.c 

# Ajoute tous tes fichiers source de ft_printf
SRC_PRINTF = ft_printf/src/ft_printf.c ft_printf/src/ft_printadresse.c ft_printf/src/ft_printhexa_low.c \
                ft_printf/src/ft_printhexa_upper.c ft_printf/src/ft_printunsigned_decimal.c ft_printf/src/ft_putchar.c \
                ft_printf/src/ft_putnbr.c ft_printf/src/ft_putstr.c   

# Ajoute tous tes fichiers source de get_next_line
SRC_GET_NEXT_LINE = get_next_line/src/get_next_line.c get_next_line/src/get_next_line_utils.c  

# Liste des fichiers objets
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)
OBJ_GET_NEXT_LINE = $(SRC_GET_NEXT_LINE:.c=.o)

# Règles de compilation
all: $(NAME)

$(NAME): $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GET_NEXT_LINE)
	ar rcs $(NAME) $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GET_NEXT_LINE)

# Règles de compilation des sources pour libft
libft/%.o: libft/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règles de compilation des sources pour ft_printf
ft_printf/%.o: ft_printf/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règles de compilation des sources pour get_next_line
get_next_line/%.o: get_next_line/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GET_NEXT_LINE)

# Nettoyage de tout, y compris l'exécutable
fclean: clean
	rm -f $(NAME)

# Règle par défaut, recompile tout
re: fclean all

.PHONY: all clean fclean re
