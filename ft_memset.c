/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:22:50 by marvin            #+#    #+#             */
/*   Updated: 2023/09/26 22:22:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memset(void *s, int c, size_t n)
{
    size_t  i;
    unsigned char   value;
    unsigned char   *str;
    
    value = (unsigned char)c;
    str = (unsigned char*)s;
    i = 0;
    while(i < n)
    {
        str[i] = value;
        i++;
    }
    return (s);
}