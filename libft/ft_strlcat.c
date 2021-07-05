/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:45:02 by youngpar          #+#    #+#             */
/*   Updated: 2021/05/04 16:57:28 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;
	size_t	ret;

	dstlen = ft_strlen(dst);
	i = 0;
	if (dstlen + 1 < dstsize)
	{
		while (src[i] && (i + dstlen + 1) < dstsize)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = 0;
	}
	ret = ft_strlen(src);
	if (dstsize != 0)
	{
		if (dstsize <= dstlen)
			ret += dstsize;
		else
			ret += dstlen;
	}
	return (ret);
}
