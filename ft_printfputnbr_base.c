/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <marvin@42.fr>                         +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 07:40:34 by vbachele          #+#    #+#             */
/*   Updated: 2021/06/21 10:05:40 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	calcul_longueur_x_X(unsigned int i)
{	
	int	j[300];
	int	size;

	size = 0;
	while (i != 0)
	{
		j[size++] = i % 16;
		i /= 16;
	}	
	return (size);
}

void	ft_printfputnbr_base(unsigned int nbr, char *base, t_print *tab)
{
	int			sizebase;
	long int	i;

	i = nbr;
	sizebase = ft_strlen(base);
	if (i >= sizebase)
		ft_printfputnbr_base(i / sizebase, base, tab);
	write(1, &base[i % sizebase], 1);
	tab->ret++;
}
