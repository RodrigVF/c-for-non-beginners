/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divisao.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

void	mostra(char *expr, int valor)
{
	ft_putstr(expr);
	ft_putstr(" = ");
	ft_putnbr(valor);
	ft_putchar('\n');
}

int	main(void)
{
	mostra("7 / 2     ", 7 / 2);
	mostra("7 % 2     ", 7 % 2);
	mostra("-7 / 2    ", -7 / 2);
	mostra("-7 % 2    ", -7 % 2);
	mostra("1 / 3 * 3 ", 1 / 3 * 3);
	mostra("1 * 3 / 3 ", 1 * 3 / 3);
	mostra("123 % 10  ", 123 % 10);
	mostra("123 / 10  ", 123 / 10);
	return (0);
}
