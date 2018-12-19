/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:38:06 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 03:14:03 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static void		format_init(t_format *format)
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

static t_list	*parser(char *spec, va_list args)
{
	t_format	format;
	t_list		*node;

	format_init(&format);
	spec++;
	format.diff += 1;
	if (ft_strchr(FLAGS, *spec))
		extract_flags(&spec, &format);
	if (ft_isdigit(*spec) || *spec == '*')
		extract_width(&spec, &format, args);
	if (*spec == '.')
		extract_precision(&spec, &format, args);
	if (ft_strchr(SIZE, *spec))
		extract_size(&spec, &format);
	if (ft_strchr(TYPE, *spec))
		extract_type(&spec, &format, args);
	node = ft_lstnew(&format, sizeof(t_format));
	return (node);
}

t_list			*format_list(const char *format, va_list args)
{
	t_list			*lst;
	t_list			*node;
	char			*spec;

	lst = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			spec = ft_strsub(format, 0, ft_strcspn(format, TYPE) + 1);
			node = parser(spec, args);
			ft_lstaddback(&lst, node);
			format += ((t_format *)(node->data))->diff;
			ft_strdel(&spec);
		}
		else
			format += ft_strcspn(format, "%");
	}
	return (lst);
}

static int		format_to_buffer(const char **format)
{
	int				result;
	char			*tmp;
	size_t			index;

	index = ft_strcspn(*format, "%");
	tmp = ft_strsub(*format, 0, index);
	result = ft_ringbuffer(tmp);
	ft_strdel(&tmp);
	*format += index;
	return (result);
}

int				output(const char *format, t_list *node)
{
	t_format		*tmp;
	char			*conv;

	if (!*format)
		return (ft_ringbuffer(NULL));
	if (*format == '%')
	{
		tmp = (t_format *)(node->data);
		conv = printformat(tmp);
		return (ft_ringbuffer(conv) + output(format + tmp->diff, node->next));
	}
	return (format_to_buffer(&format) + output(format, node));
}
