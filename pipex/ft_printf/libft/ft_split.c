/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:20:19 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/04/05 18:15:51 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntwords(char const *s, char lim)
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

static char	*ft_strncpy(char *dest, const char *src, size_t n)
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

static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
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
	while (s && s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tabela[k] = ft_strndup(s + j, i - j);
			k++;
		}
	}
	tabela[k] = NULL;
	return (tabela);
}
/*
int	main(void)
{
	char	**resultado;
	int		i = 0;

	resultado = ft_split(",o,bolo,de,chocolate,e,feito,de,merda", ',');
	while (resultado[i] != NULL)
	{
		printf("%s\n", resultado[i]);
		i++;
	}
}
*/

//Linha 78 - Percorrer a String "s" enquanto o char
//na pos "i" for igual ao char de "c"

//Linha 80 - Encontramos a primeira palavra,
//guardamos o valor da posicao (i) na variavel j

//Linha 81 - Continuamos a percorrer a string ate encontrarmos outro limitador
//ou ate ao final da string

//Linha 83 - Acontece quando encontramos uma palavra
//(quando entramos no loop anterior)

//Linha - 85 - Igualamos a posicao "k" no array 2D ao resultado do strndup
//(s + j) = Array "s" + j = posicao inicial da palavra
//(i - j) = Tamanho da palavra, j = inicio da palavra, i = final da palavra
