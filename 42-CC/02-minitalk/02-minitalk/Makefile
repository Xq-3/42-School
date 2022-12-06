# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 12:11:48 by pfaria-d          #+#    #+#              #
#    Updated: 2022/12/06 13:39:41 by pfaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCA = server.c client.c extra/ft_printf.c extra/ft_printf_utils1.c extra/ft_atoi.c extra/ft_printf_nbrb.c
SRCC = client.c extra/ft_printf.c extra/ft_printf_utils1.c extra/ft_atoi.c extra/ft_printf_nbrb.c
SRCS = server.c extra/ft_printf.c extra/ft_printf_utils1.c extra/ft_printf_nbrb.c
SRCBONUS = 

OBJSA = $(SRCA:.c=.o)
OBJSC = $(SRCC:.c=.o)
OBJSS = $(SRCS:.c=.o)

OBJSBONUS = $(SRCBONUS:.c=.o)

GCC = gcc -Wall -Werror -Wextra

RM  = rm -f

HFILE = Minitalk.h

ifdef MAKEBONUS
    OBJS = $(OBJSBONUS)
endif

all: $(OBJSA)
			$(GCC) -o client $(OBJSC)
			$(GCC) -o server $(OBJSS)

.c.o:
	$(GCC) -I $(HFILE) -c $< -o $(<:.c=.o)

bonus:
			@make MAKEBONUS=1 all

clean:
			$(RM) $(OBJSA) $(OBJSBONUS)

fclean:		clean
			$(RM) server client

re:			fclean $(NAME) 
			
.PHONY: all clean fclean re bonus

