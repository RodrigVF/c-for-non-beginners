/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mostra_args.c                                      :+:      :+:    :+:   */
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

	ft_putstr("argc = ");
	ft_putnbr(argc);
	ft_putchar('\n');
	i = 0;
	while (i < argc)
	{
		ft_putstr("argv[");
		ft_putnbr(i);
		ft_putstr("] = \"");
		ft_putstr(argv[i]);
		ft_putendl("\"");
		i++;
	}
	if (argv[argc] == 0)
		ft_putendl("argv[argc] = NULL (fim da lista)");
	return (0);
}
