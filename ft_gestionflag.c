/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestionflag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:38:41 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/07 16:14:00 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_remise_a_zero_flags(t_print *tab)
{
	tab->width = 0;
	tab->zero = 0;
	tab->dash = 0;
	tab->precision = 0;
	tab->dot = 0;
	tab->length = 0;
}

void	gestion_width_parsing(t_print *tab)
{
	tab->width = (int)va_arg(tab->args, int);
	if (tab->width < 0)
	{
		tab->width = tab->width * -1;
		tab->dash = 1;
		tab->zero = 0;
	}
}

int		check_for_flags(t_print *tab, const char *format, int position)
{
	int	j;

	j = 0;
	while (format[position] == '0' || format[position] == '-')
	{
		if (format[position] == '-')
		{
			position++;
			j++;
			gestion_dash_parsing(tab);
		}
		if (format[position] == '0')
		{
			position++;
			j++;
			gestion_Zero_Parsing(tab);
		}
	}
	if (format[position] == '*')
	{
		position++;
		j++;
		gestion_width_parsing(tab);
	}
	j = check_for_flags2(tab, format, position, j);
	return (j);
}

void	gestion_precision_parsing(t_print *tab)
{
	tab->precision = (int)va_arg(tab->args, int);
	if (tab->precision < 0)
	{
		tab->precision = tab->precision * -1;
		tab->dash = 1;
		tab->zero = 0;
	}
}

int	check_for_flags2(t_print *tab, const char *format, int position, int j)
{
	int	l;
	int	k;
	int	i;

	i = 0;
	l = 0;
	k = 0;
	(void) j;
	if (format[position] >= '0' && format[position] <= '9')
	{
		tab->width = ft_atoi(&format[position]);
		l = ft_nbrlen(tab->width);
		position = position + l;;
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
		gestion_precision_parsing(tab);
	}
	check_for_conversions(tab, format, position);
	i = l + j + k;
	return (i);
}
