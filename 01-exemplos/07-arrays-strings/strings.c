/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

void	soletra(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar('[');
		ft_putchar(str[i]);
		ft_putchar(']');
		i++;
	}
	ft_putendl("[\\0]");
}

int	main(void)
{
	char	palavra[4];
	char	*literal;

	palavra[0] = 'o';
	palavra[1] = 'l';
	palavra[2] = 'a';
	palavra[3] = '\0';
	literal = "ola";
	soletra(palavra);
	palavra[0] = 'O';
	ft_putendl(palavra);
	ft_putstr("sizeof(palavra) = ");
	ft_putnbr(sizeof(palavra));
	ft_putstr(" | sizeof(literal) = ");
	ft_putnbr(sizeof(literal));
	ft_putchar('\n');
	soletra(literal);
	return (0);
}
