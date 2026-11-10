/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vazamento.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../util/ft_util.h"

int	main(void)
{
	int	*numeros;
	int	i;

	i = 0;
	while (i < 3)
	{
		numeros = malloc(sizeof(int) * 10);
		if (numeros == NULL)
			return (1);
		numeros[0] = i;
		i++;
	}
	ft_putendl("Pedi 3 blocos de 40 bytes e nao devolvi nenhum.");
	return (0);
}
