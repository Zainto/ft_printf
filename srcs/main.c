/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 03:54:37 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/20 00:30:31 by cempassi         ###   ########.fr       */
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
	float	num;
	int 	b;
	int		r_printf;
	int		r_ftprintf;


	num = 45.4563879;
	str = "Salut, comment ca va?";
	b = 5000;
	a = 'Z';
	r_printf = printf(": %.7f\n", num);
	r_ftprintf = ft_printf("binary: %b\n", b);
	printf("Result printf = %d | Result ft_printf = %d\n", r_printf, r_ftprintf);
	return (0);
}
