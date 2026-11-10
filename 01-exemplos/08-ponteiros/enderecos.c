/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enderecos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

void	mostra_num(char *rotulo, int n)
{
	ft_putstr(rotulo);
	ft_putnbr(n);
	ft_putchar('\n');
}

void	mostra_ptr(char *rotulo, void *p)
{
	ft_putstr(rotulo);
	ft_putptr(p);
	ft_putchar('\n');
}

int	main(void)
{
	int	n;
	int	*p;

	n = 42;
	p = &n;
	mostra_num("n            = ", n);
	mostra_ptr("&n           = ", &n);
	mostra_ptr("p            = ", p);
	mostra_num("*p           = ", *p);
	*p = 7;
	mostra_num("apos *p = 7, n = ", n);
	return (0);
}
