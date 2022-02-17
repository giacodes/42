/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magiacov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:29:54 by magiacov          #+#    #+#             */
/*   Updated: 2022/01/28 19:29:56 by magiacov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		if (i < ft_strlen(s1))
			dest[i] = s1[i];
		else
			dest[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
