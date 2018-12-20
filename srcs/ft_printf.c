/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:28:43 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/20 01:16:40 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		ft_vprintf_fd(const char *format, va_list args, int fd)
{
	t_list			*lst;

	lst = format_list(format, args);
	return (output(format, lst, fd));
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_vprintf_fd(format, args, 1);
	va_end(args);
	return (result);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_vprintf_fd(format, args, fd);
	va_end(args);
	return (result);
}
