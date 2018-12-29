/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 03:54:37 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/29 06:31:26 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	char	a;
	char	*str;
	char	*tmp;
	float	num;
	int 	b;
	int		r_printf;
	int		r_ftprintf;


	num = 45.44;
	b = INT_MIN;
	a = '%';
	str = "Salut %d";
	tmp = "ok";
	//printf("%+100d %p\n", b, &a);
	r_ftprintf = ft_printf("% 05.2d|\n", b);
	r_printf = printf("% 05.2d|\n", b);
	printf("Resultat ft_printf = %d | Resultat printf = %d\n", r_ftprintf, r_printf);
	return (0);
}
