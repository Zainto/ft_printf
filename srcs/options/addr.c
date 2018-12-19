/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:19:59 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 11:36:18 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "unitest.h"

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

void			printf_p(t_format *format)
{
	char		*tmp;
	char		*dst;
	char		*output;
	uintptr_t	addr;

	addr = (uintptr_t)&format->p;
	printf("Doing Addr conversion !\n");
	tmp = ft_itoa_unintptr(addr);
	dst = ft_convert_base(tmp, BINARY, HEXA_SMALL);
	output = (char *)malloc((sizeof(char)) * (ft_strlen(dst) + 3));
	output = ft_strcpy(output, "0x");
	output = ft_strcat(output, dst);
	format->output = output;
	return ;
}
