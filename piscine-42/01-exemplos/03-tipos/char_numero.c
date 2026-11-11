/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_numero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

void	mostra(char *rotulo, int valor)
{
	ft_putstr(rotulo);
	ft_putnbr(valor);
	ft_putchar('\n');
}

int	main(void)
{
	char	c;

	c = 'A';
	mostra("'A' como numero: ", c);
	c = c + 1;
	ft_putstr("'A' + 1 como letra: ");
	ft_putchar(c);
	ft_putchar('\n');
	mostra("'7' - '0' = ", '7' - '0');
	mostra("'a' - 'A' = ", 'a' - 'A');
	c = 127;
	c = c + 1;
	mostra("char 127 + 1 = ", c);
	return (0);
}
