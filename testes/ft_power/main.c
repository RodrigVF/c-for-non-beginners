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

int	ft_power(int nb, int power);

void	teste(int nb, int power)
{
	printf("ft_power(%d, %d) = %d\n", nb, power, ft_power(nb, power));
}

int	main(void)
{
	teste(2, 10);
	teste(0, 0);
	teste(5, 0);
	teste(2, -1);
	teste(-2, 3);
	teste(3, 1);
	teste(0, 3);
	return (0);
}
