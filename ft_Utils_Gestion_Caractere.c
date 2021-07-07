/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Utils_Gestion_Caractere.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:45:06 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/05 13:54:27 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	gestion_caracteres(t_print *tab)
{
	char	c;

	c = (char) va_arg(tab->args, char *);
	tab->length = tab->width - 1;
	if ((tab->dash == 1 && tab->zero == 1) || tab->dash == 1)
	{
		ft_putchar(c);
		ft_Calcul_Espace(tab);
		tab->ret++;
	}
	else if (tab->zero == 1)
	{
		ft_Calcul_Zero(tab);
		ft_putchar(c);
		tab->ret++;
	}
	else
	{
		ft_Calcul_Espace(tab);
		ft_putchar(c);
		tab->ret++;
	}
}
