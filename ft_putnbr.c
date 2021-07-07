/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:24:23 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/07 13:57:08 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_putnbr(int n, t_print *tab)
{
	long	i;

	i = n;
	if (i > 9)
	{
		ft_putnbr(i / 10, tab);
		ft_putnbr(i % 10, tab);
	}
	else
	{
		ft_putchar(i + 48);
		tab->ret++;
	}
}

void	ft_unsigned_putnbr(unsigned int n, t_print *tab)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar('-');
		i = i * -1;
		tab->ret++;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10, tab);
		ft_putnbr(i % 10, tab);
	}
	else
	{
		ft_putchar(i + 48);
		tab->ret++;
	}
}

void	ft_putnbr_ll(long long i, t_print *tab)
{
	if (i > 9)
	{
		ft_putnbr(i / 10, tab);
		ft_putnbr(i % 10, tab);
	}
	else
	{
		ft_putchar(i + 48);
		tab->ret++;
	}
}
