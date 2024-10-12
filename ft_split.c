/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:53:48 by thomarna          #+#    #+#             */
/*   Updated: 2024/10/11 10:14:40 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == sep) && s[i] != sep)
			count++;
		i++;
	}
	return (count);
}

static int	ft_countletters(const char *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != sep)
		i++;
	return (i);
}

static void	*ft_freetab(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_array(char **tab, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			tab[j] = ft_calloc(ft_countletters(&s[i], c) + 1, sizeof(char));
			if (tab[j] == NULL)
				return (ft_freetab(tab, j));
			while (s[i] && s[i] != c)
				tab[j][k++] = s[i++];
			tab[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (s == NULL)
		return (NULL);
	res = ft_calloc(ft_countwords(s, c) + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	res = ft_array(res, s, c);
	return (res);
}
