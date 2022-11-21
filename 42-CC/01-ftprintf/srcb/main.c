/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:27:45 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/21 22:27:45 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	main(void)
{
	int i = 12;
	printf("%d \n", printf(" %+d \n", i));
	ft_printf("%d \n", ft_printf(" %+d \n", i));	
	return (0);
}