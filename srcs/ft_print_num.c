/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:41:06 by youngpar          #+#    #+#             */
/*   Updated: 2021/07/03 00:19:38 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		ft_setnum(t_number *num, t_option *opt, va_list *ap)
{
	int		len;

	num->origin = ft_get_value(opt, ap);
	num->value = ft_get_uvalue(opt, num->origin);
	if (opt->type == 'u' && (num->origin < 0))
		num->origin = (unsigned long long)num->origin;
	len = ft_numlen(num->origin, opt, num);
	if (num->numlen < opt->precision)
		num->lft_z = opt->precision - num->numlen;
	if (opt->width > (len + num->lft_z) && !(opt->flags & 8))
		num->lft = opt->width - (len + num->lft_z);
	if (opt->precision == -1 && opt->flags & 8)
		num->lft_z = opt->width - len;
	num->lft = opt->width - len - num->lft_z;
	if (!num->origin && !opt->precision)
		return (-1);
	return (1);
}

static void		ft_print_form(long long value, t_option *opt, int *len)
{
	if ((opt->flags & 16) &&
			(opt->type == 'x' || opt->type == 'X' || opt->type == 'p'))
	{
		if (!value && !(opt->type == 'p'))
			return ;
		if (opt->type == 'x' || opt->type == 'p')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		*len += 2;
	}
	if (value < 0 && !(opt->flags & 16) &&
			(opt->type == 'd' || opt->type == 'i'))
		*len += write(1, "-", 1);
	else if (opt->flags & 2 || opt->flags & 4)
		if (value >= 0)
		{
			if (opt->flags & 2)
				write(1, "+", 1);
			else if (opt->flags & 4)
				write(1, " ", 1);
			*len += 1;
		}
}

void			ft_put_num(unsigned long long value, t_option *opt, int *len)
{
	unsigned int	base;

	base = 10;
	if (opt->type == 'x' || opt->type == 'X' || opt->type == 'p')
		base = 16;
	if (!value && !opt->precision)
		return ;
	if (value >= base)
		ft_put_num(value / base, opt, len);
	if (opt->type == 'X')
		ft_putchar_fd("0123456789ABCDEF"[value % base], 1);
	else
		ft_putchar_fd("0123456789abcdef"[value % base], 1);
	*len += 1;
}

int				ft_print_d(t_option *opt, va_list *ap)
{
	int				len;
	t_number		num;

	ft_memset(&num, 0, sizeof(t_number));
	ft_setnum(&num, opt, ap);
	len = 0;
	while (!(opt->flags & 1) && (num.lft > 0))
	{
		len += write(1, " ", 1);
		num.lft -= 1;
	}
	ft_print_form(num.origin, opt, &len);
	while (num.lft_z > 0)
	{
		len += write(1, "0", 1);
		num.lft_z -= 1;
	}
	ft_put_num(num.value, opt, &len);
	while ((opt->flags & 1) && (opt->width - len > 0))
		len += write(1, " ", 1);
	return (len);
}
