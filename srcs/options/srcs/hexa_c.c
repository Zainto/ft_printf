/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:26:03 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 14:17:02 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/unitest.h"

void	printf_xc(t_format *format)
{
	char	*dst;

	dst = ft_itoa(format->d);
	dst = ft_convert_base(dst, TEN, HEXA_CAP);
	format->output = dst;
	return ;
}
