/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:29:47 by marvin            #+#    #+#             */
/*   Updated: 2023/09/27 21:29:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

    i = 0;
    if (size == 0)
        return (ft_strlen(src));
    while(src[i] && i < (size - 1))
    {
        dst[i] = src[i];
        i++;
    }
    
    /* Porque é que nao é preciso fazer esta parte?
    while(i < size - 1)
    {
        dst[i] = '\0';
        i++;
    }
    */
    dst[i] = '\0';
    return (ft_strlen(src));
}