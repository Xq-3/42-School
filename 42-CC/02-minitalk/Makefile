# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 12:11:48 by pfaria-d          #+#    #+#              #
#    Updated: 2022/11/25 17:52:41 by pfaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = 
SRCBONUS = 

OBJS = $(SRC:.c=.o)

OBJSBONUS = $(SRCBONUS:.c=.o)

GCC = gcc -Wall -Werror -Wextra

RM  = rm -f

HFILE = ft_printf.h

NAME = libftprintf.a

ifdef MAKEBONUS
    OBJS = $(OBJSBONUS)
endif

all: $(NAME)

.c.o:
	$(GCC) -I $(HFILE) -c $< -o $(<:.c=.o)

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

