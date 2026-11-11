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

void	ft_swap(int *a, int *b);

void	teste(int x, int y)
{
	int	a;
	int	b;

	a = x;
	b = y;
	ft_swap(&a, &b);
	printf("antes: a=%d b=%d | depois: a=%d b=%d\n", x, y, a, b);
}

int	main(void)
{
	teste(1, 2);
	teste(-5, 42);
	teste(7, 7);
	return (0);
}
