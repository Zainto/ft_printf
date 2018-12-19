/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:19:59 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 23:46:46 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "ft_printf.h"

void			pointer(t_format *format)
{
	char		*tmp;
	char		*dst;

	tmp = ft_ullitoa((uintptr_t)format->arg.pointer);
	dst = ft_convert_base(tmp, TEN, HEXA);
	format->output = ft_strjoin("0x", dst);
	ft_strdel(&tmp);
	ft_strdel(&dst);
	return ;
}
