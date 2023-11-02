/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:39:52 by ajorge-p          #+#    #+#             */
/*   Updated: 2023/10/18 11:51:10 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
int main()
{
	int	fd = open("newline.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(fd == -1)
	{
		printf("Nao funcionou burro");
	}
	ft_putendl_fd("KEKW OMEGALUL", fd);
}
*/
