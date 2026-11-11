/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eco.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:03:22 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/11 12:03:22 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		ft_putendl("uso: ./eco palavra [outras palavras...]");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		if (i < argc - 1)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (0);
}
