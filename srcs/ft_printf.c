/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:41:06 by youngpar          #+#    #+#             */
/*   Updated: 2021/12/14 21:27:57 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			len;
	va_list		ap;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			str = ft_check_obj(str + 1, &ap, &len);
		else
		{
			write(1, str++, 1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
