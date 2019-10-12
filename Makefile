# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 12:22:01 by dnichol           #+#    #+#              #
#    Updated: 2019/10/09 18:29:56 by lcaesar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAG = -Wall -Wextra -Werror
FLAGINC = -I
PATH_LIB = ./libft/
HEARDS = fillit_src/fillit.h 
CFILE = fillit_src/main.c fillit_src/read_file.c fillit_src/check_error.c fillit_src/chech_tetr.c fillit_src/permutation.c fillit_src/board.c fillit_src/slate_b.c fillit_src/god_bless_norminette.c fillit_src/memory_management.c fillit_src/point.c
OBG = fillit_src/main.o fillit_src/read_file.o fillit_src/check_error.o fillit_src/check_tetr.o fillit_src/permutation.o fillit_src/board.o fillit_src/slate_b.o fillit_src/god_bless_norminette.o fillit_src/memory_management.o fillit_src/point.o

all: $(NAME)
$(NAME): $(OBG)
	make -C $(PATH_LIB)
	$(CC) -I $(HEARDS) -o $(NAME) $(OBG) -L $(PATH_LIB) -lft
%.o: %.c $(HEARDS)
	$(CC) $(FLAGINC) $(FLAG) -c $< -o $@
clean:
	make -C $(PATH_LIB) clean
	rm -f $(OBG)
fclean: clean
	make -C $(PATH_LIB) fclean
	rm -f $(NAME)
debug: $(OBG)
	make -C $(PATH_LIB)
	$(CC) -g -I $(HEARDS) -o $(NAME) $(OBG) -L $(PATH_LIB) -lft
re: fclean all
