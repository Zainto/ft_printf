/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 03:54:37 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/05 21:32:19 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	float		num;
	long long	 b;
	int		r_printf;
	int		r_ftprintf;


	num = 45.44;
	b = -9223372036854775808;
	r_ftprintf = ft_printf("% Malut|\n", 4294967296);
	r_printf = printf("% Malut|\n", 4294967296);
	printf("Resultat ft_printf = %d | Resultat printf = %d\n", r_ftprintf, r_printf);
	return (0);
}
