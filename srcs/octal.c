/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:47:35 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 22:01:01 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	octal(t_format *format)
{
	char	*dst;

	if (ft_strequ(format->size, "l"))
		dst = ft_ullitoa(format->arg.ul_integer);
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		dst = ft_ullitoa(format->arg.ull_integer);
	else
		dst = ft_ullitoa(format->arg.u_integer);
	dst = ft_convert_base(dst, TEN, OCTAL);
	format->output = dst;
	return ;
}
