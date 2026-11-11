/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:35:13 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/11 12:35:13 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

void	ft_putnbr_base(int nbr, char *base);

void	teste(int n, char *base)
{
	printf("ft_putnbr_base(%d, \"%s\") = [", n, base);
	ft_putnbr_base(n, base);
	printf("]\n");
}

int	main(void)
{
	setbuf(stdout, NULL);
	teste(42, "0123456789");
	teste(0, "01");
	teste(255, "01");
	teste(255, "0123456789ABCDEF");
	teste(-42, "01");
	teste(10, "poneyvif");
	teste(INT_MAX, "0123456789abcdef");
	teste(INT_MIN, "0123456789");
	teste(INT_MIN, "01");
	teste(42, "");
	teste(42, "0");
	teste(42, "0+1");
	teste(42, "01-");
	teste(42, "0120");
	return (0);
}
