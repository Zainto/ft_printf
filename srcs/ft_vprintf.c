/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:24:06 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/18 16:05:04 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

static int	format_to_buffer(char **format)
{
	return ();
}
int		ft_vprintf(const char *format, va_list args)
{
	int				result;
	char			*tmp;
	size_t			index;

	tmp = NULL;
	index = 0;
	result = 0;
	if (args)
		;
	while (*format)
	{
		if (*format == '%')
		{
			result += ft_ringbuffer("[replace]");
			format++;
		}
		else
		{
			index = ft_strcspn(format, "%");
			tmp = ft_strsub(format, 0, index);	
			result += ft_ringbuffer(tmp);
			ft_strdel(&tmp);
			format += index;
		}
	}
	ft_ringbuffer(NULL);
	return (result);
}
