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

void	ft_div_mod(int a, int b, int *div, int *mod);

void	teste(int a, int b)
{
	int	div;
	int	mod;

	ft_div_mod(a, b, &div, &mod);
	printf("a=%d b=%d -> div=%d mod=%d\n", a, b, div, mod);
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
