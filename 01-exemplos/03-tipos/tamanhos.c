/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tamanhos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/ft_util.h"

void	mostra(char *nome, int tamanho)
{
	ft_putstr(nome);
	ft_putstr(": ");
	ft_putnbr(tamanho);
	ft_putendl(" byte(s)");
}

int	main(void)
{
	mostra("char  ", sizeof(char));
	mostra("short ", sizeof(short));
	mostra("int   ", sizeof(int));
	mostra("long  ", sizeof(long));
	mostra("float ", sizeof(float));
	mostra("double", sizeof(double));
	mostra("char *", sizeof(char *));
	mostra("int * ", sizeof(int *));
	return (0);
}
