# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliens <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 16:44:51 by aliens            #+#    #+#              #
#    Updated: 2021/01/08 16:50:55 by aliens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE	= 	$(shell tput -Txterm setaf 5)
RED		= 	$(shell tput -Txterm setaf 1)
GREEN	= 	$(shell tput -Txterm setaf 2)
WHITE	= 	$(shell tput -Txterm setaf 7)
RESET	= 	$(shell tput -Txterm sgr0)

SRCS	=	ft_printf.c\
			ft_get.c\
			ft_type_c.c\
			ft_type_s.c\
			ft_type_p.c\
			ft_type_u.c\
			ft_type_d_i.c\
			ft_type_lowerx.c\
			ft_type_upperx.c

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
			@echo "$(GREEN)libftprintf.a created$(RESET)"

.c.o:
			@$(CC) $(CFLAGS) -c -I./ $< -o $(<:.c=.o)
			@echo "$(PURPLE)ft.c -> $< -> ft.o$(RESET)"

all:		$(NAME)

allup:		$(NAME) clean

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
