/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:47:35 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 13:29:45 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/unitest.h"

void printf_o(t_format *format)
{
	char 	*dst;

	printf("Doing Octal conversion !\n");
	dst = ft_itoa(format->d);
	dst = ft_convert_base(dst, TEN, OCTAL);
	format->output = dst;
	return;
}
