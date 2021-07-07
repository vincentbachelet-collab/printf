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

int	ft_printf(const char *format, ...)
{
	t_print	tab;
	int		position;
	int		i;

	va_start(tab.args, format);
	ft_remise_a_zero_flags(&tab);
	tab.ret = 0;
	i = 0;
	position = 0;
	while (format[position])
	{
		if (format[position] != '%')
			ft_printf2(format, position, &tab);
		else if (format[position] == '%')
		{
			i = check_for_flags(&tab, format, position + 1);
			position = position + i;
			position++;
			ft_remise_a_zero_flags(&tab);
		}
		position++;
	}
	va_end(tab.args);
	return (tab.ret);
}

void	ft_printf2(const char *format, int position, t_print *tab)
{
	ft_putchar(format[position]);
	tab->ret++;
}
