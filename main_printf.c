/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:46:45 by vbachele          #+#    #+#             */
/*   Updated: 2021/07/07 10:13:17 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int main( int argc, char * argv[] ) 
{
    int size; 
	int a = 10;
	int *b = &a;
	
	#define INT_MAX 2147483647
	#define INT_MIN -2147483648
	#define LONG_MIN -2147483647
	#define LONG_MAX 2147483647
	#define UINT_MAX 4294967295
	#define CHAR_MAX 127
	#define CHAR_MIN -128
	
	
	size = ft_printf("\n23.Fonction ft_printf: %0.i||\n", 8);
	ft_printf("23.Retour int printf: %d||\n", size);	
	size = printf("\n23.Fonction ft_printf: %0.i||\n", 8);
	printf("23.Retour int printf: %d||\n", size);
	
	size = ft_printf("\n23.Fonction ft_printf: %9.2d||\n", UINT_MAX);
	ft_printf("23.Retour int printf: %d||\n", size);	
	size = printf("\n23.Fonction ft_printf: %9.2d||\n", UINT_MAX);
	printf("23.Retour int printf: %d||\n", size);
	
	size = ft_printf("\n23.Fonction ft_printf: %9.2u||\n", UINT_MAX);
	ft_printf("23.Retour int printf: %d||\n", size);	
	size = printf("\n23.Fonction ft_printf: %9.2u||\n", UINT_MAX);
	printf("23.Retour int printf: %d||\n", size);
	
	size = ft_printf("\n60.Fonction ft_printf: %-10p||\n", 0, 0);
	ft_printf("60.Retour int printf: %d||\n", size);	
	size = printf("\n60.Fonction ft_printf: %-10p||\n", 0, 0);
	printf("60.Retour int printf: %d||\n", size);
	
	size = ft_printf("\n79.Fonction ft_printf: %%*.c%c%%*.s*%ps%%*.X||\n", '0', NULL);
	ft_printf("79.Retour int printf: %d||\n", size);	
	size = printf("\n79.Fonction ft_printf: %%*.c%c%%*.s*%ps%%*.X||\n", '0', NULL);
	printf("79.Retour int printf: %d||\n", size);
	
	size = ft_printf("\n80.Fonction ft_printf: %10.*i%*.10i||\n", 7, 42, 8, -42);
	ft_printf("80.Retour int printf: %d||\n", size);	
	size = printf("\n80.Fonction ft_printf: %10.*i%*.10i||\n", 7, 42, 8, -42);
	printf("80.Retour int printf: %d||\n", size);
	return (0);
}