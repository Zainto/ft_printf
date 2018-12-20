/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 03:54:37 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/20 20:03:27 by cempassi         ###   ########.fr       */
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
	b = 5000;
	a = '%';
	str = "Salut %d";
	tmp = "ok";
	//printf("%+100d %p\n", b, &a);
	r_ftprintf = ft_printf("%+10d|\n", 42);
	r_printf = printf("%+10d|\n", 42);
	printf("Resultat ft_printf = %d | Resultat printf = %d\n", r_ftprintf, r_printf);
	return (0);
}
