/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:53:44 by ajorge-p          #+#    #+#             */
/*   Updated: 2023/10/16 14:26:32 by ajorge-p         ###   ########.fr       */
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
	return (NULL);
}
/*
int	main(void)
{
	char	*str;
	char	*str2;
	char	*str3;

    str = "With everything going on I will accept my fate";
    str2 = ft_strnstr(str,"on",100);
    str3 = strstr(str,"on");
    printf("%s\n", str2);
    printf("%s", str3);
}
*/