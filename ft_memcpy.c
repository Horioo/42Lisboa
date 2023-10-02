/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:27:44 by marvin            #+#    #+#             */
/*   Updated: 2023/09/26 22:27:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    int i;
    unsigned char *udest;
    unsigned char *usrc;

    i = 0;
    udest = (unsigned char*)dest;
    usrc = (unsigned char*)src;
    while(i < n)
    {
        udest[i] = usrc[i];
        i++;
    }
    return (udest);
}