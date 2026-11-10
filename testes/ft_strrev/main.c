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

char	*ft_strrev(char *str);

void	teste(char *original)
{
	char	buf[64];
	char	*ret;

	strcpy(buf, original);
	ret = ft_strrev(buf);
	printf("\"%s\" -> \"%s\" retorno_ok=%d\n", original, buf, ret == buf);
}

int	main(void)
{
	teste("abc");
	teste("abcd");
	teste("a");
	teste("");
	teste("Piscine 42");
	return (0);
}
