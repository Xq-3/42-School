/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:02:25 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/21 22:31:00 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

//ft_printf_utils1.c
int		ft_strlen(const char *str);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_printfarg(char c, va_list aptr);
int		ft_printfnbr(const char *str, va_list aptr);

//ft_printf_nbrb.c
int		ft_nbrb(long nbr, int fd, char *base);
int		ft_nbrp(unsigned long long int *nbr, int fd, char *base);
int		ft_unbrb(unsigned int nbr, int fd, char *base);
int		ft_nbrbp(long nbr, int fd, char *base);

//ft_printf
int		ft_printf(const	char *str, ...);

#endif