/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:41:43 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/02/06 15:59:01 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	ft_cntwords(char *s, char lim)
{
	int				counter;
	unsigned int	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == lim)
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] && s[i] != lim)
			i++;
	}
	return (counter);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strndup(char *s, size_t n)
{
	char	*str;

	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tabela;

	i = 0;
	k = 0;
	tabela = (char **)malloc(sizeof(char *) * (ft_cntwords(s, c) + 1));
	if (tabela == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i >= j)
		{
			tabela[k] = ft_strndup(s + j, i - j);
			k++;
		}
	}
	tabela[k] = NULL;
	return (tabela);
}