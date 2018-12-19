/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:19:59 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 22:58:46 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "ft_printf.h"

static void		ft_putnbr_itoa(uintptr_t n, char *tmp_tab, int i)
{
	if (n > 0)
	{
		ft_putnbr_itoa(n / 10, tmp_tab, i + 1);
		tmp_tab[i] = (n % 10) + '0';
	}
}

static char		*ft_itoa_unintptr(uintptr_t n)
{
	int			len;
	int			i;
	char		tmp_tab[21];
	char		*dst;

	i = 0;
	len = 0;
	ft_bzero(tmp_tab, 21);
	if (n == 0)
	{
		dst = ft_strdup("0");
		return (dst);
	}
	ft_putnbr_itoa(n, tmp_tab, i);
	ft_strrev(tmp_tab + i);
	dst = ft_strdup(tmp_tab);
	return (dst);
}

void			pointer(t_format *format)
{
	char		*tmp;
	char		*dst;
	uintptr_t	addr;

	addr = (uintptr_t)format->arg.pointer;
	tmp = ft_itoa_unintptr(addr);
	dst = ft_convert_base(tmp, TEN, HEXA);
	format->output = ft_strjoin("0x", dst);
	ft_strdel(&tmp);
	ft_strdel(&dst);
	return ;
}
