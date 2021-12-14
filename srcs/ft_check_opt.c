/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:41:06 by youngpar          #+#    #+#             */
/*   Updated: 2021/12/14 21:56:58 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

const char	*ft_check_flag(const char *str, t_option *opt)
{
	int		option;
	int		tmp;

	option = 0;
	tmp = is_flag(*str);
	while (tmp)
	{
		if (!(option & tmp))
			option += tmp;
		str++;
		tmp = is_flag(*str);
	}
	if ((option & 1) && (option & 8))
		option -= 8;
	opt->flags = option;
	return (str);
}

const char	*ft_check_width(const char *str, t_option *opt, va_list *ap)
{
	int		flag;

	flag = 1;
	if (*str == '*')
		opt->width = va_arg(*ap, int);
	if ((opt->width < 0) && (*str++ == '*'))
		flag = -1;
	else
	{
		while (ft_isdigit(*str) || *str == '-')
		{
			if (*str == '-')
				flag = -1;
			else
				opt->width = opt->width * 10 + *str - '0';
			str++;
		}
	}
	if (!(opt->flags & 1) && flag == -1)
		opt->flags += 1;
	if ((opt->flags & 1) && (opt->flags & 8))
		opt->flags -= 8;
	opt->width *= flag;
	return (str);
}

const char	*ft_check_precision(const char *str, t_option *opt, va_list *ap)
{
	int		flag;

	flag = 1;
	if (*str == '.')
	{
		opt->precision = 0;
		while (*str == '-' || *str == '.')
			if (*str++ == '-')
				flag = -1;
		if (ft_isdigit(*str))
			while (ft_isdigit(*str))
				opt->precision = opt->precision * 10 + *str++ - '0';
		else if (*str == '*')
		{
			opt->precision = va_arg(*ap, int);
			if (opt->precision < 0)
				flag = -1;
			str++;
		}
	}
	if (flag == -1)
		opt->precision = flag;
	return (str);
}

const char	*ft_check_length(const char *str, t_option *opt)
{
	if (*str == 'l')
	{
		opt->length = 1;
		str++;
		if (*str == 'l')
		{
			opt->length += 2;
			str++;
		}
	}
	else if (*str == 'h')
	{
		opt->length = 2;
		str++;
		if (*str == 'h')
		{
			opt->length += 2;
			str++;
		}
	}
	return (str);
}

const char	*ft_check_type(const char *str, t_option *opt)
{
	if (*str == 'c')
		opt->type = 'c';
	else if (*str == 's')
		opt->type = 's';
	else if (*str == 'p')
	{
		if (!(opt->flags & 16))
			opt->flags += 16;
		opt->length = 3;
		opt->type = 'p';
	}
	else if (*str == 'd' || *str == 'i')
		opt->type = 'd';
	else if (*str == 'u')
		opt->type = 'u';
	else if (*str == 'x' || *str == 'X')
		opt->type = *str;
	else if (*str == '%')
		opt->type = '%';
	else if (*str == 'n')
		opt->type = 'n';
	else
		return (str);
	return (str + 1);
}
