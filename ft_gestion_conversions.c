/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_conversions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:33:36 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/05 14:09:24 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void check_for_conversions(t_print *tab, const char *format, int position)
{
	if (format[position] == 'c')
		gestion_caracteres(tab);
	else if (format[position] == 's')
		gestion_String(tab);
	else if (format[position] == 'd' || format[position] == 'i')
		{
			Gestion_decimal_integers(tab);
		}
	else if (format[position] == 'u')
		gestion_Unsigned(tab);
	else if (format[position] == 'x' || format[position] == 'X')
	{
		if (format[position] == 'x')
			gestion_Hexadecimal_x_X(tab, "0123456789abcdef");
		else if ( format[position] == 'X')
			gestion_Hexadecimal_x_X(tab, "0123456789ABCDEF");
	}
	else if (format[position] == '%')
		gestion_pourcentage(tab);
	else if (format[position] == 'p')
			ft_putnbr_basehexap("0123456789abcdef", tab);
}