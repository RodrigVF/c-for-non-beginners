/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ponto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:08:29 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/11 12:08:29 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONTO_H
# define PONTO_H

typedef struct s_ponto
{
	int	x;
	int	y;
}	t_ponto;

void	ft_mostra_ponto(char *nome, t_ponto p);
void	ft_move(t_ponto *p, int dx, int dy);

#endif
