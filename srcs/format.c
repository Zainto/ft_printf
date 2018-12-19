/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:38:06 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 02:23:10 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int		format_to_buffer(const char **format)
{
	int				result;
	char			*tmp;
	size_t			index;

	result = 0;
	tmp = NULL;
	index = 0;
	index = ft_strcspn(*format, "%");
	tmp = ft_strsub(*format, 0, index);
	result += ft_ringbuffer(tmp);
	ft_strdel(&tmp);
	*format += index;
	return (result);
}

static void		format_convert(const char **format, t_list **lst, va_list args)
{
	t_list			*node;
	char			*spec;

	spec = ft_strsub(*format, 0, ft_strcspn(*format, TYPE) + 1);
	node = parser(spec, args);
	ft_lstaddback(lst, node);
	*format += ((t_format *)(node->data))->diff;
}

void			format_init(t_format *format)
{
	format->id = 0;
	format->type = 0;
	format->flag_minus = 0;
	format->flag_plus = 0;
	format->flag_zero = 0;
	format->flag_space = 0;
	format->flag_hashtag = 0;
	format->diff = 0;
	format->width = 0;
	format->precision = 0;
	format->size = NULL;
	format->output = NULL;
	format->convert = NULL;
}

t_list			*format_list(const char *format, va_list args)
{
	t_list			*lst;

	lst = NULL;
	while (*format)
	{
		if (*format == '%')
			format_convert(&format, &lst, args);
		else
			format += ft_strcspn(format, "%");
	}
	return (lst);
}

int				format_output(const char *format, t_list *current, int result)
{
	t_format		*tmp;
	char			*convert;

	if (!*format)
		return ((result += ft_ringbuffer(NULL)));
	if (*format == '%')
	{
		tmp = (t_format *)(current->data);
		convert = printformat(tmp);
		result += ft_ringbuffer(convert);
		format += tmp->diff;
		return (format_output(format, current->next, result));
	}
	return (format_to_buffer(&format) + format_output(format, current, result));
}
