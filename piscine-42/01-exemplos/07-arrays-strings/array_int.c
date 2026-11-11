/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

int	soma(int *tab, int tamanho)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < tamanho)
	{
		total = total + tab[i];
		i++;
	}
	return (total);
}

int	main(void)
{
	int	notas[3];

	notas[0] = 10;
	notas[1] = 7;
	notas[2] = 25;
	ft_putstr("soma das notas = ");
	ft_putnbr(soma(notas, 3));
	ft_putchar('\n');
	return (0);
}
