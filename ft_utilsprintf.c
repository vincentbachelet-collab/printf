/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:18:17 by vbachele          #+#    #+#             */
/*   Updated: 2021/06/29 14:11:58 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_Calcul_Espace(t_print *tab)
{
	while (tab->length > 0)
	{
		ft_putchar(' ');
		tab->ret++;
		tab->length--;
	}
}

void	ft_Calcul_Zero(t_print *tab)
{
	while (tab->length > 0)
	{
		ft_putchar('0');
		tab->length--;
		tab->ret++;
	}
}
