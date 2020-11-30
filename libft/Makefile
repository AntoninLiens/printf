# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliens <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 16:23:35 by aliens            #+#    #+#              #
#    Updated: 2020/11/30 17:37:49 by aliens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE		= 	$(shell tput -Txterm setaf 5)
RED			= 	$(shell tput -Txterm setaf 1)
GREEN		= 	$(shell tput -Txterm setaf 2)
WHITE		= 	$(shell tput -Txterm setaf 7)
RESET		= 	$(shell tput -Txterm sgr0)

SRCS		=	$(shell ls srcs | grep -E ".+\.c")

SRCS_BONUS	=	$(shell ls srcs_bonus | grep -E ".+\.c")

OBJS		=	$(addprefix srcs/, $(SRCS:.c=.o))

OBJS_BONUS	=	$(addprefix srcs_bonus/, $(SRCS_BONUS:.c=.o))

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "$(GREEN)libft.a created..$(RESET)"

bonus:		$(OBJS_BONUS)
			@ar -rcs $(NAME) $(OBJS_BONUS)
			@ranlib $(NAME)
			@echo "$(GREEN)bonus.o -> libft.a$(RESET)"
		
full:		$(NAME) bonus

.c.o:
			@$(CC) $(CFLAGS) -c -I./ $< -o $(<:.c=.o)
			@echo "$(PURPLE)ft.c -> $< -> ft.o$(RESET)"

all:		$(NAME)

clean:
			@$(RM) $(OBJS) $(OBJS_BONUS)
			@echo "$(RED)Objects are clean..$(RESET)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)libft.a is clean..$(RESET)"

re:			fclean all
			@echo "$(GREEN)Restart OK!$(RESET)"

.PHONY:		all clean fclean re bonus full
