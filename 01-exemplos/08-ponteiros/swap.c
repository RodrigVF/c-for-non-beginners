/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

void	troca_errada(int a, int b)
{
	int	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void	troca(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	mostra(char *rotulo, int x, int y)
{
	ft_putstr(rotulo);
	ft_putstr(" x=");
	ft_putnbr(x);
	ft_putstr(" y=");
	ft_putnbr(y);
	ft_putchar('\n');
}

int	main(void)
{
	int	x;
	int	y;

	x = 1;
	y = 2;
	troca_errada(x, y);
	mostra("depois de troca_errada(x, y):", x, y);
	troca(&x, &y);
	mostra("depois de troca(&x, &y):     ", x, y);
	return (0);
}
