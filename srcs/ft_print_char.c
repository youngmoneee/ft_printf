/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:41:06 by youngpar          #+#    #+#             */
/*   Updated: 2021/12/14 19:22:10 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_print_c(t_option *opt, va_list *ap)
{
	int					len;
	int					c;

	len = 1;
	c = va_arg(*ap, int);
	while ((opt->width > len) && !(opt->flags & 1))
		len += write(1, " ", 1);
	write(1, &c, 1);
	while ((opt->width > len) && (opt->flags & 1))
		len += write(1, " ", 1);
	return (len);
}

size_t	ft_print_per(t_option *opt)
{
	int			len;

	len = 1;
	if ((opt->flags & 8) && (opt->width > len))
		while (opt->width > len)
			len += write(1, "0", 1);
	else if (!(opt->flags & 1) && (opt->width > len))
		while (opt->width > len)
			len += write(1, " ", 1);
	write(1, "%", 1);
	if ((opt->flags & 1) && opt->width > len)
		while (opt->width > len)
			len += write(1, " ", 1);
	return (len);
}

size_t	ft_print_s(t_option *opt, va_list *ap)
{
	char		*c;
	int			len;
	int			strlen;

	len = 0;
	c = va_arg(*ap, char *);
	if (!c)
		c = "(null)";
	strlen = ft_strlen(c);
	if (opt->precision < 0)
		opt->precision = strlen;
	else if (opt->precision < strlen)
		strlen = opt->precision;
	while (!(opt->flags & 1) && (opt->width - strlen - len > 0))
		len += write(1, " ", 1);
	len += write(1, c, strlen);
	while ((opt->flags & 1) && (opt->width - len > 0))
		len += write(1, " ", 1);
	return (len);
}
