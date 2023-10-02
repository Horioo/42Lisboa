/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:10:43 by marvin            #+#    #+#             */
/*   Updated: 2023/09/27 22:10:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlcat(char *dst, char *src, size_t size)
{
    size_t i;
    size_t dst_size;

    dst_size = ft_strlen(dst);
    i = 0;
    if(size == 0)
        return (ft_strlen(src));
    while(src[i] && (dst_size + i) < (size - 1))
    {
        dst[dst_size + i] = src[i];
        i++;
    }
    dst[dst_size + i] = '\0';

    /* Seria possivel fazer isto assim? Qual seria o erro que poderia produzir?
    if((dst_size + i) > size)
        return (size);
    */
   
    if(dest_size < size)
        return (dst_size + ft_strlen(src));
    return (size + ft_strlen(src));
}