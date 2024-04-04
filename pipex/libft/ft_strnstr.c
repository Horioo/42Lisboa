/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:53:44 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/25 16:16:06 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*sbig;
	size_t	little_len;

	sbig = (char *)big;
	if (little[0] == '\0')
		return (sbig);
	little_len = (size_t)ft_strlen(little);
	while (*sbig && len >= little_len)
	{
		if (*sbig == *little)
		{
			if (ft_strncmp(little, sbig, little_len) == 0)
				return (sbig);
		}
		len--;
		sbig++;
	}
	return (0);
}
