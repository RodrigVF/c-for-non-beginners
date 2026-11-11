/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:08:29 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/11 12:08:29 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ponto.h"

void	ft_move_copia(t_ponto p, int dx, int dy)
{
	p.x = p.x + dx;
	p.y = p.y + dy;
}

int	main(void)
{
	t_ponto	a;
	t_ponto	b;

	a.x = 1;
	a.y = 2;
	b = a;
	ft_mostra_ponto("a", a);
	ft_move_copia(a, 10, 10);
	ft_mostra_ponto("a depois de ft_move_copia", a);
	ft_move(&a, 3, -1);
	ft_mostra_ponto("a depois de ft_move", a);
	ft_mostra_ponto("b (copia feita antes)", b);
	return (0);
}
