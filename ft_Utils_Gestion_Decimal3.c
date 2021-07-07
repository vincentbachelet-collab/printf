/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Utils_Gestion_Decimal3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:05:18 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/07 10:43:40 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	gestion_i_Egale_Zero(t_print *tab, long long i, int size, int j)
{
	gestion_Espace_Dot_Decimal(tab, i, size, j);
}

void	gestion_Zero_Zero_Dot_Decimal(t_print *tab, long long i, int size)
{
	if (tab->precision > 0 && tab->width > tab->precision && i < 0)
	{	
		if (size > tab->precision)
			tab->length = tab->precision - size - tab->width;
		else
			tab->length = tab->precision - size;
		ft_Calcul_Zero(tab);
	}
	else if (tab->precision < tab->width)
	{	
		if (size + 1 > tab->precision && tab->precision == 0)
			tab->length = tab->precision - size - tab->width - 1;
		else
			tab->length = tab->precision - size;
		ft_Calcul_Zero(tab);
	}
	else
	{
		if (size + 1 > tab->precision)
			tab->length = tab->precision - size - tab->width;
		else
			tab->length = tab->precision - size;
		ft_Calcul_Zero(tab);
	}
}

void	gestion_Espace_Dot_Decimal2(t_print *tab, long long i, int size)
{
	if (i < 0 && tab->precision != 0)
		tab->length = tab->width - tab->precision - 1;
	else if (i > 0 && tab->precision != 0 && tab->width < size)
		tab->length = tab->width - size;
	else if (i > 0 && tab->width - tab->precision > size
		&& tab->precision != 0)
		tab->length = tab->width - tab->precision;
	else
		tab->length = tab->width - size;
	ft_Calcul_Espace(tab);
}
