/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verdade.c                                          :+:      :+:    :+:   */
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
	ft_putstr(" vale ");
	ft_putnbr(valor);
	ft_putchar('\n');
}

int	main(void)
{
	mostra("5 > 3   ", 5 > 3);
	mostra("5 < 3   ", 5 < 3);
	mostra("!0      ", !0);
	mostra("!42     ", !42);
	mostra("3 && 0  ", 3 && 0);
	mostra("3 || 0  ", 3 || 0);
	if (-1)
		ft_putendl("if (-1) entrou: qualquer valor diferente de 0 e verdade");
	if (0)
		ft_putendl("isto nunca aparece");
	return (0);
}
