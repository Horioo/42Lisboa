/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:24:25 by marvin            #+#    #+#             */
/*   Updated: 2023/09/29 22:24:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while(i <= ft_strlen(s))
    {
        if(s[i] == c)
            return(&((char*)s)[i]);
        else
            i++;
    }
    return (NULL);
}

// Linha 21 - Vai returnar o Adress do Type Casting feito ao point s