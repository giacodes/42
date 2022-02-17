/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magiacov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:31:57 by magiacov          #+#    #+#             */
/*   Updated: 2022/01/28 19:32:02 by magiacov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char	*ft_filldst(const char *s1, const char *set, char *trimmed)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[j])
		j++;
	j = j - 1;
	while (s1[k])
	{
		if (ft_strchr(set, s1[i]))
			i++;
		if (ft_strchr(set, s1[j]))
			j--;
		k++;
	}
	k = 0;
	while (i <= j)
		trimmed[k++] = s1[i++];
	trimmed[k] = 0;
	return (trimmed);
}

static char	*ft_countdst(const char *s1, const char *set)
{
	char	*trimmed;
	int		trimmedlen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		if (ft_strchr(set, s1[i]))
			i++;
		j++;
	}
	j = j - 1;
	while (j > i)
	{
		if (ft_strchr(set, s1[j]))
			j--;
		else
			break ;
	}
	trimmedlen = j - i;
	trimmed = (char *)malloc(sizeof(char) * (trimmedlen + 2));
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;

	if (s1 == NULL)
		return (NULL);
	dst = ft_countdst(s1, set);
	if (dst == NULL)
		return (NULL);
	ft_filldst(s1, set, dst);
	return (dst);
}
