/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 22:11:53 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 22:13:18 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	binary(t_format *format)
{
	char	*dst;

	if (ft_strequ(format->size, "l"))
		dst = ft_ullitoa(format->arg.ul_integer);
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		dst = ft_ullitoa(format->arg.ull_integer);
	else
		dst = ft_ullitoa(format->arg.u_integer);
	dst = ft_convert_base(dst, TEN, BINARY);
	format->output = dst;
	return ;
}
