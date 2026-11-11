/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contagem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

void	contagem(int n)
{
	if (n == 0)
	{
		ft_putendl("caso base: n == 0, comecando a voltar");
		return ;
	}
	ft_putstr("ida   n = ");
	ft_putnbr(n);
	ft_putchar('\n');
	contagem(n - 1);
	ft_putstr("volta n = ");
	ft_putnbr(n);
	ft_putchar('\n');
}

int	soma_ate(int n)
{
	if (n <= 0)
		return (0);
	return (n + soma_ate(n - 1));
}

int	main(void)
{
	contagem(3);
	ft_putstr("soma_ate(4) = ");
	ft_putnbr(soma_ate(4));
	ft_putchar('\n');
	return (0);
}
