/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Utils_Gestion_Pointeur.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:24:28 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/06 16:47:00 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_putnbr_basehexap(char *base, t_print *tab)
{
	int					size;
	int					j[300];
	unsigned long int	k;
	unsigned long int	nbr;

	nbr = (unsigned long) va_arg(tab->args, unsigned long);
	k = nbr;
	size = 0;
	while (k > 0)
	{
		j[size++] = k % 16;
		k /= 16;
	}
	tab->ret += 2;
	if (tab->width > 0 && nbr == 0)
		tab->length = tab->width - 1 - (size + 2);
	else
		tab->length = tab->width - (size + 2);
	if (tab->dash == 1)
	{
		write(1, "0x", 2);
		while (size --)
		{
			write(1, &base[j[size]], 1);
			tab->ret++;
		}
		gestion_Nbr_Egale_Zero(tab, nbr);
		ft_Calcul_Espace(tab);
		//gestion_Dash_Pointeur(tab, nbr, size, base, j);	
	}
	else if (tab->zero == 1)
	{
		write(1, "0x", 2);
		ft_Calcul_Zero(tab);
		while (size --)
		{
			write(1, &base[j[size]], 1);
			tab->ret++;
		}
		ft_Calcul_Espace(tab);
		gestion_Nbr_Egale_Zero(tab, nbr);
	}
	else
	{
		ft_Calcul_Espace(tab);
		write(1, "0x", 2);
		while (size --)
		{
			write(1, &base[j[size]], 1);
			tab->ret++;
		}
		gestion_Nbr_Egale_Zero(tab, nbr);
	}
}

void 	gestion_Nbr_Egale_Zero(t_print *tab, unsigned long int nbr)
{
	if (tab->width > 0 && nbr == 0)
			ft_putnbr_ll(nbr, tab);
		else if ((void *) nbr == NULL && tab->width == 0)
		{
			ft_putchar('0');
			tab->ret++;
		}	
}

/*void gestion_Dash_Pointeur(t_print *tab, unsigned long int nbr, int size, char *base, int j[size])
{
	write(1, "0x", 2);
	{
		write(1, &base[j[size]], 1);
		tab->ret++;
	}
	gestion_Nbr_Egale_Zero(tab, nbr);
	ft_Calcul_Espace(tab);		
}*/