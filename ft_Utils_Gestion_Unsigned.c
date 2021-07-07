/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Utils_Gestion_Unsigned.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:57:14 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/06 16:15:25 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	gestion_Dot_Unsigned(t_print *tab, unsigned int i)
{
	int				size;
	unsigned int	j;

	j = i;
	size = ft_nbrlen(i);
	gestion_Espace_Dot_Decimal(tab, i, size, j);
	if (tab->precision != 0 && tab->precision > tab->width)
		tab->length = tab->precision - size;
	else if (i == 0 && tab->precision != 0 )
	{
		tab->length = tab->width - size;
	}
	ft_Calcul_Zero(tab);
	if (i == 0 && tab->precision == 0)
		return ;
	else if((tab->precision >= 0) || (tab->width > 0))
		ft_putnbr_ll(i, tab);
}

void	gestion_Dot_Dash_Unsigned(t_print *tab, unsigned int i)
{
	int	size;
	int	j;

	j = i;
	size = ft_nbrlen(i);
	if (i == 0)
		size = 1;
	gestion_Affichage_Dash_Dot_Unsigned(tab, i, size, j);
}

void	gestion_Affichage_Dash_Dot_Unsigned(t_print *tab, unsigned int i,
											int size, unsigned int j)
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

void	gestion_Zero_Unsigned(t_print *tab, unsigned int i)
{
	int	size;

	size = ft_nbrlen(i);
	if (i == 0)
		size = 1;
	tab->length = tab->width - size;
	ft_Calcul_Zero(tab);
	ft_putnbr_ll(i, tab);
}

void	gestion_Unsigned(t_print *tab)
{
	int	i;

	i = (unsigned int)va_arg(tab->args, unsigned int);
	if (tab->dot == 1 && tab->zero == 1)
		gestion_Zero_Dot_Unsigned(tab, i);
	else if (tab->dash == 1 && tab->dot == 1)
		gestion_Dot_Dash_Unsigned(tab, i);
	else if (tab->dot == 1)
		gestion_Dot_Unsigned(tab, i);
	else if (tab->dash == 1)
		gestion_Dash_Unsigned(tab, i);
	else if (tab->zero == 1)
		gestion_Zero_Unsigned(tab, i);
	else
		gestion_Sans_Flag_Unsigned(tab, i);
}
