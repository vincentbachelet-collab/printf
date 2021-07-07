/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Utils_Gestion_Unsigned2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 13:39:11 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/05 18:40:33 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	gestion_Dash_Unsigned(t_print *tab, unsigned int i)
{
	int	size;

	size = ft_nbrlen(i);
	if (i == 0)
		size = 1;
	if (i < 0)
	{
		ft_putchar('-');
		tab->ret++;
		i = i * -1;
	}
	ft_putnbr_ll(i, tab);
	tab->length = tab->width - size;
	ft_Calcul_Espace(tab);
}

void	gestion_Zero_Dot_Unsigned(t_print *tab, unsigned int i)
{
	int	size;

	size = ft_nbrlen(i);
	if (i == 0)
		size = 1;
	if (tab->width <= size)
		tab->length = 0;
	else if ((tab->width > size && tab->precision == 0)
		|| (tab->precision < tab->width
			&& tab->width > size && tab->precision > 0))
		gestion_Zero_Dot_Unsigned2(tab, i, size);
	else
		tab->length = tab->width - tab->precision;
	ft_Calcul_Espace(tab);
	gestion_Zero_Zero_Dot_Decimal(tab, i, size);
	if (i == 0 && tab->precision == 0)
		return ;
	if ((tab->precision > 0) || (tab->width > 0))
		ft_putnbr_ll(i, tab);
}

void	gestion_Sans_Flag_Unsigned(t_print *tab, unsigned int i)
{
	int	size;

	size = ft_nbrlen(i);
	if (i == 0)
		size = 1;
	tab->length = tab->width - size;
	ft_Calcul_Espace(tab);
	ft_putnbr_ll(i, tab);
}

void	gestion_Zero_Dot_Unsigned2(t_print *tab, unsigned int i, int size)
{
	if (i == 0)
		tab->length = tab->width - tab->precision;
	else if (tab->width > tab->precision
		&& tab->width - tab->precision > size && tab->precision != 0)
		tab->length = tab->width - tab->precision;
	else if ((tab->width - tab->precision) <= size
		|| (tab->width - tab->precision > size))
		tab->length = tab->width - size;
}
