/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magiacov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:26:15 by magiacov          #+#    #+#             */
/*   Updated: 2022/01/28 19:26:19 by magiacov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t	n)
{
	size_t	i;

	i = 0;
	if (src > dst)
	{
		while (i < n)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	else
	{
		i = n;
		while (i--)
			*(char *)(dst + i) = *(char *)(src + i);
	}
	return (dst);
}
