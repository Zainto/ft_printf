/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:35:41 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 11:28:04 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITEST_H
#define UNITEST_H
# include "../../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define BINARY "0123456789"
# define HEXA_SMALL "0123456789abcdef"

typedef struct	s_format
{
	char 			*output;
	char			c;
	char			*str;
	int 			d;
	void			*p;
}				t_format;

void	printf_c(t_format *format);
void	printf_s(t_format *format);
void	printf_p(t_format *format);

#endif
