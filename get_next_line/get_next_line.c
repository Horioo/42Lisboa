/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:05:02 by ajorge-p          #+#    #+#             */
/*   Updated: 2023/11/02 11:03:39 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

char    *get_next_line(int fd)
{
    static char    buffer[BUFFER_SIZE];
    size_t  i;
    char    *str;

    i = 0;
    str = malloc(BUFFER_SIZE);
    while(buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0))
    {
        if(buffer[i] == '\n')
            return str;
        else
            str = ft_strjoin(str, buffer);
    }
    return (str);
}