/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 03:54:37 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/20 02:59:36 by cempassi         ###   ########.fr       */
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
	char	*tmp;
	char	*tmp2;
	float	num;
	int 	b;
	int		r_ftprintf;


	num = 45.4563879;
	b = 5000;
	a = 'Z';
	str = NULL;
	tmp = "marche parfaitement comme il faut";
	tmp2 = "et ouais mon gars";
	r_ftprintf = ft_printf("%s %s %s %s %llX\n","Salut", tmp2, "tout", tmp, 0x22FD);
	ft_putstr(str);
	return (0);
}
