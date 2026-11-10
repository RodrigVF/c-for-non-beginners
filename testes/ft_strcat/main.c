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
#include <string.h>

char	*ft_strcat(char *dest, char *src);

void	teste(char *inicio, char *src)
{
	char	buf[64];
	char	*ret;

	strcpy(buf, inicio);
	ret = ft_strcat(buf, src);
	printf("\"%s\" + \"%s\" = \"%s\" retorno_ok=%d\n",
		inicio, src, buf, ret == buf);
}

int	main(void)
{
	teste("Ola, ", "Piscine");
	teste("", "abc");
	teste("abc", "");
	teste("", "");
	return (0);
}
