/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestionflag2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:42:09 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/07 16:06:17 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	gestion_Zero_Parsing(t_print *tab)
{
	tab->zero++;
	if (tab->dash == 1)
		tab->zero = 0;
}

void	gestion_dash_parsing(t_print *tab)
{	
	tab->dash = 1;
	if (tab->zero == 1)
		tab->zero = 0;
}