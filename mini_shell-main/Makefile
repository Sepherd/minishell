# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arecce <arecce@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 16:12:55 by ohassyao          #+#    #+#              #
#    Updated: 2023/01/17 19:15:30 by arecce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

C_LGRN = \033[92m
C_LMGN = \033[95m
C_END = \033[0m

SRC =   src/main.c src/error.c src/utils/utils.c \
		src/utils/init.c src/built-in/create.c \
		src/built-in/echo.c src/built-in/utils.c \
		src/utils/input.c src/utils/input_utils.c

OBJ	=  $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -I /Users/$(USER)/.brew/opt/readline/include

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	gcc $(OBJ) $(FLAGS) -o $(NAME) -L libft -lft -lreadline
	@echo "$(C_LGRN)➜ [$(NAME)] Program has been compiled successfully !$(C_END)"

clean:
	@rm -f $(OBJ)
	@echo "$(C_LMGN)➜ [$(NAME)] Objects have been cleaned successfully !$(C_END)"

fclean:
	@make -C ./libft fclean
	@rm -f $(NAME) $(OBJ)
	@echo "$(C_LMGN)➜ [$(NAME)] Objects has been deleted successfully !$(C_END)"

re: fclean $(NAME)

run: all

.PHONY: all clean fclean re reb
