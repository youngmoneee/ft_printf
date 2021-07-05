/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:04:02 by youngpar          #+#    #+#             */
/*   Updated: 2021/05/08 19:04:22 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(long long buf)
{
	size_t	size;

	size = 0;
	while (buf)
	{
		buf /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	size_t			size;
	size_t			idx;
	unsigned int	flag;
	long long		buf;
	char			*cbuf;

	flag = n < 0 ? 1 : 0;
	buf = n > 0 ? n : -(long long)n;
	size = n > 0 ? 0 : 1;
	size += ft_numlen(buf);
	if (!(cbuf = (char *)malloc(sizeof(char) * (size + 1))))
	{
		return ((void *)0);
	}
	idx = 0;
	while (idx < size)
	{
		cbuf[size - idx++ - 1] = buf % 10 + '0';
		buf /= 10;
	}
	if (flag)
		cbuf[0] = '-';
	cbuf[size] = 0;
	return (cbuf);
}
