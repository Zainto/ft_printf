/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:40:24 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 14:20:31 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/unitest.h"

static void		ft_putnbr_itoa(unsigned int n, char *tmp_tab, int i)
{
	if (n > 0)
	{
		ft_putnbr_itoa(n / 10, tmp_tab, i + 1);
		tmp_tab[i] = (n % 10) + '0';
	}
}

static char		*ft_itoa_uint(unsigned int n)
{
	int		len;
	int		i;
	char	tmp_tab[21];
	char	*dst;

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

void			printf_u(t_format *format)
{
	format->output = ft_itoa_uint(format->u);
	return ;
}