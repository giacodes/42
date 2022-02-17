/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magiacov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:24:03 by magiacov          #+#    #+#             */
/*   Updated: 2022/01/26 15:24:19 by magiacov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char	*put_string(const char *s1, int start, int finish)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (finish - start) + 1);
	while (start < finish)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

static void	ft_fillarr(const char *s1, char c, char **splitted)
{
	size_t	i;
	int		j;
	int		control;

	i = 0;
	j = 0;
	control = -1;
	while (i <= ft_strlen(s1))
	{
		if (s1[i] != c && control < 0)
			control = i;
		else if ((s1[i] == c || i == ft_strlen(s1)) && control >= 0)
		{
			splitted[j++] = put_string(s1, control, i);
			control = -1;
		}
		i++;
	}
	splitted[j] = 0;
}

static int	ft_strcnt(const char	*s1, char c)
{
	int	i;
	int	control;

	i = 0;
	control = 0;
	while (*s1)
	{
		if (*s1 != c && control == 0)
		{
			control = 1;
			i++;
		}
		else if (*s1 == c)
			control = 0;
		s1++;
	}
	return (i);
}

char	**ft_split(char const *s1, char c)
{
	char	**splitted;

	if (s1 == NULL)
		return (NULL);
	splitted = malloc(sizeof(char *) * ((ft_strcnt(s1, c)) + 1));
	if (splitted == NULL)
		return (NULL);
	ft_fillarr(s1, c, splitted);
	return (splitted);
}
