/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestionflag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:38:41 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/04 14:28:20 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void ft_remise_a_zero_flags(t_print *tab)
{
	tab->width = 0; 
	tab->zero = 0; 
	tab->dash = 0;
	tab->precision = 0; 
	tab->dot = 0; 
	tab->length = 0; 
}

int		check_for_flags(t_print *tab, const char *format, int position)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (format[position] == '0' || format[position] == '-')
	{
		if (format[position] == '-')
		{
			position++;
			tab->dash = 1;	
			j++;
			if (tab->zero == 1)
				tab->zero = 0;
		}
		if (format[position] == '0')
		{
			position++;
			tab->zero = 1;
			j++;
			if (tab->dash == 1)
				tab->zero = 0;
		}
	}
	if (format[position] == '*')
	{
		position++;
		j++;
		tab->width = (int)va_arg(tab->args, int);
		if (tab->width < 0)
		{
			tab->width = tab->width * - 1;
			tab->dash = 1;
			tab->zero = 0;
		}
	}
	if (format[position] >= '0' && format[position] <= '9')
	{
		tab->width = ft_atoi(&format[position]);
		l = ft_nbrlen(tab->width);
		position = position + l;
	}
	if (format[position] == '.')
	{
		position++;
		tab->dot = 1;
		j++;
	}
	if (format[position] >= '0' && format[position] <= '9')
	{
		
		tab->precision = ft_atoi(&format[position]);
		k = ft_nbrlen(tab->precision);
		position = position + k;
	}
	if (format[position] == '*')
	{
		position++;
		j++;
		tab->precision = (int)va_arg(tab->args, int);
		if (tab->precision < 0)
		{
			tab->precision = tab->precision * -1;
			tab->dash = 1;
			tab->zero = 0;;
		}
	}
	check_for_conversions(tab, format, position);
	i = l + j + k;
	return (i);
}