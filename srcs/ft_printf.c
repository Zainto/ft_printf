/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:28:43 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/20 03:04:16 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		ft_vdprintf(const char *format, va_list args, int fd)
{
	t_list			*lst;

	lst = format_list(format, args);
	return (doutput(format, lst, fd));
}

int		ft_vasprintf(char **dst, const char *format, va_list args)
{
	t_list			*lst;

	lst = format_list(format, args);
	return (soutput(dst, format, lst));
}

int		ft_asprintf(char **dst, const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_vasprintf(dst, format, args);
	va_end(args);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_vdprintf(format, args, 1);
	va_end(args);
	return (result);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_vdprintf(format, args, fd);
	va_end(args);
	return (result);
}
