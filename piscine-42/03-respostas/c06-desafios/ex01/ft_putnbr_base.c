/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:34:48 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/11 12:34:48 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_base_valida(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_escreve_base(long n, char *base, int tamanho)
{
	if (n >= tamanho)
		ft_escreve_base(n / tamanho, base, tamanho);
	write(1, &base[n % tamanho], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		tamanho;
	long	n;

	tamanho = ft_base_valida(base);
	if (tamanho == 0)
		return ;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	ft_escreve_base(n, base, tamanho);
}
