/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aritmetica.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

void	mostra(char *rotulo, void *p, int valor)
{
	ft_putstr(rotulo);
	ft_putptr(p);
	ft_putstr(" -> ");
	ft_putnbr(valor);
	ft_putchar('\n');
}

void	percorre_string(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		ft_putchar(' ');
		str++;
	}
	ft_putchar('\n');
}

int	main(void)
{
	int		tab[3];
	int		*p;
	char	*s;

	tab[0] = 10;
	tab[1] = 20;
	tab[2] = 30;
	p = tab;
	s = "abc";
	mostra("p     = ", p, *p);
	mostra("p + 1 = ", p + 1, *(p + 1));
	mostra("p + 2 = ", p + 2, p[2]);
	mostra("s     = ", s, *s);
	mostra("s + 1 = ", s + 1, *(s + 1));
	percorre_string(s);
	return (0);
}
