/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 03:54:37 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/20 15:26:38 by cempassi         ###   ########.fr       */
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
	char	*tmp2;
	float	num;
	int 	b;


	num = 45.4563879;
	b = 5000;
	a = 'Z';
	str = NULL;
	tmp = "marche parfaitement comme il faut";
	tmp2 = "et ouais mon gars";
	//printf("%+100d %p\n", b, &a);
	ft_printf("%s %llb n", tmp, LLONG_MAX);
	return (0);
}
