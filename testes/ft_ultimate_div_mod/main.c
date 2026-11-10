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

void	ft_ultimate_div_mod(int *a, int *b);

void	teste(int x, int y)
{
	int	a;
	int	b;

	a = x;
	b = y;
	ft_ultimate_div_mod(&a, &b);
	printf("a=%d b=%d -> a=%d b=%d\n", x, y, a, b);
}

int	main(void)
{
	teste(42, 10);
	teste(10, 42);
	teste(-7, 2);
	teste(7, -2);
	teste(0, 5);
	return (0);
}
