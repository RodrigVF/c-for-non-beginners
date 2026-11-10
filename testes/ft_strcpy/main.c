/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

void	teste(char *src)
{
	char	buf[64];
	char	*ret;
	int		i;

	i = 0;
	while (i < 63)
	{
		buf[i] = 'X';
		i++;
	}
	buf[63] = '\0';
	ret = ft_strcpy(buf, src);
	printf("[%s] retorno_ok=%d\n", buf, ret == buf);
}

int	main(void)
{
	teste("Ola");
	teste("");
	teste("Piscine 42 Sao Paulo");
	return (0);
}
