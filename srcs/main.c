/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 03:54:37 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/04 00:38:21 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	float	num;
	ssize_t b;
	int		r_printf;
	int		r_ftprintf;


	num = 45.44;
	b =-1;
	r_ftprintf = ft_printf("%zd\n", b);
	r_printf = printf("%zd\n", b);
	printf("Resultat ft_printf = %d | Resultat printf = %d\n", r_ftprintf, r_printf);
	return (0);
}
