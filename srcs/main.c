/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 03:54:37 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 23:30:08 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include "limits.h"

int		main(void)
{
	char	a;
	char	*str;
	int 	b;
	int		r_printf;
	int		r_ftprintf;


	str = "Salut, comment ca va?";
	b = -4000;
	a = 'Z';
	r_printf = printf("unsigned int: %ld\n", LONG_MIN);
	r_ftprintf = ft_printf("unsigned int: %ld\n", LONG_MIN);
	printf("Result printf = %d | Result ft_printf = %d\n", r_printf, r_ftprintf);
	return (0);
}
