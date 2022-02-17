/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magiacov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:25:08 by magiacov          #+#    #+#             */
/*   Updated: 2022/01/28 19:25:11 by magiacov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

static long	ft_abs(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
			return ((long)2147483648);
		return (n * -1);
	}
	return (n);
}

static size_t	ft_ilen(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_ilen(n) + 1;
	str = (char *)malloc(sizeof(char) * (len));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	i = len - 1;
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (i >= 0 && n != 0)
	{
		str[i--] = 48 + (int)(ft_abs(n) % 10);
		n /= 10;
	}
	return (str);
}
