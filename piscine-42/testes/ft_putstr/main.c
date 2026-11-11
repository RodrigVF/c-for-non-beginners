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

void	ft_putstr(char *str);

void	teste(char *str)
{
	printf("[");
	ft_putstr(str);
	printf("]\n");
}

int	main(void)
{
	setbuf(stdout, NULL);
	teste("Ola, Piscine!");
	teste("");
	teste("a");
	teste("com\ttab e espaco");
	teste("quebra\nde linha");
	return (0);
}
