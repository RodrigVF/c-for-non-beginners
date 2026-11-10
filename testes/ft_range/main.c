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
#include <stdlib.h>

int	*ft_range(int min, int max);

void	teste(int min, int max)
{
	int	*tab;
	int	i;

	tab = ft_range(min, max);
	printf("ft_range(%d, %d) =", min, max);
	if (tab == NULL)
	{
		printf(" NULL\n");
		return ;
	}
	i = 0;
	while (i < max - min)
	{
		printf(" %d", tab[i]);
		i++;
	}
	printf("\n");
	free(tab);
}

int	main(void)
{
	teste(0, 5);
	teste(-3, 3);
	teste(5, 6);
	teste(5, 5);
	teste(5, 0);
	teste(-2147483648, -2147483645);
	return (0);
}
