/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Utils_Gestion_Decimal2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:40:00 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/07 10:43:01 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	gestion_Intergerszero(t_print *tab, int size)
{
	if (tab->precision >= size)
	{
		tab->length = tab->width - tab->precision;
		ft_Calcul_Espace(tab);
	}
	else
	{
		tab->length = tab->width;
		ft_Calcul_Espace(tab);
	}
}

void	gestion_Sansflag(t_print *tab, long long i)
{
	int	size;

	size = ft_nbrlen(i);
	if (i == 0)
		size = 1;
	tab->length = tab->width - size;
	ft_Calcul_Espace(tab);
	if (i < 0)
	{
		ft_putchar('-');
		tab->ret++;
		size --;
		i = i * -1;
	}	
	ft_putnbr_ll(i, tab);
}

void	gestion_Dot_Decimal(t_print *tab, long long i)
{
	int	size;
	int	j;

	j = i;
	size = ft_nbrlen(i);
	gestion_Espace_Dot_Decimal(tab, i, size, j);
	if (i < 0)
	{
		ft_putchar('-');
		tab->ret++;
		size--;
		i = i * -1;
	}	
	if (i == 0 && tab->dot == 1)
		tab->length = tab->precision;
	else if (tab->precision > 0)
		tab->length = tab->precision - size;
	ft_Calcul_Zero(tab);
	if (!(i == 0 && tab->dot == 1))
		ft_putnbr_ll(i, tab);
}

void	gestion_Affichage_Dash_Dot_Decimal(t_print *tab, long long i
											, int size, int j)
{
	if (i == 0 && tab->dot == 1)
		tab->length = tab->precision;
	else if (tab->precision > 0)
		tab->length = tab->precision - size;
	ft_Calcul_Zero(tab);
	if (!(i == 0 && tab->dot == 1))
		ft_putnbr_ll(i, tab);
	if (i == 0 && tab->dot == 1)
		gestion_Intergerszero(tab, size);
	else if (tab->width > tab->precision && j < 0 && tab->precision != 0)
	{
		if (size > tab->precision)
			tab->length = tab->width - size - tab->precision + 1;
		else
			tab->length = tab->width - tab->precision - 1;
	}
	else if (tab->width > 0 && size < tab->precision)
		tab->length = tab->width - tab->precision;
	else if (j < 0)
		tab->length = tab->width - size - 1;
	else
		tab->length = tab->width - size;
	ft_Calcul_Espace(tab);
}

void	gestion_Espace_Dot_Decimal(t_print *tab, long long i, int size, int j)
{
	if (i == 0)
		gestion_Intergerszero(tab, size);
	else if (tab->width > tab->precision)
		gestion_Espace_Dot_Decimal2(tab, i, size);
	else if ((tab->width > tab->precision && j < 0 && tab->precision != 0)
		|| (tab->width > 0 && size < tab->precision))
	{
		tab->length = tab->width - tab->precision - 1;
		ft_Calcul_Espace(tab);
	}
	else
	{
		tab->length = tab->width - size - 1;
		ft_Calcul_Espace(tab);
	}
}
