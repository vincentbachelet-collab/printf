/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:47:59 by vbachele          #+#    #+#             */
/*   Updated: 2021/06/20 17:28:36y vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf(const char *format, ...)
{
	t_print tab;
	va_start(tab.args, format); 
	int position;
	int i;
	ft_remise_a_zero_flags(&tab);
	tab.ret = 0;
	
	i = 0;
	position = 0;
	while (format[position])
	{
		if (format[position] != '%')
		{
			ft_putchar(format[position]);
			tab.ret++;
		}
		else if (format[position] == '%')
		{
			i = check_for_flags(&tab, format, position + 1);
			//printf("\nposition 1 : %c\n", format[position]);
			position = position + i; 
			//printf("\nposition 2 : %c\n", format[position]);
			position++;
			//printf("\nposition 3 : %c\n", format[position]);
			ft_remise_a_zero_flags(&tab);
		}
		position++;
	}
	va_end(tab.args);
	return(tab.ret);
}