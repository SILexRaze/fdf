# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifonne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/05 18:03:13 by vifonne           #+#    #+#              #
#    Updated: 2019/01/30 13:46:24 by vifonne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		main.c			\
					key_hook.c		\
					error.c			\
					draw.c			\
					parser.c		\
					split.c			\
					utils.c			\
					draw_map.c		\
					display.c
SRCS_DIR	=		$(addprefix srcs/, $(SRCS))
LIBFT		=		libft/
MLX			=		mlx/
OBJ			=		$(SRCS_DIR:.c=.o)
CC			=		gcc -Wall -Wextra -Werror -g
HDR			=		-I $(LIBFT) -I . -I mlx/
NAME		=		fdf
.PHONY		=		all $(NAME) $(OBJ) clean fclean re
UNDER		=		$'\x1b[4m$'
RED			=		$'\x1b[31m$'
GREEN		=		$'\x1b[32m$'
YELLOW		=		$'\x1b[33m$'
WHITE		=		$'\x1b[37m$'
END			=		$'\x1b[0m$'

all:	$(NAME)

$(NAME): $(OBJ)
	@echo "\n$(UNDER)Compiling libft :$(END)\t\t$(YELLOW)$(CC)$(WHITE)\n"
	@/bin/echo -n "0% ["
	@make -C libft/
	@echo "] 100%"
	@echo "\n$(UNDER)Compiling mlx :$(END)\t\t$(YELLOW)$(CC)$(WHITE)\n"
	@make -C mlx/
	@echo "\n$(UNDER)Compiling $(NAME) :$(END)\t\t$(YELLOW)$(CC)$(WHITE)\n"
	$(CC) $(OBJ) mlx/libmlx.a -o $(NAME) $(HDR) -L $(LIBFT) -lft -lm -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(HDR) -c $< -o $@

clean:
	@echo "$(UNDER)Cleaning project :$(END)$(RED)"
	rm -rf $(OBJ)
	@echo "$(GREEN)[OK]$(RED)\n"
	make clean -C $(LIBFT)
	@echo "$(GREEN)[OK]$(RED)\n"
	make clean -C mlx/
	@echo "$(GREEN)[OK]$(WHITE)"

fclean:	clean
	@echo "\n$(UNDER)Full cleaning project :$(END)$(RED)"
	rm -f $(NAME)
	@echo "$(GREEN)[OK]$(RED)\n"
	make fclean -C $(LIBFT)
	@echo "$(GREEN)[OK]$(WHITE)"
	make clean -C mlx/
	@echo "$(GREEN)[OK]$(WHITE)"

re:	fclean all
