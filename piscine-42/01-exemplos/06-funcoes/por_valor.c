/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   por_valor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

void	tenta_mudar(int x)
{
	x = 100;
	ft_putstr("dentro de tenta_mudar, x = ");
	ft_putnbr(x);
	ft_putchar('\n');
}

int	dobro(int x)
{
	return (x * 2);
}

int	main(void)
{
	int	n;

	n = 5;
	tenta_mudar(n);
	ft_putstr("na main, n continua = ");
	ft_putnbr(n);
	ft_putchar('\n');
	n = dobro(n);
	ft_putstr("usando o retorno: n = dobro(n) = ");
	ft_putnbr(n);
	ft_putchar('\n');
	return (0);
}
