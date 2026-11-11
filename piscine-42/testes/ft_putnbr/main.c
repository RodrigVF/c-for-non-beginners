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
#include <limits.h>

void	ft_putnbr(int nb);

void	teste(int n)
{
	printf("[");
	ft_putnbr(n);
	printf("] esperado [%d]\n", n);
}

int	main(void)
{
	setbuf(stdout, NULL);
	teste(0);
	teste(7);
	teste(-7);
	teste(10);
	teste(42);
	teste(-42);
	teste(100000);
	teste(INT_MAX);
	teste(INT_MIN);
	teste(INT_MIN + 1);
	return (0);
}
