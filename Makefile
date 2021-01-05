# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliens <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 16:44:51 by aliens            #+#    #+#              #
#    Updated: 2021/01/05 12:27:51 by aliens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE	= 	$(shell tput -Txterm setaf 5)
RED		= 	$(shell tput -Txterm setaf 1)
GREEN	= 	$(shell tput -Txterm setaf 2)
WHITE	= 	$(shell tput -Txterm setaf 7)
RESET	= 	$(shell tput -Txterm sgr0)

SRCS	=	ft_convert_d_i.c\
			ft_convert_s.c\
			ft_printf.c\
			ft_convert.c\
			ft_convert_lowerx.c\
			ft_convert_u.c ft_convert_c.c\
			ft_convert_p.c\
			ft_convert_upperX.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

LIBFT	=	./libft

$(NAME):	$(OBJS)
			@make full -C $(LIBFT)
			@cp libft/libft.a ./$(NAME)
			@ar -rcs $(NAME) $(OBJS)
			@echo "$(GREEN)libftprintf.a created..$(RESET)"

.c.o:
			@$(CC) $(CFLAGS) -c -I./ $< -o $(<:.c=.o)
			@echo "$(PURPLE)ft.c -> $< -> ft.o$(RESET)"

all:		$(NAME)

clean:
			@$(RM) $(OBJS)
			@make clean -C $(LIBFT)
			@echo "$(RED)ft_printf objects erased$(RESET)"

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C $(LIBFT)
			@echo "$(RED)libftprintf.a erased$(RESET)"

re:			fclean all
			@echo "$(GREEN)Restart OK!$(RESET)"

.PHONY:		all clean fclean re
