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
#include <stdlib.h>

char	*ft_strdup(char *src);

void	teste(char *src)
{
	char	*dup;

	dup = ft_strdup(src);
	if (dup == NULL)
	{
		printf("retornou NULL\n");
		return ;
	}
	printf("\"%s\" copia_nova=%d\n", dup, dup != src);
	free(dup);
}

int	main(void)
{
	teste("Ola");
	teste("");
	teste("Piscine 42 Sao Paulo");
	return (0);
}
