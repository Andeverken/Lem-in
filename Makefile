# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfernand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/16 15:52:11 by rfernand          #+#    #+#              #
#    Updated: 2016/06/10 22:11:47 by rfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

NAME = lem_in

SRC_NAME = main.c \
		   check.c \
		   get_anthill.c \
		   get_next_line.c \
		   list_anthill.c \
		   second_check.c \
		   get_pipe.c \
		   resolve.c \
		   print_path.c \
		   find_path.c \

CC = clang
CFLAGS = -Werror -Wall -Wextra

LDFLAGS = -Llibft
LDLIBS = -lft

OBJ_PATH = obj
SRC_PATH = SRC
OBJ_SRC_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ_SRC = $(addprefix $(OBJ_PATH)/,$(OBJ_SRC_NAME))

all: $(NAME)

$(NAME): $(OBJ_SRC)
	make -C libft/
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		 $(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C libft
	rm -fv $(OBJ_SRC)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft
	rm -fv $(NAME)

re: fclean all
