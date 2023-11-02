/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:12:49 by ajorge-p          #+#    #+#             */
/*   Updated: 2023/10/31 15:33:33 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (s1 && s2)
	{
		str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (str)
		{
			i = 0;
			while (*s1)
				str[i++] = *s1++;
			while (*s2)
				str[i++] = *s2++;
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
