# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 12:11:48 by pfaria-d          #+#    #+#              #
#    Updated: 2022/11/21 22:16:20 by pfaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ./src/ft_printf_nbrb.c ./src/ft_printf.c ./src/ft_printf_utils1.c
SRCBONUS = ./srcb/ft_printf_nbrb_bonus.c ./srcb/ft_printf_bonus.c ./srcb/ft_printf_utils1_bonus.c

OBJS = $(SRC:.c=.o)

OBJSBONUS = $(SRCBONUS:.c=.o)

GCC = gcc -Wall -Werror -Wextra

RM  = rm -f

NAME = libftprintf.a

ifdef MAKEBONUS
    OBJS = $(OBJSBONUS)
endif

all: $(NAME)

.c.o:
	$(GCC) -I ./ -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:
			@make MAKEBONUS=1 all

clean:
			$(RM) $(OBJS) $(OBJSBONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME) 
			
.PHONY: all clean fclean re bonus

