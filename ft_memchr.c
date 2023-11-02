/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:52:57 by ajorge-p          #+#    #+#             */
/*   Updated: 2023/10/16 11:30:26 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	c1;
	size_t			i;

	s1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*s1 == c1)
			return (s1);
		s1++;
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[];
	const char	ch;
    char *ret;

    str[] = "http://www.tutorialspoint.com";
    ch = 'p';
   ret = ft_memchr(str, ch, strlen(str));
   printf("%s", ret);
}
*/