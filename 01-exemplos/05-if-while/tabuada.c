/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabuada.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

void	linha_da_tabuada(int n, int i)
{
	ft_putnbr(n);
	ft_putstr(" x ");
	ft_putnbr(i);
	ft_putstr(" = ");
	ft_putnbr(n * i);
	ft_putchar('\n');
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 5)
	{
		linha_da_tabuada(7, i);
		i++;
	}
	return (0);
}
