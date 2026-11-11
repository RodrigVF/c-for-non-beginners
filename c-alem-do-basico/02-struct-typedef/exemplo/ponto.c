/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ponto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:08:29 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/11 12:08:29 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ponto.h"

static void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

static void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	ft_mostra_ponto(char *nome, t_ponto p)
{
	ft_putstr(nome);
	ft_putstr(" = (");
	ft_putnbr(p.x);
	ft_putstr(", ");
	ft_putnbr(p.y);
	ft_putstr(")\n");
}

void	ft_move(t_ponto *p, int dx, int dy)
{
	p->x = p->x + dx;
	p->y = p->y + dy;
}
