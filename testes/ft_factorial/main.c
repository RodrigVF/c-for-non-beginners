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

int	ft_factorial(int nb);

void	teste(int nb)
{
	printf("ft_factorial(%d) = %d\n", nb, ft_factorial(nb));
}

int	main(void)
{
	teste(-5);
	teste(0);
	teste(1);
	teste(5);
	teste(10);
	teste(12);
	return (0);
}
