/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

void	desenha(int linhas, int colunas)
{
	int	l;
	int	c;

	l = 0;
	while (l < linhas)
	{
		c = 0;
		while (c < colunas)
		{
			if ((l + c) % 2 == 0)
				ft_putchar('#');
			else
				ft_putchar('.');
			c++;
		}
		ft_putchar('\n');
		l++;
	}
}

int	main(void)
{
	desenha(4, 8);
	return (0);
}
