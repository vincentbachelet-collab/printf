/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Utils_Gestion_Decimal1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:23:17 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/07 10:02:43 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	gestion_Zero_Dot_Decimal(t_print *tab, long long i)
{
	int	size;

	size = ft_nbrlen(i);
	if (i == 0)
		size = 1;
	if (i < 0)
		tab->width--;
	if (((tab->width > 0 && size < tab->precision) && tab->precision != 0)
		|| (tab->width > tab-> precision && tab->precision != 0))
		tab->length = tab->width - tab->precision;
	else
		tab->length = tab->width - size + 1;
	ft_Calcul_Espace(tab);
	if (i < 0)
	{
		ft_putchar('-');
		tab->ret++;
		size--;
		i = i * -1;
	}	
	gestion_Zero_Zero_Dot_Decimal(tab, i, size);
	if (i == 0 && tab->precision == 0)
		return ;
	if ((tab->precision >= 0) || (tab->width >= 0))
		ft_putnbr_ll(i, tab);
}

void	gestion_Zero_Decimal(t_print *tab, long long i)
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
	tab->length = tab->width - size;
	ft_Calcul_Zero(tab);
	ft_putnbr_ll(i, tab);
}

void	gestion_Dash_Decimal(t_print *tab, long long i)
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

void	gestion_Dash_Dot_Decimal(t_print *tab, long long i)
{	
	int	size;
	int	j;

	j = i;
	size = ft_nbrlen(i);
	if (i == 0)
		size = 1;
	if (i < 0)
	{
		ft_putchar('-');
		tab->ret++;
		i = i * -1;
		size--;
	}
	gestion_Affichage_Dash_Dot_Decimal(tab, i, size, j);
}

void	Gestion_decimal_integers(t_print *tab)
{
	long long	i;

	i = va_arg(tab->args, int);
	if ((tab->dot == 1 && tab->zero == 1))
		gestion_Zero_Dot_Decimal(tab, i);
	else if (tab->dot == 1 && tab->dash == 1)
		gestion_Dash_Dot_Decimal(tab, i);
	else if (tab->dot == 1)
		gestion_Dot_Decimal(tab, i);
	else if (tab->dash == 1)
		gestion_Dash_Decimal(tab, i);
	else if (tab->zero == 1)
		gestion_Zero_Decimal(tab, i);
	else
		gestion_Sansflag(tab, i);
}	
