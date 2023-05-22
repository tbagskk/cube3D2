/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:10:48 by mbouaza           #+#    #+#             */
/*   Updated: 2023/05/17 22:07:48 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static char	*free_for_substr(char *str)
{
	free(str);
	return (NULL);
}

// copy of substr, but can free if my malloc fail //

static char	*ft_substr_can_free(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (free_for_substr(str));
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

// free all words in my **tab and free my **tab //

static void	*free_all(char **tab, int w)
{
	int	i;

	i = 0;
	while (i != w)
	{
		free (tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

// count all word without my separator //

static int	ft_count_word(char const *s, char c)
{
	char	str;
	int		i;
	int		j;

	str = c;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (str == c && s[i] != c)
		{
			j++;
		}
		str = s[i];
		i++;
	}
	return (j);
}

// principal fonction //

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word;
	int		i;
	int		j;

	word = 0;
	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!tab)
		return (0);
	while (s[j] && s[i] && word < ft_count_word(s, c))
	{
		i = j;
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		tab[word++] = ft_substr_can_free(s, i, j - i);
		if (!tab[word - 1])
			return (free_all(tab, word));
	}
	tab[word] = NULL;
	return (tab);
}