/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:29:34 by ajorge-p          #+#    #+#             */
/*   Updated: 2023/10/20 16:33:21 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sbstr;
	size_t	i;

	if (start >= (unsigned int)ft_strlen(s))
		len = 0;
	else if (start + (unsigned int)len >= (unsigned int)ft_strlen(s))
		len = ft_strlen(s) - start;
	sbstr = (char *)malloc(len + 1);
	if (sbstr == NULL)
		return (NULL);
	i = 0;
	while (i < len && len != 0)
	{
		sbstr[i] = s[start + i];
		i++;
	}
	sbstr[i] = '\0';
	return (sbstr);
}
/*
int main()
{
	printf("%s\n", ft_substr("", 0, 0));
	printf("%s\n", ft_substr("", 0, 1));
	printf("%s\n", ft_substr("", 1, 1));
	printf("%s\n", ft_substr("hola", -1, 0));
	printf("%s\n", ft_substr("hola", 0, -1));
	printf("%s\n", ft_substr("hola", -1, -1));
	printf("%s\n", ft_substr("hola", 0, 0));
	printf("%s\n", ft_substr("hola", 0, 1));
	printf("%s\n", ft_substr("hola", 0, 3));
	printf("%s\n", ft_substr("hola", 0, 4));
	printf("%s\n", ft_substr("hola", 0, 5));
	printf("%s\n", ft_substr("hola", 2, 0));
	printf("%s\n", ft_substr("hola", 2, 1));
	printf("%s\n", ft_substr("hola", 2, 2));
	printf("%s\n", ft_substr("hola", 2, 3));
	printf("%s\n", ft_substr("hola", 2, 30));
	printf("%s\n", ft_substr("hola", 3, 0));
	printf("%s\n", ft_substr("hola", 3, 1));
	printf("%s\n", ft_substr("hola", 3, 2));
	printf("%s\n", ft_substr("hola", 4, 0));
	printf("%s\n", ft_substr("hola", 4, 20));
	printf("%s\n", ft_substr("hola", 5, 2));
}
*/