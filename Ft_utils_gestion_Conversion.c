/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ft_utils_gestion_Conversion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:09:20 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/05 17:55:19 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	gestion_pourcentage(t_print *tab)
{
	tab->length = tab->width - 1;
	if ((tab->dash == 1 && tab->zero == 1) || tab->dash == 1)
	{
		ft_putchar('%');
		ft_Calcul_Espace(tab);
		tab->ret++;
	}
	else if (tab->zero == 1)
	{
		ft_Calcul_Zero(tab);
		ft_putchar('%');
		tab->ret++;	
	}
	else
	{
		ft_Calcul_Espace(tab);
		ft_putchar('%');
		tab->ret++;
	}
}
