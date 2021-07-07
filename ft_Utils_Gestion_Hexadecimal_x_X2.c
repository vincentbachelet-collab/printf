/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Utils_Gestion_Hexadecimal_x_X2.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:53:38 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/06 15:25:09 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void gestion_Dot_Zero_Hexadecimal_x_X(t_print *tab, unsigned int i, char *base)	
{
	int	size;

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
	if ((tab->precision > 0) || (tab->width > 0))
		ft_printfputnbr_base(i, base, tab);
}

void gestion_dash_Hexadecimal_x_X(t_print *tab, unsigned int i, char *base)
{
	int	size;

	size = calcul_longueur_x_X(i);
	if (i == 0)
		size = 1;
	ft_printfputnbr_base(i, base, tab);
	tab->length = tab->width - size;
	ft_Calcul_Espace(tab);
}

void gestion_Sansflag_Hexadecimal_x_X(t_print *tab, unsigned int i, char *base)
{
	int	size;

		size = calcul_longueur_x_X(i);
		if (i == 0)
			size = 1;
		tab->length = tab->width - size;
		ft_Calcul_Espace(tab);
		ft_printfputnbr_base(i, base, tab);
}

void	gestion_Espace_Dot_Hexademal_x_X(t_print *tab, unsigned int i, int size)
{
	if (i == 0)
		gestion_Intergerszero(tab, size);
	else if (tab->width > tab->precision)
	{
		if (i < 0 && tab->precision != 0)
			tab->length = tab->width - tab->precision - 1;
		else if (tab->width > tab->precision && size < tab->width && tab->dash == 1 && tab->dot == 0)
		{
			tab->length = tab->width - size;	
		}
		else if (tab->width > tab->precision && size < tab->precision && tab->dot == 1)
		{
			tab->length = tab->width - tab->precision;	
		} 
		else if (tab->width > tab->precision && size > tab->precision && tab->dot == 1)
		{
			tab->length = tab->width - size;	
		} 	
		else
			tab->length = tab->width - tab->precision;
		ft_Calcul_Espace(tab);
	}
}
