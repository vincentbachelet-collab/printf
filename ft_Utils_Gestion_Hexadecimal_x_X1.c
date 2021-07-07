/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Utils_Gestion_Hexadecimal_x_X1.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:46:52 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/07 10:58:05 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	gestion_Dot_Hexadecimal_x_X(t_print *tab, unsigned int i, char *base)
{
	int				size;
	unsigned int	j;

	j = i;
	size = calcul_longueur_x_X(i);
	gestion_Espace_Dot_Hexademal_x_X(tab, i, size);
	if (i == 0 && tab->dot == 1)
		tab->length = tab->precision - 1;
	else if (tab->precision >= tab->width)
	{
		if (i < 0)
			tab->length = tab->precision - tab->width + 2;
		else
			tab->length = tab->precision - size;
	}
	else if (tab->precision <= tab->width)
		tab->length = tab->precision - size;
	else if (tab->precision <= size)
		tab->length = 0;
	ft_Calcul_Zero(tab);
	if (i == 0 && tab->precision == 0)
		return ;
	if ((tab->precision >= 0) || (tab->width > 0))
		ft_printfputnbr_base(i, base, tab);
}

void	gestion_Affichage_Dash_Dot_Hexadecimal_x_X(t_print *tab, unsigned int i
											, int size, char *base)
{
	if (i == 0 && tab->dot == 1)
		tab->length = tab->precision - size;
	else if (tab->precision >= tab->width)
	{
		if (i < 0)
			tab->length = tab->precision - tab->width + 2;
		else
			tab->length = tab->precision - size;
	}
	else if (tab->precision <= tab->width)
		tab->length = tab->precision - size;
	else if (tab->precision <= size)
		tab->length = 0;
	ft_Calcul_Zero(tab);
	if (i == 0 && tab->precision == 0)
	{
		gestion_Espace_Dot_Hexademal_x_X(tab, i, size);
		return ;
	}
	if ((tab->precision > 0) || (tab->width > 0))
		ft_printfputnbr_base(i, base, tab);
	gestion_Espace_Dot_Hexademal_x_X(tab, i, size);
}

void	gestion_Dot_Dash_Hexadecimal_x_X(t_print *tab, unsigned int i
										, char *base)
{
	int	size;
	int	j;

	j = i;
	size = calcul_longueur_x_X(i);
	if (i == 0)
		size = 1;
	gestion_Affichage_Dash_Dot_Hexadecimal_x_X(tab, i, size, base);
}

void	gestion_Zero_Hexadecimal_x_X(t_print *tab, unsigned int i, char *base)
{
	int	size;

	size = calcul_longueur_x_X(i);
	if (i == 0)
		size = 1;
	tab->length = tab->width - size;
	ft_Calcul_Zero(tab);
	ft_printfputnbr_base(i, base, tab);
}

void	gestion_Hexadecimal_x_X(t_print *tab, char *base)
{
	int	i;

	i = (unsigned int)va_arg(tab->args, unsigned int);
	if ((tab->dash == 1 && tab->dot == 1))
		gestion_Dot_Dash_Hexadecimal_x_X(tab, i, base);
	else if (tab->dot == 1 && tab->zero == 1)
		gestion_Dot_Zero_Hexadecimal_x_X(tab, i, base);
	else if (tab->dot == 1)
		gestion_Dot_Hexadecimal_x_X(tab, i, base);
	else if (tab->zero == 1)
		gestion_Zero_Hexadecimal_x_X(tab, i, base);
	else if (tab->dash == 1)
		gestion_dash_Hexadecimal_x_X(tab, i, base);
	else
		gestion_Sansflag_Hexadecimal_x_X(tab, i, base);
}
