/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:35:41 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/18 16:51:27 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITEST_H
#define UNITEST_H
# include "../../libft/includes/libft.h"

typedef struct	s_format
{
	char 	*output;
	char	c;
}				t_format;

void	printf_c(t_format format);

#endif
