/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../util/ft_util.h"

char	*copia(char *src)
{
	char	*nova;
	int		len;
	int		i;

	len = 0;
	while (src[len] != '\0')
		len++;
	nova = malloc(sizeof(char) * (len + 1));
	if (nova == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		nova[i] = src[i];
		i++;
	}
	return (nova);
}

int	main(void)
{
	char	*c;

	c = copia("vivo no heap");
	if (c == NULL)
		return (1);
	c[0] = 'V';
	ft_putendl(c);
	free(c);
	return (0);
}
