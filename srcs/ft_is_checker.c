/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:41:06 by youngpar          #+#    #+#             */
/*   Updated: 2021/07/03 03:26:01 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int					is_flag(char c)
{
	if (c == '-')
		return (1);
	else if (c == '+')
		return (2);
	else if (c == ' ')
		return (4);
	else if (c == '0')
		return (8);
	else if (c == '#')
		return (16);
	return (0);
}

int					ft_numlen(long long value, t_option *opt, t_number *num)
{
	unsigned int	base;
	t_ull			tmp;

	base = 10;
	if (opt->type == 'x' || opt->type == 'X' || opt->type == 'p')
		if ((opt->flags & (base = 16)) && (value || opt->type == 'p'))
			num->flglen += 2;
	if (value == 0)
		num->numlen += 1;
	if (value < 0 && base == 10 && opt->type != 'u')
	{
		num->value = value * -1;
		num->flglen += 1;
	}
	else if ((opt->flags & 2 || opt->flags & 4) && base == 10)
		num->flglen += 1;
	tmp = num->value;
	while (tmp)
	{
		num->numlen += 1;
		tmp /= base;
	}
	if (!opt->precision && !value)
		return (num->flglen);
	return (num->flglen + num->numlen);
}

t_ll				ft_get_value(t_option *opt, va_list *ap)
{
	t_ll			value;

	if (opt->length == 1)
		value = (long)va_arg(*ap, long long);
	else if (opt->length == 2)
		value = (short)va_arg(*ap, long long);
	else if (opt->length == 3)
		value = (long long)va_arg(*ap, long long);
	else if (opt->length == 4)
		value = (char)va_arg(*ap, long long);
	else
		value = (int)va_arg(*ap, long long);
	return (value);
}

t_ull				ft_get_uvalue(t_option *opt, long long value)
{
	t_ull			val;

	val = (unsigned int)value;
	if (opt->length == 1)
		val = (unsigned long)value;
	else if (opt->length == 2)
		val = (unsigned short)value;
	else if (opt->length == 3)
		val = (unsigned long long)value;
	else if (opt->length == 4)
		val = (unsigned char)value;
	return (val);
}
