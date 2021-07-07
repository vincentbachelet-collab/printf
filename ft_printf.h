/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:35:57 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/06 16:42:33 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define LONG_MIN -2147483647
#define LONG_MAX 2147483647
#define UINT_MAX 4294967295
#define CHAR_MAX 127
#define CHAR_MIN -128

typedef struct s_print
{
	va_list	args;
	int 	width; //Pour gerer la largeur
	int 	zero; // Pour gerer les 0
	int		dash; // Pour gerer les -
	int		precision; // Pour gerer les *
	int 	dot; // Pour gerer les .
	int		length; //Pour la longueur
	int 	ret; // Pour gerer la valeur de retour de print;
} 			t_print;

int		check_for_flags(t_print *tab, const char *format, int position);
int		ft_isprint(int c);
int 	ft_printf(const char *format, ...);
void	ft_putnbr(int n, t_print *tab);
void	ft_unsigned_putnbr(unsigned int n, t_print *tab);
void	ft_printfputnbr_base(unsigned int nbr, char *base, t_print *tab);
void 	ft_putnbr_basehexap(char *base, t_print *tab);
void	ft_Calcul_Espace(t_print *tab);
void	Gestion_decimal_integers(t_print *tab);
void 	gestion_Unsigned(t_print *tab);
void 	gestion_Hexadecimal_x_X(t_print *tab, char *base);
int 	calcul_longueur_x_X(unsigned int i);
void 	gestion_pourcentage(t_print *tab);
void	gestion_caracteres(t_print *tab);
void	gestion_String(t_print *tab);
void	ft_Calcul_Espace(t_print *tab);
void	ft_Calcul_Zero(t_print *tab);
void 	check_for_conversions(t_print *tab, const char *format, int position);
void 	ft_remise_a_zero_flags(t_print *tab);
void	longueur_Precision_String(t_print *tab, char *string);
void 	gestion_Dot_String(t_print *tab, char *string);
void 	write_dot_string(t_print *tab, char *string);
void	gestion_Else_Dot_String(t_print *tab, char *string);
void 	gestion_Dot_Decimal_Integers(t_print *tab, long long i);
void 	gestion_Dash_Decimal(t_print *tab, long long i);
void 	gestion_Dash_Dot_Decimal(t_print *tab, long long i);
void 	gestion_Zero_Dot_Decimal(t_print *tab, long long i);
void	gestion_Intergerszero(t_print *tab, int size);
void 	gestion_Dot_Decimal(t_print *tab, long long i);
void	ft_putnbr_ll(long long i, t_print *tab);
void	gestion_Sansflag(t_print *tab, long long i);
void	gestion_Affichage_Dash_Dot_Decimal(t_print *tab, long long i, int size, int j);
void 	gestion_Espace_Dot_Decimal(t_print *tab, long long i, int size, int j);
void	gestion_i_Egale_Zero(t_print *tab, long long i, int size, int j);
void	gestion_Zero_Zero_Dot_Decimal(t_print *tab, long long i, int size);
void	gestion_Dot_Dash_String(t_print *tab, char *string);
void	gestion_NULL_String(t_print *tab, char *string);
void 	gestion_Dash_Pointeur(t_print *tab, unsigned long int nbr, int size, char *base, int j[size]);
void	gestion_Dot_Dash_Unsigned(t_print *tab, unsigned int i);
void	gestion_Dot_Unsigned(t_print *tab, unsigned int i);
void	gestion_Affichage_Dash_Dot_Unsigned(t_print* tab, unsigned int i, int size, unsigned int j);
void	gestion_Zero_Unsigned(t_print *tab, unsigned int i);
void	gestion_Dash_Unsigned(t_print *tab, unsigned int i);
void	gestion_Zero_Dot_Unsigned(t_print *tab, unsigned int i);
void	gestion_Sans_Flag_Unsigned(t_print *tab, unsigned int i);
void	gestion_Zero_Dot_Unsigned2(t_print *tab, unsigned int i, int size);
void	gestion_Dot_Hexadecimal_x_X(t_print *tab, unsigned int i, char *base);
void	gestion_Dot_Dash_Hexadecimal_x_X(t_print *tab, unsigned int i, char *base);
void	gestion_Dash_Dot_Hexadecimal_x_X(t_print *tab, unsigned int i, char *base);
void	gestion_Affichage_Dash_Dot_Hexadecimal_x_X(t_print *tab, unsigned int i
											, int size, int j, char *base);
void 	gestion_Zero_Hexadecimal_x_X(t_print *tab, unsigned int i, char *base);
void 	gestion_Dot_Zero_Hexadecimal_x_X(t_print *tab, unsigned int i, char *base);
void 	gestion_dash_Hexadecimal_x_X(t_print *tab, unsigned int i, char *base);
void 	gestion_Sansflag_Hexadecimal_x_X(t_print *tab, unsigned int i, char *base);
void	gestion_Espace_Dot_Hexademal_x_X(t_print *tab, unsigned int i, int size);
void 	gestion_Nbr_Egale_Zero(t_print *tab, unsigned long int nbr);

#endif