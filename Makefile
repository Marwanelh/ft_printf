# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/24 18:47:54 by mael-hou          #+#    #+#              #
#    Updated: 2025/09/24 20:00:56 by mael-hou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

GREEN		:= $(shell tput setaf 2)
RED			:= $(shell tput setaf 1)
YELLOW		:= $(shell tput setaf 3)
RESET		:= $(shell tput sgr0)

SRCS		= 	ft_printf.c \
				ft_printf_parser.c \
				ft_printf_dispatch.c \
				ft_printf_utils.c \
				ft_print_char_str.c \
				ft_print_int.c \
				ft_print_unsigned.c \
				ft_print_hex_ptr.c \
				ft_print_hex_utils.c \
				main.c

OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			@cp $(LIBFT) $(NAME)
			@ar rcs $(NAME) $(OBJS)
			@printf "%b%s created successfully.%b\n" "$(GREEN)" "$(NAME)" "$(RESET)"

$(LIBFT):
			@printf "%bCompiling libft...%b\n" "$(YELLOW)" "$(RESET)"
			@make -C $(LIBFT_DIR) --silent

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -f $(OBJS)
			@make -C $(LIBFT_DIR) clean --silent
			@printf "%bft_printf object files removed.%b\n" "$(RED)" "$(RESET)"

fclean:		clean
			@rm -f $(NAME)
			@make -C $(LIBFT_DIR) fclean --silent
			@printf "%b%s removed.%b\n" "$(RED)" "$(NAME)" "$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re bonus