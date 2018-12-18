/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:20:45 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/18 15:59:48 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_format{

	char *output;
	char	(*convert)(struct s_format *);
}				t_format;	

int		ft_printf(const char * format, ...);
int		ft_vprintf(const char *format, va_list args);
#endif
