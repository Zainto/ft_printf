/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:26:07 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 13:30:19 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/unitest.h"

void printf_x(t_format *format)
{
	char *dst;

	printf("Doing hexa conversion !\n");
	dst = ft_itoa(format->d);
	dst = ft_convert_base(dst, TEN, HEXA_SMALL);
	format->output = dst;
	return;
}
