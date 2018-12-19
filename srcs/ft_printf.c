/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:28:43 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 02:55:34 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int				ft_vprintf(const char *format, va_list args)
{
	int				result;
	t_list			*lst;

	result = 0;
	if (!(lst = format_list(format, args)))
		return (-1);
	result = format_output(format, lst, 0);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_vprintf(format, args);
	va_end(args);
	return (result);
}
