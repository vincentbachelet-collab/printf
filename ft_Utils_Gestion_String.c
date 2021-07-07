/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Utils_Gestion_String.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:28:32 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/06 17:13:46 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	gestion_Dot_Dash_String(t_print *tab, char *string)
{	
	if (tab->precision < (int)ft_strlen(string))
	{
		tab->length = tab->width - tab->precision;
		write_dot_string(tab, string);
		ft_Calcul_Espace(tab);
	}
	else if (tab->precision > (int)ft_strlen(string))
	{
		tab->length = tab->width - ft_strlen(string);
		write_dot_string(tab, string);
		ft_Calcul_Espace(tab);
	}
}

void	gestion_Dot_String(t_print *tab, char *string)
{
	if (tab->precision < (int)ft_strlen(string))
	{
		tab->length = tab->width - tab->precision;
		ft_Calcul_Espace(tab);
		write_dot_string(tab, string);
	}
	else if (tab->precision >= (int)ft_strlen(string))
	{
		tab->length = tab->width - ft_strlen(string);
		ft_Calcul_Espace(tab);
		write_dot_string(tab, string);
	}
	else if ((tab->width > (int)tab->precision) && tab->dot == 1)
	{
		tab->length = tab->width - tab->precision;
		ft_Calcul_Espace(tab);
		write_dot_string(tab, string);
	}
}

void	write_dot_string(t_print *tab, char *string)
{
	if (((int)ft_strlen(string) > tab->precision) && tab->dot == 1)
	{
		while (tab->precision)
		{
			ft_putchar(*string++);
			tab->ret++;
			tab->precision--;
		}
	}
	else
	{
		while (*string != '\0')
		{
			ft_putchar(*string++);
			tab->ret++;
		}
	}
}

void	gestion_NULL_String(t_print *tab, char *string)
{
	if (string == NULL && tab->width < tab->precision)
	{
		string = "(null)";
		if (tab->dash == 1)
		{
			tab->length = tab->width - ft_strlen(string);
			while (*string != '\0')
			{
				ft_putchar(*string++);
				tab->ret++;
			}
			ft_Calcul_Espace(tab);
		}
	}
}

void	gestion_String(t_print *tab)
{
	char	*string;

	string = (char *)va_arg(tab->args, char *);
	if (string == NULL && tab->width <= tab->precision)
	{
		string = "(null)";
		if (tab->dash == 1)
		{
			tab->length = tab->width - ft_strlen(string);
			while (*string != '\0')
			{
				ft_putchar(*string++);
				tab->ret++;
			}
			ft_Calcul_Espace(tab);
		}
	}
	else if (string == NULL && tab->width > tab->precision)
		string = "(null)";
	if (tab->dot == 1 && tab->dash == 1)
		gestion_Dot_Dash_String(tab, string);
	else if (tab->dot == 1)
		gestion_Dot_String(tab, string);
	else if (tab->dash == 1)
	{
		write_dot_string(tab, string);
		tab->length = tab->width - ft_strlen(string);
		ft_Calcul_Espace(tab);
	}
	else
	{
		tab->length = tab->width - ft_strlen(string);
		ft_Calcul_Espace(tab);
		write_dot_string(tab, string);
	}
}
