# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliens <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 16:44:51 by aliens            #+#    #+#              #
#    Updated: 2020/12/07 18:43:59 by aliens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE	= 	$(shell tput -Txterm setaf 5)
RED		= 	$(shell tput -Txterm setaf 1)
GREEN	= 	$(shell tput -Txterm setaf 2)
WHITE	= 	$(shell tput -Txterm setaf 7)
RESET	= 	$(shell tput -Txterm sgr0)

SRCS	=	$(shell ls srcs/ | grep -E ".+\.c")

OBJS	=	$(addprefix srcs/, $(SRCS:.c=.o))

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

LIBFT	=	./libft

$(NAME):	$(OBJS)
			@make full -C $(LIBFT)
			@cp libft/libft.a ./$(NAME)
			@ar -rcs $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "$(GREEN)libftprintf.a created..$(RESET)"

.c.o:
			@$(CC) $(CFLAGS) -c -I./ $< -o $(<:.c=.o)
			@echo "$(PURPLE)ft.c -> $< -> ft.o$(RESET)"

all:		$(NAME)

clean:
			@$(RM) $(OBJS)
			@make clean -C $(LIBFT)
			@echo "$(RED)Objects are clean..$(RESET)"

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C $(LIBFT)
			@echo "$(RED)libftprintf.a is clean..$(RESET)"

re:			fclean all
			@echo "$(GREEN)Restart OK!$(RESET)"

.PHONY:		all clean fclean re
