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
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	sinal(int n)
{
	if (n < 0)
		return (-1);
	if (n > 0)
		return (1);
	return (0);
}

void	teste(int caso, char *s1, char *s2, unsigned int n)
{
	printf("caso %d (n=%u): esperado %d, obtido %d\n", caso, n,
		sinal(strncmp(s1, s2, n)), sinal(ft_strncmp(s1, s2, n)));
}

int	main(void)
{
	teste(1, "abc", "abc", 3);
	teste(2, "abc", "abd", 3);
	teste(3, "abc", "abd", 2);
	teste(4, "abd", "abc", 10);
	teste(5, "abc", "xyz", 0);
	teste(6, "", "a", 1);
	teste(7, "ab", "abc", 2);
	teste(8, "ab", "abc", 3);
	teste(9, "\200", "a", 1);
	teste(10, "Piscine", "Pisca", 4);
	return (0);
}
