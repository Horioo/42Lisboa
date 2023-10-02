/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:33:51 by marvin            #+#    #+#             */
/*   Updated: 2023/09/26 22:33:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    char *temp;
    int i;
    char *destc;
    char *srcc;

    destc = (char *)dest;
    srcc = (char *)src;
    i = 0;
    while(i < n)
    {
        temp[i] = src[i];
        i++;
    }
    i = 0;
    while(i < n)
    {
        dest[i] = temp[i];
        i++;
    }
    return (dest);
}