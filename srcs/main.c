/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 03:54:37 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 02:08:27 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

char			*printformat(t_format *format)
{
	char	*info;

	info = ft_strnew(0);
	info = ft_strinsert(&info, '[', ft_strlen(info));
	if(format->flag_minus == 1)
		info = ft_strinsert(&info, '-', ft_strlen(info));
	if(format->flag_plus == 1)
		info = ft_strinsert(&info, '+', ft_strlen(info));
	if(format->flag_zero == 1)
		info = ft_strinsert(&info, '0', ft_strlen(info));
	if(format->flag_space == 1)
		info = ft_strinsert(&info, ' ', ft_strlen(info));
	if(format->flag_hashtag == 1)
		info = ft_strinsert(&info, '#', ft_strlen(info));
	info = ft_strinsert(&info, ']', ft_strlen(info));
	info = ft_strinsert(&info, '[', ft_strlen(info));
	info = ft_strjoin(info, ft_itoa(format->width));
	info = ft_strinsert(&info, ']', ft_strlen(info));
	info = ft_strinsert(&info, '[', ft_strlen(info));
	info = ft_strjoin(info, ft_itoa(format->precision));
	info = ft_strinsert(&info, ']', ft_strlen(info));
	info = ft_strinsert(&info, '[', ft_strlen(info));
	info = ft_strjoin(info, format->size);
	info = ft_strinsert(&info, ']', ft_strlen(info));
	info = ft_strinsert(&info, '[', ft_strlen(info));
	info = ft_strinsert(&info, format->type, ft_strlen(info));
	info = ft_strinsert(&info, ']', ft_strlen(info));
	if (format->type == 's')
	{
		info = ft_strinsert(&info, '[', ft_strlen(info));
		info = ft_strjoin(info, format->arg.string);
		info = ft_strinsert(&info, ']', ft_strlen(info));
	}
	if (format->type == 'c')
	{
		info = ft_strinsert(&info, '[', ft_strlen(info));
		info = ft_strinsert(&info, format->arg.character, ft_strlen(info));
		info = ft_strinsert(&info, ']', ft_strlen(info));
	}
	if (format->type == 'd' && format->size == NULL)
	{
		info = ft_strinsert(&info, '[', ft_strlen(info));
		info = ft_strjoin(info, ft_itoa(format->arg.integer));
		info = ft_strinsert(&info, ']', ft_strlen(info));
	}
	if (format->type == 'd' && ft_strequ(format->size, "ll"))
	{
		info = ft_strinsert(&info, '[', ft_strlen(info));
		info = ft_strjoin(info, ft_itoa(format->arg.ll_integer));
		info = ft_strinsert(&info, ']', ft_strlen(info));
	}
	return (info);
}

int		main(void)
{
	char	a;
	long long int b;

	a = 98;
	b = 40;
	printf("Salut %X\n", -4033);
	ft_printf("Salut %c mais %lld %s", a, b, "Esperons que tout se passe bien");
	return (0);
}
