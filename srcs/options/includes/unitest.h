/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:35:41 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 13:41:22 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITEST_H
#define UNITEST_H
# include "../../../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define TEN "0123456789"
# define OCTAL "01234567"
# define HEXA_SMALL "0123456789abcdef"
# define HEXA_CAP "0123456789ABCDEF"

typedef struct	s_format
{
	int				d;
	void			*p;
	char 			*output;
	char			c;
	char			*str;
	double			f;
	unsigned int 	u;
}				t_format;

void	printf_c(t_format *format);
void	printf_s(t_format *format);
void	printf_p(t_format *format);
void	printf_d(t_format *format);
void	printf_o(t_format *format);
void	printf_u(t_format *format);
void	printf_x(t_format *format);
void	printf_xc(t_format *format);
void	printf_f(t_format *format);

#endif
